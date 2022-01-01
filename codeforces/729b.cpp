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
    ll n,x,y,q;
    cin >> q;
    fu(j,1,q,1)
    {
        cin >> n >> x >> y;
        while(n!=1)
        {
            if(n%x==0&&x!=1)
            {
                n/=x;
            }
            else
            {
                n-=y;
            }
            if(n<=0)
            {
                break;
            }
        }
        if(n<=0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
int main()
{
    fastio();
    nhap();
}

