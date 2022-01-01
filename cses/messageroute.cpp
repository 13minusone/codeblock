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
vi a[maxsize+5];
int cha[maxsize+5];
int n,m,x,y;
void solve()
{
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int g=q.front();
        if(g==n)
        {
            vi o;
            while(g!=1)
            {
                o.push_back(g);
                g=cha[g];
            }
            cout << o.size()+1 << endl;
            cout << 1 <<" ";
            for(int i = (int)o.size()-1;i>=0;i--)
            {
                cout << o[i] << " ";
            }
            return ;
        }
        for(int v :a[g])
        {
            if(cha[v]==0)
            {
                cha[v]=g;
                q.push(v);
            }
        }
        q.pop();
    }
    cout << "IMPOSSIBLE" << endl;

}
void nhap()
{

    cin >> n >> m;
    for(int  i = 1 ;i <= m ; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve();
}
int main()
{

    fastio();
    // inti();
    nhap();
}



