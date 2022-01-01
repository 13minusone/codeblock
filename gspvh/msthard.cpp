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
const ll maxsize = 500000;
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
struct node
{
    int x,y,z,id;
}a[maxsize+5];
int cha[maxsize+5];
struct Dsu
{
    ll root(int i)
    {
        if(cha[i]==i)
        {
            return i;
        }
        else
        {
            return cha[i]=root(cha[i]);
        }
    }
    bool join(int u,int v)
    {
        u=root(u),v=root(v);
        if(u==v)return true;
        cha[v]=u;
        return false;
    }
}dsu;
vector<node>vec;
bool cmp(node a,node b)
{
    return a.z<b.z;
}
ll kt[maxsize+5];
void sol(vector<node> &vec)
{
    if(vec.empty())return;
    for(int i = 0 ; i<SZ(vec);i++)
    {
        vec[i].x=dsu.root(vec[i].x);
        vec[i].y=dsu.root(vec[i].y);
        if(vec[i].x==vec[i].y)
        {
            kt[vec[i].id]=1;
        }
        else
        {
            kt[vec[i].id]=2;
        }
    }
    for(int i = 0 ; i < SZ(vec);i++)
    {
            dsu.join(vec[i].x,vec[i].y);
    }
    vec.clear();
}
int n,m,t;
void nhap()
{
    cin>>t;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cha[i]=i;
    }
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z ;
         a[i].id=i;
    }
    sort(a+1,a+1+m,cmp);
    for(int i = 1 ; i <= m ; i++)
    {
        if(!vec.empty()&&vec.back().z==a[i].z)
        {
            vec.push_back(a[i]);
        }
        else
        {
            sol(vec);
            vec.push_back(a[i]);
        }

    }
    sol(vec);
    for(int i = 1 ; i <= m ; i++)
    {
        //cout << i << " " << kt[i] << endl;
        if(kt[i]==1)cout << "No" << " ";
        if(kt[i]==2)cout << "Yes" << " ";
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




