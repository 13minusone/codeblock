#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
int g=10000,n,x[10000],m,f[101][30001];

void inti()
{
    freopen("expression.inp","r",stdin);
    freopen("expression.out","w",stdout);
}
void nhap()
{

    cin>>n>>m;
    fu(1,n,1)cin>>x[i];
}
int main()
{
    inti();
    nhap();
    f[1][g+x[1]]=1;
    fu(2,n,1)
    {
        for(int j=-g; j<=g; j++)
        {

            if(f[i-1][j+x[i]+g]==1||f[i-1][j-x[i]+g]==1)
            {
                f[i][g+j]=1;
            }
        }
    }
    int i=n,j=m;
//    fu(1,n,1)
//    {
//        for(int j=-m;j<=m;j++)
//        {
//            cout<<i<<" " <<j<< " " <<f[i][j]<<endl;
//        }
//    }
    string s="";
    while(i>1)
    {


        if(f[i-1][j+g-x[i]]==1)
        {
            s='+'+s;
            j=j-x[i];
        }
        else
        {
            s='-'+s;
            j=j+x[i];
        }
        i--;
    }
    cout<<s;
}
