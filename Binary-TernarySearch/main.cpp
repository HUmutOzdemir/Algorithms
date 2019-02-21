#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;
        if (arr[mid1] == x)
            return mid1;
        if (arr[mid2] == x)
            return mid2;
        if (arr[mid1] > x)
            return ternarySearch(arr, l, mid1-1, x);
        if (arr[mid2] < x)
            return ternarySearch(arr, mid2+1, r, x);
        return ternarySearch(arr, mid1+1, mid2-1, x);
    }
    return -1;
}
int main (){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,13};
    cout << binarySearch(arr,0,12,10) << " " << ternarySearch(arr,0,12,4) << endl;
}
