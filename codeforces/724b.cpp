#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
map<string,ll>d;
string solve()
{
    fu(i,97,122,1)
    {
        char g=char(i);
        string r;
        r="";
        r=r+g;
        //cout << r << endl;
        if(d[r]==0)
        {
            // cout << r << " "<<d[r] << endl;
            return r;

        }
    }
    fu(i,97,122,1)
    {
        fu(p,97,122,1)
        {
            char t= char(i);
            char o=char(p);
            string h;
            h="";
            h=h+t;
            h=h+o;
            if(d[h]==0)
            {
                return h;
            }
        }
    }
    fu(q,97,122,1)
    {


        fu(i,97,122,1)
        {
            fu(p,97,122,1)
            {
                char t= char(i);
                char o=char(p);
                char y=char(q);
                string h;
                h="";
                h=h+y;
                h=h+t;
                h=h+o;
                if(d[h]==0)
                {
                    return h;
                }
            }
        }
    }

}
void nhap()
{
    ll t,n;

    cin >> t;
    fu(l,1,t,1)
    {
        cin >> n;

        char a[1002];
        fu(j,1,n,1)
        {
            string s;
            s="";
            cin >> a[j];
            s=s+a[j];
            d[s]++;

            if(j>=3)
            {
                fu(k,1,2,1)
                {
                    s=a[j-k]+s;
                    d[s]++;
                    //cout << s << endl;
                }
            }
            //cout << s<< " " << d[s] << endl;;



        }
        string k,g;
        g=a[1];
        k=a[2];
        d[g]++;
        d[k]++;
        d[g+k]++;

        cout << solve() << endl;;
        d.clear();
    }
}
int main()
{
    fastio();
    nhap();
}

