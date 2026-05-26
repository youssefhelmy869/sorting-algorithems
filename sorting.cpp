#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;
vector<int> bubble_sort(vector<int> list)
{
    cout << "using bubble sort\n";
    bool sorted = false;
    while (not sorted)
    {
        sorted = true;
        int temp;
        for (int i = 0; i < list.size() - 1; ++i)
        {
            if (list[i] > list[i + 1])
            {
                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                sorted = false;
            }
        }
    }
    return list;
}

void worker(int k, vector<int> &output_list, mutex &m)
{
    this_thread::sleep_for(chrono::milliseconds(k * 100));
    lock_guard<mutex> lg(m);
    output_list.push_back(k);
}

vector<int> sleep_sort(vector<int> &list)
{
    for (auto &i : list)
    {
        if (i < 0)
        {
            cout<<"error:this list has a negtive number\n";
            return{} ;
        }
    }
    cout << "using sleep sort\n";
    vector<int> output_list;
    vector<thread> threads;
    mutex m;
    for (auto k : list)
    {
        threads.emplace_back(worker, k, ref(output_list), ref(m));
    }
    for (auto &t : threads)
    {
        t.join();
    }
    return output_list;
}

int main()
{
    vector<int> nums = {1, 4, 5, 6, 2, 4, 3, 7, 8, 6, 7, 8, 5, -1, 0};
    nums = sleep_sort(nums);
    for (auto &i : nums)
    {
        cout << i << "\n";
    }
    return 0;
}
