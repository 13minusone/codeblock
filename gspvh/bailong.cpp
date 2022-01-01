#include<bits/stdc++.h>
using namespace std;
#define task "run"
#define pb push_back
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
int n, k, d[int(1e6)+5], s=0;
int main()
{
    fastio();
    //init();
    cin >> n >> k;
    deque<int> dq;
    for(int i=1; i<=n; i++)
    {
        cin >> d[i];
        if (d[i]-d[i-1]<0)
        {
        dq.push_back(i);
        }
    }

   if(d[n]>d[1])
   {
       dq.push_front(1);
   }
   //cout << dq.size();
   if((int)dq.size()<k+1||n==k)
   {

        cout << n << endl;
        for(int i = 1 ; i <= n ; i++)
        {
            cout << i << " ";
        }
        return 0 ;
   }
   if(dq.size()-1==k)
    {
        cout << dq.size() << endl;
        while(!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else
    {
        cout << 0 << endl;
    }
}

