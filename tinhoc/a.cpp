#include <bits/stdc++.h>
using namespace std ;
#define oo INT_MAX
#define test "TASK"
#define ll long long
#define pb push_back
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int maxN = 1e5 + 5 ;
int n, a[maxN],t ;
void solve()
{
    cin >> t;
    while(t--)
    {
        cin >> n ;
        int ans = -1e9 ;
        double p = 0 ;
        for(int i = 1 ; i<= n ; i++)
        {
            cin >> a[i] ;
            ans = max(ans, a[i]) ;
            p += a[i] ;
        }
         p -= ans ;
         p /= double(n - 1) ;
         p += ans;
        cout << setprecision(9) << fixed <<p << '\n' ;
    }
}

int main()
{
    fastio();
    solve();
}
