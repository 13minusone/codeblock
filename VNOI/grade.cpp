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
typedef pair<ll,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
ll maxx[N+5],x,a;
ii f[N+5];
void nhap()
{
    int n,q;
    cin >> n >> q;
    memset(maxx,0,sizeof maxx);
    for(int i = 1 ; i <=N;i++)
    {
        f[a]=ii(0,0);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x;
        for(int j = 1 ; j <= x ; j++)
        {
            cin >> a;
            if(f[a].second==i-1)
            {

                f[a].first++;

            }
            else
            {
                if(f[a].second==i)continue;
                f[a].first=1;

            }
            maxx[a]=max(maxx[a],f[a].first);
            f[a].second=i;
        }
    }
    while(q--)
    {
        cin >> x;
        if(x>=0)
        {
            cout << maxx[x] << endl;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




