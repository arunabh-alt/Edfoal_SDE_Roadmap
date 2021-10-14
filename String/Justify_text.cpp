/*Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified and no extra space is inserted between words.
Note:A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]*/
#include <bits/stdc++.h>
#include<bits/algorithmfwd.h>
using namespace std;
int print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
int print_vector(vector<vector<auto>> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
class Solution {
   public:
   vector<string> fullJustify(vector<string> &a, int b) {
      vector <string> result;
      int i, j;
      for(i = 0; i < a.size(); i = j){
         int width = 0;
         for(j = i; j < a.size() && width + a[j].size() + j - i <= b; j++){
            width += a[j].size();
         }
         int space = 1;
         int extra = 0;
         if(j - i != 1 && j != a.size()){
            space = (b - width) / (j - i - 1);
            extra = (b - width) % (j - i - 1);
         }
         string line(a[i]);
         for(int k = i + 1; k < j; k++){
            line += string(space, ' ');
            if(extra-- > 0){
               line += " ";
            }
            line += a[k];
         }
         int x = line.size();
         line += string(b - x, ' ');
         result.push_back(line);
      }
      return result;
   }
};
main(){
   vector<string> v = {"This", "is", "an", "example", "of", "text", "justification."};
   Solution ob;
   print_vector(ob.fullJustify(v, 16));
}
