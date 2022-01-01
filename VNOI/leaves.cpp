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
int n, q ,a[N+5],cnt[N+5],maxx=0;
void solve()
{
        for(int i = maxx ; i >=1;i--)
        {
                if(cnt[i]%2==1){
                        cout << "NO" << endl;
                return;
                }
                cnt[i-1]+=(cnt[i]/2);
        }
        if(cnt[1]>2)cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
}
void nhap()
{
    cin >> q;
    while(q--)
    {
        memset(cnt,0,sizeof cnt);
        cin >> n;
        maxx=0;
        for(int  i = 1; i <= n ; i++){
                cin >> a[i];
                maxx=max(maxx,a[i]);
        cnt[a[i]]++;
        }
        solve();
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




