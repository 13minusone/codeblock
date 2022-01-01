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
    ll t,a,b,c,d;
    cin >> t;
    fu(i,1,t,1)
    {
        cin >> a >> b >> c >> d;

            if(c==1&& d==1)
            {
                cout << a << " " << b << " " << a<<" " << 1 << endl;


            }
            else
            {
              cout << 1 << " " << 1 << " " << a << " " << b << endl;
            }


    }
}
int main()
{
    fastio();
    nhap();
}

