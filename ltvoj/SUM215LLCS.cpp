#include<bits/stdc++.h>
using namespace std;
#define task "SUM215LLCS"
#define ll long long
#define SZ(c) (int)c.size()
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
int f[100][100],minn=INT_MAX;
string in[100];
int  lcs(string s,string s1)
{
    int n=SZ(s);
    int m=SZ(s1);
    s=" "+s;
    s1=" "+s1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(s[i]==s1[j])
            {
                f[i][j]=f[i-1][j-1]+1;

            }
            else
            {
                f[i][j]=max(f[i][j-1],f[i-1][j]);
            }
            if(f[i][j]>=minn)
            {
                return INT_MAX;
            }
        }

    }
    return f[n][m];
}
void nhap()
{
    int t,n;
    string s,s1;
    cin >> t;
    while(t--)
    {
        minn=INT_MAX;
        cin >> n;
        for(int i = 1 ; i <= n ; i++)
        {
            cin >>in[i];
        }
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i+1 ; j <=n;j++)
            {
                minimize(minn,lcs(in[i],in[j]));
            }
        }
        cout << minn << endl;

    }
}
int main()
{

    fastio();
    inti();
    nhap();
}



