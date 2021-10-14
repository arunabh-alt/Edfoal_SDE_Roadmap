#include<iostream>
using namespace std;

int SearchinArray(int arr[], int key, int left, int right){
        if (left>right){
            return -1;
        }
        int mid = (left+right)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[left]<= arr[mid]){
            if(key >= arr[left]&& key<=arr[mid]){
                return SearchinArray(arr,key,left,mid-1);
            }
            return SearchinArray(arr,key,mid+1,right);
        }
        if(key>=arr[mid]&& key<= arr[right]){
            return SearchinArray(arr,key,mid+1,right);
        }
        return SearchinArray(arr,key,left,mid-1);
}
int main(){
        int arr[100];
        int n,i;
        int key;
        cout<<"Enter the array size: \n";
        cin>>n;
        cout<<"Enter the rotated shorted array: \n";
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Enter the target: \n";
        cin>>key;
        int index= SearchinArray(arr,key,0,n-1);
        if (index==-1){
            cout<<"-1";
        }
        else{
            cout<<index;
        }
        return 0;
}
