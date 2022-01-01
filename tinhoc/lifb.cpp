#include<bits/stdc++.h>
using namespace std;
///define-zone
#define task "LFIB"
#define vec vector
#define priq priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define SZ(a) a.begin(), a.end()
#define SZZ(a, begin, end) a + begin, a + begin + end
#define fi first
#define se second
#define N int(2e5) + 1

///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
typedef pair<long long, long long> pll;
typedef pair<int, ii> iii;
void init()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}

void fastio()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}
ull a, b, n, k, m;
struct mt
{
	ull p[3][3];
};
mt mul(mt t1, mt t2)
{
	mt ret;
	for(int i = 0; i < 3; i++)
	{
    	int  s=0;
        while(s<=2)
    	{
        	ret.p[i][s] = 0LL;
        	for(int k = 0; k < 3; k++)
        	{
            	ret.p[i][s] = ((ret.p[i][s]%m) + (fmul(t1.p[i][k]%m, t2.p[k][s]%m, m)%m))%m;
        	}
            s++;
    	}
	}
	return ret;
}
mt ltmt(mt t1, ull y)
{
	if(y == 1) return t1;
	mt cnt = ltmt(t1, y/2);
	cnt = mul(cnt, cnt);
	if(y&1) return mul(cnt, t1);
	else return cnt;
}
ll f(ull i)
{
	if(i == 1) return a%m;
	if(i == 2) return b%m;
	mt A;
	A.p[0][0] = 0; A.p[0][1] = 1; A.p[0][2] = 0;
	A.p[1][0] = 1; A.p[1][1] = 1; A.p[1][2] = 1;
	A.p[2][0] = 0; A.p[2][1] = 0; A.p[2][2] = 1;
	mt F = ltmt(A, i - 1);
	return ((fmul((F.p[0][0]%m),(a%m), m)%m) + (fmul((F.p[0][1]%m),(b%m), m)%m) + (F.p[0][2]%m))%m;
}
void sol()
{
	cin >> a >> b >> n >> k >> m;
	ull tmp = ((f(n + 2)%m) - (f(2)%m) - (n%m) + m*m)%m;
	if(k == 1) cout << tmp << "\n";
	else if(k == 2)
	{
    	cout << ((((a%m)*(a%m))%m) + (((f(n)%m)*(f(n + 1)%m))%m) - ((a%m)*(b%m)) - (tmp%m) + (a%m) + m*m)%m << '\n';
	}
}
int main()
{
	fastio();

	//init();

	int t;
	cin >> t;
	while(t--)
	{
    	sol();
	}
	return 0;
}

