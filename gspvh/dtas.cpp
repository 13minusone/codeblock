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
#define task "dtas"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define ll long long
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
ll a;
ll psum[6*N+5];
struct bien
{
    string s;
    ll x;
    unsigned long long  sum;
};
bien s[6*N+5];
bool cmp(bien a,bien b)
{
    if(a.sum!=b.sum)return a.sum>b.sum;
    if(a.x!=b.x)return a.x<b.x;
    return  a.s<b.s;
}
ll n,q;
vector<ll>question[6*N+5];
void nhap()
{
    cin >> n >> q;
    memset(psum,0,sizeof psum);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> s[i].s >> s[i].x;
        for(int j = 1 ; j <= s[i].x; j++)
        {
            cin >> a;
            question[i].push_back(a);
            psum[a]++;
        }
    }
    unsigned ll res=0,g;
    for(int i = 1 ; i <= q ; i++)res+=psum[i];
    for(int i = 1 ; i <= n ; i++)
    {
        g=res;
        for(int j : question[i])
        {
            g-=psum[j];
        }
        s[i].sum=g;
    }
    sort(s+1,s+1+n,cmp);
    for(int i = 1 ; i <= n ; i++)
    {
        cout << s[i].s  << " "<< s[i].sum << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




