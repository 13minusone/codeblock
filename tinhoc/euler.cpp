#include<bits/stdc++.h>
#define TASK "test"
#define forup(i,l,r) for (int i=l; i<=r; i++)
#define fordown(i,l,r) for(int i=l ; i>=r ; i--)
#define oo INT_MAX
#define ll long long
#define pub push_back
#define pob pop_back
#define ull unsigned long long
#define fi first
#define se second
#define ti20_ntson int main()
#define vector <int>  vi
using namespace std;
int n;
int f[2];
struct son
{
    int l , r;
}a[1000002];
bool ss ( son a , son b)
{
    if (a.l < b.l) return true;
    return false;
}
void nhap()
{
    cin >> n;
    forup(i,1,n)
    {
        cin >> a[i].l;
        a[i].r=i;
    }
   sort ( a+1 ,a+n+1 ,ss);
//    forup(i,1,n)
//      cout << a[i] .l <<" " << a[i].r <<endl;
//      cout <<endl;
}
void solve()
{

    int res = 0 ;
     f[1] = a[1].r;
    forup(i,2,n)
       {
           res = max ( res , a[i].r - f[1]);
           if(a[i].r < f[1])
              f[1] = a[i].r;
          // cout << i-f[i-1] << " " << f[i]<<endl;
       }
    if (res==0)
        cout << -1;
    else
    cout << res ;
}
ti20_ntson
{
//freopen(TASK".INP","r",stdin);
//freopen(TASK".OUT","w",stdout);
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
nhap();
solve();
}
