#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define sz(c) c.size()
const ll maxsize = 1000000;
string s;
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
ll tinhcap(int x,int y)
{
    ll to=0;
    while(y!=x)
    {
        ll d=1,f=1;
        fu(i,2,y,1)
        {
            d=d*i;
        }
        fu(i,x-y+1,x,1)
        {
            f=f*i;
        }
        to=to+(f/d);
        y++;
    }
    return to;
}
ll tinhcap1(ll x,ll y)
{
    ll to=0;
    while(y!=x)
    {
        ll d=1,f=1;
        fu(i,2,y,1)
        {
            d=d*i;
        }
        fu(i,x-y+1,x,1)
        {
            f=f*i;
        }
        to=to+(f/d);
        y+=6;
    }
    return to;
}
ll d[maxsize+5];
void nhap()
{
    getline(cin,s);
    //cout << s <<endl;
    ll g=sz(s);
    int sum=0;
    ll maxx=0;
    int x;
//    cout << s << " " << g <<endl;
    cin >> x;
    //cout << s[6] <<endl;
    if(x==2)
    {
        ll tcc=int(s[0]-48);
       // cout << tcc ;
        fu(i,1,g-1,1)
        {


            tcc=tcc*10+int(s[i]-48);
            //cout << tcc <<endl;
            if(tcc%33==0)
            {
               maxx=max(tcc,maxx);
            }
            fu(j,0,i,1)
            {
                ll sl=0;
                fu(k,0,j,1)
                {
                    sl=sl*10+int(s[k]-48);
                }
                fu(k,j+1,i,1)
                {
                    sl=sl*10;
                }
                if((tcc-sl)%33==0)
                {
                    maxx=max(maxx,tcc-sl);
                }
            }
            //cout << i << " " <<maxx <<endl;

        }
        cout << maxx <<endl;
    }
    else
    {
        cout << "0" <<endl;
    }

}
int main()
{
    fastio();
    //inti();
    //cout << int ('0');
    nhap();
}

