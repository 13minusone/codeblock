#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int m,n,d[1001][1001],s=0,h=0,p=0,k=0,maxx=0;;
char x[1001][1001];
void inti()
{
    freopen("farm.inp","r",stdin);
    freopen("farm.out","w",stdout);
}
void check(int i,int j)
{

    if(d[i][j]==0&&i>0&&j<=m&&i<=n&&j>0)
    {
        if(x[i][j]=='.'||x[i][j]=='c'||x[i][j]=='f')
        {
            d[i][j]=1;
            if(x[i][j]=='c')
            {
                s++;
            }
            if(x[i][j]=='f')
            {
               h++;
            }
            check(i+1,j);
            check(i-1,j);
            check(i,j-1);
            check(i,j+1);
        }
    }

}
void nhap()
{

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
            h=0;
            if(x[i][j]=='.'||x[i][j]=='c'||x[i][j]=='f')
            {
                check(i,j);

                if(s>h)
                {
                    k=k+s;
                }
                if(s<=h)
                {
                    p=p+h;
                }
//                if(s!=0)
//                {cout<<i<<" "<<j<<" "<<h<<" "<<s<<" "<<k<<" "<<p<<endl;}
            }

        }
    }
    cout<<p<<" "<<k;
}
int main()
{
    inti();
    nhap();
}


