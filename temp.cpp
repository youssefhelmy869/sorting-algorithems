#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;



vector<int> merge_sort(vector<int> arr)
{
    int arr_size = arr.size();
    if (arr_size <= 1)
    {
        return arr;
    }

    int mid = (arr_size - 1) / 2;
    vector<int> list1 = {};
    vector<int> list2 = {};
    if (arr_size > 1)
    {
        for (int i = 0; i <= mid; ++i)
        {
            list1.push_back(arr[i]);
        }
        for (int i = mid + 1; i < arr_size; ++i)
        {
            list2.push_back(arr[i]);
        }

        list1 = merge_sort(list1);
        list2 = merge_sort(list2);
    }
    // merge step
    vector<int> ordered_list;
    int i = 0;
    int j = 0;
    while (i < list1.size() && j < list2.size())
    {
        if (list1[i] < list2[j])
        {
            ordered_list.push_back(list1[i]);
            ++i;
        }
        else
        {
            ordered_list.push_back(list2[j]);
            ++j;
        }
    }
    while (i < list1.size())
    {
        ordered_list.push_back(list1[i]);
        ++i;
    }

    while (j < list2.size())
    {
        ordered_list.push_back(list2[j]);
        ++j;
    }

    return ordered_list;
}