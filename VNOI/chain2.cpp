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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 250005;
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
int trie[N][27],cnt=0,d[N],f[N];
void nhap()
{
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        int u=0;
        for(char c : s)
        {
            if(!trie[u][c-'a'])trie[u][c-'a']=++cnt;
            u=  trie[u][c-'a'];
        }
        d[u]++;
    }
    for(int i = cnt ; i>=0;i--)
    {
        for(int j = 0; j< 26;j++) if(trie[i][j])f[i]=max(f[i],f[trie[i][j]]);
            f[i]+=d[i];
    }
    cout << f[0];
}
int main()
{

    fastio();
    // inti();
    nhap();
}




