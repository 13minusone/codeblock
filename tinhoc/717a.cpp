#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x;
    int a[101];
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;
fu(k,1,n,1)
{
    cin>>x >> m;
    fu(j,1,x,1)
    {
       cin >> a[j];

    }
    int i=1;
     while(m!=0 && i<x)
    {
        while (a[i]!=0 && m!=0)
        {
            a[i]--;
            a[x]++;
            m--;
        }
        i++;
    }
    fu(j,1,x,1)
    {
        cout<<a[j] << " " ;
    }
    cout <<endl;
}
}
int main()
{
IOS
//inti()
nhap();

}

