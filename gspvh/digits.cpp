/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
const ll mod =1e9+9;
const ll base = 311;
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
int d[10],d1[10];
int checkt(int d[],string t)
{
    int dm=0;
    for(int i = 0 ; i <SZ(t);i++)
    {
        int x=int(t[i]-'0');
        if(d[x]==0)
        {
            if(dm==1)
            {
                return -1;
            }
            if(i+1<SZ(t))
            {
                int z=int(t[i+1]-'0');
                if(x>0&&z<9)
                {
                    if(x==1&&i==0){}
                    else if(d[x-1]!=0&&d[z+1]!=0)
                    {
                        dm++;
                        i++;
                        continue;
                    }
                }
                if(x<9&&z>0)
                {
                    if(d[x+1]!=0&&d[z-1]!=0)
                    {
                        dm++;
                        i++;
                        continue;
                    }
                }
            }
             if(i-1>=0)
            {
                int z=int(t[i-1]-'0');
                if(x>0&&z<9)
                {
                    if(d[x-1]!=0&&d[z+1]!=0)
                    {
                        dm++;
                        continue;
                    }
                }
                if(x<9&&z>0)
                {
                    if(z==1&&i==1){}
                    else if(d[x+1]!=0&&d[z-1]!=0)
                    {
                        dm++;
                        continue;
                    }
                }
            }
            return -1 ;
        }
    }
    return dm;
}
void nhap()
{
    string s,t;
    cin >> s >> t;
    memset(d,0,sizeof d);
    for(int i = 0 ; i < SZ(s);i++)
    {
        d[s[i]-'0']++;
    }
    for(int i = 0 ; i < SZ(t);i++)
    {
        d1[t[i]-'0']++;
    }
    int dt,ds;
    dt=checkt(d,t);
    ds=checkt(d1,s);
    //cout << dt << endl;
    if(ds==0&&dt==0)cout << "friends";
    else if(ds==-1||dt==-1) cout << "nothing";
    else if(ds==1||dt==1) cout << "almost friends";
}
int main()
{

    fastio();
    // inti();
    nhap();
}




