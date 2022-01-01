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
    ll t,n;
    string s;
    cin >> t;
    fu(k,1,t,1)
    {
        cin >> s;
        cin >> n;
        ll sum=1;
        fu(i,1,s.size(),1)
        {
            sum*=i;
        }
        cout << sum << endl;
    }
}
int main()
{
    fastio();
    nhap();
}

