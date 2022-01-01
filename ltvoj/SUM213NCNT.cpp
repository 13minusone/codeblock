#include<bits/stdc++.h>
using namespace std;
#define task "SUM213NCNT"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int m;
ii a[101];
int sol(long long i, int j = 1)
{
    if(i == 0)
    {
        return 0;
    }
    if(j > m)
    {
        return 1;
    }
    if(i < a[j].first)
    {
        return 1;
    }
    int maxx = sol(i, j + 1);
    for(int k = 1; k <= a[j].second; k++)
    {
        if(i < a[j].first) break;
        i /= a[j].first;
        maxx += sol(i, j + 1);
    }
    return maxx;
}
void nhap()
{
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+m+1);
    for(int i = 1; i <= 3; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << sol(y)-sol(x-1) <<endl;
    }
    return ;
}
int main()
{
    fastio();
    inti();
    nhap();

}
