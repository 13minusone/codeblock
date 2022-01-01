#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int s=0;
    int m,n,x,a[1001][1001],d[1001][1001]={0};
    void solve(int i,int j)
    {
        if(a[i][j]==1&&d[i][j]==0&&i>0&&j>0&&i<=n&&j<=m)
        {
            s--;
            d[i][j]=1;
            solve(i-1,j);
            solve(i+1,j);
            solve(i,j+1);
            solve(i,j-1);
        }
    }
void inti()
{
   freopen("starwars.inp","r",stdin);
   freopen("starwars.out","w",stdout);
}
void nhap()
{
int l,r;
scanf("%d%d%d",&n,&m,&x);
fu(i,1,n,1)
{
    fu(j,1,m,1)
    {
        scanf("%d",&a[i][j]);
       if(a[i][j]==1)
       {
           s++;
       }
    }
}
fu(i,1,x,1)
{
    scanf("%d%d",&l,&r);
    solve(l,r);
    printf("%d\n",s);

}

}
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
  //  cout.tie(0);
    inti();
nhap();
}

