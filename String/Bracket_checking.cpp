/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([)]"
Output: false*/
#include <bits/stdc++.h>
using namespace std;
bool bracketckecking(string m)
{
    int i,l;
    stack<char> s;
    char x;
    l = m.length();
    for( i = 0; i <l; i++)
    {
        if (m[i] == '(' || m[i] == '['|| m[i] == '{')
        {
            s.push(m[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (m[i]) {case ')':

            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
            case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
            case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    string m = "(]";
    if(bracketckecking(m))
        cout << "True";
    else
        cout << "False";
    return 0;
