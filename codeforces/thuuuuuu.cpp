#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
const int mod = int(1e9)+7;
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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n, t;
bool check(int x)
{
    return x<=3;
}
void sol()
{
    cin >> n;
    int dem=n;
    if (check(n))
    {
        for (int i=0;i<n; i++) cout << char('a'+i);
        return;
    }
    for (int i=1;i<=n/2;++i)
    {
        dem--;
        cout << 'a';
    }
    cout << 'e';
    dem--;
    if (n&1)
    {
        if (dem>0)
        {
            dem--;
            cout << 'd';
        }
    }
    for (int i=1; i<=dem; i++) cout << 'a';
}
int main()
{
    fastio();
    //init();
    cin>>t;
    while (t--)
    {
        sol();
        cout << "\n";
    }
}
