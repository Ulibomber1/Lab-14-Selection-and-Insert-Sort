#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include "Sort.h"
#include "Vector.h"
#include "Random.h"
using namespace std;

int main()
{
    Vector<int> nums1;
    Vector<int> nums2;
    Vector<int> ascending1, ascending2;
    Vector<int> descending1, descending2;

    for (int i = 1; i <= 25; i++)
    {
        ascending1.push_back(2 * i);
        ascending2.push_back(2 * i);
    }
    for (int i = 25; i > 0; i--)
    {
        descending1.push_back(3 * i);
        descending2.push_back(3 * i);
    }

    int ops1;
    int ops2;

    insertionSort(ascending1, ops1);
    selectionSort(ascending2, ops2);

    cout << "insertionSort on 25 ascending: " << ops1 << endl;
    cout << "selectionSort on 25 ascending: " << ops2 << endl;
    cout << endl;

    insertionSort(descending1, ops1);
    selectionSort(descending2, ops2);

    cout << "insertionSort on 25 descending: " << ops1 << endl;
    cout << "selectionSort on 25 descending: " << ops2 << endl;
    cout << endl;

    float sum1 = 0;
    float sum2 = 0;

    for (int i = 1; i <= 10; i++)
    {
        nums1.clear();
        nums2.clear();
        rand_seed();
        random_vector(25, 1, 250, nums1, 0);
        for (int i = 0; i < nums1.size(); i++)
            nums2.push_back(nums1[i]);

        insertionSort(nums1, ops1);
        selectionSort(nums2, ops2);

        cout << "insertionSort on 25 random values: " << ops1 << endl;
        cout << "selectionSort on 25 random values: " << ops2 << endl;
        cout << endl;

        sum1 += ops1;
        sum2 += ops2;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    cout << "insertionSort average: " << sum1 / 10 << endl;
    cout << "selectionSort average: " << sum2 / 10 << endl;

    return 0;
}
