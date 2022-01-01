#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 50000;
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
ll n,y,dem=0;
vector<ll>vec[maxsize+1];
void nhap()
{
    cin >> n;
    fu(i,1,n,1)
    {

        fu(j,1,5,1)
        {
            cin >> y;
            vec[i].push_back(y);


        }
        fd(g,i-1,1,1)
        {
            ll s=0;
            fu(j,1,5,1)
            {
                ll x=vec[i][j];
                ll k=lower_bound(vec[g].begin(),vec[g].end(),x)-vec[g].begin();
                if(vec[g][k]==x)
                {
                    s++;
                    break;
                }
            }
            if(s==0)
            {
                dem++;
            }
        }
        sort(vec[i].begin(),vec[i].end());

    }
    cout << dem;
}

int main()
{
    fastio();
    nhap();
}

