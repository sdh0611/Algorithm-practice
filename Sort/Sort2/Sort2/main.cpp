#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> Numbers) 
{
	string Answer = "";
	sort(Numbers.begin(), Numbers.end(), greater<int>());

	int Greatest = Numbers[0];
	int Radix;
	for (; Greatest > 0; Greatest /= 10)
	{
		++Radix;
	}
	vector<vector<int>> RadixSorted(10);

	for (auto& Sorted : RadixSorted)
	{
		


	}



	return Answer;
}