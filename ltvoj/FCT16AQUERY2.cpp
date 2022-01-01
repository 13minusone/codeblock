#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
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
    freopen("FCT16AQUERY2.inp","r",stdin);
    freopen("FCT16AQUERY2.out","w",stdout);
}

typedef pair<int,int> ii;

int main()
{
    fastio();
    inti();
    int n;
    cin >> n;

    vector<ii> a;
    a.resize(n);
    fu(i,0,n-1,1)
    {

            cin >> a[i].first>> a[i].second;
    }
    ll k;
    cin >> k;
    sort(a.begin(), a.end());
    ll sum = 0;
    fu(i, 0,n,1)
    {
        sum += a[i].second;
        if (sum >= k)
         {
            cout << a[i].first;
            break;
        }
    }
    return 0;
}
