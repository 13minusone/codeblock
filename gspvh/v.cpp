#include<bits/stdc++.h>
using namespace std;
#define task "equivalent"
#define pb push_back
#define ll long long
#define fi first
#define se second
typedef pair<int, int> ii;
void init()
{
    freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int n;
vector<string> t;
vector<int> block[int(2e5)+5];
void read()
{
    string s;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> s;
        for(int j=0; j<s.size(); j++) t.pb(s.substr(j)+s.substr(0,j));
    }
}
string sol(string s)
{
    int nn=s.size();
    int deg[nn+1]={0};
    int dem[nn+1][10]={0};
    for(int i=0; i<=9; i++) dem[nn][i]=-1;
    for(int i=nn-1; i>=0; i--)
    {
        block[i].clear();
        for(int j=0; j<=9; j++)
        {
            if (s[i]-'0'==j) dem[i][j]=i;
            else dem[i][j]=dem[i+1][j];
        }
    }
    for(int i=0;  i<nn; i++)
    {
        for(int c=max(s[i]-'0'-1,0); c<=min(s[i]-'0'+1,9); c++)
        {
            int j=dem[i+1][c];
            if (j!=-1)
            {
                block[i].pb(j);
                deg[j]++;
            }
        }
    }
    priority_queue<ii, vector<ii>, greater<ii>> q;
    string ans;
    for(int i=0; i<nn; i++)
    {
        if (deg[i]==0) q.push({s[i], i});
    }
    while(!q.empty())
    {
        int digit=q.top().fi, pos=q.top().se;
        q.pop();
        ans.pb(digit);
        for(int j:block[pos])
        {
            deg[j]--;
            if (deg[j]==0) q.push({s[j], j});
        }
    }
    return ans;
}
void sol()
{
    set<string> ans;
    for(int i=0; i<t.size(); i++)
    {
        string res=sol(t[i]);
        ans.insert(res);
    }
    cout << ans.size();
}
int main()
{
    init();
    fastio();
    read();
    sol();
}
