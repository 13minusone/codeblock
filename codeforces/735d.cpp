#include<bits/stdc++.h>
using namespace std;
#define task "select"
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
const ll maximum=1500000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int n, t;
bool kt(int x)
{
    return x<=3;
}
void nhap()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
    int res=n;
    if (kt(n))
    {
        for (int i=0;i<n; i++)
        {
            cout << char('f'+i);
        }
        cout << endl;
        continue;
    }
    for(int i=1;i<=n/2;++i)
    {
        res--;
        cout << 'f';
    }
    cout << 'e';
    res--;
    if (n%2==1)
    {
        if (res>0)
        {
            res--;
            cout << 'b';
        }
    }
    for (int i=1; i<=res; i++)
    {
        cout << 'f';
    }
    cout << endl;
    }
}
int main()
{
    fastio();
    nhap();
}
