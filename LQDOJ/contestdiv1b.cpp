#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fu(i,a,b,c) for(ll  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(ll i = a ; i >=b ;i-=c)
#define SZ(x) (int)((x).size())
const ll maxsize = 200000;
const unsigned ll mod=1000000007;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
unsigned ll d[maxsize+4],k[maxsize+4];
unsigned ll  s=0;
map<unsigned ll,unsigned ll>f;
vector<unsigned ll>vec;
void nhap()
{
    ll n;
    cin >> n;
    fu(i,1,n,1)
    {
        cin >> d[i];
        f[d[i]]++;
        if(f[d[i]]==2)
        {
            vec.push_back(d[i]);
        }
    }
    ll g=SZ(vec);

    fu(i,0,g-1,1)
    {
        //cout << vec[i] << endl;
       unsigned  ll eq=f[vec[i]];
        unsigned ll e=eq*(eq-1)/2;
        unsigned ll ed=eq*(eq-1)*(eq-2)*(eq-3);
        ed=ed/24;
        ed%=mod;
        e%=mod;
        s=s+ed;
        s%=mod;
        k[i]=e;
        fd(j,i-1,0,1)
        {
            s+=(k[i]*k[j])%mod;
            s%=mod;

        }
    }
    cout << s;

}
int main()
{
    fastio();
    nhap();
}

