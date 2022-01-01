/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "TG0302SEG"
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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
const ll mod =1e9+9;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
map<int,int>cnt;
vector<pair<int,char>>a;
bool cmp(pair<int,char>a,pair<int,char> b)
    {
        if(a.fi!=b.fi)return a.fi<b.fi;
    if (a.se == 's' && b.se == 'e') return true;		// s : start
	if (a.se== 'e' && b.se == 's') return false;		// e : end
	if (a.se == 's' && b.se == 'p') return true;      // p : point (diem can tinh)
	if (a.se == 'p' && b.se == 'e') return true;
	return false;
    }
void nhap()
{
    int n,m,x,y;
	cin>>n>>m;
    for (int i = 0; i<n; i++)
	{
		cin>>x>>y;
		if (x > y) swap(x,y);
		a.push_back({x,'s'});
		a.push_back({y,'e'});
	}
	ll ans[m+3];
	for(int i = 0 ; i < m ; i++)
    {
        cin >> ans[i];
        a.push_back({ans[i],'p'});
    }
    map <int,int> cnt;
    int sum=0;
	sort(a.begin(),a.end(),cmp);
	for (int i = 0; i<a.size(); i++)
	{
		if (a[i].se == 's')
		{
			sum++ ;
		}
		else if (a[i].se == 'e')
		{
			sum--;
		}
		else
		{
			cnt[a[i].fi] = sum;
		}
	}
	for (int i = 0; i<m; i++)
	{
		cout<<cnt[ans[i]]<< " ";
	}
}
int main()
{

    fastio();
     inti();
    nhap();
}




