#include<bits/stdc++.h>
using namespace std;
#define SZ(c) (long long)c.size()
#define task "dhbb2110easytask"
typedef long long ll;
typedef pair<int,int> ii;
const ll maxsize =3000005;
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
vector<ll>vec;
ll a[maxsize+5],pre[maxsize+5],dd[maxsize+5];
int main()
{
    fastio();
    in();
    int n;
    cin >> n;
    for(ll i = 2 ; i<= n ; i++)
    {
        if(dd[i]==0)
        {
            vec.push_back(i);
            if(i*i<=n)
            {
                for(ll j = i*i ; j<=n; j+=i)
                {
                    dd[j]=1;
                }
            }
        }
    }
    pre[0]=0;
    ll maxx=-1e13-7;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];

    }
    memset(dd,0,n+20);


    //cout << maxx << endl;
    int l,r;
    ll minn =1e13+7;
    for(int i = 0 ; i < SZ(vec); i++)
    {
        l=vec[i];
        maxx=max(maxx,a[l]);
        minn=min(minn,pre[l-1]);
        maxx=max(maxx,pre[l]-minn);

    }
    cout << maxx << endl;
}
