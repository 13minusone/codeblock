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
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 1000000;
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
ll a[maxsize+5],s=0;
deque<int>vec;
void nhap()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(i>=2)
        {
            if(a[i]-a[i-1]<0)
            {
                s++;
                vec.push_back(i);
            }
        }
    }
    if(a[1]<a[n])
    {
        vec.push_front(1) ;
    }
    if(vec.size()==0||n==k)
    {
        cout << n << endl;
        for(int i = 1 ; i <= n ; i++)
        {
            cout << i << " ";
        }
        return;
    }
    if(vec.size()-1<=k)
    {if(vec.size()-1==k)
    {
        cout << vec.size() << endl;
        while(!vec.empty())
        {
            cout << vec.front() << " ";
            vec.pop_front();
        }
    }
    else
    {
        cout << n  << endl;
      for(int i = 1 ; i <= n ; i++)
        {
            cout << i << " ";
        }
        return;
    }
    }
    else
    {
        cout << 0;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



