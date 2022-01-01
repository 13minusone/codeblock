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
ll a[6][50005],d[50005];
vector<ii>vec[6];
void nhap()
{
    int t,n ;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int f=-1;
        for(int i = 1 ; i <= 5 ; i++)
        {
            vec[i].clear();
        }
        for(int j = 1 ; j <= n ; j++)
        {

            int s=0,o=0;
            d[j]=0;
            for(int i = 1 ; i <= 5 ; i++)
            {
                cin >> a[i][j];
                vec[i].push_back({a[i][j],j});
            }

        }
        for(int i = 1 ; i <= 5 ; i++)
        {
            sort(vec[i].begin(),vec[i].end());
        }
        for(int j = 0 ; j<min(1,n/2) ; j++)
        {
            for(int i = 1 ; i <= 5; i++)
            {
                //cout << i << " " << vec[i][j].second <<" "<< d[vec[i][j].second] << endl;
                if(j==0)
                {
                   d[vec[i][j].second]++;

                }
                else
                {
                    if(vec[i][j].first<vec[i][min(j+1,n-1)].first&&vec[i][j].first>vec[i][max(j-1,0)].first)
                {
                    d[vec[i][j].second]++;
                }
                }
                if(d[vec[i][j].second]>=3)
                {
                    f=vec[i][j].second;
                    break;
                }

            }
            if(f!=-1)
            {
                cout << f << endl;
                break;
            }


        }
        if(f==-1)
        {
            cout << f << endl;
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



