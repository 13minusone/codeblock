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
ll pre[20];
void nhap()
{
    pre[0]=1;
    for(int i = 1 ; i <= 18 ; i++)pre[i]=pre[i-1]*10;
    int q,a,b,c,d;
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> c >> d;
        ll s1=a*pre[b];
        ll s2=c*pre[d];
        if(s1>s2)cout << "X > Y" << endl;
        else if(s1<s2) cout << "X < Y"  << endl;
        else cout << "X = Y" << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



