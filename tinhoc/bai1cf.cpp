#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[10001];
    ll s=1;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
bool  solve()
{
    fu(j,1,m,1)
    {

        int g=sqrt(x[j]);
       if(g*g!=x[j])
       {
         return false;

       }
    }
    return true;
}
void nhap()
{

cin>>n;
 int t=0;
fu(i,1,n,1)
{
    cin >> m;


    fu(j,1,m,1)
    {
        cin >> x[j];


    }
    if(solve()==true)
    {
        cout << "NO" <<endl;
    }
    else
    {
        cout << "YES" <<endl;
    }

}
}
int main()
{
IOS
//inti()
nhap();

}

