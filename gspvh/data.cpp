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
const ll N = 1e4+5;
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
int x,a[N],n,dd[N],s=0;
void nhap()
{
    cin >> n >> x;
    for(int i = 1; i <= n ; i++)cin >> a[i];
    sort(a+1,a+1+n);
    int mid=n;
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i]>x/2)
        {
            mid=i-1;
            break;
        }
    }
    int r=mid+1;
    while(true)
    {
        if(mid==0||r==n+1)break;
        if(a[mid]+a[r]<=x)
        {
            s++;
            dd[mid]=1;
            dd[r]=1;
            r++;
            mid--;
        }
        else
        {
            mid--;
        }
    }
    vector<int>vec;
    for(int i = 1 ; i<= n ; i++)
    {
        if(dd[i]==0)vec.push_back(i);
    }
    int h=SZ(vec);
    for(int i = 0 ; i < h  ; i++)
    {
        if(i<h-1)
        {
            int z=vec[i];
            int y=vec[i+1];
            if(dd[z]==0&&dd[y]==0)
            {
                if(a[z]+a[y]<=x)
                {
                    dd[z]=1,dd[y]=1;
                    s++;
                }
                else
                {
                    dd[z]=1;
                    s++;
                }
            }
        }
        else
        {
            int y=vec[i];
            if(dd[y]==0)
            {
                s++;
            }
        }
    }
    cout << s;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




