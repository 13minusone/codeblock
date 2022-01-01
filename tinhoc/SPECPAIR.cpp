#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long n,a[100000],x,s=0,f=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x%11]++;
if(x<10)
{
    f++;

}
    }

    for(int i=1;i<=f;i++)
    {
        long long h=f;
        s=s+(h-i);
    }

    for(int i=1;i<=5;i++)
    {
        s=s+abs(a[i]*a[11-i]);
    }
    cout<<s;
}
