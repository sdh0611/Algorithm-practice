#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int N, vector<vector<int>> Computers)
{
	int Answer = 0;

	vector<bool> Visited(N, false);

	list<int> Queue;


	for(int Node = 0; Node < N; )
	{
		Queue.push_back(Node);

		do
		{
			int Current = Queue.front();
			Queue.pop_front();
			Visited[Current] = true;
			for (int i = 0; i < N; ++i)
			{
				if (i != Current && !Visited[i])
				{
					if (Computers[Current][i])
					{
						Queue.push_back(i);
					}
				}
			}

		}while(!Queue.empty());

		++Answer;

		Node = N;
		for (int i = 0; i < N; ++i)
		{
			if (!Visited[i])
			{
				Node = i;
				break;
			}
		}

	}

	return Answer;
}


int main()
{
	int Testcase = 0;
	cin >> Testcase;

	vector<vector<int>> Computers(Testcase, vector<int>());
	int Input;
	for (auto& Net : Computers)
	{
		for (int i = 0; i < Testcase; ++i)
		{
			cin >> Input;
			Net.push_back(Input);
		}
	}

	solution(Testcase, Computers);

	return 0;
}