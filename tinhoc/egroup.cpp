#include<bits/stdc++.h>
using namespace std;
const long long maxx = 1000005;
long long k[maxx],arr[maxx],f[maxx];
long long res = LONG_MIN,x=LONG_MIN;
long long n;
void nhap()
{
    //freopen("liqlis.inp","r",stdin);
   // freopen("liqlis.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
}
bool ss(long long a,long long b)
{
    if(a>b){return true;}
    else {return false;}
}
void solve()
{
    vector<long long> vec(n+1,LONG_MAX);
    vec[0] = LONG_MIN;
    for(long long i=1;i<=n;i++){
        k[i] =lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin();
        vec[k[i]] = arr[i];
        res = max(res,k[i]);
    }

}

void solve1()
{
    vector<long long> resss(n+1,LONG_MIN);
    resss[0] = LONG_MAX;

    for(long long i=1;i<=n;i++){
        f[i] = upper_bound(resss.begin(),resss.end(),arr[i],ss) - resss.begin();
        resss[f[i]] = arr[i];
        x= max(x,f[i]);
    }

}


int main()
{
    freopen("egroup.inp","r",stdin);
    freopen("egroup.out","w",stdout);
    nhap();
    solve();

   solve1();

   cout<<min(n-x,n-res);
}
