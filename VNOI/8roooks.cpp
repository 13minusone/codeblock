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
int d[9],dsuf[9],dd[9];
int q,k;
ll minn;
void solve(int x)
{
    if(x==9)
    {
        ll sum=0;
        for(int i = 1; i <= 8 ; i++)
        {
            int h=10000;
            int x=(d[i]-dsuf[i]+8)%8;
            int y=(dsuf[i]-d[i]+8)%8;
            if(x%k==0){

                    x/=k;
            h=min(h,x);
            }
            if(y%k==0){
                    y/=k;
            h=min(h,y);
            }
            if(h==10000)return;
            sum+=h;
        }
        minn=min(minn,sum);
    }
    for(int i = 1; i <= 8 ; i++)
    {
        if(dd[i]==0)
        {
            dd[i]=1;
            dsuf[x]=i;
            solve(x+1);
            dsuf[x]=0;
            dd[i]=0;
        }
    }
}
void nhap()
{

    string n;
    cin >> q >> k;

    while(q--)
    {
        memset(d,0,sizeof d);
        memset(dsuf,0,sizeof dsuf);
        memset(dd,0,sizeof dd);
        minn =mod;
        cin >> n;
        for(int i = 0 ; i < 8 ; i++)
        {
            d[i+1]=int(n[i]-'0');
            //cout << d[i+1];
        }
        solve(1);
        if(minn==mod)cout << -1 << endl;
        else cout << minn << endl;
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}



