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
const ll N = 31400 + 5;
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
int n,u,v,f,g;
struct edge
{
    ll x1,y1,x2,y2,s;
    edge(int _x = 0, int _y = 0, int _a = 0, int _b=0)
    {
        x1=_x;
        y1=_y;
        x2=_a;
        y2=_b;
        s=abs(x2-x1)*abs(y1-y2);
    }

};
vector<edge>vec;
vector<edge>canh;
bool cmp(edge a,edge b)
{
    if(a.y1 == b.y1)return a.x1 < b.x1;
    else return a.y1 < b.y1;
}
bool check(ll p)
{
    int check1=canh[0].x1+p;
    int check2=canh[0].y1+p;
    for(edge v : canh)
    {
        if(v.x2 >check1 || v.y2 > check2 || v.x1 < canh[0].x1 || v.y1 < canh[0].y1)return false;
    }
    return true;
}
void nhap()
{
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> u >> v >> f >> g;
        vec.push_back(edge(u,v,f,g));
    }
    int k = mu2(n);
    for(int i = 1 ; i < k; i++)
    {
        ll s=0;

        for(int  j = 0 ; j < n ; j++)
        {
            if(getbit(i,j)==1)
            {
                s+=vec[j].s;
                canh.push_back(vec[j]);
            }
        }
        ll p=sqrt(s);
        sort(all(canh),cmp);
        if(p*p == s && SZ(canh)>1)
        {
            if(check(p)==true)
            {
                cout << "YES";
                return;
            }
            else
            {
                canh.clear();
            }

        }
        else
        {
            canh.clear();
        }
    }
    cout << "NO";
}
int main()
{
    fastio();
    // inti();
    nhap();
}

 
