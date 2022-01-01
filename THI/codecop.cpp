#include <bits/stdc++.h>
#define task "test"
using namespace std;
const long long N = 1e5 + 7;
long long par[N], sz[N], psum[N];
struct ii{
	long long x,y,w;
};
bool cmp(ii a, ii b)
{
	return a.w < b.w;
}
void init()
{
	freopen(task".in","r",stdin);
	freopen(task".out","w",stdout);
}
void fastio()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
long long get(long long a)
{
	if (a != par[a])
	{
		par[a] = get(par[a]);
	}
	return par[a];
}
void unite(long long a, long long b)
{
	if (sz[a] > sz[b]) swap(a,b);
	par[a] = b;
	sz[b] += sz[a];
}
void solve()
{
	long long n,q;
	cin>>n>>q;
	for (long long i = 1; i<=n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	n--;
	vector <ii> a(n);
	vector <long long> edge;
	map<long long,long long> m;
	for (long long i = 0; i<n; i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a.begin(),a.end(),cmp);
	long long u,v;
	for (long long i = 0; i<n; i++)
	{
		u = get(a[i].x);
		v = get(a[i].y);
		if (u == v) continue;
		edge.push_back(a[i].w);
		psum[edge.size()-1] += sz[u] * sz[v];
		psum[edge.size()] += psum[edge.size() - 1];
	//	m[a[i].w] += sz[u] * sz[v];
		unite(u,v);
	}

	vector <long long>::iterator low,up;
	long long pos1, pos2, l , r;
	long long ans ;

	for (long long i = 0; i<q; i++)
	{
		ans = 0;
		cin>>l>>r;
		low = lower_bound(edge.begin(),edge.end(),l);
		if (low == edge.end())
		{
			cout<<0<<endl;
			continue;
		}
		pos1 = low - edge.begin();
		up = upper_bound(edge.begin(),edge.end(),r);
		if (up == edge.end())
		{
			pos2 = edge.size() - 1;
		}
		else
		{
			up--;
			pos2 = up - edge.begin();
		}

		if (edge[pos1] < l || edge[pos2] > r)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			if (pos1 == 0)
			{
				ans = psum[pos2];
			}
			else
			{
				ans = psum[pos2] - psum[pos1 - 1];
			}
		}
		cout<<ans<<endl;
	}
}
int main()
{
	fastio();
//	init();
	solve();
}
