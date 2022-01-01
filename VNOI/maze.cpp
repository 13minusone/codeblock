#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#define ll long long
#define ull unsigned long long
#define ed <<'\n';
#define el cout<<'\n';
#define db(x) cerr << "[" << #x << " :  " << (x) << "] ";
#define endln cerr << "\n";
/**

⠀⠀⠀ ⢀⣴⣿⣿⣿⡿⠋⠀⠀⠀⠹⣿⣦⡀
⠀⠀⢀⣴⣿⣿⣿⣿⣏⠀⠀⠀⠀⠀ ⠀⢹⣿⣧
⠀⠀⠙⢿⣿⡿⠋⠻⣿⣿⣦⡀⠀⠀⠀ ⢸⣿⣿⡆
⠀⠀⠀⠀⠉⠀⠀⠀ ⠈⠻⣿⣿⣦⡀⠀⢸⣿⣿⡇
⠀⠀⠀⠀⢀⣀⣄⡀⠀⠀ ⠈⠻⣿⣿⣶⣿⣿⣿⠁
⠀⠀⠀⣠⣿⣿⢿⣿⣶⣶⣶⣶⣾⣿⣿⣿⣿⡁
⢠⣶⣿⣿⠋⠀⠉⠛⠿⠿⠿⠿⠿⠛ ⠻⣿⣿⣦⡀
⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠈⠻⣿⡿

**/

/// khai báo biến

char a[1001][1001];
int x,y,leftt[4]= {-1,0,0,1},rightt[4]= {0,-1,1,0},n,m;
bool visited[1001][1001],check=false;
struct pt
{
    ll a,b;
};
pt luu[1000];

void print(int dem)
{
    check=true;
    cout<<dem ed
        for(int  i=dem-1; i>=0; i--) cout<<luu[i].a<<' '<<luu[i].b ed
    }
void xuly(int x,int y,ll dem)
{
    if(x ==1 or x ==n or y == m or y == 1 )
    {
        if(!check) print(dem);
        return;
    }
    for(int i=0; i < 4; i++)
    {
        if(a[x+leftt[i]][y+rightt[i]]=='O' and !visited [x+leftt[i]] [y+rightt[i]])
        {
            luu[dem].a=x+leftt[i];
            luu[dem].b=y+rightt[i];
            visited[x+leftt[i]][y+rightt[i]]=true;
            if(!check) xuly(x+leftt[i],y+rightt[i],dem+1);
        }
        if(check) return;
    }

}
void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='E') x=i,y=j;
        }
    /// start
    visited[x][y]=true;
    luu[0].a=x;luu[0].b=y;
    /// the code goes here
    xuly(x,y,1);
    if(!check) cout<<-1;
}


void inp()
{
    int test;
    cin>>test;
    while(test-->0) solve();
}
void file()
{
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
