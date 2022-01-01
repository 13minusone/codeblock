#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x[100001],a[100001];
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{
    int t=1;
    cin>>n>>m;
    fu(i,1,n,1)cin>>x[i];
    fu(i,1,m,1)cin>>a[i];
    int j=1;
    while(t<=n||j<=m)
    {
        if(t<=n&&j<=m)
        {
            if(x[t]<=a[j])
            {
                cout<<x[t]<<" ";
                t++;
            }
            else
            {
                cout<<a[j]<<" ";
                j++;
            }
        }
        else
        {
            if(j<=m)
            {
                fu(h,j,m,1){cout<<a[h]<<" "; j++;}
            }
            else
            {
                fu(h,t,n,1){cout<<x[h]<< " "; t++;}
            }
        }
    }
}
int main()
{
    IOS
//inti()
    nhap();

}

