#include<bits/stdc++.h>
using namespace std;
#define task "hanoi"
#define pb push_back
#define ll long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) s.size()
#define getbit(x,i) (((x)>>(i))&1)
#define turnoff(x,i) ((x)&(~(1<<i)))
const int mod = int(1e9)+7;
typedef pair<int, int> ii;
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
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check[1002][1002], river=false;
int n, m, k, cnt=0;
char a[1002][1002];
struct iii{
    int x, y, cnt;
}dem[int(1e6)+2];
void read()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }
}
bool cango(int x, int y)
{
    return (x>=1 && y>=1 && x<=n && y<=m && a[x][y]=='.' && !check[x][y]);
}
void bfs(int i, int j)
{
    queue<ii> q;
    q.push(ii(i,j));
    dem[cnt+1].cnt=1;
    if (i==1 || j==1 || i==n || j==m) river=true;
    while(!q.empty())
    {
        int x=q.front().fi, y=q.front().se;
        q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int xx=x+dx[dir];
            int yy=y+dy[dir];
            if (cango(xx, yy))
            {
                dem[cnt+1].cnt++;
                if (xx==1 || yy==1 || xx==n || yy==m) river=true;
                check[xx][yy]=true;
                q.push(ii(xx,yy));
            }
        }
    }
}
bool CANGO(int x, int y)
{
    return x>=1 && y>=1 && x<=n && y<=m && a[x][y]=='.';
}
void BFS(int i, int j)
{
    queue<ii> q;
    q.push(ii(i,j));
    a[i][j]='#';
    while(!q.empty())
    {
        int x=q.front().fi, y=q.front().se;
        q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int xx=x+dx[dir];
            int yy=y+dy[dir];
            if (CANGO(xx, yy))
            {
                a[xx][yy]='#';
                q.push(ii(xx,yy));
            }
        }
    }
}
bool cmp(iii a, iii b)
{
    return a.cnt<b.cnt;
}
void sol()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if (!check[i][j] && a[i][j]=='.')
            {
                //cout << i << " " << j << "\n";
                river=false;
                check[i][j]=true;
                bfs(i,j);
                if (!river)
                {
                    cnt++;
                    dem[cnt].x=i;
                    dem[cnt].y=j;
                }
            }
        }
    }
    int ans=0;
    sort(dem+1, dem+cnt+1, cmp);
    int sz=cnt;
    for(int i=1; sz>k && i<=cnt; i++, sz--)
    {
        ans+=dem[i].cnt;
        BFS(dem[i].x, dem[i].y);
    }
    cout << ans << "\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout << a[i][j];
        cout << "\n";
    }
}
int main()
{
    fastio();
    init();
    read();
    sol();
}
