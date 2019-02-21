#include <iostream>
#include <math.h>

using namespace std;
int log_2(int i){
    double result = log(i)/log(2);
    result = ceil(result);
    return result;
}
void constructTree(int position[],int arr[],int segmentTree[],int i,int j,int pos){
    if(i==j){
        segmentTree[pos]=arr[i];
        position[i]=pos;
        return;
    }
    int mid = (i+j)/2;
    constructTree(position,arr,segmentTree,i,mid,2*pos+1);
    constructTree(position,arr,segmentTree,mid+1,j,2*pos+2);
    segmentTree[pos] = segmentTree[2*pos+1]^segmentTree[2*pos+2];
}
int findSoulution(int segmentTree[],int qLow,int qHigh,int low,int high,int pos){
    if(qLow<=low&&qHigh>=high)
        return segmentTree[pos];
    if(qLow>high||qHigh<low)
        return 0;
    int mid =(low+high)/2;
    return findSoulution(segmentTree,qLow,qHigh,low,mid,2*pos+1)+findSoulution(segmentTree,qLow,qHigh,mid+1,high,2*pos+2);
}
void recalculate(int segmentTree[],int pos,int newValue){
    segmentTree[pos]=newValue;
    while(pos!=0){
        int parent = (pos-1)/2;
        segmentTree[parent]=segmentTree[2*parent+1]+segmentTree[2*parent+2];
        pos =parent;
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    int arr[n];
    int position[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        position[i]=-1;
    }
    int k = (int)pow(2,log_2(n)+1)-1;
    int segmentTree[k];
    constructTree(position,arr,segmentTree,0,n-1,0);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            cout << findSoulution(segmentTree,b-1,c-1,0,n-1,0)<<endl;
        }else{
            recalculate(segmentTree,position[b-1],c);
        }
    }
    return 0;
}