#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 1000000000;
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
unsigned ll f[101][101],d[101][101];
void nhap()
{
    ll n,m;
    cin >> m >> n;
    fu(i,1,m,1)
    {
        fu(j,1,n,1)
        {
            cin >> d[i][j];
        }
    }
    fu(i,1,m,1)
    {
        f[i][1]=1;
    }
    fu(i,1,m,1)
    {
        fu(j,1,n-1,1)
        {

            fu(k,i,m,1)
            {
                fu(o,j,n,1)
                {

                    if(i+j<o+k)
                    {
                         //cout <<i << " " << j <<  k << " " << o << endl;
                        if(__gcd(d[i][j],d[k][o])>1)
                        {
                            f[k][o]+=f[i][j];
                            f[k][o]%=maxsize;
                        }
                    }
                }
            }
        }
    }
    unsigned ll s=0;
    fu(i,1,m,1)
    {
        s+=f[i][n];
        s%=maxsize;
    }
    cout << s << endl;
}
int main()
{
    fastio();
    nhap();
}

