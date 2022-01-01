#include<bits/stdc++.h>
using namespace std;
#define task "SUM212BLACKHOLE"
#define ll long long
#define SZ(c) c.size()
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll maxsize = 1000000000;
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
ll a[105][105];
vector<ii>vec;
ll n,m,x,y;
ll l=-1000000001,r=-1000000001;
bool cmp(ii a,ii b)
{
    return a.second<b.second;
}
void nhap()
{

    cin >> n ;
    if(n>0)
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> x >> y;
            a[x][y]=1;
        }
    }
    cin >> m;
    for(int  i = 1 ; i <= m ; ++i)
    {
        cin >> x >> y;

        vec.push_back({x,y});
    }

    ll s=0;
    sort(vec.begin(),vec.end());

    l=vec[int((m+1)/2)].first;
    sort(vec.begin(),vec.end(),cmp);
    r=vec[int((m+1)/2)].second;
    //cout << l << " " << r;
    for(int i=0; i < m ; ++i)
    {
        s+=abs(r-vec[i].second)+abs(l-vec[i].first);
    }
    cout << s << endl;
}

int main()
{

    fastio();
    inti();
    nhap();
}


