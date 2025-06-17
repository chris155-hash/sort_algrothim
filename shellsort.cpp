// 希尔排序：数组按照一定间隔划分成若干个组，每个组内进行插入排序；随后逐步缩小间隔 ，重复流程，直至最后一轮间隔为1.
// 稳定性： 不稳定。
// 时间复杂度： 介于O(N*log(n)^2)到O(N^2)之间。基于间隔序列，一般是在O(log(N))到O(N^2)之间，比如常用的间隔序列，size/2,一直/2直到为1。
// 适合中等数据规模，是插入排序的进阶版。
#include<bits/stdc++.h>
using namespace std;
void shellsort(int* nums,int n){
    //代码就是对插入排序外面套一个for循环
    int gap = n / 2;
    while (gap >0){
        for (int i = gap;i < n;i++){
            int temp = nums[i];
            int j = i;
            while (j >= gap && nums[j - gap] > temp){
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
        gap /= 2;
    }
}

int main(){
    int nums[6] = {1,5,6,4,2,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    shellsort(nums,n);
    for (int i = 0;i < n;i++){
        cout << nums[i];
    }
    return 0;
}