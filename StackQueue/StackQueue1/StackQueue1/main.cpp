#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> Progresses, vector<int> Speeds) 
{
	vector<int> Answer;

	int Publish = 0;
	int Front = 0;
	size_t Size = Progresses.size();

	while (Front < Size)
	{
		for (int i = Front; i < Size; ++i)
		{
			if (Progresses[i] < 100)
			{
				Progresses[i] += Speeds[i];
			}
		}

		for (int i = Front; i < Size; ++i)
		{
			if (Progresses[i] >= 100)
			{
				if (i == Front)
				{
					++Publish;
					++Front;
				}
			}
		}
		
		if (Publish > 0)
		{
			cout << Publish << endl;
			Answer.push_back(Publish);
			Publish = 0;
		}

	}

	return Answer;
}

int main()
{
	int Testcase = 0;
	puts("Testcase 입력");
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