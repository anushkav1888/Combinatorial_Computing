#include <bits/stdc++.h>
using namespace std;
int counter = 0;
int check(int n, vector<int> a){
    int b = 0;
    int z;
    int y = a[n];
    if(n > 0){
    for(int j = 0; j < n; j++){
        if(a[j] == y ){
            b = -1;
        }
    } }
    if(b == -1) 
    { z = -1;}
    if(b == 0){
        z = 1;
    }
    return z;

}
void printsoln(vector <int> a, int n){
   if(counter == 0){
    for(int i = 0; i < n; i++){
    cout<<i+1<<" "<<a[i]<<endl;
   }
   counter = 1;
}
}
void assign(vector <int> a,int k, int l, int n, int arr[50][50] ){
    if (n == l){
        printsoln(a, l);
    }
   
    for(int i = 0; i < k; i++){
        if(n == l){
            break;
        }
        int work = arr[n][i];
        a.push_back(work);
        if(n == 0){
            assign(a, k, l, n+1, arr);
        }
        if(n >= 1){

        if(check(n, a) > 0){
            assign(a, k, l, n+1, arr);
        }
        else if(check(n, a) < 0){
             a.pop_back();
            int count=0;
            for(int v = 0; v < n; v++){
                int p = arr[v][k];
                if(a[v] == p){
                 count++;
                }
            }
            if (count == n){
                cout<<"No solution"<<"-1";
                break;
            }
        }

    }
    
    
    }
    }

int main(){
    int  n, m, k;
    cin>>n>>m;
    if(n>m){
        cout<<"No solution"<<" "<<-1<<endl;
    }
    else{
    vector<vector<int>> matrix;
    int arr[50][50]={0};
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
       k = row.size();
        for( int z = 0; z < k; z++){
            arr[i-1][z] = row[z];
        }
       }
       
    }
    vector <int> a;
     assign(a, k, n, 0, arr);
}
 }
