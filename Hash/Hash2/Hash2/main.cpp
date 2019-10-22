#include <string>
#include <vector>


using namespace std;

bool solution(vector<string> phone_book)
{
	bool answer = true;

	for (auto FirstIt = phone_book.cbegin(); FirstIt != phone_book.cend(); ++FirstIt)
	{
		size_t size = FirstIt->length();
		for (auto SecondIt = phone_book.cbegin(); SecondIt != phone_book.cend(); ++SecondIt)
		{
			if (FirstIt == SecondIt)
			{
				continue;
			}

			if ((*FirstIt) == (*SecondIt).substr(0, size))
			{
				return false;
			}

		}

	}

	return answer;
}

//bool solution(vector<string> phone_book)
//{
//	bool answer = true;
//
//	
//
//
//	return answer;
//}

int main()
{



	return;
}