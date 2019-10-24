#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<int> Primes;
vector<bool> Visited;
string PrimeNumber;

bool IsPrimeNumber(int Number)
{
	if (Number < 2)
	{
		return false;
	}

	for (int i = 2; i < Number / 2; ++i)
	{
		if (Number % i == 0)
		{
			return false;
		}
	}

	return true;
}




int solution(string Numbers)
{
	int Answer = 0;
	
	PrimeNumber.assign(4, NULL);
	Visited.assign(Numbers.length(), false);
	
	sort(Numbers.begin(), Numbers.end(), greater<char>());

	

	

	Answer = Primes.size();

	return Answer;
}


int main()
{
	solution("011");
	
	return 0;
}