#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int N) 
{
	string Answer = "";
	string Num = "412";

	int Remain = 0;
	while (N > 0)
	{
		Remain = N % 3;
		N /= 3;
		if (0 == Remain)
		{
			--N;
		}
		Answer.push_back(Num[Remain]);
	}

	string Temp(Answer.rbegin(), Answer.rend());
	swap(Temp, Answer);

	return Answer;
}


int main()
{
	int Testcase;
	cin >> Testcase;
	
	cout << solution(Testcase) << endl;

	return 0;
}