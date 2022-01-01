#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fu0(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fd0(i,a,b,c) for(int i =a ; i>=b ;i-=c)
#define fu1(i,a,b,c) for(int i = a ;i < b ;i+=c)
#define fd1(i,a,b,c) for(int i =a ; i> b ; i-=c)
#define pb(i) push_back(i)
int n;
ll m;
map<int,ll>d;
vector<int>vec;
void nhap()
{
    vector<int>a;

    cin >> n >> m ;
    int f;
    fu0(i,1,n,1)
    {

       cin >> f;
         int o=f%m;
        if(d [o]==0 )
        {
            vec.push_back(o);

        }
        d[o]++;

    }
    int res=vec.size();

    ll g;
    unsigned ll p,s=0;

    fu1(i,0,res,1)
    {
        if(d[vec[i]]>=2)
        {
            g=vec[i]*vec[i];
            p=vec[i]+vec[i];
            if((g%m)==(p%m))
            {
                if(d[vec[i]]%2==0)
                {
                    s=s+(d[vec[i]]/2)*(d[vec[i]]-1);

                }
                else
                {
                    s=s+((d[vec[i]]-1)/2)*(d[vec[i]]);
                }
            }
        }
        fu1(j,i+1,res,1)
        {
            g=vec[i]*vec[j];
            p=vec[i]+vec[j];
            if((g%m)==(p%m))
            {
                s=s+d[vec[i]]*d[vec[j]];
            }
        }
    }
   cout << s;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    nhap();
}

