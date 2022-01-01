#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
#define top() front()
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
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
int dx[6]= {0,1,-1,0,0};
int dy[6]= {0,0,0,1,-1};
char dir[6]= {'0','D','U','R','L'};
ll d[1005][1005];
ll a[1005][1005];
char inputt[1005][1005];
ii dau,cuoi;
void truyvet(int g,int h)
{
    vector<char>vec;
    ii i={g,h};
    d[dau.first][dau.second]=0;
    while(d[i.first][i.second]>=1)
    {
        //cout << i.first << " " << i.second << endl;
        for(int j = 1 ; j<=4; j++)
        {

                if(d[i.first][i.second]==j)
                {
                    i.first-=dx[j];
                    i.second-=dy[j];
                    vec.push_back(dir[j]);
                    break;
                }
        }

    }
    cout << (int)vec.size()-1 << endl;
    for(int o = (int)vec.size()-1; o>=1; o--)
    {
        cout << vec[o];
    }
    return ;
}
void nhap()
{
    ll n, m;
    cin >> n >> m;
    char in;

    for(int i = 0 ; i <= n+1 ; ++i)
    {

        for(int  j = 0 ; j <= m+1 ; ++j)
        {

            if((i<=n)&&(i>=1)&&(j<=m)&&(j>=1))
            {
                cin >> in;
                inputt[i][j]=in;
                if(in=='.')
                {
                    d[i][j]=0;
                }
                else d[i][j]=-1;
                if(in=='A')
                {
                    d[i][j]=0;
                    dau.first=i;
                    dau.second=j;
                }
                if(in=='M')
                {
                    for(int k = j-1;k>=0;k--)
                    {
                        if(inputt[i][k]!='A'&&inputt[i][k]!='#')
                         {
                             d[i][k]=-1;
                         }
                         else
                         {
                             break;
                         }
                    }
                    while(j<n)
                    {
                        j++;
                        cin >> inputt[i][j] ;
                         if(inputt[i][j]!='A'&&inputt[i][j]!='#')
                         {
                             d[i][j]=-1;
                         }
                         else
                         {
                             break;
                         }

                    }

                }
            }
            else{
            d[i][j]=0;
             a[i][j]=10;
            }
        }
    }

    queue<ii>qu;
    qu.push(dau);
    while(!qu.empty())
    {

        if(a[qu.top().first][qu.top().second]==10)
        {
            //cout << qu.top().first << " " << qu.top().second <<" " << d[qu.top().first][qu.top().second] << endl;
            cout <<"YES" << endl;
            truyvet(qu.top().first,qu.top().second);
            return ;
        }
        for(int i = 1 ; i <= 4 ; i++)
        {
            if(d[qu.top().first+dx[i]][qu.top().second+dy[i]]==-0)
            {
                //cout <<qu.top().first+dx[i] << " " <<qu.top().second+dy[i] << endl  ;
                d[qu.top().first+dx[i]][qu.top().second+dy[i]]=i;
                qu.push(ii(qu.top().first+dx[i],qu.top().second+dy[i]));
            }
        }
        qu.pop();

    }
    cout << "NO";
}
int main()
{

    fastio();
    // inti();
    nhap();
}

