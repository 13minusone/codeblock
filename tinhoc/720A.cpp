#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
const unsigned ll  mod=1000000000000000000;
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
    int t;
    cin >> t;
    //cout << mod;
    fu(i,1,t,1)
    {
        ll a,b;
        cin >> a >> b;
        if(b==1)
        {
            cout << "NO" <<endl;
            continue;
        }


        unsigned ll u=(b-1)*a;
unsigned ll v=a*b;

        if(b==2)
        {
            u=3*a;
            v=4*a;
        }

//        if(u>mod||v>mod)
//        {
//            cout << "NO" <<endl;
//            continue;
//        }
        cout << "YES" <<endl;

        cout << a << " " <<u << " " << v <<endl;

    }
}
int main()
{
    fastio();
    //nti();
    nhap();
}
