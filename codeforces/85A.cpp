#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;
int le=0,chan=0,vl,vc;
fu(i,1,n,1)
{
    cin>>x;
    if(x&1)
    {
        chan++;
        vc=i;
    }
    else
    {
        le++;
        vl=i;
    }
}
if(le==1)
{
    cout << vl;
}
else
{
    cout <<vc;
}
}
int main()
{
IOS
//inti()
nhap();

}

