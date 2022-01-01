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
ll n,x;
vector<ll>vec;
       map<unsigned ll , ll >d;
bool solve()
{
    cin >> n;

        fu(i,1,n,1)
        {
            cin >> x;
            vec.push_back(x);
        }
        ll g=vec.size();

        ll i=0;
        while(i!=g-1)
        {

            fu(j,i+1,g-1,1)
            {
                if(d[abs(vec[i]-vec[j])]==0)
                {
                    vec.push_back(abs(vec[i]-vec[j]));
                    d[abs(vec[i]-vec[j])]++;
                    g=vec.size();
                    if(g>300)
                    {
                return false;
                     }
                }

            }
            fd(j,i-1,0,1)
            {
                if(d[abs(vec[i]-vec[j])]==0)
                {
                    vec.push_back(abs(vec[i]-vec[j]));
                    d[abs(vec[i]-vec[j])]++;
                     g=vec.size();
                    if(g>300)
                    {
                return false;
                     }
                }
            }
             g=vec.size();
                    if(g>300)
                    {
                return false;
                     }
        }

        return true;
}

void nhap()
{
    ll t;
    cin >> t;
    fu(k,1,t,1)
    {

     if(solve()==false)
     {
         cout << "NO" << endl;
     }
     else
     {
            cout << "YES" << endl;
        fu(i,0,vec.size()-1,1)
        {
            cout << vec[i] << " ";
        }
     }
}
}
int main()
{
    fastio();
    nhap();
}

