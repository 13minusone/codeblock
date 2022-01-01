/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
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
const ll maxsize = 1000000;
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
ii a[maxsize+5];
int check(int x,int y,int l,int r)
{
    if(x==l||y==r)
    {
        return 0;
    }
    if(l>x)
    {
        if(y<r)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        if(y<r)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
}
void nhap()
{
    int n;
    cin >> n;
    for(int i = 1 ; i<=n ; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    if(n>100)return;
    ll s[6],maxx=0,l,r,cnt=1000000;
    for(int i = 1 ; i <= n ; i++)
    {
        ll x=a[i].first ;
        for(int j = i + 1 ; j<= n ; j++)
        {
            ll y=a[j].second;
            maxx=0;
            for(int p = 0 ; p<= 4 ; p++)
            {
                s[p]=0;
            }
            for(int k = 1 ; k <= n ; k++)
            {
                s[check(x,y,a[k].first,a[k].second)]++;
            }
            for(int p = 1 ; p<= 4 ; p++)
            {
                maxx=max(maxx,s[p]);
            }
            if(maxx<cnt)
            {
                l=x;
                r=y;
                cnt=maxx;

            }
        }

    }
    cout << cnt << " " << l<< " "<<r<< endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



