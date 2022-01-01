#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
ll  k =1000000007;
    int m,n,x;
    ll s=1;
    int a[100000];
void nhap()
{

cin>>n>>m;
fu(1,n,1)
{
    cin>>a[i];

}
}
int main()
{
nhap();
fu(1,n,1)
{
    if(a[i]==0)
    {
        if(max(a[i-1]-1,a[i+1]-1)<min(a[i-1]+1,a[i+1]+1))
        {
            s=s*(-max(max(a[i-1]-1,a[i+1]-1),0)+min(min(a[i-1]+1,a[i+1]+1),m)+1);
            s=s%k;
        }
    }
}
cout<<s%k;
}
