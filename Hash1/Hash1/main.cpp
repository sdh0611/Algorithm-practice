#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//string solution(vector<string> participant, vector<string> completion) 
//{
//	string answer = "";
//
//	for (auto It = completion.begin(); It != completion.end(); ++It)
//	{
//		participant.erase(find(participant.cbegin(), participant.cend(), *It));
//	}
//
//	if (!participant.empty())
//	{
//		answer = participant[0];
//	}
//
//	return answer;
//}


string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	
	size_t size = completion.size();
	for (int i = 0; i < size; ++i)
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}

	return answer;
}


int main()
{
	int testcase, completions;
	cin >> testcase;
	cin >> completions;

	puts("������ ��� �Է�");
	vector<string> tests;
	string input;
	for (int i = 0; i < testcase; ++i)
	{
		cin >> input;
		tests.push_back(input);

	}

	puts("������ ��� �Է�");
	vector<string> completion;
	for (int i = 0; i < completions; ++i)
	{
		cin >> input;
		completion.push_back(input);

	}

	cout << "Ż���� : " << solution(tests, completion) << endl;

	return 0;
}

