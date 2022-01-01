#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,x[101][101],d[101][101],s=0,h;
void inti()
{
   freopen("mien.inp","r",stdin);
   freopen("mien.out","w",stdout);
}
void check(int i,int j)
{
    if(x[i][j]==h&&d[i][j]==0&&i>0&&j<=m&&i<=n&&j>0)
    {
        d[i][j]=1;
        s++;
        check(i+1,j);
        check(i-1,j);
        check(i,j+1);
        check(i,j-1);
    }
}
void nhap()
{
int d=0,maxx=0,le,ri;
cin>>n>>m;
fu(i,1,n,1)
{
    fu(j,1,m,1)
    {
        cin>>x[i][j];
    }
}
fu(i,1,n,1)
{
    fu(j,1,m,1)
    {
        s=0;
       h=x[i][j];
            check(i,j);

        if(s>0)
        {
            d++;
            if(maxx<s)
            {
                maxx=s;
                le = i;
                ri=j;
            }
        }

    }
}
cout<<d<<endl;
cout<<maxx<<endl;
cout<<"a["<<le<<","<<ri<<"]"<<endl;
}
int main()
{
    inti();
nhap();
}

