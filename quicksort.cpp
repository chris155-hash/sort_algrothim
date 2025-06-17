// 快速排序：分治思想。选择数组中某个元素作为基准，将数组分为两部分，一部分都比基准小，另一部分逗比基准大；再递归地对每个子数组进行快排。

#include<bits/stdc++.h>
using namespace std;

vector<int> quicksort(vector<int> nums){
     
}

int main(){
    vector<int> nums{1,3,4,5,6,2};
    nums = quicksort(nums);
    for (int i = 0;i < nums.size();i++){
        cout << nums[i];
    }
    return 0;
}