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
#define task "a2round2"
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
const ll N = 8e5;
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
ll pos[N+5];
void nhap()
{
    int t,n;
    string s;
    cin >> t;
    for(int p = 1 ; p <= t ; p++)
    {
        cin>> n;
        cin >> s;
        memset(pos,0,sizeof pos);
        ll vt=0;
        char vtpos=s[0];
        for(int i = 1 ; i < n ; i++)
        {
            if(s[i]=='F' || vtpos == s[i] || vtpos=='F'){
                pos[i]=pos[i-1];
                if(s[i]!='F'){
                    vtpos=s[i];
                    vt=i;
                }
                continue;
            }
            ll sum=0;
            sum=(sum+vt)%mod;
            sum=(sum+pos[vt]+1)%mod;
            pos[i]=(pos[i]+sum)%mod;
            vtpos=s[i];
            vt=i;
        }
        ll su=0;
        for(int i = 0 ; i < n ; i++)su=(su+pos[i])%mod;
        cout <<"Case #"<<p<<": "<< su << endl;

    }
}
int main()
{

    fastio();
    inti();
    nhap();
}




