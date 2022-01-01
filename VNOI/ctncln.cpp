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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
ll a[40005],f[40005],cnt[40005],vtri[205][40005];
void nhap()
{
    int n,t;
    cin >> n >> t;
    for(int i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        f[i]=mod;
    }
    f[0]=0;
memset(vtri,0,sizeof vtri);
    for(int i = 1 ; i*i<=t ; i++)
    {
        ll j=1,diff=0;
        memset(cnt,0,sizeof cnt);
        for(int k = 1 ; k <= n ; k++)
        {
            if(cnt[a[k]]==0)diff++;
            cnt[a[k]]++;
            while(diff>i)
            {
                    cnt[a[j]]--;
                    if(cnt[a[j]]==0)diff--;
                    j++;
            }
            vtri[i][k]=j;

        }
    }
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i*i <= t ; i++)
        {
            if(!vtri[i][k])continue;
            f[k]=min(f[k],f[vtri[i][k]-1]+i*i);
            //cout << f[i] << " " << i << endl;
        }
    }
    cout << f[n] ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




