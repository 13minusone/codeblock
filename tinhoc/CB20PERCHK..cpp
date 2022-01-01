#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000];
int main()
{
    unsigned long long s=0,g;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s=s+a[i];
    }
    g=((n+1)*n)/2;
    if(s!=g)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
}
