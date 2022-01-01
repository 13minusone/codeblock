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
bool tinh(int n, int m, int le, int ri, int v)
{
    int minn=max(0,le-n)+max(0,ri-m);
    int maxx=min(le,m)+min(ri,n);
    if (minn<=v && v<=maxx && abs(v-minn)%2==0)
    {
        return true;
    }
    return false;
}
bool check(int n, int m, int v)
{
    ll t=n+m, l=t/2, r=t-l;
    bool kt;
    kt=tinh(n,m,l,r,v);
    if (kt)
    {
        return true;
    }
    kt=tinh(n,m,r,l,v);
    if (kt)
    {
        return true;
    }
    return false;
}
int a, b;
void nhap()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        vector<int> vec;
        for (int i=0; i<= a+b; i++)
        {
            if (check(a,b,i))
            {
                vec.push_back(i);
            }
        }
        cout << vec.size() << endl;
        for(int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main()
{
    fastio();
    nhap();
}
