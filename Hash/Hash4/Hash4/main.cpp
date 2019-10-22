#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

/*
	���� ����
	��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�.�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

	���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
	�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
	�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
	�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

	���ѻ���
	genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
	plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
	genres�� plays�� ���̴� ������, �̴� 1 �̻� 10, 000 �����Դϴ�.
	�帣 ������ 100�� �̸��Դϴ�.
	�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
	��� �帣�� ����� Ƚ���� �ٸ��ϴ�.

	����� ��
	genres									plays								return
	[classic, pop, classic, classic, pop], [500, 600, 150, 800, 2500], [4, 1, 3, 0]

	����� �� ����
	classic �帣�� 1, 450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.
	���� ��ȣ 3: 800ȸ ���
	���� ��ȣ 0 : 500ȸ ���
	���� ��ȣ 2 : 150ȸ ���
	pop �帣�� 3, 100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.

	���� ��ȣ 4 : 2, 500ȸ ���
	���� ��ȣ 1 : 600ȸ ���
	���� pop �帣��[4, 1]�� �뷡�� ����, classic �帣��[3, 0]�� �뷡�� �״����� �����մϴ�.
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


