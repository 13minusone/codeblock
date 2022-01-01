#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
void minimize(ll a,ll b)
{
    a=min(a,b);
    return;
}
 void maximize(ll a,ll b)
{
    a=max(a,b);
    return;
}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<int>vec[500];
int vt[500];
void nhap()
{
    string s;
    ll k,h,n,maxx=0;
    cin >> s;
    n=SZ(s);
    s=" "+s;
    cin >> k;
    h=k;
    for(int i = 1 ; i <=n ; i++)
    {
        vec[s[i]].push_back(i);
        vt[s[i]]=0;
    }
    for(int i = 1 ; i<= n ; i++)
    {
        ll su=1;
        int j=vt[s[i]];
        if(j==SZ(vec[s[i]])-1)
        {
            maxx=max(maxx,min(n-vec[s[i]][j]+1,k+1));
            continue;
        }
        h=k;
        while(h>=0)
        {
            if(j==vec[s[i]].size()-1)
            {
                su+=min(n-vec[s[i]][j],h);
                maxx=max(maxx,su);
                h=0;
                break;
            }
            if(vec[s[i]][j+1]-vec[s[i]][j]-1<=h)
            {
                h-=(vec[s[i]][j+1]-vec[s[i]][j]-1);
                su+=(vec[s[i]][j+1]-vec[s[i]][j]);
                j++;
            }
            else
            {
                if(h==0)
                {
                    break;
                }
                su+=h;
                h=0;


            }
            maxx=max(maxx,su);

        }
        //cout << i << " " <<maxx << endl;
        maxx=max(maxx,su);
        vt[s[i]]++;

    }
    maxx=min(maxx,n);
    cout << maxx << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}
