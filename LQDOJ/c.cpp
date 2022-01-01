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
vector<int>vec[500];
int vt[500];
void nhap()
{
    string s;
    int k,h,n,maxx=0;
    cin >> s;
    n=SZ(s);
    s=" "+s;
    cin >> k;
    h=k;
    for(int i = 1 ; i <=n ; i++)
    {
        vec[s[i]].push_back(i);
        vt[s[i]]=0;
    }
    for(int i = 1 ; i<= n ; i++)
    {
        int su=1;
        int j=vt[s[i]];
        if(j==SZ(vec[s[i]])-1)
        {
            maximize(maxx,min(n-j+1,k+1));
            continue;
        }
        h=k;
        //cout << i << endl;
        while(h>=0)
        {
            //cout << i << " " << j << " " << su << endl;
            if(vec[s[i]][j+1]-vec[s[i]][j]-1<=h)
            {
                h-=(vec[s[i]][j+1]-vec[s[i]][j]-1);
                if(h<0)
                {
                    break;
                }
                su+=(vec[s[i]][j+1]-vec[s[i]][j]);
                j++;


            }
            else
            {
                if(h==0)
                {
                    break;
                }
                su+=h;
                h=0;
            }
            maximize(maxx,su);

            if(j==vec[s[i]].size())
                {
                    su+=min(h,n-vt[j-1]+1);
                    break;
                }
        }
         //cout << i << " " <<maxx << endl;
        vt[s[i]]++;


    }
    minimize(maxx,n);
    cout << maxx << endl;

}
int main()
{

    fastio();
    // inti();
    nhap();
}



