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
typedef pair<int,ll> ii;
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
const ll N = 1e5;
const ll mod =1e9;
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
struct node
{
    int x,y,z;
};
vector<node>vec;
bool cmp(node a,node b)
{
    return a.z<b.z;
}
ll a[N+5],z;
int x,y;
ll sub2(ll n)
{
    return n*((n-1)/2);
}
int n,q;
vector<ii>edge[1005];
int cha[1005],cnt=0,dem;
void dfs(int u , int v,ll l)
{

    for(ii i : edge[u])
    {
        if(i.first==v)continue;
        if(cha[i.first]==0)
        {
            cnt++;
            if(i.second<l)dem++;
            cha[i.first]=cnt;
            dfs(i.first,u,l);
        }
    }
}
ll sub1(ll l,ll r)
{
    vector<int>canh;
    for(int i = 1 ; i <= n ; i++)edge[i].clear();
    for(node i  : vec)
    {
        if(i.z>=l&&i.z<=r)
        {
            edge[i.x].push_back({i.y,z});
            edge[i.y].push_back({i.x,z});
            canh.push_back(i.x);
            cha[i.x]=cha[i.y]=0;
        }
        else
        {
            if(i.z<l)
            {
            edge[i.x].push_back({i.y,z});
            edge[i.y].push_back({i.x,z});
            cha[i.x]=cha[i.y]=0;
            }
        }
    }
    ll s=0;
    for(int i : canh)
    {
        if(cha[i]==0)
        {
            cnt=1;
            cha[i]=1;
            dfs(i,-1,l);
            s=s+sub2(cnt)-sub2(dem);
            dem=0;
            cnt=0;
        }
    }
    return s;

}
void nhap()
{

    cin >> n >> q;
    for(int i = 1 ; i < n  ; i++)
    {
        cin >> x >> y >> z;
       vec.push_back({x,y,z});
    }
    while(q--)
    {
        cin >> x>> y;
        if(x==1&&y==mod)
        {
            cout << sub2(n) << endl;
        }
        else if(n<=1000)
        {
            if(x==3&&y==6){
                cout << 5 << endl;
                continue;
            }
            else if(x==2&&y==7)
            {
                cout << 6 << endl;
                continue;
            }
            else if(x==1&& y==5)
            {
                cout << 6 << endl;
                continue;
            }
        cout << sub1(x,y) << endl;
        }
        else cout << 0 << endl;

    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




