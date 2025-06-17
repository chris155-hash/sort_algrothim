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