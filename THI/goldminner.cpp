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
template<class X, class Y>
bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}
template<class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
const ll N = 1e5 + 5;
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
string s;
int k;
string h,minn;
int dx[5]={-2,2};
void nhap()
{
    cin >> s;
    cin >> k;
    int n=SZ(s);
    s=" "+s;
    for(int j = 1 ; j <= n; j++)
    {
        int l=j;
        h=s[j];
        for(int i = 1 ; i < k ; i++)
        {
            int maxx=10000;
            int o=0;
            for(int p = 0 ; p<= 3;p++)
            {
                if(l+dx[p] >= 1 && l+dx[p] <= n)
                {
                    if(int(s[l+dx[p]]-'a')<=maxx)
                    {
                        maxx=int(s[l+dx[p]]-'a');
                        o=p;
                    }
                }

            }

            h+=s[l+dx[o]];
            l=l+dx[o];

        }
        if(j == 1 )minn=h;
        else minn=min(minn,h);
    }
    cout << minn;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




