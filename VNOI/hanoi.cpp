/*
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE A.K.A PVM
*/
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
char a[1006][1005];
void nhap()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='.')
            {
                vec[i].push_back(j);
            }
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


