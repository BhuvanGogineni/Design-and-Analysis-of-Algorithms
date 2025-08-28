#include<iostream>
using namespace std;

int partition(int arr[],int left,int right){
    int pivot=arr[right];
    int i=left-1;

    for(int j=left; j<right; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i+1;
}

void quickSort(int arr[],int left,int right){
    if(left<right){
        int pi=partition(arr,left,right);
        quickSort(arr,left,pi-1);
        quickSort(arr,pi+1,right);
    }
}

int main() {
    int n;
    cout<<"enter Size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
