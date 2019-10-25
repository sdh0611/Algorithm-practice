#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> Citations) 
{
	int Answer = 0;

	sort(Citations.begin(), Citations.end());

	vector<int> HIndices;
	vector<int> Remains;

	


	//int HIndex = Citations.size() / 2;
	
	//int Num = 0;

	//while (Num != Citations[HIndex])
	//{
	//	Num = 0;
	//	for (const auto& Element : Citations)
	//	{
	//		if (Element >= Citations[HIndex])
	//		{
	//			if (++Num > Citations[HIndex])
	//			{
	//				++HIndex;
	//				break;
	//			}
	//			
	//		}
	//	}
	//	
	//	if (Num < Citations[HIndex])
	//	{
	//		--HIndex;
	//	}
	//}

	//Answer = Citations[HIndex];

	return Answer;
}


int main()
{
	int Testcase = 0;
	cin >> Testcase;

	vector<int> Citations;
	int Input;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Citations.push_back(Input);
	}

	cout << solution(Citations) << endl;



	return 0;
}