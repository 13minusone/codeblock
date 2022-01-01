#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[2005];
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{
cin >> n;
fu(i,1,n,1)
{
    int s;
    cin >> m;
    cin >> x[1];
    s=x[1];
    fu(j,2,m,1)
    {
        cin >> x[i];
        s=s^x[i];
        //cout << s <<endl;
    }
    if(s==0)
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

