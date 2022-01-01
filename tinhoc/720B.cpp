#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
map<ll,int>f;
int d[5];

void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    int t;
    ll n,a[maxsize+1];
    cin >> t;
    d[1]=3;
    d[2]=5;
    d[3]=7;
    d[4]=11;
    fu(i,1,t,1)
    {
        cin >> n;
        vector<int>vec;
        fu(j,1,n,1)
        {
            cin >> a[i];
            if(__gcd(a[i],a[i-1])!=1)
            {
                vec.push_back(i-1);
            }
        }
        int g=vec.size();
        if(g==0)
        {
            cout << 0 <<endl;
            continue;

        }
        else
        {
            fu(i,0,g-1,1)
            {
                int r=vec[i];
                cout << r << " " << r+1 <<
        }
        }
    }
}

int main()
{
    fastio();
    nhap();
}
