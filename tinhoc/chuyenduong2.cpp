#include <bits/stdc++.h>
using namespace std;
int n,c[1001],i=1,top=0,bot=1,d=0;
queue<int> b;

void nhap()
{
    cin>>n;
    for (int j=1;j<=n;j++) cin>>c[j];
}
void xuli()
{
    int i=1;
    for (int j=1;j<=n;j++)
    {
        while (i<c[j])
        {
            b.push(i);
            d++;
         //   cout<<"a b"<<endl;
            i++;
        }
        if (i==c[j])
        {
            d++;
          //  cout<<"a c"<<endl;
            i++;
        }
        else
        {
            int x=b.front();b.pop();
          //  cout<<x<<endl;
            if (x==c[j])
            {
                d++;
               // cout<<"b c"<<endl;
            }
            else
            {
                cout<<"0";
                return;
            }
        }
        //cout<<d<<endl;
    }
    cout<<d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("chuyenduong2.inp","r",stdin);
    freopen("chuyenduong2.out","w",stdout);
    nhap();
    xuli();
}
