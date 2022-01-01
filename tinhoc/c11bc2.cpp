#include<bits/stdc++.h>
using namespace std;
#define task "c11bc2"
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
void ini()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
struct dsu
{
    vector<int>cha;
    void inti(int n)
    {
        cha.resize(n+5,0);
        for(int i = 1 ; i <= n ; i++)
        {
            cha[i]=i;
        }
    }
    int finding(int i)
    {
        if(cha[i]==i)
        {
            return i;
        }
        return cha[i]=finding(cha[i]);
    }
    void them(int v,int u)
    {
         v=finding(v),u=finding(u);
        if(u==v)return ;
        if(v<u)
        {
            cha[v]=u;
        }
        else
        {
            cha[u]=v;
        }
        return ;
    }
}dsu;
 ll  n,m,x,b,y;
void nhap()
{

     char loai;
    cin >> n >> m;
    dsu.inti(n);
    for(int i = 2 ; i <=n; i++)
    {
        cin >> x >> b;
        if(b==1)
        {
            dsu.them(x,i);
        }
        //cout << max(a,b) << min (a,b) << endl;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> x >> y;
        int d=dsu.finding(x),f=dsu.finding(y);
        if(d!=f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;      }

    }

}
int main()
{

    fastio();
    ini();
    nhap();
}






