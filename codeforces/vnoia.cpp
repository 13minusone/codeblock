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
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 2e5 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block=500;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int n,a[N],lazy[N/block+5][105],l,r,x,y;
void upda(int id)
{
    for(int i = id*block ; i <=min(n-1,((id+1)*block-1));i++)
    {
        a[i]=lazy[id][a[i]];
    }
    for(int j = 0 ; j <= 100;j++)lazy[id][j] = j;
}
void updin(int l,int r,int old,int neww)
{
    int id=r/block;
    upda(id);
    for(int i = l ; i <= r; i++)if(a[i] == old)a[i]=neww;
}
void update(int l,int r,int old ,int neww)
{
    int lb = (l/block);
    int rb=(r/block);
    if(l == r)
    {
        updin(l,r,old,neww);
        return;
    }
    for(int i = lb +1 ; i< rb ;i++)
    {
        for(int j = 0 ; j <= 100 ; j++)
            if(lazy[i][j] == old)lazy[i][j] = neww;
    }
    updin(l,(lb+1)*block-1,old,neww);
    updin(rb*block,r,old,neww);

}
int q;
void nhap()
{
    cin >> n;
    for(int i = 0; i < n ;i++)
    {
        cin >> a[i];
    }
    int nblocks=(n+block-1)/block;
    for(int i = 0; i <nblocks;i++)
    {
        for(int j = 1; j <= 100 ;j++)lazy[i][j]=j;
    }
    cin >> q;
    while(q--)
    {
        cin >> l >> r >> x >> y;
        l--;
        r--;
        update(l,r,x,y);
    }
    for(int i = 0 ; i < nblocks;i++)upda(i);
    for(int i = 0; i < n ; i++)cout << a[i] << " ";

}
int main()
{

    fastio();
     //inti();
    nhap();
}




