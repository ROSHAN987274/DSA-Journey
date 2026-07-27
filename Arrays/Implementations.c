#include<stdio.h>

// INSERTION

// Insertion at the beginning 

int AtBeginning(int arr[],int n, int value){

    for(int i=n ; i> 0 ; i--){     
    arr[i] = arr[i-1];
    }
    arr[0] = value;
    n++;

return n;
}

// Insert at the end 

int AtEnd(int arr[],int n,int value){

    arr[n]=value;
    n++;

    return n;
}

// Insert at Any position

int InsertAtAnyPosition(int arr[], int n, int value,int pos){

    for(int i=n; i>= pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1]=value;
    n++;

    return n;
}

// Deletion At End

int DeleteAtEnd(int arr[],int n){
    n--;

    return n;
}

// Deletion At Beginning/ middle 

int DeletionAtBeginning(int arr[],int n,int pos){
   for(int i = pos-1; i<n-1;i++) {
    arr[i]=arr[i+1];
   }
   n--;
   return n;
}

int LinearSearch(int arr[], int n, int target){

    for(int i=0; i<n;i++){
        if(arr[i] == target){
          return i;
        }
    }
return -1;
}

// Main Function

int main(){
    int arr[100]={2,3,4,5};
    int n=4;
    n= AtBeginning(arr,n,1);

    n = AtEnd(arr,n,6);

    n= InsertAtAnyPosition(arr,n,7,3);

    n = DeleteAtEnd(arr,n);

    n = DeletionAtBeginning(arr,n,3);

    for(int i = 0 ; i<n ; i++){
        printf("%d ",arr[i]);
    }
printf("\n");
    int result = LinearSearch(arr,n,4);
    if (result == -1){
       printf("Element not found");
    }else{
        printf("%d",result);
    }
}
