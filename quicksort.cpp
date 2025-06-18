// 快速排序：分治思想。选择数组中某个元素作为基准，将数组分为两部分，一部分都比基准小，另一部分逗比基准大；再递归地对每个子数组进行快排。
// 稳定性： 不稳定。基准蒜素可能会被交换到相等元素的右侧。
// 时间复杂度： O(n×logn)~~O(n^2)。平均时间复杂度O(n×logn)。空间复杂度O(n)。
// 无论快速排序算法递归与否，排序过程中都需要用到堆栈或其他结构的辅助空间来存放当前待排序数组的首、尾位置。
// 适用情况： 很常见的排序算法，是很多编程语言内置的排序算法实现。 
#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& nums,int low,int high){   //对nums的从low--high的元素进行快速排序
    
    if (low >= high) return;
    int i = low,j = high;
    //可选，随机生成一个0~high- low下标的索引和low的元素交换位置作为基准；改变以第一个元素作为基准的快排。
    // int random = low + rand() % (high - low + 1);
    // swap(nums[low],nums[random]);
    int temp = nums[low];
    while (i < j){
        while (i < j && nums[j] > temp) j--;//从右边找第一个小于基准的数，把它赋值给temp位置
        nums[i] = nums[j];
        while (i < j && nums[i] < temp) i++;//从左边找第一个大于基准的数，把它赋值给刚才的nums[j]
        nums[j] = nums[i];
    }
    nums[i] = temp;    //把基准放在自己该待的位置
    quicksort(nums,low,i - 1);
    quicksort(nums,i + 1,high);
}

int main(){
    vector<int> nums{3,1,4,5,6,2};
    quicksort(nums,0,nums.size() - 1);
    for (int i = 0;i < nums.size();i++){
        cout << nums[i];
    }
    return 0;
}