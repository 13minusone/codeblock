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
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    ll t;
    string a;
    cin >> t;
    fu(i,1,t,1)
    {
        cin >> a ;
        ll g=a.size();
        ll res=g;
        ll j=0;
        ll s=0;
       // cout << g << endl;
        while(a[j]!=a[j-1])
        {
            s++;

            j++;
            if(j>g-1)
            {
                break;
            }
            //cout << j << " " << s << endl;
        }
       // cout << s << endl;
        res=res+(s-1)*(s/2);
        //cout << j << endl;


        for(; j<g-1; j++)
        {
           cout << j << endl;
            s=1;
            while(a[j]!=a[j-1])
            {
                s++;

                j++;
                if(j>g-1)
                {
                    break;
                }
                //cout << j << " " << s << endl;
            }


            res=res+(s-1)*(s/2);
        }
        //cout << a << endl;
        cout << res << endl;
    }
}
int main()
{
    fastio();
    nhap();
}

