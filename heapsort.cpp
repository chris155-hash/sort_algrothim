// 堆排序：利用堆的性质，将待排序的数组构造成一个大顶堆，堆的顶点就是最大值，和末尾元素交换位置；然后将剩余n-1个元素重新构成堆，重复进行。
//稳定性：不稳定。出堆的时候可能会打乱原本的顺序。
// 时间复杂度： O(log(n))。   空间复杂度： O(1),将数组维护堆的性质，而不是调用额外的堆结构。
//适用情况： 处理大规模数据，优点是不需要额外的空间。

#include<bits/stdc++.h>
using namespace std;

// // 利用priority_queue来辅助的，空间复杂度O(n).
// void minheapsort(int* nums,int n){
//     priority_queue<int,vector<int>,greater<>> minheap;
//     for (int i = 0;i < n;i++) minheap.push(nums[i]);
//     for (int i = 0;i < n;i++) {
//         nums[i] = minheap.top();
//         minheap.pop();
//     }
// }

void adjustheap(int nums[], int i,int n){
    int temp = nums[i];
    for (int k = 2 * i + 1;k < n;k = k * 2 + 1){    //k = k * 2 + 1即表示继续向下查找左子节点
        if (k + 1 < n && nums[k] < nums[k + 1]) k++;//从右至左
        if (nums[k] > temp) {      //子节点大于父节点，把子结点的值复制给父节点
            nums[i] = nums[k];    //从下至上
            i = k;
        }
        else {
            break;
        }
    }
    nums[i] = temp;
}
void  heapsort(int* nums, int n){
    for (int i = n / 2 - 1;i >= 0;i--) adjustheap(nums,i,n);//不断调整，第一个非叶子结点length/2-1从下至上从右至左调整结构
    for (int j = n - 1;j > 0;j--){     //总共调整n-1次
        swap(nums[0],nums[j]);
        adjustheap(nums,0,j);//重新调整对结构
    }
}

int main(){
    int nums[6] = {1,5,4,3,2,6};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapsort(nums,n);
    for (int i = 0;i < 6;i++) cout << nums[i] ;
    return 0;
}