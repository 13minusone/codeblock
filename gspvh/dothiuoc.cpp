#include<bits/stdc++.h>
using namespace std;
#define task "gcd-graph"
#define ll long long
#define SZ(c) c.size()
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
ll UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
ll n,m,k;
void in()
{
     cin >> n >> k >> m;
}
ll cha[maxsize+6],cnt=0;
bool t=true;
vector<ll>g[maxsize+2];
void dfs(int u)
{
    cha[u]=cnt;
    for(int c:g[u])
    {
        if(!cha[c])
        {
            dfs(c);
        }
    }
    return;
}
ll a[maxsize+5];

void nhap()
{
   in();
    for(int i = 1 ;i<=n;i++)
    {
        cin >> a[i];
        for(int j =i-1;j>=1;j--)
        {
            if(UCLN(a[j],a[i])>k)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    ll x,y;
    for(int i = 1;i<=m ;i++)
    {
        cin >> x>> y;
        if(k==1)
        {
            cout << "Y";
        }
        else
        {
            if(x==y)
            {
                cout << "Y";
            }
            else
            {
                if(!cha[x])
                {
                    cnt++;
                    dfs(x);
                }
                if(cha[x]==cha[y])cout << "Y";
                else cout << "N";
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



