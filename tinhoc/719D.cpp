#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
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
 map<ll,ll>d;
void nhap()
{
    int t,n,x;
    cin >> t;
    fu(k,1,t,1)
    {
        cin >> n;

        fu(j,1,n,1)
        {
            cin >> x;

                d[x-j]++;

        }
        ll s=0;
        fu(i,-n,n,1)
        {
            if(d[i]>1)
            {
                if(d[i]%2==0)
                {
                    s=s+d[i]-1+(d[i]-1)*((d[i]-1)/2);
                }
                else
                {
                    s=s+(d[i])*((d[i]-1)/2);
                }
            }
            d[i]=0;
        }
        cout << s <<endl;;
    }
}
int main()
{
    fastio();
    //inti();
    nhap();
}
