#include <bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1] */
int firstOc(int arr[], int low, int high, int x, int n)
{

    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return firstOc(arr, (mid + 1), high, x, n);
        else
            return firstOc(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int lastOc(int arr[], int low, int high, int x, int n)
{

    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return lastOc(arr, low, (mid - 1), x, n);
        else
            return lastOc(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main()
{
    int arr[100];
    int n = sizeof(arr) / sizeof(int);
    int x,i;
    cout<<"Enter the array size: \n";
    cin>>n;
    cout<<"Enter array elements: \n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the target value: \n";
    cin>>x;
    int a= firstOc(arr,0, n - 1, x, n);
    int b= lastOc(arr, 0,n - 1, x, n);
    cout<<a<<" "<<b<<endl;

    return 0;
}
