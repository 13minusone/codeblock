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
ll n,m,ke,x,a[maxsize],nho;
vector<ll>arr;
void inti()
{
    freopen("2105.inp","r",stdin);
    freopen("2105.out","w",stdout);
}
void nhap()
{
    cin >> n >> m >> ke;
    nho=ke;
    fu(i,1,n,1)
    {
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(),arr.end());
//    fu(i,0,n-1,1)
//    {
//        cout << arr[i] <<" ";
//    }
    fu(i,1,m,1)
    {
        cin >> a[i];
    }
    ll s=0;
    sort(a+1,a+m+1);
    m=min(n,m);
    fu(i,1,m,1)
    {
        ll k = lower_bound(arr.begin(),arr.end(),a[i])-arr.begin();
        cout << k  << endl;
        if(arr[k]==a[i])
        {
            arr[k]=0;
            s++;
        }
        else
        {
            ll u=arr[n-1];
            ll o=n-1;
            while(u==0)
            {
                o--;
                u=arr[o];
                if(o<0)
                {
                    cout << s << " " <<nho- ke ;
                    return;
                }
                //cout << u << endl;
            }

            if(u+ke>=a[i])
            {
                s++;
                ke=u+ke-a[i];
            }
            else
            {
                cout << s << " " <<nho- ke ;
                return ;
            }

        }
    }
    cout << s << " "  << nho-ke;
}
int main()
{
    fastio();
    inti();
    nhap();
}

