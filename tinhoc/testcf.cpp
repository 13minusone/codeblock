#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n;
string x;
void inti()
{
    freopen("715b.inp","r",stdin);
    freopen("715b.out","w",stdout);
}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        cin>>m;
        cin >>x;
        int g=x.size();
        int res=0,s=0,r,t=0;
        fu(j,0,g-1,1)
        {
            if(x[j]=='T')
            {
                res++;
            }
            else
            {
                s++;
                r=res;
                if(res<s)
                {
                    cout << "NO" <<endl;
                    t=1;
                    break;
                }
            }}
            if(t==0)
            {
                if(res==2*s)
                {
                    //cout << "YES" <<endl;
                    if(x[0]=='M'|| x [g-1]=='M')
                    {
                        cout << "NO" <<endl;
                    }
                    else
                    {
                        if(r>=s)
                        {
                            if((r-s)+(m-r-s)==s)
                            {
                                cout << "YES" <<endl;

                            }
                            else
                            {
                                cout << "NO " <<endl;
                            }
                        }
                        else
                        {
                            cout << "N0" << endl;
                        }
                    }
                }
                else
                {
                    cout << "NO" <<endl;
                }
            }
        }
    }

int main()
{
    IOS
    //inti();
    nhap();

}
