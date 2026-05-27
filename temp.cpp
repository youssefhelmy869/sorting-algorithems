#include <vector>
#include <iostream>

using namespace std;

int linear_search(vector<int> &list, int target)
{
    // return index of number found if not found then index = -1
    int i = 0;
    for (int num : list)
    {
        if (num == target)
        {
            return i;
        }
        ++i;
    }
    return -1;
}

int earse_small(vector<int> &list)
{
    cout << "earse small function called\n";

    // find smallest number form the list return it and removes it from the vector
    int small = INT_MAX;
    for (int num : list)
    {
        if (num < small)
        {
            small = num;
        }
    }
    int index = linear_search(list, small);
    list.erase(list.begin() + index);

    cout << "earse small function finised\n";
    return small;
}
vector<int> selection_sort(vector<int> &list)
{
    vector<int> sorted_list;
    while(list.size()>0){
        sorted_list.push_back(earse_small(list));
    }
    return sorted_list;
}

int main()
{
    vector<int> nums = {3, 5, 7, 8, 2, 9};
    vector<int> list = selection_sort(nums);
    for (int &i : list)
    {
        cout << i << "\n";
    }
    
    return 0;
}
