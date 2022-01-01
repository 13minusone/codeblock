#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
void nhap()
{
    int x,y,z,a,b,c;
    while(true)
    {
        cin >> x >> y >> z >> a >> b >> c;
        if(x==0)
        {
            break;
        }
        vector<pair<int,int>>vec;
        vec.push_back({max(x,y),min(x,y)});
        vec.push_back({max(z,a),min(z,a)});
        vec.push_back({max(c,b),min(b,c)});
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        ll s=0;
        s=s+vec[0].first*vec[0].second;
        fu(i,1,2,1)
        {
            if(vec[i].second > vec[i-1].second)
            {
                s=s+(vec[i].second-vec[i-1].second)*vec[i].first;
            }
            else
            {
                vec[i].second=vec[i-1].second;
            }
        }
        cout << s << endl;
        vec.clear();
    }
}
int main()
{
    fastio();
    nhap();
}

