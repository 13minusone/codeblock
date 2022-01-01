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
    string x;
    map<string,int>dd;
    int n;
    cin >> n ;

    fu(i,1,n,1)
    {
        cin >> x;
        if(dd[x]==0)
        {
            cout << "OK" <<endl;
            dd[x]=1;
        }
        else
        {
            cout << x <<dd[x] <<endl;
            dd[x]=(dd[x]+1);
        }


    }

}
int main()
{
    fastio();
    //inti();
    nhap();
}
