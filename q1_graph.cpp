#include <bits/stdc++.h>
using namespace std;
int main()
{
int n, m;
cin>>n>>m;
int A[n][n];
int B[n][n-1];
for(int i = 0; i < n; i++){
    for(int j = 0; j < n-1; j++){
        cin>>B[i][j];
    }}

for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        if(i == j){
            A[i][j] = 0;
        }
        if(j < i){
        A[i][j] = B[i][j];}
        if(j > i){
            A[i][j] = B[i][j-1];
        }}}
int pos = 0;
int max = A[1][0];
for(int j=0; j < n ;j++){
    if(j!= 1){
    if(A[1][j] > max){
        max = A[1][j];
        pos = j;
    }}
}
if( A[0][1] + A[pos][1]*(m-1) > A[1][pos]*(m)){
    cout<<1;
}
else{
    cout<<2<<endl;
}
}