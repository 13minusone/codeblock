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
    ll t,n,a,b;

    string s;
    cin >> t;
    for(int j=1;j<=t;j++)
    {
        vector<ll>g(3,0);
        cin >> n >> a >> b;
        cin >> s;
        ll su=0;
        if(b>=0)
        {
            su=n*a+b*n;
        }
        else
        {
            su=n*a;
            for(int i=0;i<n;i++)
            {
                ll k=i;
                while(s[i]==s[i+1])
                {
                    i++;
                    if(i==n-1)
                    {
                        break;
                    }
                }
                g[int(s[k])-int('0')]++;
            }
            //cout << g[1] << " " << g[0]<<endl;
            su=su+(min(g[1],g[0])+1)*b;
        }
        cout << su << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}


