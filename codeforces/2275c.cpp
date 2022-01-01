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
    ll n,s;
    cin >> n >> s;
    ll minn=0;
    if(s==0 ||n*9<s )
    {
        cout << -1 << " " << -1 ;
        return ;
    }
    ll a[n+4];
    ll su=0;


    fu(i,1,n,1)
    {

        if(s>0)
        {
            a[i]=1;
        }
        else
        {
            a[i]=0;
        }
        s--;
        //cout << a[i] << endl;
    }
    fu(i,1,n,1)
    {
        if(s>0)
        {
            while(a[i]<9)
            {
                a[i]++;
                s--;
                if(s==0)
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    fu(i,1,n,1)
    {
        //cout << a[i] << endl;
        su=su*10+a[i];
    }
    fd(i,n,1,1)
    {
        ll j=i;
        if(a[n]==0&&j==n)
        {
            while(a[j]==0)
            {
                j--;

            }
            minn+=a[j];
            fd(k,i,j+1,1)
            {
                minn*=10;
            }
            i=j;
            continue;

        }

        minn=minn*10+a[i];
    }
    cout <<minn<< " " <<  su << endl;



}
int main()
{
    fastio();
    nhap();
}

