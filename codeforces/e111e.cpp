#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define getbit(x,i) (((x) >> (i)) & 1)
const int oo=int(1e9);
typedef pair<int, int> ii;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int d[(1<<18)+5];
const int N=int(2e5)+5;
int n,k;
int fp[N][25];
string s;
int pe[N][25];
bool check(int val)
{
    fd(i,n,1)
    {
        fu(j,0,k-1)
        {
            pe[i][j]=pe[i+1][j];
            if(fp[i][j]>=val) pe[i][j]=i;
        }
    }
    for(int i=0; i<(1<<k); ++i) d[i]=oo;
    d[0]=0;
    for(int ma=0; ma<(1<<k); ++ma)
    {
        fu(i,0,k-1)
        {
            if(!getbit(ma,i))
            {
                if(d[ma]==oo) continue;
                int c=d[ma];
                int tmp=ma+(1<<i);
                if(!pe[c+1][i]) continue;
                int tam=pe[c+1][i]+val-1;
                assert(tam<=n);
                d[tmp]=min(d[tmp],tam);
            }
        }
    }
    if (d[(1<<k)-1]<=n) return true;
    return false;
}
void sol()
{
    cin >> n >> k;
    cin >> s;
    s=' '+s;
    fd(i,n,1)
    {
        if(s[i]=='?')
        {
            fu(j,0,k-1) fp[i][j]=fp[i+1][j]+1;
            continue;
        }
        else
        {
            int c=s[i]-'a';
            fp[i][c]=fp[i+1][c]+1;
        }
    }
    int l=1, r=n, res=0;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if(check(m))
        {
            l=m+1;
            res=m;
        }
        else r=m-1;
    }
    cout << res;
}
int main()
{
    //init();
    sol();
}
