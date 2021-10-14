/*Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.
 
Example 1:
Input: nums = [1,2,0]
Output: 3
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Example 3:
Input: nums = [7,8,9,11,12]
Output: 1 */

#include<iostream>
using namespace std;
int firstMissingPositive(int A[], int n1) {
    int i = 0;
   while (i < n1) {
     if (A[i] > 0 && A[i] <= n1 && A[i] != i+1 && A[i] != A[A[i]-1]) {
       int temp = A[A[i]-1];
       A[A[i]-1] = A[i];
       A[i] = temp;
     } else {
       ++i;
     }
   }
   i = 0;
   while (i < n1 && A[i] == i+1) ++i;
   return i+1;
}


int main(){
    int A[100],n1,i,index;
    int smallest;
    cout<<"Enter the array size: \n";
    cin>>n1;
    cout<<"Enter the array elements: \n";
    for(i=0;i<n1;i++){
        cin>>A[i];
    }
    smallest=firstMissingPositive(A,n1);

    cout<<smallest;
    return 0;

}
