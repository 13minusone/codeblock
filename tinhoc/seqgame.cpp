#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int  m,n,x;

void inti()
{
    freopen("seqgame.inp","r",stdin);
    freopen("seqgame.out","w",stdout);
}
void nhap()
{
vector<ll> s;
vector<ll> y;
ll g,k,p;
    cin>>n>>m>>x;
    fu(i,1,n,1)
    {
        scanf("%lld",&g);
        s.pb(g);
    }
    fu(i,1,m,1)
    {
        scanf("%lld",&k);
        y.pb(k);
    }

sort(s.begin(),s.end());
sort(y.begin(),y.end());
    fu(i,1,x,1)
    {
        cin>>p;
        ll res=s.size()-1;
        ll minn=1000000000000000000000;
        fu(j,0,y.size()-1,1)
        {
            if(s[res]+y[j]<=p)
            {
                minn=min(minn,p-s[res]-y[j]);
                continue;
            }
            else
            {
                if(s[0]+y[j]>=p)
                {
                    minn=min(minn,s[0]+y[j]-p);
                }
                else
                {

                    res=std::lower_bound(s.begin(),s.end(),p-y[j])-s.begin()-1;
                    ll s1=abs(p-s[res]-y[j]);
                    ll s2=abs(s[res+1]+y[j]-p);
                    minn=min(min(minn,s1),s2);
                }
            }
        }
        cout<<minn<<endl;

    }
}
int main()
{
    //IOS
    inti();
    nhap();

}

