#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int n,c,x[maxn];
void nhap()
{
    scanf("%d%d",&n,&c);
    for (int i=1; i<=n; i++) {scanf("%d",&x[i]);}
}
bool check(int k)
{
    int p=1,d=1;
    for(int i=2;i<=n;i++)
    {
        if(x[i]-x[p]>=k)
        {
            d++;
            if(d==c) return true;
            p=i;
        }
    }
    return false;
}

int tknp(int l,int r)
{
    int res=0,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)==true)
        {
            res=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return res;
}
void solve()
{
    sort(x+1,x+1+n);
    int res=tknp(1,x[n]-x[1]);
    cout<<res;
}
int main()
{
    freopen("COTBO.inp","r",stdin);
    freopen("COTBO.out","w",stdout);
    nhap();
    solve();
}
