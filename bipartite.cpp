#include <bits/stdc++.h>
using namespace std;
bool check(int n, vector<int> a){
    int b = 0;
    int z;
    for(int j = 0; j < n; j++){
        if(a[j] == a[n] ){
            b = -1;
        }
    } 
    if(b == -1) 
    { z = -1;}
    if(b == 0){
        z = 1;
    }
    return z;

}
void printsoln(vector <int> a, int n){
   for(int i = 0; i < n; i++){
    cout<<i+1<<" "<<a[i]<<endl;
   }
}
void assign(vector <int> a,int k, int l, int n, vector<vector<int>> matrix){
    if (n >= l){
        printsoln(a, l);
    }
    else{
    for(int i = 0; i < k; i++){
        a[n] = matrix[n][i];
        if(check(n, a)){
            assign(a, k, l, n+1, matrix);
        }
        else if(check(n, a) < 0){
            a.pop_back();
            int count=0;
            for(int v = 0; v < n; v++){
                if(a[v] == matrix[v][k]){
                 count++;
                }
            }
            if (count == n-1){
                cout<<"No solution"<<"-1";
                break;
            }
        }

    }
    }
}
int main(){
    int  n, m;
    cin>>n>>m;
    if(n>m){
        cout<<"No solution"<<" "<<-1<<endl;
    }
    else{
    vector<vector<int>> matrix;
    for (int i = 0; i < n+1; i++){
       string line;
       vector<int> row;
       getline(cin, line);
       if(i >= 1){
       for( char c: line){
       if(c != ' '){ 
        int a = c - '0';
       row.push_back(a); 
       }
       }
       matrix.push_back(row);
       }
    }
    int k = matrix[0].size();
    vector <int> a;
    assign(a, k, n, 0, matrix);
}
}