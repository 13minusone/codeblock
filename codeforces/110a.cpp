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
    ll t,x,y,z,r;
    cin >> t;
    fu(i,1,t,1)
    {
        cin >> x >> y >> z >> r;
        if(x > min(z,r)|| y > (min(z,r)))
        {
            if(z > min(x,y) || r > min (x,y))
            {


            cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << " NO" << endl;
        }
    }

}
int main()
{
    fastio();
    nhap();
}

