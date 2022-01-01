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
ll f[10004],a[10004],dd[10004];
int t,n;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        vll vec;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            vec.push_back(a[i]);
        }
        sort(all(vec));
        vec.resize(unique(all(vec))-vec.begin());
        f[0]=0;
        memset(dd,0,sizeof dd);
        ll res=0;
        for(int i = 1 ; i <= n ; i++)
        {
            a[i]=lower_bound(all(vec),a[i])-vec.begin();

            f[i]=f[i-1]+dd[a[i]];
            //cout << a[i] << " "<<dd[a[i]] << " "<< f[i] << endl;
            res+=f[i];
           dd[a[i]]+=i;
        }
        cout <<res << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}





