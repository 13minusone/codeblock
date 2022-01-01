#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int m,n,x,t,y,z;
void inti()
{
    freopen("keuler1.inp","r",stdin);
    freopen("keuler1.out","w",stdout);
}
int g[int(1e6)];
void nhap()
{
    cin>>t;

    fu(j,1,t,1)
    {
        ll h=2;
        cin>>n>>m;
        fu(i,1,m,1)
        {
            cin>>x>>y>>z;
            g[x]=g[x]+z;
            g[y]=g[y]+z;
        }
        fu(i,1,n,1)
        {
            if(g[i]%2!=0)
            {
                h--;
            }
            g[i]=0;

        }
        if(h==2)
        {
            cout<<"euler"<<endl;

        }
        else
        {
            if(h!=0)
            {
                cout<<"khong"<<endl;
            }
            else
            {
                cout<<"nua euler"<<endl;
            }
        }

    }
}
int main()
{
    inti();
    nhap();
}

