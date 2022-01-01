#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,x[1000],d[1000];
    vector<int>vec;
    vector<int>mex;
void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
void nhap()
{

cin>>n;
fu(j,1,n,1)
{
    cin>>m;

    fu(i,1,m,1)
    {
        cin>>x[i];
        if(d[x[i]]==0)
        {
            vec.push_back(x[i]);
            d[x[i]]++;
        }
        else
        {
            mex.push_back(x[i]);
        }

    }
    if(m==1)
    {
        cout<<x[m]<<endl;
        continue;
    }
    sort(vec.begin(),vec.end());
    fu(i,0,vec.size()-1,1)
    {
        cout<<vec[i]<<" ";
        d[vec[i]]=0;
    }
    fu(i,0,mex.size()-1,1)
    {
        cout<<mex[i]<<" ";
    }
    cout<<endl;
    mex.resize(0);
    vec.resize(0);

}

}
int main()
{
IOS
//inti()
nhap();

}

