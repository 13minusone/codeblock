//  ---Author: Đặng Võ Hồng Phúc---  //
#include<bits/stdc++.h>
#define name "practice"
#define maxn int(1e5)+1
#define oo LLONG_MAX
#define fo(i,a,b) for(ll i=a;i<=b;++i)
#define CONST
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;

ll t,n,a[maxn];
vector<ll>vec;

void solve()
{
    ll minn = oo;
    sort(a+1,a+n+1);
    int res = 0;
    fo(i,1,n)
    {
        if(a[i]<=0)++res,minn = min(minn,abs(a[i]-a[i+1]));
        else{
            if(a[i]<=minn) ++res;
            break;
        }
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
//    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);
    cin>>t;
    while(t--)
    {
        vec.clear();
        cin>>n;
        fo(i,1,n) cin>>a[i];
        solve();
    }
}
