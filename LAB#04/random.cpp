#include <iostream>
using namespace std;


void merge(int *arr, int start, int mid, int end){
    int l1=mid-start+1;
    int l2=end-mid;

    int a[l1];
    int b[l2];

    for(int i=0; i<l1; i++){
        a[i]=arr[start+i];
    }

    for(int i=0; i<l2; i++){
        b[i]=arr[mid+1+i];
    }
 
    int i=0;
    int j=0;
    int k=start;

    while(i<l1 && j<l2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++,k++;
        }
        else{
            arr[k]=b[j];
            j++,k++;
        }
    }

    while(i<l1){
        arr[k]=a[i];
            i++,k++;
    }

    while(j<l2){
        arr[k]=b[j];
            j++,k++;
    }


}

void merge_sort(int*arr, int start, int end){

    if(start<end){
        int mid=start+(end-start)/2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        
        merge(arr, start, mid, end);
    }

}

void print(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[10]={9,7,5,11,12,2,14,4,3,10};
    print(A, 10);
    merge_sort(A, 0, 9);
    print(A, 10);

    return 0;
}