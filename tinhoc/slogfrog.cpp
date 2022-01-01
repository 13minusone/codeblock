#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[301][301],d[int(1e5)+1],k;
    ll s=0;
void inti()
{
   freopen("slogfrog.inp","r",stdin);
   freopen("slogfrog.out","w",stdout);
}
void nhap()
{

cin>>n>>m>>k;
fu(i,1,n,1)
{
    fu(j,1,m,1)
    {
        cin>>x[i][j];
        d[x[i][j]]++;
    }
}
sort(d+1,d+int(1e5)+1);
fd(i,100000,100000-k+1,1)
{
    s=s+d[i];
    //cout<<d[i]<<endl;
}
cout<<s;
}
int main()
{
IOS
inti();
nhap();

}

