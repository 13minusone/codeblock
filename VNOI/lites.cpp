#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100040;

int sum[MAXN * 4], flip[MAXN * 4];

void update(int id, int l, int r, int x, int y)
{
    if(x<=l && r<=y)
    {
        flip[id] ^= 1;
        sum[id] = (r-l+1) - sum[id];
        return;
    }
    int m = (l+r) / 2;
    if(x<=m) update(id<<1,l,m,x,y);
    if(m<y) update(id<<1|1,m+1,r,x,y);
    sum[id] = sum[id<<1] + sum[id<<1|1];
    if(flip[id]) sum[id] = (r-l+1) - sum[id];
}

int getsum(int id, int l, int r, int x, int y, int f)
{
    if(x<=l && r<=y)
    {
        if(f) return (r-l+1) - sum[id];
        else return sum[id];
    }
    int m = (l+r) / 2;
    f ^= flip[id];
    int res = 0;
    if(x<=m) res += getsum(id<<1,l,m,x,y,f);
    if(m<y) res += getsum(id<<1|1,m+1,r,x,y,f);
    f ^= flip[id];
    return res;
}

int main()
{
//    freopen("vnoi.inp","r",stdin);
//    freopen("vnoi.out","w",stdout);
    int n, m;
    cin >>n >> m;
    for(int i=0; i<m; ++i)
    {
        int c, u, v;
        cin >> c >> u >> v;
        if(c==0) update( 1, 1, n, u, v);
        else cout << getsum(1,1,n,u,v,0) <<endl;;
    }
    return 0;
}
