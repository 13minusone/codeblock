/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c9"
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
const ll N = 1e5 + 5;
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
int t,n;
int check[N];
ll a[N];
vector<ll>vec;
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;  i <= n ; i++)
        {
            cin >> a[i];
            if(a[i] <= n && check[a[i]] == 0)
            {
                check[a[i]]=1;
            }
            else vec.push_back(a[i]);
        }
        sort(all(vec));
        bool t=true;
        int j=0;
        for(int i = 1 ; i <= n ;i++)
        {
            if(!check[i])
                if(vec[j] <= 2*i)
                {
                    t=false;
                    break;
                }
                else j++;
        }
        if(!t)cout << -1 << endl;
        else cout << SZ(vec) << endl;
        memset(check,0,sizeof check);
        vec.clear();

    }
}
int main()
{

    fastio();
     inti();
    nhap();
}




