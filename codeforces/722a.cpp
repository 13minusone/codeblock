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
    ll  t,n,arr[105];
    cin >> t;
    fu(i,1,t,1)
    {
        cin >> n;

        fu(j,1,n,1)
        {
            cin >> arr[j];

        }
        sort(arr+1,arr+n+1);
//        fu(j,1,n,1)
//        {
//            cout << arr[j];
//        }
        ll  s=arr[1],su=0;
        fu(k,2,n,1)
        {
            if(arr[k]>s)
            {
                su++;
            }
        }
        cout << su << endl;;
    }
}
int main()
{
    fastio();
    nhap();
}

