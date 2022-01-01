#include<bits/stdc++.h>
using namespace std;
#define task ""
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
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
float pow(float n,ll x)
{
    if(x<=1)
    {
        return n;
    }
    ll d=x/2;
    if(x&1)
    {

        float u=((pow(n,d)%float(1000))*(pow(n,d)%float(1000))*(n%float(1000)))%float(1000);
        return u;
    }
    else
    {
        float u=((pow(n,d)%float(1000))*(pow(n,d)%float(1000)))%float(1000);
        return u;
    }
}
void nhap()
{

    float a;
    a=5.449489743;
    cout << a;
}
int main()
{

    fastio();
    // inti();
    nhap();
}


