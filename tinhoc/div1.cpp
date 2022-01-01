#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

unsigned ll maxx=1000000000000000000;
vector<unsigned ll>vec;
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
unsigned ll n ;
void nhap()
{
    int t;
    for(unsigned ll i  = 2050; i<=maxx; i*=10)
    {
        vec.push_back(i);
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        unsigned ll sum=0;
        if(n<2050||n%2050!=0)
        {
            cout << "-1 " <<endl;
            continue;
        }
        while(n>0)
        {
            ll k =upper_bound(vec.begin(),vec.end(),n)-vec.begin();
            unsigned ll f=vec[k-1];
           // cout << f <<endl;
            unsigned ll r=n/f;
            sum+=r;
            n=n%f;
        }

cout << sum <<endl;
    }
}
int main()
{
    IOS
//inti()
    nhap();

}

