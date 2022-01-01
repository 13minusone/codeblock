#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n;
ll x[100001],d[100001];
void inti()
{
    freopen("split.inp","r",stdin);
    freopen("split.out","w",stdout);
}
ll solve(ll i,ll j,ll l)
{


    if(l>0)
    {
        int k;
        if((i+j)%2==0)
        {
            k=(i+j)/2;

        }
        else
        {
             k=int((i+j)/2)+1;
        }
        if(d[k]==0)
        {
            n++;
            l--;
            if(k>i)
            {
                if(k==j)
            {
                j++;
            }            d[k]++;
                solve(k,j,l);
            }




        }
        else
        {
            return i;
        }



    }
    else
    {
        return i;
    }

}
void nhap()
{

    int t;
    cin>>t;
    fu(j,1,t,1)
    {
        ll maxx=-1;
        cin>>n>>m;

        fu(i,1,n,1)
        {
            cin>>x[i];
            d[x[i]]++;
            maxx=max(maxx,x[i]);

        }
        int i=0;
        while(d[i]!=0)
        {
            i++;
        }


//cout<<i<< " "<<maxx<<endl;
int g=solve(maxx,i,m);
        cout<<n<<endl;
        //cout<<g<<endl;
        fu(k,0,g,1)
        {
            d[k]=0;
        }
    }


}
int main()
{
    IOS
    //inti();
    nhap();

}

