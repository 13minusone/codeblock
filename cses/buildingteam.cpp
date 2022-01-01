#include<bits/stdc++.h>
using namespace std;
#define task ""
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
vi a[100005];
int cha[100005],cnt=1;
bool tr=true;
void dfs(int u)
{
    for(int v:a[u])
    {
        if(cha[v]==0)
        {
            cha[v]=cha[u]+1;
            dfs(v);
        }
        else
        {
            if(cha[v]==cha[u]||cha[v]%2==cha[u]%2)
            {
                tr=false;
                return ;
            }
        }

    }
}
void nhap()
{
    int n,m,x,y,s=0;
    cin >> n >> m;
    for(int  i = 1 ; i <= m ; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1 ; i<=n ; i++)
    {
        if(cha[i]==0)
        {

            cha[i]=1;
            dfs(i);


        }
    }
    if(tr==true)
    {
        for(int i = 1 ; i<= n ; i++)
        {
            cout << (cha[i]+1)%2+1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




