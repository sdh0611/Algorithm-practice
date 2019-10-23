#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> Array, vector<vector<int>> Commands)
{
	vector<int> Answer;

	for (const auto& Command : Commands)
	{
		vector<int> NewArray(Array.begin() + Command[0] - 1, Array.begin() + Command[1] - 1);
		sort(NewArray.begin(), NewArray.end());
		Answer.push_back(NewArray[Command[2] - 1]);
		
	}


	return Answer;
}

int main()
{


	return 0;
}