#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
struct dta
{
    ll a,b,c;
};
int m,n,cha[1000000],d[100000];
dta x[100000];
bool cmp(dta x,dta y)
{
    if(x.c>y.c)return false;
    if(x.c<y.c)return !false;
}
void inti()
{
    freopen("mst.inp","r",stdin);
    freopen("mst.out","w",stdout);
}
int findd(int u)
{
    if (cha[u] != u) cha[u] = findd(cha[u]);
    return cha[u];
}
void nhap()
{

    cin>>n>>m;
    fu(i,0,m-1,1)
    {
        cin>>x[i].a>>x[i].b>>x[i].c;

    }
    ll res=0,s=0;
    sort(x,x+m,cmp);
    fu(i,0,m-1,1)
    {
        ll p=findd(x[i].a);
        ll k=findd(x[i].b);
        if(k!=p)
        {
            cha[k]=p;

            s=s+x[i].c;
            d[i]++;
            res++;
        }
        if(res==n-1)
        {
            cout<<s<<endl;
            fu(j,0,i,1)
            {
                if(d[i]>0)
                {
                    cout<<x[i].a<<" "<<x[i].b;
                }
            }
            break;
        }

    }
}
int main()
{
    IOS
    inti();
    nhap();

}

