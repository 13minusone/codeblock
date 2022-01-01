#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n,x,y,z,s,t;
int cha[1001],d[1001],a[1001];
typedef pair<int,int>ii;
priority_queue<ii,vector<ii>,greater<ii> > qu;

/*
-----------------AUTHOR-----------------------
--------------Parth Mangal--------------------
----------------------------------------------

██████╗░██╗░░░░░███████╗░█████╗░░██████╗███████╗  ██████╗░░█████╗░███╗░░██╗██╗████████╗
██╔══██╗██║░░░░░██╔════╝██╔══██╗██╔════╝██╔════╝  ██╔══██╗██╔══██╗████╗░██║╚█║╚══██╔══╝
██████╔╝██║░░░░░█████╗░░███████║╚█████╗░█████╗░░  ██║░░██║██║░░██║██╔██╗██║░╚╝░░░██║░░░
██╔═══╝░██║░░░░░██╔══╝░░██╔══██║░╚═══██╗██╔══╝░░  ██║░░██║██║░░██║██║╚████║░░░░░░██║░░░
██║░░░░░███████╗███████╗██║░░██║██████╔╝███████╗  ██████╔╝╚█████╔╝██║░╚███║░░░░░░██║░░░
╚═╝░░░░░╚══════╝╚══════╝╚═╝░░╚═╝╚═════╝░╚══════╝  ╚═════╝░░╚════╝░╚═╝░░╚══╝░░░░░░╚═╝░░░

░██╗░░░░░░░██╗░█████╗░████████╗░█████╗░██╗░░██╗  ███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░██████╗░███████╗
░██║░░██╗░░██║██╔══██╗╚══██╔══╝██╔══██╗██║░░██║  ████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗██╔══██╗██╔════╝
░╚██╗████╗██╔╝███████║░░░██║░░░██║░░╚═╝███████║  ██╔████╔██║░╚████╔╝░  ██║░░╚═╝██║░░██║██║░░██║█████╗░░
░░████╔═████║░██╔══██║░░░██║░░░██║░░██╗██╔══██║  ██║╚██╔╝██║░░╚██╔╝░░  ██║░░██╗██║░░██║██║░░██║██╔══╝░░
░░╚██╔╝░╚██╔╝░██║░░██║░░░██║░░░╚█████╔╝██║░░██║  ██║░╚═╝░██║░░░██║░░░  ╚█████╔╝╚█████╔╝██████╔╝███████╗
░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░░╚════╝░╚═════╝░╚══════╝
*/
void inti()
{
    freopen("move.inp","r",stdin);
    freopen("move.out","w",stdout);
}
vector<ii>vec[1001];
void solve()
{
    qu.push(ii(0,s));

    while(qu.empty() == false)
    {

        ll u=qu.top().first;
        ll v=qu.top().second;
        qu.pop();
        if(v==t)
        {

           int minn=0;


            vector<int>g;
            while(v!=s)
            {

                minn=max(minn,cha[v]);
                g.push_back(v);

               // cout << v  << endl ;

                v=d[v];





            }
            cout << minn << endl  ;
            cout << s << " " ;
            int res = g.size() -1 ;
            fd(i,res,0,1)
            {
                cout<<g[i]<< " ";
            }
            return;
        }
//cout <<u << " " << v <<endl;
        fu(i,0,vec[v].size()-1,1)
        {
            ll o=vec[v][i].first;
            ll j=vec[v][i].second;
            if(d[v] != j &&cha[j]>o&&d[j]!=INT_MAX)
            {
                d[j]=v;
                cha[j]=o;
                qu.push(ii(o,j));
                //cout <<j << " " << v << " " << o <<endl;
            }



        }


    }
    cout<<-1<<endl;
    return;
}
void nhap()
{

    cin >> n >> s >> t;

    fu(i,1,n,1)
    {
        cin >> a[i];

    }
    while( cin >> x >> y )
    {
        vec[x].pb(ii(abs( a[x] - a[y] ),y));
        vec[y].pb(ii(abs( a[x] - a[y] ),x));
    }
    fu(i,1,n,1)
    {
        d[i]=i;
        cha[i]=INT_MAX;
    }
    cha[s]=0;
    d[s]=INT_MAX;
    solve();
}
int main()
{
    IOS
    inti();
    nhap();

}


