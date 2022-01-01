#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[1000][1000],s[1000][1000],f[501][501];
//void inti()
//{
//   freopen("chiadat.inp","r",stdin);
//   freopen("chiadat.out","w",stdout);
//}
ll solve(int i,int j,int l,int r)
{
    ll s=0;
    fu(k,i,l,1)
    {
        fu(o,j,r,1 )
        {
           s=s+x[k][o];
        }
    }
    return s;

}
void nhap()
{

cin>>n;
ll p=0;
fu(i,1,n,1)
{
    ll o=0;
    fu(j,1,n,1)
    {
        cin>>x[i][j];
        p=p+x[i][j];
o=o+x[i][j];
        s[i][j]=p;
        f[i][j]=f[i-1][j]+o;
    }
}
int minn=100000;
fu(i,1,n-1,1)
{
    fu(j,1,n-1,1)
    {
        int u,v;
      int k=f[i][j];
      int g=f[n][j]-f[i][j];
      int h=s[i][n]-k;
      u=max(max(max(k,g),h),s[n][n]-k-g-h);
       v=min(min(min(k,g),h),s[n][n]-k-g-h);
       minn=min(minn,u-v);

//       cout<<i<<" "<<j<<" "<<k<<" "<<g<<" "<<h<<" "<<minn<<endl;
//cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<minn<<endl;

    }

}
cout<<minn<<endl;
}
int main()
{
IOS
//inti();
nhap();

}

