#ifndef SORT_H
#define SORT_H

#include "Vector.h"

template <typename T>
void insertionSort(Vector<T>& a, int& ops)
{
	ops = 0;
	for (int p = 1; p < a.size(); ++p)
	{
		ops++;
		T tmp = a[p];
		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j)
		{
			a[j] = a[j - 1];
			ops++;
		}
		a[j] = tmp;
	}
}

template <typename T>
void selectionSort(Vector<T>& a, int& ops)
{
	ops = 0;
	int mindex;
	for (int i = 0; i < a.size(); i++)
	{
		ops++;
		mindex = i;
		for (int j = i; j < a.size(); j++)
		{
			if (a[j] < a[mindex])
				mindex = j;
			ops++;
		}
		std::swap(a[i], a[mindex]);
	}
}

#endif // !SORT_H

