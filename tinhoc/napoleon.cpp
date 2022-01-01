#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x[200001],d[200001];
struct data
{
    ll u,v;
};
void inti()
{
    freopen("napoleon.inp","r",stdin);
    freopen("napoleon.out","w",stdout);
}
void nhap()
{

    int st[200001];
    cin>>n;
    fu(i,1,n,1)
    {

        int minn=1000000,s=0;
        cin>>m;
        fu(j,1,m,1)
        {

            cin>>x[j];

            if(j-x[j]>s)
            {
                minn=j;
                while(j-x[j]>s)
                {
                    if(j-x[j]>s)
                    {
                        s=j-x[j];
                    }
                    else
                    {
                        if(j-x[j]==s)
                        {
                            st[minn]=s;
                            d[minn]=1;
                            s=j;
                            minnn=100000;
                            break;
                        }
                        else
                        {
                            minn=10000000;
                            s=j;
                            break;
                        }
                    }

j++;
                }

            }
            else
            {
                if(j-x[j]<s)
                {
                    if(minn)
                }
            }

            fu(j,1,m,1)
            {
               if(d[j]==1)
               {
                   int k=j;
                   fu(j,k,st[k],1)
                   {
                       cout<<"0"<<" ";
                   }
               }
               else
               {
                   cout<<"1"<<endl;
               }
            }
            cout<<endl;
        }

    }
}
int main()
{
    IOS
    inti();
    nhap();

}

