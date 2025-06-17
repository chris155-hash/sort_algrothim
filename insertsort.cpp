// 插入排序： 将数组分为左：排序区间 和右： 未排序区间 两个区间。每次从右边取出一个元素，放到左边适当的位置。
// 稳定性：稳定。(while (j > 0 && nums[j - 1] >= temp,写成>=就不稳定了！！！)
// 时间复杂度：最好情况O(N),最差的情况O(N^2)。     适用情况： 小规模数据，或基本有序的数据。
#include<bits/stdc++.h>
using namespace std;

void insertsort(int * nums,int n){
    for (int i = 1; i < n;i++){
        int temp = nums[i];  //一会腾位置会被覆盖，提前存一下
        int j = i;
        while (j > 0 && nums[j - 1] > temp){     //nums[j - 1]即排序区间最后一位，大于即将新加入的元素，右移腾出位置。
            nums[j] = nums[j - 1];
            j --;
        }
        nums[j] = temp;
    }
}

int main(){
    int nums[6] = {1,4,3,5,6,2};
    int n = sizeof(nums) / sizeof(nums[0]);
    insertsort(nums,n);
    for (int i = 0;i < n;i++){
        cout << nums[i];
    }
    return 0;
}