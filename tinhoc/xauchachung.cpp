#include<bits/stdc++.h>
using namespace std;

string a,b,c;
int f[1000][1000],m,n;
void nhap()
{
    getline(cin,a);
    getline(cin,b);
    m=a.length();n=b.length();
    a=' '+a;
    b=' '+b;
}

void tim_xau_con_chung()
{
    c="";
    int res=f[m][n];
    int i=m,j=n;
    while(res!=0)
    {
        if(a[i]==b[j])
        {
            c=a[i]+c;
            res=res-1;
            i--;j--;
        }
        else
        {
            if(f[i-1][j]==res) i=i-1;
            if(f[i][j-1]==res) j=j-1;
        }
    }
   // cout<<c<<endl;
}
void dp()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    //cout<<f[m][n]<<endl;
}

void tim_xau_cha_chung()
{
    string cha="";
    int i=1,j=1;
  //  cout<<c.length();
    for(int k=0;k<c.length();k++)
    {
      //  cout<<"dafd";
        while(a[i]!=c[k])
        {
            cha=cha+a[i];
            i++;
        }
        while(b[j]!=c[k])
        {
            cha=cha+b[j];
            j++;
        }
        cha=cha+c[k];
        i++;j++;

    }
   // cout<<i<<" "<<j<<" "<<m<<" "<<n<<" "<<b.length()<<endl;
   for(int k=i;k<=m;k++)
        cha=cha+a[k];
    for(int k=j;k<=n;k++)
        cha=cha+b[k];
    cout<<cha;
}

void giai()
{
    dp();
    tim_xau_con_chung();
    tim_xau_cha_chung();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xauchachung.inp","r",stdin);
    freopen("xauchachung.out","w",stdout);
    nhap();
    giai();
}
