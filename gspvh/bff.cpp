#include<bits/stdc++.h>
using namespace std;
#define task "bff"
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
pair<string,string> a[51];
void nhap()
{
    ll n;
    cin >> n;
    ll sum=0;
    string s ,t;
    for(int i = 1;i<=n;i++)
    {
        cin >> s >> t;
        a[i].first=s;
        a[i].second=t;
        for(int j=i-1;j>=1;j--)
        {
         if(a[j].first==t)
         {
             sum++;
         }
         if(a[j].second==s)
         {
             sum++;
         }
        }
    }
    cout << sum;
}
int main()
{

    fastio();
    inti();
    nhap();
}


