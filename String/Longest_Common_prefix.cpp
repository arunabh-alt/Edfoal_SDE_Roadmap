/*1. Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/
#include<iostream>
#include<algorithm>

using namespace std;

string longestCommonPrefix(string st[], int n)
{
    //If string 0, then return empty string
    if (n == 0)
        return "";
    if (n == 1)
        return st[0];

    //Using library sort the array
    sort(st, st + n);
    //Try to find the minimum length
    int a = min(st[0].size(),st[n - 1].size());
    //Now the common prefix in first and last string is the longest common prefix
    string first = st[0], last = st[n - 1];
    int i = 0;
    while (i < a && first[i] == last[i])
        i++;

    string finalresult = first.substr(0, i);
    return finalresult;
}

int main()
{
    string st[] = {"flower","flow","flight"};
    int n = sizeof(st) / sizeof(st[0]);
    cout << " "<< longestCommonPrefix(st, n);
    return 0;
}
