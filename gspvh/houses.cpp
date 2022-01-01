#include<bits/stdc++.h>
using namespace std;
#define task "houses"
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
void nhap()
{
    ll k,n,i=0;
    vector<int>a(11,0);
    cin >> k >> n;
    ll h=k;
    while(i<n)
    {

        k=h;
        while(k>0)
        {
            ll o=k%10;
            a[o]++;
            k/=10;
        }
        i++;
        h=h+2;
    }



    for(int i=0; i<=9; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}

