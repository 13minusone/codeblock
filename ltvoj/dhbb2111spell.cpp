#include <bits/stdc++.h>

#define fi first
#define se second
#define For(i, a, b) for (int i=a;i<=b;++i)
#define Ford(i, a, b) for(int i=a;i>=b;--i)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N=305;
const int oo=1e9;

int a[N][N], s[N], f[N][N], f2[N][N];

void solve()
{
    int n, m, K;
    cin>>n>>m>>K;
    For(i, 1, K)
    {
        char c;cin>>c;
        s[i]=c-'A'+1;
    }

    For(i, 1, n) For(j, 1, m)
    {
        char c;cin>>c;
        a[i][j]=c-'A'+1;
    }

    For(i, 1, n) For(j, 1, m) if (a[i][j]==s[1]) f[i][j]=1;else f[i][j]=oo;

    For(k, 1, K-1)
    {
        For(i, 1, n) For(j, 1, m) f2[i][j]=oo;
        For(i, 1, n) For(j, 1, m) if (a[i][j]==s[k])
        {
            f2[i+1][j]=min(f2[i+1][j], f[i][j]+1);
            f2[i][j+1]=min(f2[i][j+1], f[i][j]+1);
            f2[i-1][j]=min(f2[i-1][j], f[i][j]+1);
            f2[i][j-1]=min(f2[i][j-1], f[i][j]+1);
        }
        For(i, 1, n)
        {
            For(j, 1, m)
            {
                f2[i][j+1]=min(f2[i][j+1], f2[i][j]+1);
                f2[i+1][j]=min(f2[i+1][j], f2[i][j]+1);
            }
            Ford(j, m, 1)
            {
                f2[i][j-1]=min(f2[i][j-1], f2[i][j]+1);
                f2[i+1][j]=min(f2[i+1][j], f2[i][j]+1);
            }
        }
        Ford(i, n, 1)
        {
            For(j, 1, m)
            {
                f2[i][j+1]=min(f2[i][j+1], f2[i][j]+1);
                f2[i-1][j]=min(f2[i-1][j], f2[i][j]+1);
            }
            Ford(j, m, 1)
            {
                f2[i][j-1]=min(f2[i][j-1], f2[i][j]+1);
                f2[i-1][j]=min(f2[i-1][j], f2[i][j]+1);
            }
        }
        For(i, 1, n) For(j, 1, m) if (a[i][j]==s[k+1]) f[i][j]=f2[i][j];
        else f[i][j]=oo;
    }

    int ans=oo;
    For(i, 1, n) For(j, 1, m) ans=min(ans, f[i][j]);
    cout<<ans;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    freopen("dhbb2111spell.inp","r",stdin);
    freopen("dhbb2111spell.out","w",stdout);
	solve();

	return 0;
}
