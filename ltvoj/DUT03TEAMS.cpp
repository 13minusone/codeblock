/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "DUT03TEAMS"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 505 + 5;
const ll mod =1e9+7;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int n, mx;
int dp[N];
int a[N], b[N];

void nhap()
{
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	dp[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(a[j] < a[i]) {
				dp[i] = (dp[i] + dp[j]) % mod;
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum = (sum + dp[i]) % mod;
	}
	cout << sum;
}
int main()
{

    fastio();
     inti();
    nhap();
}



