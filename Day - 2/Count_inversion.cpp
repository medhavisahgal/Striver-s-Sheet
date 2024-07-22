#include <bits/stdc++.h>
int check(long long* arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int  temp[high-low+1];
    int cnt = 0;
    int k=0;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp[k]=arr[left];
            k++;
            left++;
        } else {
            temp[k]=arr[right];
            k++;
            right++;
            cnt += (mid - left + 1); 
        }
    }

    while(left <= mid) {
       temp[k++] = arr[left++];
    }

    while(right <= high) {
        temp[k++] = arr[right++];
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int ms(long long* arr,int low,int high){
    if(low>=high)return 0;
    int mid=(low+high)/2;
    int cnt=ms(arr,low,mid);
    cnt+=ms(arr,mid+1,high);
    cnt+=check(arr,low,mid,high);
    return cnt;
} 
long long getInversions(long long *arr, int n){
    return ms(arr,0,n-1);
}
//Time Complexity: O(nlogn)
//Space Complexity: O(n)