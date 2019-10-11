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

	/* Key 초기화 */
	for (const auto& Genre : genres)
	{
		GenrePlayMap.insert(std::make_pair(Genre, vector<pair<int, int>>()));
		GenreTotalPlay.insert(std::make_pair(Genre, 0));
	}

	/* Value 초기화 */
	for (int i = 0; i < genres.size(); ++i)
	{
		GenrePlayMap[genres[i]].push_back(make_pair(i, plays[i]));
		GenreTotalPlay[genres[i]] += plays[i];
	}


	/* 정렬 : PlayMap*/
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

	puts("Play 정렬");
	for (const auto& Play : GenrePlayMap)
	{
		puts(Play.first.c_str());
		for (const auto& Genre : Play.second)
		{
			cout << Genre.first << " : " << Genre.second << "\n";
		}
		puts("");
	}


	/* 정렬 : Total Play */
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


	/* 출력 */
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
	puts("장르 입력.");
	for (int i = 0; i < TestCase; ++i)
	{
		cin >> Input;
		//cout << Input << " ";
		Genres.push_back(Input);
	}

	puts("플레이 횟수 입력");
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


