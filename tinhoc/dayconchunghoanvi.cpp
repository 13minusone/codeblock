#include <bits/stdc++.h>
#define Nekan "lishoanvi"
#define fi first
#define se second
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define forr(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i<(b);++i)
#define bacc(i,a,b) for(int i=(a);i>=(b);--i)
const LL N=1e5+5;
const LL MOD=1e9+7;
using namespace std;



int n, t;
int a[5*N], b[5*N];
int st[20*N];
vector <int> A[N];




void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || r < pos) return;
    if (l == r)
    {
        st[id]= max(st[id], val);
        return;
    }
    int mid= (l+r)/2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id]= max(st[id*2], st[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int mid= (l+r)/2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}



void xuly()
{
    cin>>n>>t;
    n*= t;
    forr(i,1,n)
    {
        cin>>a[i];
        A[a[i]]. pb(i);
    }

    int ans= 0;
    forr(i,1,n)
    {
        cin>>b[i];
        bacc(j,t-1,0)
        {
            int v= A[b[i]][j];
            int k= get(1, 1, n, 1, v - 1);
            ans= max(ans, k + 1);
            update(1, 1, n, v, k+1);
        }
    }
    cout<<ans<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    LL t;
//    cin>>t;
//    while(t--)
    xuly();
}
