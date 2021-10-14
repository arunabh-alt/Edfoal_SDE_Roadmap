/*Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]*/
#include<iostream>
using namespace std;
int main(){
        int n,m;
        cout<<"Enter row and coloumn: \n";
        cin>>n>>m;
        int a[n][m];
        int i,j,col,row;
        cout<<"Enter matrix elements: \n";
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int row_start=0,row_end=n-1;
        int coloumn_start=0,coloumn_end=m-1;
        while(row_start<= row_end && coloumn_start<=coloumn_end){
            for(col = coloumn_start;col<=coloumn_end;col++){
                cout<<a[row_start][col]<<" ";

            }
            row_start++;

            for(row = row_start;row<=row_end;row++){
                cout<<a[row][coloumn_end]<<" ";

            }
             coloumn_end--;

            for(col = coloumn_end;col>=coloumn_start;col--){
                cout<<a[row_end][col]<<" ";

            }
             row_end--;

            for(row = row_end;row>=row_start;row--){
                cout<<a[row][coloumn_start]<<" ";

            }
            coloumn_start++;

        }

       return 0;
}
