#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x[100001];
int s=0;
vector<int>vec;
vector<int>k;
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
void nhap()
{
    int t;
    cin>>t;
    fu(o,1,t,1)
    {


        cin>>n;
        fu(i,1,n,1)
        {
            cin>>x[i];
            if(s==0)
            {
                s=x[i];
                k.pb(x[i]);
            }
            else
            {
                ll p=__gcd(x[i],s);
                if(p==1)
                {
                    s=0;
                    vec.pb(i);

                }
                else
                {
                    s=x[i];
                    k.pb(i);
                }
            }

        }
        if(vec.size()==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            ll g=k.size();
            ll h=0;
            if(s==0)
            {
                s=x[k[0]];
            }
            ll i=0;
            while(h!=g-1)
            {

                if(k[i]!=0)
                {
                    ll u=__gcd(s,x[k[i]]);
                    if(u==1)
                    {

                        vec.pb(k[i]);
                        k[i]=0;
                        g--;

                        s=k[i+1];

                        continue;
                    }
                    else
                    {
                        s=x[k[i]];
                        h++;
                    }
                }
                if(i<k.size()-1)
                {
                    i++;
                }
                else
                {
                    i=0;
                    h=0;
                }
            }
        }
        cout<<vec.size()<<" ";

        if(vec.size()>0)
        {
            fu(j,0,vec.size()-1,1)
            {
                cout<<vec[j]<<" ";
            }
        }
        cout<<endl;
        vec.resize(0);
        k.resize(0);
    }
}

int main()
{
    IOS
//inti()
    nhap();

}

