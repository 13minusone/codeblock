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
#define task "BACTER"
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
map<int,ll>node[N+5];
int n,m;
void upd(int x, int y, ll val)
{
    for (; x <= n   ; x += x & -x)
        for (int v = y; v <= n; v += v & -v)
            node[x][v] += val;
}
ll get(int x, int y)
{
    if(x==0||y==0)return 0;
    ll res = 0;
    for (; x > 0; x -= x & -x)
        for (int v = y; v > 0; v -= v & -v)
            res += node[x][v];
    return res;
}
void nhap()
{

    cin >> n >> m;
    char s;
    ll x,y,z,d;
    while(m--)
    {
        cin >> s >> x >> y >> z;
        if(s=='S')
        {
            upd(x,y,z);
        }
        else
        {
            cin >> d;
            cout << get(z,d)+get(x-1,y-1)- get(x-1,d)-get(z,y-1)  << endl;;
        }
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}




