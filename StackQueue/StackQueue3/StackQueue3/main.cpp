#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> Heights) 
{
	vector<int> Answer;
	Answer.assign(Heights.size(), 0);

	for (int i = Heights.size() - 1; i > 0; --i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (Heights[j] > Heights[i])
			{
				Answer[i] = j+1;
				break;
			}

		}

	}

	return Answer;
}


int main()
{




	return 0;
}