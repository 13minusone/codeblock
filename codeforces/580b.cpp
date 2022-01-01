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
void nhap()
{
    ll n ,d;
    vector<pair<ll,ll>>vec;
    cin >> n >> d;
    fu(i,1,n,1)
    {
        ll x,y;
        cin >> x >> y ;
        vec.push_back({x,y});

    }
    unsigned ll maxx=0;
    sort(vec.begin(),vec.end());
    ll j=1;
    unsigned ll s=vec[0].second;
    fu(i,0,n-1,1)
    {
        //cout << vec[i].first << " " << vec[i].second << endl;


        while(j<n&&vec[j].first<vec[i].first+d)
        {
            s+=vec[j].second;
            j++;
        }
        maxx=max(maxx,s);
        s=s-vec[i].second;
    }
    cout << maxx;
}
int main()
{
    fastio();
    nhap();
}

