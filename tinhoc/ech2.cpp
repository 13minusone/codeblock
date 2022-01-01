#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, k;
    cin >> n >> k;

    int a[100001];
    for (int i=1; i<=n; i++ ) cin >>a[i] ;

    ll dp[100001];
    dp[0]=0;
    for (int i = 2; i <= n; ++i)
    {
        ll minn=100000000000000;

        for (int j = i - 1; j >= max(1, i - k); --j)
        {
            minn=min(minn,dp[j]+abs(a[i]-a[j]));
        }
        dp[i]=minn;
        //cout<<dp[i]<<endl;
    }

    cout << dp[n];
    return 0;
}
