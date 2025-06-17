// 归并排序： 分治思想，递归地将当前数组分成两半，然后将有序数组两两合并，最终合并成一个有序数组。
// 稳定性： 稳定。（取决于你的写法！！！）
// 时间复杂度： O(N*log(N))。空间复杂度：O(N)。
// 适用场景： 处理大规模数据，缺点是会用到N的额外空间。
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
// 写的变量命名好像有一点乱，大家包涵下。
vector<int> merge(vector<int>& nums1,vector<int>& nums2){
    int n1 = nums1.size(),n2 = nums2.size();
    int left_i = 0,right_i = 0;
    vector<int>nums;
    while (left_i < n1 && right_i < n2){
        if (nums1[left_i] <= nums2[right_i]) nums.push_back(nums1[left_i++]);  //这里<=才是稳定的，同等条件先放nums1的。<的话就不是稳定的喽
        else nums.push_back(nums2[right_i++]);
    }
    while (left_i < n1){
        nums.push_back(nums1[left_i]);
        left_i ++;
    }
    while (right_i < n2){
        nums.push_back(nums2[right_i]);
        right_i ++;
    }
    return nums;
}

vector<int> mergesort(vector<int>& nums){
    int n = nums.size();
    if (nums.size() <= 1) return nums;
    vector<int> left_nums(nums.begin(),nums.begin() + n / 2);
    vector<int> right_nums(nums.begin() + n / 2,nums.end());
    vector<int> left = mergesort(left_nums);
    vector<int> right = mergesort(right_nums);
    return merge(left,right);
}

int main(){
    vector<int> nums = {1,3,4,2,5,6};
    nums = mergesort(nums);
    for (int i = 0;i < nums.size();i++){
        cout << nums[i];
    }
    return 0;
}