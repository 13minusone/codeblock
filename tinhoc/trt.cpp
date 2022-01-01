#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  unsigned ll a,b;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>a>>b;
if(a-b==0)
{
    cout<<"YES"<<endl;
    return;
}
else
{
    if((b+a)%2==0)
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

