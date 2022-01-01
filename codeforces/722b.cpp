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
    freopen("722b.inp","r",stdin);
    freopen("722b.out","w",stdout);
}
ll t,n,arr[maxsize+5];
void nhap()
{

    cin >> t;
    fu(k,1,t,1)
    {
        ll s1=0,minn=INT_MAX;
        cin >> n;
        fu(i,1,n,1)
        {
            cin >> arr[i];
            // cout << s1  << " ";
        }
        sort(arr+1,arr+1+n);
        fu(i,1,n,1)
        {
            if(arr[i]<=0)
            {
                s1++;
                minn = min(minn,abs(arr[i]-arr[i+1]));
            }
            else
            {
                if(arr[i]<=minn)
                {
                    s1++;
                }
                break;
            }
        }
        cout<<s1<<endl;
    }
}
int main()
{
    fastio();
    inti();
    nhap();
}

