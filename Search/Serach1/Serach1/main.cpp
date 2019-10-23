#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> solution(vector<int> Answers) 
//{
//	vector<int> MyAnswer;
//	vector<int> Win(3, 0);
//	
//	vector<vector<int>> Patterns(3);
//
//	Patterns[0].push_back(1);
//	Patterns[0].push_back(2);
//	Patterns[0].push_back(3);
//	Patterns[0].push_back(4);
//	Patterns[0].push_back(5);
//	
//	Patterns[1].push_back(2);
//	Patterns[1].push_back(1);
//	Patterns[1].push_back(2);
//	Patterns[1].push_back(3);
//	Patterns[1].push_back(2);
//	Patterns[1].push_back(4);
//	Patterns[1].push_back(2);
//	Patterns[1].push_back(5);
//
//	Patterns[2].push_back(3);
//	Patterns[2].push_back(3);
//	Patterns[2].push_back(1);
//	Patterns[2].push_back(1);
//	Patterns[2].push_back(2);
//	Patterns[2].push_back(2);
//	Patterns[2].push_back(4);
//	Patterns[2].push_back(4);
//	Patterns[2].push_back(5);
//	Patterns[2].push_back(5);
//	
//	
//	for(int i = 0; i < Patterns.size(); ++i)
//	{
//		const auto& Pattern = Patterns[i];
//		size_t PatternSize = Pattern.size();
//		for(int j = 0; j < Answers.size(); ++j)
//		{
//			if (Pattern[ ((j >= PatternSize) ? (j%PatternSize) : j) ] == Answers[j])
//			{
//				++Win[i];
//			}
//
//		}
//	}
//
//	int Max = 0;
//	for (int i = 1; i < 3; ++i)
//	{
//		if (Win[Max] < Win[i])
//		{
//			Max = i;
//		}
//	}
//
//	for (int i = 0; i < 3; ++i)
//	{
//		if (Win[Max] == Win[i])
//		{
//			MyAnswer.push_back(i+1);
//		}
//	}
//
//	sort(MyAnswer.begin(), MyAnswer.end());
//
//	return MyAnswer;
//}

vector<int> solution(vector<int> Answers)
{
	vector<int> MyAnswer;
	vector<int> Win(3, 0);

	vector<int> One = { 1, 2, 3, 4, 5 };
	vector<int> Two = { 2,1,2,3,2,4,2,5 };
	vector<int> Three = { 3,3,1,1,2,2,4,4,5,5 };
	
	for (int i = 0; i < Answers.size(); ++i)
	{
		if (Answers[i] == One[i%One.size()])
		{
			++Win[i];
		}

		if (Answers[i] == Two[i%One.size()])
		{
			++Win[i];
		}

		if (Answers[i] == Three[i%One.size()])
		{
			++Win[i];
		}
	}

	int Max = *max_element(Win.begin(), Win.end());
	for (int i = 0; i < 3; ++i)
	{
		if (Win[i] == Max)
		{
			MyAnswer.push_back(i + 1);
		}
	}


	return MyAnswer;
}


int main()
{
	int Testcase = 0;
	cin >> Testcase;

	vector<int> Answers;
	int Input;
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Answers.push_back(Input);
	}

	solution(Answers);

	return 0;
}