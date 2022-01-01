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
int main()
{
    fastio();
    int t;
    cin >> t;
    fu(i,1,t,1)
    {
        int k;
        cin >> k;
    if (k==100)
    {
        cout << 1 << endl;

    }

   else if (__gcd(k,100)==1)
    {
        cout << 100 << "\n";

    }else
    {int e=k/__gcd(k,100), h=100/__gcd(k,100);
    cout <<  min(100, h) << endl;;
    }
}}
