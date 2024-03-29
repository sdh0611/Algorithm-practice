#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> UsingWord;

bool CanConvert(string Word, string Other)
{
	sort(Word.begin(), Word.end());
	sort(Other.begin(), Other.end());

	int Differ = 0;
	for (int i = 0; i < Word.length(); ++i)
	{
		if (Word[i] != Other[i])
		{
			++Differ;
			if (Differ > 2)
			{
				return false;
			}
		}
	}

	return true;
}

bool DFS(int& Level, string CurrentWord, string Target, const vector<string>& Words)
{
	if (CurrentWord == Target)
	{
		return true;
	}

	bool Result = false;

	for (const auto& Word : Words)
	{
		if (UsingWord.find(Word) != UsingWord.end())
		{
			if (CanConvert(CurrentWord, Word))
			{
				UsingWord.insert(Word);
				Result = DFS(++Level, Word, Target, Words);
				UsingWord.erase(Word);
			}
		}
	}

	if (!Result)
	{
		--Level;
	}

	return Result;
}

int solution(string Begin, string Target, vector<string> Words) 
{
	if (find(Words.begin(), Words.end(), Target) == Words.end())
	{
		return 0;
	}
	
	int Answer = 0;

	vector<bool> Converted(Begin.length(), false);
	
	string CurrentWord = Begin;
	
	int Result = 0;
	for (const auto& Word : Words)
	{
		if (Target == Word)
		{
			Answer = 1;
			break;
		}

		if (DFS(Result, CurrentWord, Target, Words))
		{
			if (Answer > Result)
			{
				Answer = Result;
			}
		}
	}

	return Answer;
}
