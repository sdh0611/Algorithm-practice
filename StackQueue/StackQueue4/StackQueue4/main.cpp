#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int Solution(int BridgeLength, int Weight, vector<int> TruckWeights) 
{
	int Seconds = 0;

	list<int> TruckOnBridge(TruckWeights.begin(), TruckWeights.end());
	
	int TotalWeight = 0;
	while(true)
	{
		if (TotalWeight < Weight)
		{
		
		}


		++Seconds;
	}


	return Seconds;
}


int main()
{
	int Testcase = 0;
	cin >> Testcase;

	puts("���� �Է�");
	int Length = 0;
	cin >> Length;

	puts("���� �Է�");
	int Weight= 0;
	cin >> Weight;

	puts("Ʈ�� �Է�");
	vector<int> Weights;
	int Input = 0;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Weights.push_back(Input);
	}

	cout << "Seconds : " << Solution(Length, Weight, Weights) << "\n";

	return 0;
}