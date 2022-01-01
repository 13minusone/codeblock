#include<bits/stdc++.h>
using namespace std;
#define task "shipping"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<ll,ll> ii;
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
ll  a,b;
vector<ii>vec,vec1;
void nhap()
{
    ll n, k,h;
    cin >> n >> k;
    h=k;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a >> b;
        if(a>0)
        {
            vec.push_back({a,b});
        }
        else
        {
            vec1.push_back({-a,b});
        }

    }
    sort(vec.begin(),vec.end());
    sort(vec1.begin(),vec1.end());
    int i=0;
    ll s=0;
    while(i<SZ(vec1))
    {
        if(vec1[i].second>k)
        {
            s+=abs(vec1[i].first*2);
            vec1[i].second-=k;
        }
        else
        {
            s+=abs(vec1[i].first*2);
            while(k>0)
            {
                if(k>=vec1[i].second)
                {
                    k-=vec1[i].second;
                    vec1[i].second=0;
                    i++;
                }
                else
                {
                    vec1[i].second-=k;
                        k=0;
                }
            }
            k=h;
        }
    }
    i=SZ(vec)-1;
    //cout << i << endl;
    while(i>=0)
    {

        if(vec[i].second>k)
        {
            s+=abs(vec[i].first*2);
            vec[i].second-=k;
        }
        else
        {

            s+=abs(vec[i].first*2);
            while(k>0)
            {
                if(k>=vec[i].second)
                {
                    k-=vec[i].second;
                    vec[i].second=0;
                    i--;
                }
                else
                {
                    vec[i].second-=k;
                    k=0;

                }
            }
            k=h;
        }
    }
    cout << s<< endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}



