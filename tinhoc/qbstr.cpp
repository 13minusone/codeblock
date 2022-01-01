#include<bits/stdc++.h>
using namespace std;

string x,y;
int f[1000][1000],m,n;
void nhap()
{
    getline(cin,x);
    getline(cin,y);
}

void truy_vet()
{
    string k="";
    int res=f[m][n];
    int i=m,j=n;
    while(res!=0)
    {
        if(x[i]==y[j])
        {
            k=x[i]+k;
            res=res-1;
            i--;j--;
        }
        else
        {
            if(f[i-1][j]==res) i=i-1;
            if(f[i][j-1]==res) j=j-1;
        }
    }
    cout<<k;
}
void xuli()
{
    m=x.length();n=y.length();
    x=' '+x;
    y=' '+y;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[m][n]<<endl;
    truy_vet();

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("qbstr.inp","r",stdin);
    freopen("qbstr.out","w",stdout);
    nhap();
    xuli();
}
