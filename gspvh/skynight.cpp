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
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
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
template <class val>
inline bool getBit(val pos, val mask) { return ((mask >> pos) & 1); }

int r,c,m,n,a[5005][5005];
void nhap()
{
    string s;
    cin >> r >> c >> m >> n;
    memset(a,0,sizeof a);
    for (int i = 1; i <= r; i++)
    {
        cin >> s;
        int dem = 0;
        for(char x : s)
        {
            int num = 0;
            if ('0' <= x && x <= '9') num = x - '0';
            else if ('A' <= x && x <= 'Z')num = x - 'A' + 10;
            else if ('a' <= x && x <= 'z')num = x - 'a' + 36;
            else if (x == '#')num = 62;
            else num = 63;
            for (int j = 0; j <= 5 && dem <= c; j++)
            {
                a[i][++dem] = getbit(num, j);
            }
            if (dem > c)
                break;
        }
    }

    for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    int maxx = 0;
    for (int i = 1; i + m - 1 <= r; i++)
    for (int j = 1; j + n - 1 <= c; j++)
    {
    maxx = max(maxx, a[i + m - 1][j + n - 1] - a[i + m - 1][j - 1] - a[i - 1][j + n - 1] + a[i - 1][j - 1]);
    }
    cout << maxx ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



