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
const ll N = 1e5;
const ll mod =1e9+7;
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
ll nvu[355][355];
void add(ll &a ,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void minusone(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
ll chap[355][355];
void nhap()
{
    int numdev;
    cin >> numdev;
    chap[1][1]=1;chap[0][0]=1;
    chap[1][0]=1;
    ll s=numdev;
    for(int j = 2 ; j <= numdev; j++){
            chap[j][j]=1;chap[j][0]=1;
            s*=numdev;
            if(s>=mod)s%=mod;
    for(int k = 1; k < j ;k++)
    {
        add(chap[j][k],chap[j-1][k]);
        add(chap[j][k],chap[j-1][k-1]);
    }
    }
    memset(nvu,0,sizeof nvu);
    nvu[0][0]=1;
    for(int i = 1 ; i <= numdev ; i++)
    for(int j = 0 ; j <= numdev ; j++)
    for(int k = 0 ; k <= j ; k++)
        if(k!=i)
        {
            add(nvu[i][j],((chap[j][k]%mod)*(nvu[i-1][j-k]%mod))%mod);
        }
    minusone(s,nvu[numdev][numdev]);
    cout <<  s;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




