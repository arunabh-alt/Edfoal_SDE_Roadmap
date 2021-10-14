/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:
Input: strs = [""]
Output: [[""]]
Example 3:
Input: strs = ["a"]
Output: [["a"]] */
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef unordered_map<string, vector<string>> map;

void printAnagrams(string arr[], int size)
{
    unordered_map<string, vector<string>> map;
    for(int i = 0; i < size; i++)
    {

        string w = arr[i];
        char letters[w.size() + 1];
        strcpy(letters, w.c_str());
        sort(letters, letters + w.size() + 1);
        string newWord = "";
        for(int i = 0; i < w.size() + 1; i++)
        {
            newWord += letters[i];
        }
        if (map.find(newWord) != map.end())
        {
            map[newWord].push_back(w);
        }
        else
        {
            vector<string> words;
            words.push_back(w);
            map[newWord] = words;
        }
    }
    unordered_map<string,vector<string>>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
    {
        vector<string> values = map[it->first];
        if (values.size() >= 1)
        {
            cout << "[";
            for(int i = 0; i < values.size() - 1; i++)
            {
                cout << values[i] << ", ";
            }
            cout << values[values.size() - 1];
            cout << "]";
        }
    }
}

int main()
{
    string arr[] = { "eat","tea","tan","ate","nat","bat"};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAnagrams(arr, size);

    return 0;
}
