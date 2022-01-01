#include<bits/stdc++.h>
using namespace std;
#define SZ(c) (long long)c.size()
#define task "c"
typedef long long ll;
typedef pair<int,int> ii;
const ll maxsize =1000005;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void in()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<int>vec;
ll a[maxsize+5],pre[maxsize+5],dd[maxsize+5];
int main()
{
    fastio();
    //in();
    int n;
    cin >> n;
    pre[0]=0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    memset(dd,0,n+20);
    for(ll i = 2 ; i<= n ; i++)
    {
        if(dd[i]==0)
        {
            vec.push_back(i);
            for(ll j = i*i ; j<=n;j+=i)
            {
                dd[j]=1;
            }
        }
    }
    ll maxx=-1e13-7;
    //cout << maxx << endl;
    int l,r;
    for(int i = 0 ; i < SZ(vec);i++)
    {
        l=vec[i];
        maxx=max(maxx,pre[l]-pre[l-1]);
        for(int j = i+1 ; j < SZ(vec) ; j++)
        {
            r=vec[j];
            //cout << vec[j] << " "<< vec[i] << endl;
            maxx=max(maxx,pre[r]-pre[l-1]);
        }
    }
    cout << maxx << endl;
}
