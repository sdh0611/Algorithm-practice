#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(int BridgeLength, int Weight, vector<int> TruckWeights) 
{
	typedef struct Truck
	{
		int Weight = 0;
		int Distance = 0;

		Truck(int NewWeight, int NewDistance)
			:Weight(NewWeight), Distance(NewDistance)
		{
		}

	}Truck;

	int Seconds = 0;

	list<int> WaitTrucks;
	WaitTrucks.assign(TruckWeights.begin(), TruckWeights.end());

	list<int> TruckOnBridge;

	int BridgeWeight = 0;

	do
	{
		if (BridgeWeight + WaitTrucks.front() < Weight)
		{
			BridgeWeight += WaitTrucks.front();
			TruckOnBridge.push_back(0);
			//WaitTrucks.pop_front();
		}

		for (auto& Truck : TruckOnBridge)
		{
			++Truck;
		}

		if (TruckOnBridge.front()> BridgeLength)
		{
			BridgeWeight -= TruckOnBridge.front().Weight;
			WaitTrucks.pop_front();
			if (BridgeWeight < 0)
			{
				BridgeWeight = 0;
			}
			
			TruckOnBridge.pop_front();
		}

		++Seconds;
	} while (!(TruckOnBridge.empty() && WaitTrucks.empty()));


	return Seconds;
}


int main()
{
	int Testcase = 0;
	cin >> Testcase;

	puts("길이 입력");
	int Length = 0;
	cin >> Length;

	puts("무게 입력");
	int Weight= 0;
	cin >> Weight;

	puts("트럭 입력");
	vector<int> Weights;
	int Input = 0;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Weights.push_back(Input);
	}

	cout << "Seconds : " << solution(Length, Weight, Weights) << "\n";

	return 0;
}