#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/*
	BridgeLength : 다리 길이
	Weight : 다리가 버틸 수 있는 최대 무게
	TruckWeight : 대기중인 트럭들의 무게 리스트
*/
int Solution(int BridgeLength, int Weight, vector<int> TruckWeights) 
{
	typedef struct TruckInfo
	{
		int Weight = 0;
		int Distance = 0;

		TruckInfo(int NewWeight, int NewDistance)
			:Weight(NewWeight), Distance(NewDistance)
		{
		}

	}TruckInfo;
	
	int Seconds = 0;

	/* 대기중인 트럭 */
	list<int> TruckWaiting;
	TruckWaiting.assign(TruckWeights.begin(), TruckWeights.end());

	/* 다리 위의 트럭 */
	list<TruckInfo> TruckOnBridge;
	
	/* 다리 위의 트럭 총 무게 */
	int TotalWeight = 0;
	
	/* 모든 트럭이 다리 위를 지나갔을 경우 */
	while(!(TruckWaiting.empty() && TruckOnBridge.empty()))
	{
		/* 시간 증가 */
		++Seconds;

		/* 트럭 이동거리 증가 */
		for (auto& Truck : TruckOnBridge)
		{
			++Truck.Distance;
		}

		/* 다리를 건넌 트럭이 있는지 체크 */
		if (!TruckOnBridge.empty())
		{
			if (TruckOnBridge.front().Distance > BridgeLength)
			{
				/* 빠져나간 트럭의 무게만큼 감소 */
				TotalWeight -= TruckOnBridge.front().Weight;
				/* 빠져나간 트럭 제거 */
				TruckOnBridge.pop_front();
			}
		}

		if (!TruckWaiting.empty())
		{
			if ((TotalWeight + TruckWaiting.front()) <= Weight)
			{
				/* 다리를 지나고 있는 트럭 추가 */
				TruckOnBridge.emplace_back(TruckWaiting.front(), 1);
				/* 현재 다리가 지탱하는 무게 갱신 */
				TotalWeight += TruckOnBridge.back().Weight;
				/* 트럭 대기목록에서 제거 */
				TruckWaiting.pop_front();
			}
		}

	}

	return Seconds;
}


int main()
{

	puts("길이 입력");
	int Length = 0;
	cin >> Length;

	puts("무게 입력");
	int Weight= 0;
	cin >> Weight;

	puts("트럭 개수 입력");
	int Testcase = 0;
	cin >> Testcase;

	puts("트럭 무게 입력");
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