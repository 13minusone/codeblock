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
    freopen("matrix1297.inp","r",stdin);
    freopen("matrix1297.out","w",stdout);
}
ll f[205][205],d[205][205],c[205][205];
void nhap()
{
    ll m,n,p;
    cin >> m >> n >> p;
    fu(i,1,m,1)
    {
        fu(j,1,n,1)
        {
            cin >> f[i][j];
        }
    }
    fu(i,1,n,1)
    {
        fu(j,1,p,1)
        {
            cin >> d[i][j];
        }
    }
    fu(i,1,m,1)
    {
        fu(j,1,p,1)
        {
            fu(k,1,n,1)
            {
                c[i][j]+=(f[i][k]*d[k][j]);
            }
        }
    }
    fu(i,1,m,1)
    {
        fu(j,1,p,1)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    fastio();
    inti();
    nhap();
}

