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
vector<int>vec;
int a[2*N+5],dd[2*N+5];
map<ll,int>check;
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    ll s=2;
    for(int i = 1 ; i <= 4; i++)
    {
        check[s]=i;
        s=s*s;

    }
    for(int i = 1 ; i <= n ; i++)
    {
        memset(dd,0,sizeof dd);
        set<ll>luu;
        for(int j = i +1 ; j <= n ; j++)
        {
            luu.insert(a[j]);
            dd[a[j]]++;
            for(int v: luu)
            {
                if(check[dd[i]]==0)
                {
                    break;
                }
                else
                {
                    dd[i+1]
                }
            }
        }
    }

}
int main()
{

    fastio();
    // inti();
    nhap();
}




