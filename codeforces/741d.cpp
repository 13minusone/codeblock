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
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
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
int t,n,q;
char c,a[3*maxsize+5];
ll d[3*maxsize+5],x,y;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        d[0]=0;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> c;
            a[i]=c;
            //cout << c << endl;
            if(c=='+')
            {
                d[i]=d[i-1]+((i%2==0)?-1:1)*1;
            }
            else
            {
                d[i]=d[i-1]-((i%2==0)?-1:1)*1;
            }
            //cout << d[i] << " "<<c << endl; ;
        }
        //cout << d[n] << endl;
        while(q--)
        {
            cin >> x >> y;
            ll s;
           s=d[y]-d[x-1];
            if(s==0){
                    cout << 0 << endl;
            continue;
            }
            if((y-x+1)&1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
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




