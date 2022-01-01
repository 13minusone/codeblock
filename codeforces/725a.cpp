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
    ll q,n,a[105];
    cin >> q;
    fu(k,1,q,1)
    {
        cin >> n;
        ll maxx=0,minn=1111,u,t;
        fu(i,1,n,1)
        {
            cin >> a[i];
            if(a[i]<minn)
            {
                minn=a[i];
                u=i;
            }
            if(a[i]>maxx)
            {
                maxx=a[i];
                t=i;

            }
        }
        ll mid=n/2;
        cout << min(min(max(u,t),n-min(u,t)+1),min(u,t)+n-max(u,t)+1)<<endl;

    }
}
int main()
{
    fastio();
    nhap();
}

