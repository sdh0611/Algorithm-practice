#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Heap
{
public:
	Heap(size_t NewSize, bool bGreater = false)
		:HeapSize(NewSize), Container(NewSize+1), bIsMaxHeap(bGreater)
	{
	}

	~Heap()
	{
		Container.clear();
	}

public:
	void Insert(const T& Value)
	{
		if (Container.size() == HeapSize + 1)
		{
			return;
		}

		if (bIsMaxHeap)
		{
			MaxHeapInsert(Value);
		}
		else
		{
			MinHeapInsert(Value);
		}

	}
	
	void Delete(const T& Value)
	{
		if (Container.empty())
		{
			return;
		}


	}

	T Top()
	{
		return Container[1];
	}

private:
	void MaxHeapInsert(const T& Value)
	{
		int CurrentIndex = HeapSize;
		++HeapSize;

		Container.push_back(Value);

		while (CurrentIndex > 0)
		{
			if (Value > Container[CurrentIndex / 2])
			{
				T Temp = Container[CurrentIndex / 2];
				Container[CurrentIndex / 2] = Value;
				Container[CurrentIndex] = Temp;
			}

		}

	}

	void MinHeapInsert(const T& Value)
	{

	}


private:
	bool bIsMaxHeap;
	size_t HeapSize;

	vector<T> Container;

};

int solution(vector<int> Scoville, int K) {
	int Answer = 0;


	return Answer;
}


int main()
{
	int Testcase = 0;
	puts("Testcase 입력");
	cin >> Testcase;

	vector<int> Scoville;
	int Input;
	puts("Scoville 입력");
	for (int i = 0; i < Testcase; ++i)
	{
		cin >> Input;
		Scoville.push_back(Input);
	}

	puts("K 입력");
	int K = 0;
	cin >> K;

	solution(Scoville, K);

	return 0;
}