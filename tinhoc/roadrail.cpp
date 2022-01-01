#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
int m,n,x,y,z,h;
vector<int> a[20000];
vector<int> b[20000];
int f[200001],cha[200001],k[200001];
void dfs(int g)
{
    for(int i=0; i<a[g].size(); i++)
    {
        int t=a[g][i];
        if(cha[t]!=g)
        {
            cha[t]=g;
            f[t]++;
            dfs(t);
        }
    }
}
void dray(int g)
{
    for(int i=0; i<b[g].size(); i=i+1)
    {
        int t=b[g][i];
        if(cha[t]!=g)
        {
            cha[t]=g;
            f[t]++;
            dray(t);
        }




    }

}

void nhap()
{

    cin>>n>>m>>x;
    fu(1,m,1)
    {
        cin>>y>>z;
        a[y].push_back(z);
        a[z].push_back(y);
    }
    fu(1,x,1)
    {
        cin>>y>>z;
        b[y].push_back(z);
        b[z].push_back(y);
    }
}
int main()
{
    nhap();

    fu(1,n,1)
    {

        h=i;
        dfs(i);
        dray(i);
        for(int l=0; l<b[i].size(); l++)
        {

            int t=b[i][l];
//cout<<i<<" "<<t<<endl;
            if(f[t]=2)
            {
                k[i]++;
            }
          // cout<<t<<" "<<f[t]<<endl;
            f[t]=0;
        }
        for(int k=0; k<a[i].size(); k=k+1)
        {
            int t=a[i][k];
            f[t]=0;
        }
        //cout<<k[i]+1<<" ";
    }
}
