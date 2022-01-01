#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x,d[100001];
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{
    int t;
    cin>>t;
    fu(j,1,t,1)
    {
        ll s=0;
        cin>>n>>m;
        fu(i,1,n,1)
        {
            cin>>x;
            d[x%m]++;
        }
        if(d[0]>0)
        {
            s++;
        }

        fu(i,1,m-1,1)
        {
            if(d[i]>0)
            {

                if(abs(d[i]-d[m-i])<=1)
                {
                    s=s+1;
                }
                else
                {
                    s=s+abs(d[i]-d[m-i]);
                }
                d[i]=0;
                d[m-i]=0;
            }

            }
        cout<<s<<endl;
    }

}
int main()
{
    IOS
//inti()
    nhap();

}

