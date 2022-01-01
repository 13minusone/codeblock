#include <bits/stdc++.h>
using namespace std;
struct doan
{
    int x,y;
};
doan d[100001];
int n;
void nhap()
{
    int k;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>d[i].x>>d[i].y;

    }
}

bool ss(doan p,doan q)
{
    if (p.x<q.x) return true;
    return false;
}

void xuli()
{
    sort(d+1,d+1+n,ss);
    long long a=d[1].x,b=d[1].y;
    long long res=0;
    for (int i=2;i<=n;i++)
    {
        if (b>=d[i].x)
        {
            if (d[i].y>b) b=d[i].y;
        }
        else
        {

            res=max(res,b-a);
            a=d[i].x;
            b=d[i].y;
        }
    }
    res=max(res,b-a);

    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("doanphu943.inp","r",stdin);
    freopen("doanphu943.out","w",stdout);
    nhap();
    xuli();
}

