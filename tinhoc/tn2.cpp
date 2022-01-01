#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
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
int q;
long long k;
void sol()
{
    long long x,y;
    cin >> k;
    if (k==1)
    {
         cout << 1 << "\n";
         return;
    }
    if (k==2)
    {
        cout << 3 << "\n";
        return;
    }
    x=2*k;
    x=sqrt(x);
    if (x*(x+1)==2*k)
    {
        cout << x << "\n";
        return;
    }
    if (x*(x-1)==2*k)
    {
        cout << x-1 << "\n";
        return;
    }
    //cout << x << " ";
    while ((x*(x+1)/2)<k) x++;
    y=x*(x+1)/2 - k;

//    cout << y << " ";
    if (y%2==0) cout << x << "\n";
    else
    {
        if (x%2==1) cout << x+2 << "\n";
        else cout << x+1 << "\n";
    }
}
int main()
{
    init();
    fastio();
    cin >> q;
    while (q--) sol();
}

