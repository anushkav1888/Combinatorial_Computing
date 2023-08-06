#include <bits/stdc++.h>
using namespace std;
static int b;
int a=0;
int P(int N, int k)
{   
    if(N-k==1)
    { a=1;}
     else if(N==k)
    { a=1;}
     else if(N<k)
    { a=0;}
     else if(k==1)
    { a=1;} 
     else { a=P(N-k,k)+P(N-1,k-1);}
    return a;


}

int R(int N, int k)
{
return P(N+k,k);
}
int Q(int N, int k)
{ 

    if(k-1==0)
    { b=1;}
    else if(N<=k)
    {b=P(2*N,N);}
    else if(N==0 && k>0)
    {b=1;}
     
   
 else {b = Q(N-k, k) +Q(N,k-1);}
 return b;
}
int main()
{
    int N,k;
    cin>>N>>k;
{
    cout<<R(N,k)<<" ";
    cout<<Q(N,k);

}
}
