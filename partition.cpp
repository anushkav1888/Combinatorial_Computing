#include <bits/stdc++.h>
using namespace std;
int front;
int j=0;
int counter=0;
int N;
int k;
int b;
vector <int> S;

void printSubset( vector<int> sub, vector<int> S) {
  vector <vector<int>> list;
  list[0][0] = front;
  while ( S.size()>-1){
  for( int i =0; i < sub.size(); i++){
  list[j][i+1]=sub[i];
  }
  for( int i =0; i < sub.size(); i++){
   S.erase(S.begin());

  }
   b=S.size()-sub.size();
     j++;
  comp(S, b);
  if(S.size()==0)
  { counter++;}
  if(counter==k)
  {
    cout<<"yes";
  }
}
  
 
}




void backtrack(const vector<int>& nums, vector<int>& subset, int start, int size) {
   
    if (subset.size() == size) {
      
        printSubset(subset, nums);
        return;
    }

 
    for (int i = start; i < nums.size(); i++) {
    
        subset.push_back(nums[i]);

        
        backtrack(nums, subset, i + 1, size);

        subset.pop_back();
    }
}

void printSubsetsOfSize( vector<int>& S, int size) {
    vector<int> subset;
    backtrack(S, subset, 0, size);
}
void comp(vector<int> S, int N )
{
    front = S[0];
    S.erase(S.begin());
    for(k = 0; k < N; k++){
    printSubsetsOfSize(S,k);
    }

}



int main()
{
cin>>N>>k;
for(int i = 1; i < N+1; i++)
{
    S.push_back(i);
}
comp(S, N);
}