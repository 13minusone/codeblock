#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = sqrt(10000000)+1;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll f[maxsize+5];
vector<ll>vec;
ll df[maxsize*maxsize],vec1[maxsize*maxsize];
void sang()
{
    fu(i,2,maxsize,1)
    {

        if(f[i]==0)
        {
            vec.push_back(i);
            if(i<=216)
        {
            df[i*i*i]++;
        }
            for(unsigned ll j = i*i;j<=maxsize;j+=i)
            {
                f[j]=1;
            }
        }
    }
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    sang();
    int g=SZ(vec);
    fu(i,0,g-1,1)
    {
        fd(j,i-1,0,1)
        {
            vec1.[vec[i]*vec[j]]++;;
        }
    }
    g=SZ(vec);

    int q;
    cin >> q;
    ll l,r;

    fu(i,1,q,1)
    {
        int t=0,t1=0;
        cin >> l >> r ;
        ll s = lower_bound(df.begin(),df.end(),l)-df.begin();
        ll s1 = upper_bound(df.begin(),df.end(),r)-df.begin()-1;
        ll o = lower_bound(vec1.begin(),vec1.end(),l)-vec1.begin();
        ll o1 = upper_bound(vec1.begin(),vec1.end(),r)-vec1.begin()-1;
        cout << o << " " << o1 << " " << s << " " << s1 <<endl;
       // cout << vec1[o] << endl;
        if(vec1[o1]<l||vec1[o1]>r)
        {
            o=0;
        }
        if(vec1[o]>=l&&vec1[o]<=r)
        {
            //cout << vec[o1];
            t=1;
        }
        else
        {
         o1=0;
        }
        if(df[s1]<l||df[s1]>r)
        {
            s=0;
        }
        if(df[s]>=l&&df[s]<=r)
        {
            t1=1;
        }
        else
        {
            s1=0;
        }
        cout << s-s1+o-o1+t+t1 << endl;
    }
}
int main()
{
    fastio();
    nhap();
}

