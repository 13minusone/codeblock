#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(ll  i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m;
const int maxx=10000000;
int g[int(1e7)+1];
vector<int>vec;
void sang()
{
    for(ll i =2 ; i<=maxx; i++)
    {
        if(g[i]==0)
        {
            vec.pb(i);
            unsigned ll   f=i*i;
            if(f+i<=maxx)
            {
               for(ll j =f ; j<=maxx;j+=i)
                {
                    g[j]=1;
                }
            }
        }

    }
}
int i=0;
ll res,s;
void nhap()
{
    sang();
    cin >> m;

    while(m!=0)
    {
        res=vec[i];
        s=2*res;
        if(g[s-1]==0)
        {
            m--;
            if(m==0)
            {
                cout << res << " "<< res << " "  << s-1;
                break;
            }

        }
        if(g[s+1]==0)
        {
            m--;
            if(m==0)
            {
                cout << res << " "<< res << " "  << s+1;
                break;
            }

        }
        i++;
    }
}
int main()
{
    IOS
//inti()
    nhap();

}

