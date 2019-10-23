#include <string>
#include <algorithm>
#include <set>

using namespace std;

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
	set<int> Primes;

	/* 1�ڸ� �Ҽ� */
	{
		int Num = 0;
		for (const auto& Number : Numbers)
		{
			int Num = atoi(&Number);
			if (IsPrimeNumber(Num))
			{
				Primes.insert(Num);
			}

		}
	}
	
	/* 2�ڸ� �̻��� �Ҽ� */
	for (int Radix = 2; Radix <= Numbers.length(); ++Radix)
	{
		for (const auto& Number : Numbers)
		{
			string Num(&Number);
			

		}

	}
	


	Answer = Primes.size();

	return Answer;
}