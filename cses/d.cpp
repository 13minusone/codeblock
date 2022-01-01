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
vector<unsigned ll>a(73);
string d[73];
string doichu(ll n)
{
    string g;
    while(n>0)
    {
        int h=n%10;
        g=char(h+'0')+g;
        n/=10;
    }
    g=" "+g;
    return g;
}
ll solve(string s)
{
    ll minn=SZ(s);
    ll n=SZ(s)-1;
    for(int i = 1 ; i<= 63; i++)
    {
        ll h=SZ(d[i])-1;
        ll o=0,k=1;
        for(int j = 1 ; j <=h ; j++)
        {
            if(k>n)break;
            while(k<=n)
            {
                if(s[k]==d[i][j])
                {
                    o++;
                    k++;
                   // if(i==11)cout <<k <<" "<< j << endl;
                    break;
                }
                k++;
            }
        }
        //if(i==11)cout << o << endl;
        if(minn>n+h-2*o)
        {
            minn=n+h-2*o;
            //cout << i << " " << h  << " " << n << " "<< o<<" "<< minn <<  endl;
        }
    }
    return minn;

}
void nhap()
{
    int t;
    ll n;
    cin >> t;
    a[1]=1;
    d[1]=doichu(a[1]);
    for(int i = 2 ; i <= 63; i++)
    {
        a[i]=a[i-1]*2;
        d[i]=doichu(a[i]);
    }
    //cout << SZ(d[1]);
    while(t--)
    {
        cin >> n;
        string s;
        s=doichu(n);
        //cout << SZ(s) << endl;
        cout << solve(s) << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



