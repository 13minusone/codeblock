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
    ll t,x,n;
    cin >> t;
    fu(i,1,t,1)
    {
        cin >> n;
        ll s=0;
        fu(j,1,n,1)
        {
            cin >> x;
            s=s+x;

        }
        if(s<=0||s<n)
        {
            cout << "1" << endl;
        }
        else
        {
        cout << s-n << endl;
        }
    }
}
int main()
{
    fastio();
    nhap();
}

