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
string s,r;
int vtri[maxsize+5];
vector<int>d[200];
void nhap()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s >> r;
        s=" "+s;
        for(int i ='a'; i<='z'; i++)
        {
            d[i].clear();
        }
        if(s.size()<r.size())
        {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 1 ; i <(int)s.size(); i++)
        {
            vtri[i]=0;
            d[s[i]].push_back(i);
        }
        bool tr=false;
        for(int i = 1 ; i<(int)r.size(); i+=2)
        {
            tr=false;
            for(int j = 0 ; j<(int)d[r[i]].size(); j++)
            {
                if(d[r[i]][j]<vtri[i-2])
                {
                    continue;
                }
                for(int k=0; k<(int)d[r[i-1]].size(); k++)
                {
                    int s=d[r[i]][j]-d[r[i-1]][k]-1;
                    cout << i << " " << d[r[i]][j] <<" " << d[r[i-1]][k]<< " " << s<<" " << j << " " << k << endl;
                    if(s<0)
                    {
                        continue;
                    }
                    if(s%2==0)
                    {
                        if(i>=3)
                        {
                            if(vtri[i-2]<d[r[i]][j]&&vtri[i-2]<d[r[i-1]][k])
                            {
                                tr=true;
                                vtri[i]=d[r[i]][j];
                                vtri[i-1]=d[r[i-1]][k];
                                break;
                            }
                        }
                        else
                        {
                            tr=true;
                            vtri[i]=d[r[i]][j];
                            vtri[i-1]=d[r[i-1]][k];
                            break;
                        }
                    }
                }
                if(tr==true)
                {
                    break;
                }
            }


            if(tr==false)
            {
                cout << "NO" << endl;
                break;
            }
        }

        if(r.size()%2!=0&&tr==true)
        {
            bool te=false;
            for(int i = d[r[(int)r.size()-1]].size()-1; i>=0; i--)
            {
                if(d[r[(int)r.size()-1]][i]>vtri[(int)r.size()-2])
                {
                    //cout << i << " "<<d[r[(int)r.size()-1]][i] << " " << vtri[(int)r.size()-2] ;
                    te=true;
                    break;
                }
            }
            tr=te;
            if(tr==false)
            {
                cout << "NO" << endl;
            }
        }
        if(tr==true)
        {
            cout << "YES" << endl;
        }


    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



