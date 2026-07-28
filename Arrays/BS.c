#include <stdio.h>

// Binary Search 

int BinarySearch(int arr[], int n, int target){
    int s = 0;
    int e = n - 1;

    while(s <= e){    
        int mid = s + (e - s) / 2;
        if(target == arr[mid]){
            return mid;
        }else if(target > arr[mid]){
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = BinarySearch(arr,n,7);

    if(result == -1){
        printf("The element is not found.");
    }else{
        printf("The element is found at index: %d",result);
    }
    return 0;
}