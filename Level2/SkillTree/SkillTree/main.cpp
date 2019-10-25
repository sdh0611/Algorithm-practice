#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string Skill, vector<string> SkillTrees)
{
	int Answer = 0;

	int Index = 0;
	bool bCollect = true;
	string SkillStack;

	int CurrentSkillIndex = 0;

	for (const auto& SkillTree : SkillTrees)
	{
		SkillStack.clear();

		cout << "SkillTree : " << SkillTree << "\n";
		for (const auto& MySkill : SkillTree)
		{
			if (Skill.end() != find(Skill.begin(), Skill.end(), MySkill))
			{
				cout << MySkill << " ";
				SkillStack.push_back(MySkill);
			}

		}
		puts("");
		for (int i = 0; i < SkillStack.size(); ++i)
		{
			if (SkillStack[i] != Skill[i])
			{
				bCollect = false;
				break;
			}
		}

		if (bCollect)
		{
			++Answer;
		}
		else
		{
			bCollect = true;
		}

	}

	return Answer;
}
int main()
{

	return 0;
}