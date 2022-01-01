#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[int(1e6)+1];
    unsigned ll s=0;
    int d[int(1e6)+1],f[int(1e6)+1],res=0;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n>>m;
fu(i,1,n,1)
{
    cin>>x[i];
    s=s+x[i];
    if(s%m==0)
    {
        d[i]=n+3;
        res=i;
    }
    else
    {
        d[i]=res;
    }

}
s=0;
res=n+1;
fd(i,n,1,1)
{
     s=s+x[i];
    if(s%m==0)
    {
        f[i]=n+3;
        res=i;
    }
    else
    {
        f[i]=res;
    }
}
int maxx=0;
fu(i,1,n,1)
{
    if(d[i]==n+3 && i <=n-1)
    {
       if(f[i+1]==n+3)
       {
           maxx=max(maxx,n);
       }
       else
       {
           if(f[i+1]!=n+1)
           {
               maxx=max(maxx,i+n-f[i]+1);
           }
       }
    }
    //cout << maxx << " " << i <<endl;;
}
cout <<maxx;
}
int main()
{
IOS
//inti()
nhap();

}

