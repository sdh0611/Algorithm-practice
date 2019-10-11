#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>


using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	vector<int> answer;

	map<string, vector<pair<int, int>>> GenrePlayMap;
	unordered_map<string, int> GenreTotalPlay;

	/* Key �ʱ�ȭ */
	for (const auto& Genre : genres)
	{
		GenrePlayMap.insert(std::make_pair(Genre, vector<pair<int, int>>()));
		GenreTotalPlay.insert(std::make_pair(Genre, 0));
	}

	/* Value �ʱ�ȭ */
	for (int i = 0; i < genres.size(); ++i)
	{
		GenrePlayMap[genres[i]].push_back(make_pair(i, plays[i]));
		GenreTotalPlay[genres[i]] += plays[i];
	}


	/* ���� : PlayMap*/
	{
		auto Sort = [](pair<int, int> First, pair<int, int> Second) ->bool {
			if (First.second == Second.second)
			{
				return First.first < Second.first;
			}

			return First.second > Second.second;
		};
		for (auto& Genre : GenrePlayMap)
		{
			sort(Genre.second.begin(), Genre.second.end(), Sort);
		}
	}

	puts("Play ����");
	for (const auto& Play : GenrePlayMap)
	{
		puts(Play.first.c_str());
		for (const auto& Genre : Play.second)
		{
			cout << Genre.first << " : " << Genre.second << "\n";
		}
		puts("");
	}


	/* ���� : Total Play */
	vector<pair<string, int>> GenreTotalPlaySort;
	for (const auto& Genre : GenreTotalPlay)
	{
		GenreTotalPlaySort.push_back(Genre);
	}

	auto MapSort = [](pair<string, int> First, pair<string, int> Second)->bool {
		return First.second > Second.second;
	};
	sort(GenreTotalPlaySort.begin(), GenreTotalPlaySort.end(), MapSort);
	GenreTotalPlay.clear();

	for (auto& Genre : GenreTotalPlaySort)
	{
		GenreTotalPlay[Genre.first] = Genre.second;
		cout << Genre.first << " : " << Genre.second << "\n";
	}


	/* ��� */
	for (const auto& GenreTotal : GenreTotalPlaySort)
	{
		puts(GenreTotal.first.c_str());
		for (const auto& GenrePlay : GenrePlayMap[GenreTotal.first])
		{
			answer.push_back(GenrePlay.first);
		}

	}

	answer.pop_back();

	for (const auto& Genre : answer)
	{
		cout << Genre << " ";
	}
	puts("");

	return answer;
}


int main()
{
	int TestCase = 0;
	cin >> TestCase;

	vector<string> Genres;
	string Input;
	puts("�帣 �Է�.");
	for (int i = 0; i < TestCase; ++i)
	{
		cin >> Input;
		//cout << Input << " ";
		Genres.push_back(Input);
	}

	puts("�÷��� Ƚ�� �Է�");
	vector<int> Plays;
	int Play = 0;
	for (int i = 0; i < TestCase; ++i)
	{
		cin >> Play;
		//cout << Play << " ";
		Plays.push_back(Play);
	}

	solution(Genres, Plays);

	//auto Results = solution(Genres, Plays);
	//for (const auto& Result : Results)
	//{
	//	cout << Result << " ";
	//}
	//puts("");

	return 0;
}


