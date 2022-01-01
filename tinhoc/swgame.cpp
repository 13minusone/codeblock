#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x,d[1000000];
int maxx=0;
vector<int>vec;
void inti()
{
    freopen("swgame.inp","r",stdin);
    freopen("swgame.out","w",stdout);
}
void nhap()
{

    cin>>n>>m>>x;
    fu(i,1,n,1)
    {
        ll h ;
        cin>>h;
        if(h%2!=0)
        {
            vec.pb(i);
        }
    }
    ll f=vec.size();
    fu(i,0,vec.size()-1,1)
    {
        ll h,g;
        if(f>1)
        {
            d[i]++;
            if(i==0)
            {
                ll g=vec.size();
                h=(n-vec[g-1]+vec[i])*min(m,x);


            }
            else
            {
                h=(vec[i]-vec[i-1])*min(m,x);

            }
            if(i==vec.size()-1)
            {
                g=(n-vec[i]+vec[0])*min(m,x);
            }
            else
            {
                g=(vec[i+1]-vec[i])*min(x,m);
            }
            if(d[i-1]==0&&d[i+1]==0)
            {
                if(h>g)
                {
                    maxx=maxx+g;
                    d[i+1]++;
                }
                else
                {
                    maxx=maxx+h;
                    d[i-1]++;
                }
            }
            else
            {
                if(d[i-1]==0)
                {
                    maxx=maxx+h;
                    d[i-1]++;
                }
                if(d[i+1]==0)
                {
                    maxx=maxx+g;
                    d[i+1]++;
                }
            }
            f=f-2;

            //cout<<vec[i]<< " "<<maxx<<endl;
        }
    }
cout<<maxx<<endl;
}
int main()
{
    IOS
    inti();
    nhap();

}

