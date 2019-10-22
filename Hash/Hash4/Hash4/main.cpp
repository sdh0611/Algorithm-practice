#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

/*
	문제 설명
	스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

	속한 노래가 많이 재생된 장르를 먼저 수록합니다.
	장르 내에서 많이 재생된 노래를 먼저 수록합니다.
	장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
	노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

	제한사항
	genres[i]는 고유번호가 i인 노래의 장르입니다.
	plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
	genres와 plays의 길이는 같으며, 이는 1 이상 10, 000 이하입니다.
	장르 종류는 100개 미만입니다.
	장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
	모든 장르는 재생된 횟수가 다릅니다.

	입출력 예
	genres									plays								return
	[classic, pop, classic, classic, pop], [500, 600, 150, 800, 2500], [4, 1, 3, 0]

	입출력 예 설명
	classic 장르는 1, 450회 재생되었으며, classic 노래는 다음과 같습니다.
	고유 번호 3: 800회 재생
	고유 번호 0 : 500회 재생
	고유 번호 2 : 150회 재생
	pop 장르는 3, 100회 재생되었으며, pop 노래는 다음과 같습니다.

	고유 번호 4 : 2, 500회 재생
	고유 번호 1 : 600회 재생
	따라서 pop 장르의[4, 1]번 노래를 먼저, classic 장르의[3, 0]번 노래를 그다음에 수록합니다.
*/

using namespace std;

vector<int> solution(vector<string> Genres, vector<int> Plays) 
{
	vector<int> Answer;
	
	typedef struct PlayInfo
	{
		string GenreName;
		int Play;
		int ID;

		PlayInfo()
		{
		}

		PlayInfo(const string& NewGenre, int NewPlay, int NewID)
			:GenreName(NewGenre), Play(NewPlay), ID(NewID)
		{
		}

	}PlayInfo;

	typedef struct TotalPlayInfo
	{
		string GenreName;
		int TotalPlay;

		TotalPlayInfo()
		{
		}

		TotalPlayInfo(const string& NewGenre, int NewPlay)
			:GenreName(NewGenre), TotalPlay(NewPlay)
		{
		}

	}TotalPlayInfo;


	vector<PlayInfo> GenrePlay(Plays.size());
	for (int i = 0; i < GenrePlay.size(); ++i)
	{
		GenrePlay[i].GenreName = Genres[i];
		GenrePlay[i].Play = Plays[i];
		GenrePlay[i].ID = i;
	}


	set<string> GenreSet;
	for (const auto& GenreName : Genres)
	{
		GenreSet.insert(GenreName);
	}
	
	map<string, int> GenreTotalPlay;
	for (const auto& GenreName : GenreSet)
	{
		GenreTotalPlay.emplace(GenreName, 0);
	}
	
	for (int i = 0; i < Genres.size(); ++i)
	{
		GenreTotalPlay[Genres[i]] += Plays[i];
	}
	
	vector<pair<string, int>> SortingTotalPlay(GenreTotalPlay.begin(), GenreTotalPlay.end());
	auto Sorting = [](pair<string, int> First, pair<string, int> Second)->bool {
		return First.second < Second.second;
	};
	sort(SortingTotalPlay.begin(), SortingTotalPlay.end(), Sorting);
	
	GenreTotalPlay.clear();
	for (const auto& Element : SortingTotalPlay)
	{
		GenreTotalPlay.insert(Element);
	}
	
	


	return Answer;
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


