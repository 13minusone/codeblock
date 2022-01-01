#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 200000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 ll a[maxsize+5];
    ll f[maxsize+5];
int tknp(int l, int r, int x)
{
    int res =0, mid;
    while(l <= r)
    {
        mid = (l + r)/2;
        if((a[mid] >= x)&&(!f[mid]))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    ll t;
    cin >> t;

    fu(k,1,t,1)
    {

        ll n,s=1000000000+10;
        cin >> n;

        fu(i,1,n,1)
        {
            cin >> a[i];
            f[i]=0;

        }
        sort(a+1,a+1+n);
        ll maxx=10000000000,l,r;
        fu(i,2,n,1)
        {
            if(a[i]-a[i-1]<maxx)
            {
                maxx=a[i]-a[i-1];
                l=i-1;
                r=i;
            }
        }
        vector<ll>vec;
        vec.push_back(a[l]);
        f[l]=1;
        f[r]=1;
        fu(i,1,n-2,1)
        {
            ll k=tknp(1,n,vec[i-1]);
            if(k!=0)
            {
               vec.push_back(a[k]);
               f[k]=1;
            }
            else
            {
                ll j=1;
                while(f[j]==1)
                {
                    j++;
                }
                vec.push_back(a[j]);
                f[j]=1;
            }
        }
        vec.push_back(a[r]);
        fu(i,0,n-1,1)
        {
            cout << vec[i] << " " ;
        }
        cout << endl;
    }
    }

int main()
{
    fastio();
    nhap();
}

