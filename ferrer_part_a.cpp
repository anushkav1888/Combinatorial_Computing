#include <bits/stdc++.h>
using namespace std;

int main()
{
  string line;
  vector<int> row;
  getline(cin, line);

  for( char c: line){
   if(c != ' '){ 
     int a = c - '0';
     row.push_back(a); 
           }
  }
for(int i = 0; i < row.size(); i++){
  for(int j = 0; j < row[i]; j++){
    cout<<"*";
  }
  cout<<endl;
 }
}
