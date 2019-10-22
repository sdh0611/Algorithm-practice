#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/*
	BridgeLength : �ٸ� ����
	Weight : �ٸ��� ��ƿ �� �ִ� �ִ� ����
	TruckWeight : ������� Ʈ������ ���� ����Ʈ
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

	/* ������� Ʈ�� */
	list<int> TruckWaiting;
	TruckWaiting.assign(TruckWeights.begin(), TruckWeights.end());

	/* �ٸ� ���� Ʈ�� */
	list<TruckInfo> TruckOnBridge;
	
	/* �ٸ� ���� Ʈ�� �� ���� */
	int TotalWeight = 0;
	
	/* ��� Ʈ���� �ٸ� ���� �������� ��� */
	while(!(TruckWaiting.empty() && TruckOnBridge.empty()))
	{
		/* �ð� ���� */
		++Seconds;

		/* Ʈ�� �̵��Ÿ� ���� */
		for (auto& Truck : TruckOnBridge)
		{
			++Truck.Distance;
		}

		/* �ٸ��� �ǳ� Ʈ���� �ִ��� üũ */
		if (!TruckOnBridge.empty())
		{
			if (TruckOnBridge.front().Distance > BridgeLength)
			{
				/* �������� Ʈ���� ���Ը�ŭ ���� */
				TotalWeight -= TruckOnBridge.front().Weight;
				/* �������� Ʈ�� ���� */
				TruckOnBridge.pop_front();
			}
		}

		if (!TruckWaiting.empty())
		{
			if ((TotalWeight + TruckWaiting.front()) <= Weight)
			{
				/* �ٸ��� ������ �ִ� Ʈ�� �߰� */
				TruckOnBridge.emplace_back(TruckWaiting.front(), 1);
				/* ���� �ٸ��� �����ϴ� ���� ���� */
				TotalWeight += TruckOnBridge.back().Weight;
				/* Ʈ�� ����Ͽ��� ���� */
				TruckWaiting.pop_front();
			}
		}

	}

	return Seconds;
}


int main()
{

	puts("���� �Է�");
	int Length = 0;
	cin >> Length;

	puts("���� �Է�");
	int Weight= 0;
	cin >> Weight;

	puts("Ʈ�� ���� �Է�");
	int Testcase = 0;
	cin >> Testcase;

	puts("Ʈ�� ���� �Է�");
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