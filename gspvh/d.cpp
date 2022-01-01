#include<bits/stdc++.h>
using namespace std;
#define task "recover"
#define ll long long
#define SZ(c) c.size()
const ll maxsize =524288;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen("recover.inp","r",stdin);
    freopen("recover.out","w",stdout);
}
ll q,t,a[maxsize+5],b[maxsize+5],cnt,n,st[4*maxsize+5];
vector<ll>vec[maxsize+5];
void dfs(ll n,ll p=-1)
{
    for(int d:vec[n])
    {

        if(b[d]>0 || d==p)
        {
            return;
        }
        cnt--;
        b[d]=cnt;
        dfs(d,n);


    }
}

void nhap()
{

    cin >> q >> t;
    for(int i=1 ; i <= t ; ++i)
    {


        cin >> n;
        for(int j = 1 ; j<= n ; j++)
        {
            cin >> a[j];
            if(a[j]==-1)
            {
                vec[j+1].push_back(j);
                a[j]=j+1;

            }
            else
            {
                vec[a[j]].push_back(j);
            }
        }

        ll h=0;

        for(int j = 1; j <= n; j++)
        {
            if(a[j] <= j)
            {
                h = 1;
                break;
            }
            for(int k=j+1; k<a[j]; k++)
            {
                if(a[k]>a[j])
                {
                    h=1;
                    break;
                }
            }
            if(h==1)
            {
                break;
            }
        }
        if(h==1)
        {
            cout << "No" << " \n";
            for(int o = 1 ; o <= n ; o++)
            {
                b[o]=0;
                vec[o].clear();
            }
            b[n+1]=0;
            vec[n+1].clear();
            continue;
        }
        for(int j = 1 ; j <= n+1 ; j++)
        {
            sort(vec[j].begin(),vec[j].end());

        }
        cnt=n+1;
        b[n+1]=n+1;
        dfs(n+1);


        if(h==0)
        {
            cout << "Yes" <<" \n";
            for(int j = 1 ; j <= n ; j++)
            {
                vec[j].clear();
                cout << b[j] << " ";
                b[j]=0;
            }
            vec[n+1].clear();
            b[n+1]=0;
            cout << " \n";
        }

    }
}
int main()
{

    fastio();
    inti();
    nhap();
}


