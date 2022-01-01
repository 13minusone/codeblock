#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,a[101],b[101];
ll t;
void inti()
{
    freopen("alexey.inp","r",stdin);
    freopen("alexey.out","w",stdout);
}
void nhap()
{

    cin>>n;
    fu(j,1,n,1)
    {
        ll s=0;
        cin>>m;
        a[0]=0;
        b[0]=0;
        fu(i,1,m,1)cin>>a[i]>>b[i];

        fu(i,1,m,1)
        {
           // cout<<a[i]<< " "<<b[i]<<endl;
            cin>>t;
            s=s+a[i]-b[i-1]+t;

            if(i<m)
            {
                //cout<<b[i]-a[i]<<endl;
                if((b[i]-a[i])%2==0)
                {
                    s=s+(b[i]-a[i])/2;
                }
                else
                {

                    s=s+((b[i]-a[i])/2+1);
                }
                if(s<b[i])
                {
                    s=b[i];
                }
            }


        }
cout<<s<<endl;
    }
}
int main()
{
    IOS
    //inti();
    nhap();

}

