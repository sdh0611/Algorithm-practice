#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> Progresses, vector<int> Speeds) {
	vector<int> Answer;

	vector<bool> IsComplete;
	for (int i = 0; i < Progresses.size(); ++i)
	{
		IsComplete.push_back(false);
	}

	int PublishStack = 0;
	int PublishNum = 0;

	for(int Prog = 0; Prog < Progresses.size(); )
	{
		for (int i = Prog; i < Progresses.size() && Prog < Progresses.size() ; ++i)
		{
			if (Progresses[i] < 100)  // 해당 Progress가 완료되지 않았을 때 
			{
				Progresses[i] += Speeds[i];
				if (Progresses[i] >= 100)
				{
					IsComplete[i] = true;
				}
			}
			else  // 해당 Progress를 완료했을 때 
			{
				/* 맨 앞의 Progress가 완료되면 */
				if (IsComplete[Prog])
				{
					int j = Prog;
					for ( ; j < Progresses.size(); ++j)
					{
						if (IsComplete[j])
						{
							++PublishNum;
						}
						else
						{
							break;
						}

					}

					Prog = j;
					Answer.push_back(PublishNum);
					PublishNum = 0;

				}

			}

		}

	}
	
	for (const auto& Num : Answer)
	{
		cout << Num << " ";
	}
	puts("");

	return Answer;
}

int main()
{
	int Testcase = 0;
	cin >> Testcase;

	vector<int> Progresses;
	int Input = 0;
	puts("Progress 입력");
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Progresses.push_back(Input);
	}

	vector<int> Speeds;
	puts("Speed 입력");
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Speeds.push_back(Input);
	}

	solution(Progresses, Speeds);

}