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
#define task "volleyball"
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
void nhap()
{
    int n,k,x,y;
    cin >> n;
    while(n--)
    {
        cin >> k >> x >> y;
        int s=abs(x-y);
        if(s>=2)
        {
            if(max(x,y)>=k)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << k-max(x,y) << " ";
            }
        }
        else
        {
            if(max(x,y)+1>=k)
            {
                if(s+1>=2)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            else
            {
                cout << k-max(x,y) << " ";
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




