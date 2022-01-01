#include<bits/stdc++.h>
using namespace std;

#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)


void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int t,n,d[105][105];
void solve()
{
    cin >> n;
    if (n==1)
    {
        cout << 1 << endl;
        return;
    }
    else if (n==2)
    {
        cout << -1 << endl;
        return;
    }
    int i=0;
    fu(j,1,n)
    {
        fu(k,1,n)
        {
            i+=2;
            if (i<=n*n)
            {
                printf("%d ",i);
            }
            else
            {
                i=1;
                printf("%d ",i);
            }
        }
        cout << endl;
    }
}
int main()
{
    //init();
    //fastio();
    cin >> t;
    fu(i,1,t)
    {
        solve();
    }
}
