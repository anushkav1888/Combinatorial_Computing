#include <bits/stdc++.h>
using namespace std;

void f(vector <int> num, int n, int &counter, int arr[100],vector < vector <int>> store, int min[100][3] ){

for(int i=0;i<n;i++){
      for (int j=0;j<n; j++ )     
       { if(j!=i){
        num.push_back(arr[i]^arr[j]);
       }} 
     
      min[0][0] = num[0];
       
      if(i==0){

      for(int i=0;i<num.size();i++){
      if(num[i]<min[0][0])
      { min[0][0]=num[i];
        }
        min[0][1]=1;
        min[0][2]=i+2;
            }

      if(min[0][0]<arr[0])       
      { arr[0]=min[0][0];
      counter++;
      }   
      
       else{ min[0][1]=1;
        min[0][2]=0;

       }   }         
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
      min[i][1]=i+1;
      min[i][2]=store[0][1];}
      for(int l=0;l<store.size();l++)
         {
            if(min[i][0]>store[l][0]){
            
                min[i][0]=store[l][0];
                min[i][2]=store[l][1];
                     }
                   }
             
    
      if(arr[i]<min[i][0] && arr[i]>=arr[i-1] )
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

     if(store.size()==0)
     { if(arr[i]<arr[i-1])
     { min[i][0]=arr[i];
      min[i][1]=i+1;
      min[i][2]=0;}}

  
      }
      store.clear();
      num.clear();
     

      }
}



int main()


{
int t;
cin>>t;
while(t--){

int n;
cin>>n;
int counter=0;
int arr[100];
for (int i=0;i<n;i++){
cin>>arr[i];}

   int fla = 0;

    for(int l = 0;l<n; l++){
        if(arr[l] > arr[l+1]){
          fla = 1;
        }}

    if(fla == 0){
        cout<<"0"<<endl;
        continue;
    }
    if(fla == 1){   
vector < vector <int>> store;
vector <int> num;
int min[100][3];
int p = 4;
f(num,n,counter,arr,store,min);
bool flag = true;

while(p ){
    for(int l = 0;l<n; l++){
        if(arr[l] > arr[l+1]){
            flag = false;
            p = p -1;
        }
        if(l == n-1){
            p = 0;
        }
        if(flag == false){
            f(num,n,counter,arr,store,min);
            flag = true;
        }
    }
}

  int h=0;
  for(int i=0; i< n ;i++)
{   if(min[i][2]!=0){
     h++;
    ;}
}
cout<<h<<endl;
for(int i=0; i< n ;i++)
{   if(min[i][2]!=0){
    cout<<min[i][1]<<" "<<min[i][2]<<endl
    ;}
}

for(int i=0; i< n ;i++)
// {   cout<<arr[i]<<" ";

}
    }
}
}
