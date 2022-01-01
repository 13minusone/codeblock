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
int n,m,k;
unsigned ll s=0;
void nhap()
{
    cin >> n >> m >> k;
    fu(i,4,k-1,1)
    {
        //cout << i<<" " ;
        if(i>n)
        {
            break;
        }
        if(k-i>m)
        {

            continue;
        }

        unsigned ll r=n;
        fu(j,1,i-1,1)
        {
            r*=(n-j);
            r/=j;
        }
        r/=i;
        unsigned ll f=m;
        fu(j,1,k-i-1,1)
        {
            f*=(m-j);
            f=f/j;
        }
        f/=(k-i);
        //cout <<i << " "<< r << " " << f<<" " <<s<< endl;
        s=s+r*f;
    }
    cout << s;
}
int main()
{
    fastio();
    nhap();
}

