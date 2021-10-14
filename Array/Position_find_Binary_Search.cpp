/* Simple Binary Search in an given array, set the index position fisrt and last as 0 & 3 respectively since it is a predefined size array. This program will work only in sorted 
array.*/
#include<iostream>
using namespace std;
int main()
{
    int i, arr[10], num, first, last, middle;
    cout<<"Enter 4 Elements (in ascending order): ";
    for(i=0; i<4; i++)
        cin>>arr[i];
    cout<<"\nEnter Element to be Search: ";
    cin>>num;
    first = 0;
    last = 3;
    middle = (first+last)/2;
    while(first <= last)        // While loop for searching 
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"\nThe number, "<<num<<" found at Position "<<middle+1;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"1";
    cout<<endl;
    return 0;
}
