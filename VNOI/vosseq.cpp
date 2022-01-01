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
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
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
const ll N = 1e6;
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
priority_queue<int,vector<int>,greater<int>>q;
ll dd[N+5],a[1005],maxx=-N+5;
vector<int>edge[N+5];
void nhap()
{
    int n,t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            maximize(maxx,a[i]);
            if(i>1)
            {
                edge[a[i-1]].push_back(a[i]);
                dd[a[i]]++;
            }
        }
    }
    for(int i = 1 ; i <= maxx ; i++)
        if(dd[i]==0)q.push(i);
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        for(int i : edge[x])
        {
            dd[i]--;
            if(dd[i]==0)q.push(i);
        }
        cout << x << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




