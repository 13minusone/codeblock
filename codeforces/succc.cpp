#include<bits/stdc++.h>
using namespace std;
#define task "thi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define fu(i,a,b) for(int i=a; i<=b; i++)
const int mod = int(1e9)+7;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int t,n, a[int(2e5)+2], b[int(2e5)+2], pos[int(2e5)+2];
void sol()
{
    set<int> p;
    cin >> n;
    fu(i,1,n) b[i] = pos[i] = 0;
    fu(i,1,n)
    {
        cin >> a[i];
        p.insert(i);
    }
    fu(i,1,n)
    {
        if (p.find(a[i])!=p.end())
        {
            pos[a[i]]=i;
            b[i]=a[i];
            p.erase(a[i]);
        }
    }
    fu(i,1,n)
    {
        if (b[i]!=0) continue;
        if (*p.begin()==i)
        {
            if (next(p.begin())==p.end())
            {
                b[i]=*p.begin();
                swap(b[i],b[pos[a[i]]]);
                pos[b[i]]=i;
                pos[b[pos[a[i]]]]=pos[a[i]];
            }
            else
            {
                b[i]=*next(p.begin());
                p.erase(next(p.begin()));
            }
            continue;
        }
        b[i]=*p.begin();
        p.erase(p.begin());
    }
    int result=0;
    fu(i,1,n)
    {
        if (a[i]==b[i]) result++;
    }
    cout << result << endl;
    fu(i,1,n) cout << b[i] << " ";
}
int main()
{
    fastio();
    cin >> t;
    while (t--)
    {
        sol();
        cout << "\n";
    }
