#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&a,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    vector<int>a1;
    vector<int>b1;
    for(int i=0;i<n1;i++){
        a1.push_back(a[low+i]);
    }
    for(int i=0;i<n2;i++){
        b1.push_back(a[mid+1+i]);
    }
    int i=0;        
    int j=0;
    int k=low;
    while(i<n1 && j<n2){
        if(a1[i]<=b1[j]){
            a[k]=a1[i];
            i++;
        }
        else{
            a[k]=b1[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=b1[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& a, int low, int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
}
int main(){
    vector<int>a;
    int n=5;
    for(int i=0;i<n;i++){
        int x=rand()%100;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
