#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(vector<int> Priorities, int Location)
{
	typedef struct PrintElement
	{
		int Location = 0;
		int Priority = 0;

		PrintElement(int NewLocation, int NewPriority)
			: Location(NewLocation), Priority(NewPriority)
		{
		}
	} PrintElement;

	int Answer = 0;

	list<PrintElement> PrintQueue;
	for (int i = 0; i < Priorities.size(); ++i)
	{
		PrintQueue.push_back(PrintElement(i, Priorities[i]));
	}

	vector<PrintElement> OrderedPrintList;
	bool bPrint = true;
	while (!PrintQueue.empty())
	{
		PrintElement Print = PrintQueue.front();
		PrintQueue.pop_front();

		for (const auto& Element : PrintQueue)
		{
			if (Element.Priority > Print.Priority)
			{
				PrintQueue.push_back(Print);
				bPrint = false;
				break;
			}
		}

		if (bPrint)
		{
			OrderedPrintList.push_back(Print);
		}
		else
		{
			bPrint = true;
		}

	}

	for (int i = 0; i < OrderedPrintList.size(); ++i)
	{
		if (OrderedPrintList[i].Location == Location)
		{
			Answer = i;
			break;
		}
	}

	for (const auto& Print : OrderedPrintList)
	{
		cout << Print.Priority << "(" << Print.Location << ")";
	}
	puts("");

	return Answer + 1;
}