#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x[2*2001];
vector<int>a[2*1000];
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{

    cin>>n>>m;
    fu(i,1,2*n,1)
    {
        cin>>x[i];
       fd(j,i-1,1,1)
       {
           int s = abs( x[i] - x[ j])
           if(s>=-m&&s<=d)
           {
               vec[j].push_back(i);
           }

       }
    }
    fu(i,1,)
}
int main()
{
    IOS
//inti()
    nhap();

}

