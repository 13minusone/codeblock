#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x[1000001];
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;
fu(i,1,n,1)cin>>x[i];

m=1;

int maxx=-1;
fu(i,2,n,1)
{
    if(x[i-1]<x[i])
    {
        maxx=maxx+1;

    }
    else
    {
         fd()
        }
}
cout<<maxx;
}
int main()
{
nhap();
}

