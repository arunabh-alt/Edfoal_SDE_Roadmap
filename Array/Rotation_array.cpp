/*Given an array, rotate the array to the right by k steps, where k is non-negative.
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100] */
#include<iostream>
using namespace std;
int main(){
        int A[100],B[100];
        int k,i;
        int n= sizeof(A)/sizeof(A[n]);
        cout<<"Enter the size of array: ";
        cin>>n;
        cout<<"Enter the array elements in ascending order: \n";
        for(i=0;i<n;i++)
            cin>>A[i];
        cout<<"Enter the target value: ";
        cin>>k;
        while (i<n){
        if (A[i] == k) {
            break;
            i++;
        }}
         for(i=0;i<n;i++){
             B[(i+k)%n]=A[i];
         }

         for(i=0;i<n;i++){
            cout<<""<<B[i];
         }
        return 0;
}
