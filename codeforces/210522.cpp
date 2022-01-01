#include<bits/stdc++.h>
using namespace std;
#define task "22a"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
#define fi first
#define se second
const int N = int(1e5)+2;
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
typedef pair<int ,int> ii;
int n;
int a[N], b[N], f[int(1e6)+1];
ii tmp[N];
void nenso()
{
    int dem=0, last=int(1e6)+1;
    sort(tmp+1, tmp+n+1);
    fu(i,1,n)
    {
        if (last!=tmp[i].fi)
        {
            dem++;
            last=tmp[i].fi;
        }
        b[tmp[i].se]=dem;
    }
    //fu(i,1,n) cout << b[i] << " ";
    //cout << "\n";
}
int main()
{
    init();
    fastio();
    cin >> n;
    fu(i,1,n)
    {
        cin >> a[i];
        tmp[i].fi=a[i];
        tmp[i].se=i;
    }
    nenso();
    int maxx=0;
    fu(i,1,n)
    {
        f[b[i]]=max(f[b[i]],f[b[i]-1])+1;
        maxx=max(max(maxx,f[b[i]-1]), f[b[i]]);
    }
    cout << n-maxx;
}
