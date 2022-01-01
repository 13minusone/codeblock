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
#define task "olp21friends"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
vector<int>vec[maxsize+5];
int n,m,x,y,q,type;
bool sol(int u,int v)
{
    for(int i : vec[u])
    {
        if(i==v)
        {
            return true;
        }
        for(int x : vec[v])
        {
            if(x==u)return true;
            if(x==i)
            {
                return true;
            }
        }
    }
    return false;
}
void nhap()
{
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cin >> q;
    while(q--)
    {
        cin >>type >>  x >> y;
        if(type==1)
        {
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        else
        {
            if(!sol(x,y))
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }

    }
}
int main()
{

    fastio();
    inti();
    nhap();
}




