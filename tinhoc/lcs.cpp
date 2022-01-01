#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x[5001][5001];
string a,b;
void inti()
{
    freopen("lcs.inp","r",stdin);
    freopen("lcs.out","w",stdout);
}
void nhap()
{



        x[0][0]=0;
        cin>>a>>b;
        a=" "+a;
        b=" "+b;
        int g=a.size();
        int f= b.size();
        fu(i,1,g-1,1)
        {
            fu(j,1,f-1,1)
            {
                if(i>=1&&j>=1)
                {
                    if(a[i]==b[j])
                {
                    x[i][j]=x[i-1][j-1]+1;
                }
                else
                {
                    x[i][j]=max(x[i-1][j],x[i][j-1]);
                }
                }
            }
        }
        cout<<x[g-1][f-1]<<endl;


}
int main()
{
    IOS
    inti();
    nhap();

}

