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
    ll t;
    cin >> t;
    int n;
    ll a[101];
    fu(i,1,t,1)
    {
        cin >> n;
        fu(j,1,2*n,1)
        {
            cin >> a[j];
        }
        sort(a+1,a+2*n+1);
        fu(i,1,n,1)
        {
            cout << a[i] << " " << a[2*n-i+1]<< " " ;
        }
        cout << endl;
    }
}
int main()
{
    fastio();
    nhap();
}

