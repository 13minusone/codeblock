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
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    ll n,maxx=-1000000;
    map<string,ll>d;
    string g;
    cin >> n;
    fu(i,1,n,1)
    {
        string s;
        ll x;
        cin >> s >> x;
        d[s]=d[s]+x;
        //cout << s << " " << d[s] << endl;
        if(maxx<d[s])
        {
            g=s;
            maxx=d[s];
        }

    }
    cout << g;
}
int main()
{
    fastio();
    nhap();
}

