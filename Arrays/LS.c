// Linear search 

#include<stdio.h>

int LinearSearch(int arr[],int n,int target){
    for(int i=0; i<n;i++){
       if(arr[i]==target){
        return i;
       }
    }

    return -1;
}

int main(){

    int arr[] = {1,2,3,5,6,7,10,23,43};
    int target = 23;

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = LinearSearch(arr,n,target);

    if(result == -1){
        printf("Element not found.");
    }else{
        printf("Element found at index %d ",result);
    }
}