#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x,z;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
bool solve()
{
    float res;
    res=float(max(m,x))/(min(m,x));
    if(abs(res-1)<=z)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void nhap()
{

cin>>n;
fu(i,1,n,1)
{
    cin >> m >> x >> z;
    if(solve())
    {
        cout << "YES" <<endl;
    }
    else
    {
        cout << "NO" <<endl;
    }
}
}
int main()
{
IOS
//inti()
nhap();

}

