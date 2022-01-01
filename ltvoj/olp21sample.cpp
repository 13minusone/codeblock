#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define prob "olp21sample"
using namespace std;

const int N = 17;
const int M = 1e5+1;

int n,m,k,a[M];
int f[N][N][(1<<17)+1]{0};
ll ans = 0;

int cal(string x)
{
    int res = 0;
    for(int i=0;i<x.size();i++)
    if(x[i]=='1') res ^= (1<<i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("olp21sample.inp","r",stdin);
    freopen("olp21sample.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        string s; cin>>s;
        a[i] = cal(s);
        f[0][0][a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=k;j++)
        for(int val = 0;val<=(1<<m)-1;val++)
        {
            f[i][j][val] += f[i-1][j][val];
            if(j>=1) f[i][j][val] += f[i-1][j-1][val^(1<<(i-1))];
        }
    }
    for(int i=1;i<=n;i++)
        ans+= f[m][k][a[i]];
    cout<<ans/2;
}

