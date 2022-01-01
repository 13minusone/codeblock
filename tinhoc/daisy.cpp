#include<bits/stdc++.h>
using namespace std;
#define task "daisy"
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
    void check(int v , int u)
    {
         v=finding(v),u=finding(u);
        if(u==v)return ;
        if(v>u)
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
void nhap()
{
     ll  n,m,a,b;
    vector<int>vec;
    cin >> n >> m;
    vec.resize(0);
    dsu.inti(n);
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> a >> b;
        dsu.check(max(a,b),min(a,b));
        //cout << max(a,b) << min (a,b) << endl;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int d=dsu.finding(i);
        //cout << i <<" " << d << endl;
        if(d>1)
        {
            vec.push_back(i);
        }
        //cout << i << " " << dsu.cha[i] << endl;
    }
        if(vec.size()==0)
    {
        cout << 0 << endl;
        return;
    }
    for(int i = 0 ;i <SZ(vec);i++ )
    {
        cout << vec[i] << endl;
    }

}
int main()
{

    fastio();
    ini();
    nhap();
}



