
#include <bits/stdc++.h>
#define task "SHHV"
using namespace std;
long long f[13];
int used[13];
int a[14];
int n;
void init()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}
void FastIO()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
void findpos()
{
	int res = 0;
	for (int i = 1; i<=n; i++)
	{
		int cnt = 0;
		for (int j = 1; j<a[i]; j++)
		{
			if(used[j] == 0) cnt++;
		}
		res += cnt*f[n-i];
		used[a[i]] = 1;
	}
	cout<<res+1<<endl;
}
void permutationarray(int k)
{
	for (int i = 1; i<=n; i++) used[i] = 0;
	for (int i = 1; i<=n; i++)
	{
		int d = k/f[n-i]+1;
		k = k%f[n-i];
	//	cout<<d<<" ";
		for (int j = 1; j<=n; j++)
		{
			if(used[j] == 0)
			{
				d--;
				if (d == 0) {
					used[j] = 1;
					cout<<j<<" ";
					break;
				}
			}
		}
	}
}
void solve()
{
	int c;
	n = 1;
	while (cin>>c)
	{
		a[n] = c;
		n++;
	}
	n -=2 ;
	f[0] = 1;
	for (int i = 1; i<=n; i++)
	{
		f[i] = f[i-1] * i;
	}
	findpos();
	permutationarray(a[n+1]-1);
}
int main()
{
	init();
	solve();
}
