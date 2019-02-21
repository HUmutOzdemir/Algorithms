#include <iostream>
#include "heap.cpp"
#include <queue>
#include <list>
void merge( int a[], int tmpArray[],
            int leftPos, int rightPos, int rightEnd )
{

    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( a[ leftPos ] <= a[ rightPos ] )
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
    while( leftPos <= leftEnd )
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
    while( rightPos <= rightEnd )
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}

void mergeS(int array[],int temp[] , int left , int right ){
    if(left<right){
        int center = (left + right)/2;
        mergeS(array,temp,left,center);
        mergeS(array,temp,center+1,right);
        merge(array,temp,left,center+1,right);
    }
}
void mergesort(int array[],int size){
    int tempArr[size];
    mergeS(array,tempArr,0,size-1);
}
void quicksort(int array[],int left,int right){
    if(left >= right) return;
    int i = left;
    int j = right-1;
    int pivot = (left+right)/2;
    std::swap(array[pivot],array[right]);
    while(true){
        while(array[i]<=array[right]&&i<=j){i++;}
        while(array[j]>array[right]&&i<=j){j--;}
        if(j>i){
            std::swap(array[i],array[j]);
        }else{
            break;
        }
    }
    std::swap(array[i],array[right]);
    quicksort(array,left,i-1);
    quicksort(array,i+1,right);
}
void quicksort(int array[],int n){
    quicksort(array,0, n-1);
}
int main() {
    int arr [] = {3,4,1,12,31,44,42,17,23,14,33};
    quicksort(arr,11);
    for(auto x : arr){
        cout << x << " ";
    }
}