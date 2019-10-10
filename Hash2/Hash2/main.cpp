#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
	bool answer = true;

	for (auto FirstIt = phone_book.cbegin(); FirstIt != (phone_book.cend() - 1); ++FirstIt)
	{
		size_t size = FirstIt->size();
		for (auto SecondIt = FirstIt + 1; SecondIt != phone_book.cend(); ++SecondIt)
		{
			if ((*FirstIt) == (*SecondIt).substr(0, size))
			{
				return false;
			}

		}

	}


	return answer;
}


int main()
{



	return;
}