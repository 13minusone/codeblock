#include<bits/stdc++.h>
using namespace std;
#define task "SUM213WORD"
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
map<string,ll>g;
map<string,ll>d;
string t,s1;
ll solve(string s)
{
    int n=SZ(s);
    if(g[s]>0)
    {
        return g[s];
    }
    if(n<=2)
    {
        return d[s];
    }

    for(int i = 0 ; i<n-1; i++)
    {
        s1="";
        t=s[i];
        t=t+s[i+1];
        if(d[t]!=0)
        {
            if(i>=1)
            {
                for(int j = 0 ; j<min(i,n); j++)
            {
                s1=s1+s[j];
            }
            }
            if(i<=n-3)
            {
                for(int j = i+2 ; j <n; j++)
            {
                s1=s1+s[j];
            }
            }

                g[s]=max(g[s],d[t]+solve(s1));

            //cout << t << endl;
        }
    }
    return g[s];
}

void nhap()
{
    string s,f;
    cin >> s;
    int n,h;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> f;
        cin >> h;
        int o=d[f];
        d[f]=max(o,h);
    }
    cout << solve(s)<< endl;
}
int main()
{

    fastio();
    inti();
    nhap();
}



