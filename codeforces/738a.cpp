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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
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
int n,t;
ll a[105];
void nhap()
{
    cin >> t;
    int k=11&7;
    cout << k << endl;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i<=n ; i++)
        {
            cin >> a[i];
        }
        for(int i = 1 ; i<= n;i++)
        {

        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


