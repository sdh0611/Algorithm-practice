#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, vector<string>> ClothMap;
	
	for (int i = 0; i < clothes.size(); ++i)
	{
		ClothMap.insert(std::make_pair(clothes[i][1], vector<string>()));
	}
	
	for (int i = 0; i < clothes.size(); ++i)
	{
		ClothMap[clothes[i][1]].push_back(clothes[i][0]);
	}

	for (const auto& Cloth : ClothMap)
	{
		answer *= (Cloth.second.size()+1);
	}

	return answer-1;
}


int main()
{


	return;
}