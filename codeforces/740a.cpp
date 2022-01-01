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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
int t,n,a[1005];
bool te;
void nhap()
{

    cin >> t;
    while(t--)
    {
        te =true;
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(a[i]>a[i+1])
            {
                te=false;
                break;
            }
        }
        if(te==true)
        {
            cout << "0" << endl;
        }
        else
        {
            for(int i = 1 ; i <= n ; i++)
            {
                if(i%2==0)
                {
                    for(int j = 2 ; j<=n-1; j+=2)
                    {
                        if(a[j]>a[j+1])
                        {
                            swap(a[j],a[j+1]);
                        }
                    }
                }
                else
                {
                    for(int j = 1 ; j<=n-2; j+=2)
                    {
                        if(a[j]>a[j+1])
                        {
                            swap(a[j],a[j+1]);
                        }
                    }
                }
                bool tr=true;
                for(int j = 1 ; j < n ; j++)
                {
                    if(a[j]>a[j+1])
                    {
                        tr=false;
                        break;
                    }
                }
                if(tr==true)
                {
                    cout << i << endl;
                    break;
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




