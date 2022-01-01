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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 1e5+5;
const ll mod =998244353;
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
void add(ll &a, ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void sub(ll &a, ll b )
{
    a-=b;
    if(a<0)a+=mod;
}
int nper,nround,maxeat,delta;
ll sum[105][N],f[105][N],minn=mod;
ll p[15];
ll cnt(int minn,int maxx)
{
    int ans=1;
    for(int i = 1; i <= nper; i++)
    {
        int L = minn - p[i];
        int R = maxx -p[i];
        maximize(L,0);
        minimize(R,nround*maxeat);
        if(L > R) return 0;
        ll h=sum[nround][R];
        if(L>0) sub(h,sum[nround][L-1]);
        ans=1LL*ans*h %mod;
    }
    return ans;
}
void nhap()
{
    cin >> nper >>  maxeat >>nround >> delta;
    for(int i = 1 ; i <= nper ; i++)
    {
        cin >> p[i];
        minimize(minn,p[i]);
    }
    //cout << minn << endl;
    f[0][0]=1;
    for(int i = 0 ; i <= nround * maxeat ; i++)sum[0][i]=1;
    for(int i = 1 ; i <= nround ; i++)
    {
        for(int j = 0 ; j <= nround*maxeat ; j++)
        {
            f[i][j]=sum[i-1][j];
            if(j - maxeat - 1 >= 0 )sub(f[i][j],sum[i-1][j-maxeat-1]);
            if(j>0)sum[i][j]=sum[i][j-1];
            add(sum[i][j],f[i][j]);
        }
    }
    ll res=0;
    for(int i = minn ; i <= minn+maxeat*nround; i++)
    {
        int maxx=i+delta;
        add(res,cnt(i,maxx));
        sub(res,cnt(i+1,maxx));
    }
    cout<< res;

}
int main()
{

    fastio();
    // inti();
    nhap();
}




