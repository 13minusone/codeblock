#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

ll divTermCount(ll a, ll b, ll lcm, ll num)
{

    return num / a + num / b - num / lcm;
}

ll findNthTerm(ll a, ll b, ll n)
{
    ll low = 1, high = max(a,b)*n, mid;
    ll lcm = (a * b) / gcd(a, b);

    while (low < high) {
        mid = low + (high - low) / 2;
        if (divTermCount(a, b, lcm, mid) < n)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main()
{
    int t;
    ll a,b,n;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
    cout << findNthTerm(a, b, n) << endl;
    }

    return 0;
}
