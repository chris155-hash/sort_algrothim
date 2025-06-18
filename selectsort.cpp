//选择排序算法：将数组分为左：排序区间，右：未排序区间。每次从右边取一个最小的元素放在左边区间末尾
// 稳定性：不稳定。
// 时间复杂度：始终为O(N^2)。  适用情况： 1.数据量小，因为和冒泡一样。时间复杂度过高。2.对空间复杂度要求较高的时候。O(1)的空间复杂度。原地操作。
#include<bits/stdc++.h>
using namespace std;

void selectsort(int * nums,int n){     //这里和bubblesort写的不一样，传一个指向int类型的指针变量。传进去nums的首元素地址，和元素数量。
    for (int i = 0;i < n;i++){
        int min_i = i;
        for (int j = i + 1;j < n;j++){
            if (nums[j] < nums[min_i]) min_i = j;
        }
        swap(nums[i],nums[min_i]);    //ranges是C++20才有的，可以使用std::swap
    }
}

int main(){
    int nums[6] = {1,3,4,2,5,6};
    int n = sizeof(nums) / sizeof(nums[0]);
    selectsort(nums,n);    //这里看起来传递的不是指针，实际上nums会自动转换为int*指针类型，即&nums[0]。。。select(&nums[0],n);也是ok的
    for (int i = 0;i < n;i++){
        cout << nums[i];
    }
    return 0;
}