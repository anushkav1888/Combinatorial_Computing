#include <bits/stdc++.h>
using namespace std;
int main() 

{
int t;
cin>>t;

int counter=0;

while(t--){

int n;
cin>>n;

int arr[n];
for (int i=0;i<n;i++){
cin>>arr[i];}

vector < vector <int>> store;
vector <int> num;
vector<vector<int>> min;



for(int i=0;i<n;i++){
      for (int j=0;j<n; j++ )     
       { if(j!=i){
        num.push_back(arr[i]^arr[j]);
       }}
     
      
      min[0][0]=num[0];  
       
      if(i==0){

      for(int i=0;i<num.size();i++){
      if(num[i]<min[0][0])
      { min[0][0]=num[i];
       min[0][1]=1;
       min[0][2]=i+2;}
        
            }

      if(min[0][0]<arr[0])       
      { arr[0]=min[0][0];
      counter++;
      }   
      
                   
      if(i!=0){
      for(int k=0; k<n-1; k++)
       {  
         if( num[k]>=arr[i-1])
         {  if(k<i)
           { store.push_back({num[k],k+1});}
           if(k>i)
           {
            store.push_back({num[k],k+2});
           }
         }
       }
       
      if(store.size()!=0){
      min[i][0]=store[0][0];
      min[i][2]=i+1;
      min[i][2]=store[0][1];}
      for(int l=0;l<store.size();l++)
         {
            if(min[i][0]>store[l][0]){
            
                min[i][0]=store[l][0];
                min[i][2]=store[l][1];
                     }
                   }
       if(store.size()==0)
       { arr[i]=0;
       cout<<"fail case";}            
    
      if(arr[i]<min[i][0] && arr[i]>arr[i-1] )
      {  
         min[i][0]=arr[i];
         min[i][1]=i+1;
         min[i][2]=0;
      }

      else {
        if(store.size()!=0){
      arr[i]=min[i][0];
      counter++;
      }}

    //   cout<<"val "<<arr[i]<<endl;
      }
      store.clear();
      num.clear();
      

      }


}

cout<<endl<<counter<<endl;
for(int i=0; i<min.size();i++)
{   if(min[i][2]!=0){
    cout<<min[i][1]<<" "<<min[i][2]<<endl;}
}

}
}
