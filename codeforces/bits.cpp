#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
ll leed()
{
    ll a;
    scanf("%lld",&a);
    return a;
}
ll fan()
{
    ll a,b,c,d,n,m,i,j,k,l,p,x,y,z;
    vector <ll > v;
    map <char,ll > mp;

    a = leed();
    b = leed();

    n = log2(b) + 1;
    m = __builtin_popcount(b);
    if(m==n)
    {
        printf("%lld\n",b);
        return 0;
    }
    if(a==b)
    {
        cout<<a<<endl;
        return 0;
    }
    z = 1;
    for(i=2;i<n;i++)
    {
        z = z<<1;
        z++;
    }
    if(z>=a)
    {
        cout<<z<<endl;
        return 0;
    }
    z++;
    if(z<a)
        z = a;
    c = 1;
    y = z;
    while(1)
    {
        if(c&z)
        {
            c = c<<1;
            continue;
        }
        z += c;
        c = c<<1;
        if(z>b)
        {
            cout<<y<<endl;
            break;
        }
        y = z;
    }
    return 0;
}

int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        fan();
}    }
