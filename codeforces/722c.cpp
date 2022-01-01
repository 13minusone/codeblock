#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
ll t,n,x,y,a[maxsize],cha[maxsize+4],s=0;
pair<ll,ll>vec[maxsize+4];
vector<int>arr[maxsize+5];
void dfs(int u,int g)
{
    if(abs(vec[u].first-a[g])>abs(vec[u].second-a[g]))
    {
        s=s+abs(vec[u].first-a[g]);
        a[u]=vec[u].first;
    }
    else
    {
        s=s+abs(vec[u].second-a[g]);
        a[u]=vec[u].second;
    }
    fu(i,0,arr[u].size()-1,1)
    {
        int v=arr[u][i];
        if(cha[v]==0)
        {cha[v]=u;

        dfs(v,u);}

    }
}
void nhap()
{
    cin >> t;
    fu(o,1,t,1)
    {
        s=0;

        cin >> n;
        fu(i,1,n,1)
        {
            cin >> x >> y;
            vec[i].first=x;
            vec[i].second=y;
        }
        fu(i,1,n-1,1)
        {
            cin >> x >> y;
            arr[y].push_back(x);
            arr[x].push_back(y);
        }

 dfs(1,0);
    cout << s << endl;
      fu(i,1,n,1)
        {
            cout << a[i] << endl;
            arr[i].clear();
            vec[i].second=INT_MAX;
            vec[i].first=0;
            a[i]=0;
        }
    }


}
int main()
{
    fastio();
    nhap();
}

