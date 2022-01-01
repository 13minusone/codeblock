#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 1000;
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
typedef pair<int,int> ii;
ll n,x,y,s=0;
pair<ll,ll>d[maxsize+6],f[maxsize+5][maxsize+5];
void nhap()
{
    cin >> n;
    fu(i,1,n,1)
    {
        cin >> x >> y;
        d[i].first=x;
        d[i].second=y;
    }
    fu(i,1,n,1)
    {
        fd(j,i-1,1,1)
        {
            ll o=d[i].first-d[j].first;
            ll o1=d[i].second-d[j].second;
            f[i][j]=ii(o,o1);
            f[j][i]=ii(o,o1);
        }
    }
    fu(i,1,n,1)
    {
        fu(j,i+1,n,1)
        {
            fu(k,1,n,1)
            {
                fu(e,k+1,n,1)
                {
                    if(f[k][e].first*f[i][j].first+f[i][j].second*f[k][e].second==0)
                    {
                        s++;
                    }
                }
            }
        }
    }
    cout << s/2;
}
int main()
{
    fastio();
    nhap();
}

