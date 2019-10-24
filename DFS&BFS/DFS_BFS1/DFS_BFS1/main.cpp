#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int DFS(const vector<int>& Numbers, int Number, int Index, int Target)
{
	if (Index < Numbers.size())
	{
		return DFS(Numbers, Number + Numbers[Index], Index + 1, Target)
			+ DFS(Numbers, Number - Numbers[Index], Index + 1, Target);
	}

	return (Number == Target) ? 1 : 0;
}

int solution(vector<int> Numbers, int Target)
{
	int Answer = 0;
	Answer = DFS(Numbers, 0, 0, Target);

	return Answer;
}

int main()
{
	int Testcase = 0;
	cin >> Testcase;

	int Input;
	vector<int> Numbers;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Numbers.push_back(Input);
	}

	int Target = 0;
	cin >> Target;

	cout << solution(Numbers, Target) << endl;


	return 0;
}