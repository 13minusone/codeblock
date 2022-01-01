#include<bits/stdc++.h>
using namespace std;
#define task ""
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
    ll t,s;
    cin >> t ;
    for(int i =1 ;i<=t;i++)
    {
        cin >> s;
        ll j=1;
        ll u=0;
        while(s-j>=0)
        {
            s-=j;
            j+=2;
            u++;
            if(s-j<0)
            {
                break;
            }
        }
        if(s>0)
        {
            u++;
        }
        cout << u << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


