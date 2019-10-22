#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> Prices) 
{
	typedef struct PriceInfo
	{
		int Price;
		int Index;

		PriceInfo()
			:Price(0), Index(0)
		{
		}

		PriceInfo(int NewPrice, int NewIndex = 0)
			:Price(NewPrice), Index(NewIndex)
		{
		}

	}PriceInfo;

	vector<PriceInfo> Stack;
	vector<int> Ages(Prices.size(), 0);

	Stack.emplace_back(Prices[0], 0);

	size_t Size = Prices.size();
	for (int i = 1; i < Size; ++i)
	{
		for (const auto& Element : Stack)
		{
			++Ages[Element.Index];
		}

		while (!Stack.empty())
		{
			if (Prices[i] < Stack.back().Price)
			{
				Stack.pop_back();
			}
			else
			{
				break;
			}
		}
		Stack.emplace_back(Prices[i], i);

	}

	return Ages;
}


int main()
{
	int Testcase = 0;
	puts("Testcase 입력");
	cin >> Testcase;
	
	puts("가격 리스트 입력.");
	vector<int> Prices;
	int Input;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Prices.push_back(Input);
	}

	auto Ages = solution(Prices);
	for (const auto& Age : Ages)
	{
		cout << Age << " ";
	}
	puts("");

	return 0;
}