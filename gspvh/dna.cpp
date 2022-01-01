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
const ll maxsize = 1000000;
string s, t;
int f[54][54];
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}
 void nhap()
 {
      cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0)
            {
                f[i][j] = j;
                continue;
            }
            if(j == 0)
            {
             f[i][j] = i;
             continue;
            }
            if(s[i - 1] == t[j - 1])
                {
                    f[i][j] = f[i - 1][j - 1];
                    continue;
                }
            f[i][j] = min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1])) + 1;

        }
    }

    if(f[n][m]<=2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
 }
int main()
{
    fastio();
//    inti();
    nhap();
}
