/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
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
const ll maxsize = 200000;
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
int n,f[maxsize+5], a[maxsize+5],cha[maxsize+5];
vector<int>vec[maxsize+5];

void dfs(int u)
{
    for(int i : vec[u])
    {
        if(cha[i]==0)
        {
            cha[i]=1;
            dfs(i);
            f[u]=f[u]+f[i]+1;
            //cout << i << " "<<u << " "<< f[u] << endl;
        }
    }
}
void nhap()
{
    cin >>n;
    for(int i = 1 ; i <= n -1 ; i++)
    {
        cin >> a[i];
        vec[a[i]].push_back(i+1);
    }
    dfs(1);
    for(int i = 1 ; i <= n ; i++)
    {
        cout << f[i] << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



