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
#define task "c2"
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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
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
ll hi[55],a[55],maxx[55];
vector<int>vec[55];
vector<ll>c;
vector<ll>canh[55];
void dfs(int u,int v)
{
    //maxx[u]=0;
    for(int i :vec[u])
    {
        if(i==v)continue;
        dfs(i,u);
        if(hi[i]>maxx[u])
        {
            canh[u].push_back(maxx[u]);
            maxx[u]=hi[i];
        }
        else
        {
            canh[u].push_back(hi[i]);
        }
    }
    sort(all(canh[u]),greater<ll>());
    if(u!=1)
    {
        if(SZ(canh[u])>=1)
        {
            for(int i = 1 ; i <SZ(canh[u]); i+=2)
            {
                c.push_back(canh[u][i-1]+canh[u][i]);
            }

            if(SZ(canh[u])%2==1)
            {
                c.push_back(canh[u][SZ(canh[u])-1]);
            }
        }
    }
    else
    {
        if(SZ(canh[1])>=1)
        {
            for(int i = 2 ; i <vec[1].size(); i+=2)
            {
                c.push_back(canh[u][i-1]+canh[u][i]);
            }
            if(SZ(canh[u])%2==1)
            {
                c.push_back(canh[u][SZ(canh[u])-1]);
            }
        }
    }
    if(maxx[u]==-1)
    {
        maxx[u]=0;
    }
    hi[u]=a[u]+maxx[u];
    //cout << u << " "<<maxx[u] << " "<< hi[u] << endl;

}
int x,y,k;
int n;

void nhap()
{
    int t;
    cin>>t;
    for(int p=1; p<= t; p++)
    {

        cin >> n >> k;
        ll k1=k;
        c.clear();
        for(int i = 1 ; i <= n ; i++)
        {
            vec[i].clear();
            hi[i]=0;
            maxx[i]=0;
            canh[i].clear();
            cin >> a[i];
        }
        for(int i = 1 ; i < n ; i++)
        {
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        dfs(1,-1);
        ll s=0;

        if(n==1)
        {
            cout <<"Case #"<<p <<": "<< hi[1] <<endl;
            continue;
        }
        //c.push_back(maxx[1]);
        sort(all(c),greater<ll>());
        //cout << vec[1].size() << endl;
        //cout <<maxx[1] << " "<< c[0] << " "<< c[1] << " "<< c[2] << endl;
        s=maxx[1];
        if(k==1)
        {
            if(vec[1].size()>=2)
            {
                //cout << c[1] << endl;
                s=s+canh[1][0]+a[1];
            }
            else
            {
                s+=a[1];
            }
        }
        else
        {
            if(k==0)
            {
                s=a[1];
            }
            else
            {
                for(int i = 0 ; i <SZ(c); i++)
                {
                    if(k<=1)
                    {
                        //cout << s << endl;
                        s+=a[1];
                        if(vec[1].size()>1)
                        {
                            s+=canh[1][0];
                        }
                        break;
                    }
                    s+=c[i];
                    k--;

                }
                if(k>1)
                {
                    s+=a[1];
                }
            }
        }
        cout <<"Case #"<<p <<": "<< s <<endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}






