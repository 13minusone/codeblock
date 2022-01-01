
#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen("22a.inp","r",stdin);
    freopen("22a.out","w",stdout);
}
ll x,f[maxsize+4],s;
void nhap()
{
    int n;
    cin >> n;
    fu(i,1,n,1)
    {
        cin >> x;
        f[x]=f[x-1]+1;
        s=max(s,f[x]);
    }
    cout << n-s;
}
int main()
{
    fastio();
    inti();
   nhap();
}
 
