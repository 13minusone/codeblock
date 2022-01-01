#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define BIT(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
const int maximum = int(1e9)+7;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
string in;
int p, n;
vector<int> b;
bool cmp(int a, int b, int c)
{
    return (a>b+c);
}
int solve(int m)
{
    int maxx=10;
    string t=in;
    for(int j=0; j<b.size(); j++)
    {
        if(BIT(m,j))
        {
            t[b[j]]='1';
        }
        else
        {
            t[b[j]]='0';
        }
    }
    ll s1=5, s2=5;
    ll r1=0, r2=0;
    for(int i=1; i<=n; i++)
    {
        if(i%2==0)
        {
            s2--;
            if(t[i]=='1')
            {
                r2++;
            }
        }
        else
        {
            s1--;
            if(t[i]=='1')
            {
                r1++;
            }
        }
        if(cmp(r2,s1,r1))
        {
            return i;
        }
        if(cmp(r1,s2,r2))
        {

            return i;
        }
    }
    return maxx;
}
int main()
{
    fastio();
    cin >> p;
   for(int dem=1;dem<=p;dem++)
    {
        cin >> in;
        n=10;
        in=' '+in;
        b.clear();
        for(int j=1; j<=n; j++)
        {
            if(in[j]=='?')
            {

                b.push_back(j);
            }
        }
        int res=maximum;
        for(int i=0; i< mu2((int)b.size()); i++){
                res=min(res,solve(i));
        }
        cout << res << "\n";
    }
}
