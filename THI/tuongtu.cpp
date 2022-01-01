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
#define task "tuongtu"
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
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
const ll N = 1e6 + 5;
const ll mod =1e9+9;
const ll base = 311;
const int block = 488;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
        if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
string s;
int sum[N],cnt[N],l,n,r;
bool check(int x)
{
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i <= n-x+1;i++)
    {
        cnt[sum[i+x-1]-sum[i-1]]++;
        if(cnt[sum[i+x-1]-sum[i-1]] ==2)return true;
    }
    return false;
}
vector<int>vec[N];
void nhap()
{
    cin >> s;
     l=1,r=SZ(s),n=SZ(s);
    for(int i = 0;i < r; i++)
    {
        if(s[i] == '1')sum[i+1]=sum[i]+1;
        else sum[i+1]=sum[i];
    }
    int mid,res=0;
    while(l <= r)
    {
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
                l=mid+1;
        }
        else r=mid-1;
    }
    //cout << res;
    memset(cnt,0,sizeof cnt);
    for(int i = 1 ; i <=n-res+1;i++)
    {
        int x=sum[i+res-1]-sum[i-1];
        vec[x].push_back(i);
        cnt[x]++;
        if(cnt[x] == 2)
        {
            cout << vec[x][0] << " "<< vec[x][0]+res-1 << " " << vec[x][1] << " "<< vec[x][1] + res-1;
            break;
        }
    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




