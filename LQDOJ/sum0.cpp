#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxsize = 100000;
map<ll,int>d;
void nhap()
{
    ll n,a[2*maxsize+5];
    cin >> n;
    for(int i = 1 ;i<=n;++i)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    ll s=0;
    for(int i = 1 ;i<=n;i++)
    {
        if(a[i]==0)
        {
            s=s+d[a[i]]-1;
        }
        else
        {
            s+=d[0-a[i]];
        }

    }
    s/=2;
    cout<<s << endl;
}
int main()
{
    nhap();
}


