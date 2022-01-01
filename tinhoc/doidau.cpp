#include<bits/stdc++.h>
using namespace std;
const long long maxx = 1000005;
long long k[maxx],arr[maxx],f[maxx],l,u;
long long res = LONG_MIN,x=LONG_MIN;
long long n;
void nhap()
{
    //freopen("liqlis.inp","r",stdin);
   // freopen("liqlis.out","w",stdout);
    cin>>n>>l>>u;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
        f[arr[i]]=i;
    }
}
bool ss(long long a,long long b)
{
    if(abs(a-b)<=u&&f[b]-f[a]>=l){return true;}
    else {return false;}
}
void solve()
{
    vector<long long> vec(n+1,LONG_MAX);
    vec[0] = LONG_MIN;
    for(long long i=1;i<=n;i++){
        k[i] =lower_bound(vec.begin(),vec.end(),arr[i],ss) - vec.begin();
        vec[k[i]] = arr[i];
        res = max(res,k[i]);
    }

}

int main()
{
    //freopen("egroup.inp","r",stdin);
    //freopen("egroup.out","w",stdout);
    nhap();
    solve();



   cout<<res;
}
