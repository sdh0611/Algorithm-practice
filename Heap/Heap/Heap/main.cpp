#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

template<typename T>
using Sorting = function<bool(T, T)>;

template<typename T>
class Heap
{
public:
	Heap(size_t NewSize, bool bMaxHeap = true)
		:HeapSize(NewSize), CurrentSize(0), Container(NewSize + 1), bIsMaxHeap(bMaxHeap)
	{
	}

	~Heap()
	{
		Container.clear();
	}

public:
	void Insert(const T& Value)
	{
		if (CurrentSize == HeapSize)
		{
			return;
		}
		++CurrentSize;

		if (bIsMaxHeap)
		{
			MaxHeapInsert(Value);
		}
		else
		{
			MinHeapInsert(Value);
		}

	}

	bool Delete(T& Return)
	{
		if (CurrentSize < 1)
		{
			return false;
		}

		Return = Container[1];

		if (bIsMaxHeap)
		{
			MaxHeapDelete();
		}
		else
		{
			MinHeapDelete();
		}


		return true;
	}

	void Resize(size_t NewSize)
	{
		if (NewSize < 1)
		{
			return;
		}

		vector<T> Temp(NewSize + 1);
		if (NewSize < CurrentSize)
		{
			for (int i = 1; i < NewSize + 1; ++i)
			{
				Temp[i] = Container[i];
			}
			CurrentSize = NewSize;
		}
		else
		{
			for (int i = 1; i < CurrentSize + 1; ++i)
			{
				Temp[i] = Container[i];
			}
		}

		Container.swap(Temp);
		HeapSize = NewSize;
	}

	T Top()
	{
		return Container[1];
	}

	void Print()
	{
		for (int i = 1; i <= CurrentSize; ++i)
		{
			cout << Container[i] << " ";
		}

		puts("");
	}

private:
	void MaxHeapInsert(const T& Value)
	{
		int CurrentIndex = CurrentSize;
		Container[CurrentIndex] = Value;

		while (CurrentIndex / 2 > 0)
		{
			if (Container[CurrentIndex] > Container[CurrentIndex / 2])
			{
				T Temp = Container[CurrentIndex / 2];
				Container[CurrentIndex / 2] = Value;
				Container[CurrentIndex] = Temp;
				CurrentIndex /= 2;
			}
			else
			{
				break;
			}
		}

	}

	void MinHeapInsert(const T& Value)
	{
		int CurrentIndex = CurrentSize;
		Container[CurrentIndex] = Value;

		while (CurrentIndex / 2 > 0)
		{
			if (Container[CurrentIndex] < Container[CurrentIndex / 2])
			{
				T Temp = Container[CurrentIndex / 2];
				Container[CurrentIndex / 2] = Value;
				Container[CurrentIndex] = Temp;
				CurrentIndex /= 2;
			}
			else
			{
				break;
			}
		}

	}

	void MaxHeapDelete()
	{
		int CurrentIndex = 1;
		Container[CurrentIndex] = Container[CurrentSize--];

		int Left = CurrentIndex * 2;
		int Right = Left + 1;
		int Select = CurrentIndex;

		while (CurrentIndex < CurrentSize)
		{
			if (Left > CurrentSize)
			{
				break;
			}

			if (Right > CurrentSize)
			{
				Select = Left;
			}
			else
			{
				if (Container[CurrentIndex] < Container[Left])
				{
					if (Container[Left] < Container[Right])
					{
						Select = Right;
					}
					else
					{
						Select = Left;
					}
				}
				else if (Container[CurrentIndex] < Container[Right])
				{
					Select = Right;
				}
				else
				{
					break;
				}
			}

			T Temp = Container[Select];
			Container[Select] = Container[CurrentIndex];
			Container[CurrentIndex] = Temp;

			CurrentIndex = Select;
			Left = CurrentIndex * 2;
			Right = Left + 1;
		}
	}

	void MinHeapDelete()
	{
		int CurrentIndex = 1;
		Container[CurrentIndex] = Container[CurrentSize--];

		int Left = CurrentIndex * 2;
		int Right = Left + 1;
		int Select = CurrentIndex;

		while (CurrentIndex < CurrentSize)
		{
			if (Left > CurrentSize)
			{
				break;
			}

			if (Right > CurrentSize)
			{
				Select = Left;
			}
			else
			{
				if (Container[CurrentIndex] > Container[Left])
				{
					if (Container[Left] > Container[Right])
					{
						Select = Right;
					}
					else
					{
						Select = Left;
					}
				}
				else if (Container[CurrentIndex] > Container[Right])
				{
					Select = Right;
				}
				else
				{
					break;
				}
			}

			T Temp = Container[Select];
			Container[Select] = Container[CurrentIndex];
			Container[CurrentIndex] = Temp;

			CurrentIndex = Select;
			Left = CurrentIndex * 2;
			Right = Left + 1;
		}
	}


private:
	bool bIsMaxHeap;
	size_t HeapSize;
	size_t CurrentSize;

	vector<T> Container;

	Sorting<T> Sort;
};

int solution(vector<int> Scoville, int K) {
	int Answer = 0;


	return Answer;
}


int main()
{
	//int Testcase = 0;
	//puts("Testcase 입력");
	//cin >> Testcase;

	//vector<int> Scoville;
	//int Input;
	//puts("Scoville 입력");
	//for (int i = 0; i < Testcase; ++i)
	//{
	//	cin >> Input;
	//	Scoville.push_back(Input);
	//}

	//puts("K 입력");
	//int K = 0;
	//cin >> K;

	//solution(Scoville, K);

	int Size = 0;
	puts("Heap size 입력.");
	cin >> Size;
	puts("원소 입력");
	Heap<int> MyHeap(Size, true);
	int Input = 0;
	for (int i = 0; i < Size; ++i)
	{
		cin >> Input;
		MyHeap.Insert(Input);
	}

	MyHeap.Print();

	int Result;
	MyHeap.Delete(Result);
	cout << "Result : " << Result << "\n";
	MyHeap.Print();

	MyHeap.Delete(Result);
	cout << "Result : " << Result << "\n";
	MyHeap.Print();

	MyHeap.Delete(Result);
	cout << "Result : " << Result << "\n";
	MyHeap.Print();

	MyHeap.Delete(Result);
	cout << "Result : " << Result << "\n";
	MyHeap.Print();

	return 0;
}