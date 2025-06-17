//冒泡排序算法： 通过比较和交换相邻元素，逐渐将最大元素慢慢向最右边移动。
//稳定:不会改变相等元素的相对顺序。
//时间复杂度：最好情况O(N),最差情况O(N^2)。一般用于1.数组较小  2.数组基本有序的情况。
#include<bits/stdc++.h>
using namespace std;

void bubblesort(int nums[],int n){
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n - i - 1;j++){
            if (nums[j] > nums[j + 1]){
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
int main(){
    int nums[6] = {1,2,5,4,3,6};
    int n = sizeof(nums) / sizeof(nums[0]);
    bubblesort(nums,n);
    for (int i = 0;i < n;i++){
        cout << nums[i];
    }
}