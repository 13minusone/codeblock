#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    int k,n;
    string s;
    int d[1000];
    cin >> k;
    fu(i,1,k,1)
    {
        cin >> n;
       int  t=0;
       cin >> s;
        fu(j,0,n-1,1)
        {
if(s[j]!=s[j-1])
            {if(d[int(s[j])]!=0)
            {
                cout << "NO" <<endl;
                t=1;
               break;

            }
            d[int(s[j])]++;
        }}
        if(t==0)
        {
            cout << "YES" <<endl;
        }
        fu(j,int('A'),int('Z'),1)
        {
            d[j]=0;
        }

    }
}
int main()
{
    fastio();
    //inti();
    nhap();
}
