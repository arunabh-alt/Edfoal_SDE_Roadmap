/* Given a rope of length n, you need to find the maximum number of pieces you can
make such that the length of every piece is in set {a, b, c} for the given three values a, b, c

Example
Input: n = 5, a = 2, b = 5, c = 1
Output: 5
Explanation: we make 5 pieces of of length 1 each

Input: n=23, a = 12, b = 9, c = 11
Output: 2
Explanation: we make 2 pieces of length 11 and 12*/
#include <iostream>
using namespace std;
int max(int a, int b, int c)
    {
        if (a > b){
            if (a > c){
                return a;
            }
            else{
                return c;
            }
        }

    else{
        if (b > c){
            return b;
        }
        else{
            return c;
        }
    }
}

int maxpiece(int n, int a, int b, int c)
    {
        int r;
        if (n == 0){
            return 0;
        }
        if (n<0){
            return -1;
        }
        r = max(maxpiece(n-a, a, b, c), maxpiece(n-b, a, b, c), maxpiece(n-c, a, b, c));

        if (r == -1)
            return -1;

        return r + 1;
}

int main()
    {
        int n;
        cout << "Enter rope length: \n";
        cin >> n;
        int a,b,c;
        cout << "Enter the only three parameters in which rope can be cut: \n";
        cout<<"a=  ";
        cin >>a;
        cout<<"b=  ";
        cin >> b;
        cout<<"c=  ";
        cin >>c;
        cout << endl
             <<"ans = "<< maxpiece(n,a,b,c);
}
