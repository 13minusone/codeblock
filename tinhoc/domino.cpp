#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x,t,k,p;
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{
    cin>>t;
    fu(i,1,t,1)
    {
        cin>>n>>m>>x;
        cin>>k>>p;
        int g=int(m+x);
        if(g>=k*2&&(n*2-g)>=2*p)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
int main()
{
    IOS
//inti()
    nhap();

}

