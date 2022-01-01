/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
#include<bits/stdc++.h>
using namespace std;
#define task "switchsign"
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
const ll maxsize = 100000;
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
ll n, m, sub;
ll a[5*maxsize+5],d;
char c;

void sub1()
{
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i<= m ; i++)
    {
        cin >> c >> d;
        if(c=='<')
        {
            for(int j = 1 ; j<= n ; j++)
            {
                if(a[j]<d)
                {
                    a[j]=-a[j];
                }
            }

        }
        else
        {
            for(int j = 1 ; j<= n ; j++)
            {
                if(a[j]>d)
                {
                    a[j]=-a[j];
                }
            }
        }
    }
    for(int i = 1 ; i<= n ; i++)
    {
        cout << a[i] << " ";
    }
}
void sub2()
{
    ll minn=-5;
    //cout << minn;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i<= m ; i++)
    {
        cin >> c >> d;
        minn=min(minn,d);
    }
    for(int i = 1 ; i<=n ; i++)
    {
        if(a[i]>minn)
        {
            a[i]=-a[i];
        }
        cout << a[i] << " " ;
    }
}
void nhap()
{
    cin >> sub;
    cin >> n >> m ;
    if(sub==1)
    {
        sub1();
        return;
    }
    if(sub==2)
    {
        sub2();
        return;
    }
    else
    {
        return;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



