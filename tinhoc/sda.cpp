#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
#define fi first
#define se second
const int mod = int(1e9)+7;
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
    /*
    .....
    .....
    dtlong*/

void sol()
{
    ll a,b;
    cin>> a >> b;
    if (b == 1) cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll x,y,z;
        x = a;
        y = (b-1)*a;
        z = a*b;
        if (b==2)
        {
            x = a;
            y = 3*a;
            z = 4*a;
        }
        cout << x << " " << y << " " << z << "\n";
    }
}
int main()
{
	//init();
	int t;
	cin >> t;
	while (t--) sol();
}
