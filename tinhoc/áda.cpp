//  ---Creator: Đặng Võ Hồng Phúc---  //
#include<bits/stdc++.h>
#define name "practice"
#define maxn int(1e5)+5
#define oo LLONG_MAX
#define INF INT_MAX
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define CONST
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define e endl
using namespace std;
typedef long long ll;
template<class T> void MIN(T &A, T 😎 {A=min(A,B);}
template<class T> void MAX(T &A, T 😎 {A=max(A,B);}
template<class T> void SUM(T &A, T 😎 {A=A+B;}
template<class T> void HIEU(T &A, T 😎 {A=A-B;}
ll t,n,a[maxn],k;

void solve()
{
    ll d=0;
    map<ll,ll>m;
    fo(i,1,n) m[a[i]]=i;
    sort(a+1,a+n+1);
    m[a[0]]=oo;
    for(int i=1; i<=n; ++i){
        if(m[a[i]]!=m[a[i-1]]+1) ++d;
    }
    if(d<=k) cout<<"YES";
    else cout<<"NO";
    cout<<e;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        fo(i,1,n) cin>>a[i];
        solve();
    }
}
