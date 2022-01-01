#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
const int mod = int(1e9)+7, N=int(1e6)+2, INF = int(1e6)+2;
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
ll maxx=-1000000000009;
ll maxl[N], minl[N], maxr[N], minr[N], a[N], n;
int main()
{
    //init();
    fastio();
    minl[0]=INF;
    maxl[0]=-INF;
    cin >> n;
    fu(i,1,n)
    {
        cin >> a[i];
        maxl[i]=maxl[i-1];
        if (a[i]>maxl[i]) maxl[i]=a[i];
        minl[i]=minl[i-1];
        if (a[i]<minl[i]) minl[i]=a[i];
    }
    //fu(i,1,n) cout << maxl[i] << " " << minl[i] << "\n";
    minr[n]=a[n];
    maxr[n]=a[n];
    for(int i=n-1; i>=1; i--)
    {
        maxr[i]=maxr[i+1];
        if (a[i]>maxr[i]) maxr[i]=a[i];
        minr[i]=minr[i+1];
        if (a[i]<minr[i]) minr[i]=a[i];
    }
    //fd(i,n,1) cout << maxr[i] << " " << minr[i] << "\n";
   ll x,y,z;
    ll m=0,k=0,l=0,f=0;
    for(int i=2; i<n; i++)
    {
        y=a[i];
        x = maxl[i-1];
        z = minr[i+1];
        m = (x-y)*(y-z);
        maxx=max(maxx,m);

        x = minl[i-1];
        z = maxr[i+1];
        f = (x-y)*(y-z);
        maxx=max(maxx,f);
    }
    cout << maxx;
}
