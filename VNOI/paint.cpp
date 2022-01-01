/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
#include<bits/stdc++.h>
using namespace std;
#define task "paint"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 1e9;
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
ii p[3];
void nhap()
{
    ll a,b,c,d,s=0;
    cin >> a >> b >> c >> d;
    //cout << a << " "<< b << " "<< c << d << endl;
    s=c+d;
    c=min(c,d);
    d=s-c;
    s=a+b;
    a=min(a,b);
    b=s-a;
    p[1].first=a;
    p[1].second=b;
    p[2].first=c;
    p[2].second=d;
    sort(p+1,p+3);
    a=p[1].first;
    b=p[1].second;
    c=p[2].first;
    d=p[2].second;
    if(c<=a)
    {
        cout << max(b,d)-c;
    }
    else if(d<=b)
    {
        cout << b-a << endl;
    }
    else if(c<=b)
    {
        cout << d-a << endl;
    }
    else
    {
        cout << b-a+d-c << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



