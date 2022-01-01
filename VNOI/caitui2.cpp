#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <cstdio>
#include <vector>
using namespace std;
template <class T> inline bool maxx(T &A,T B){return A < B ? (A = B,1) : 0;}
#define pb push_back
int n, m, res;
vector<int> f, d(10001);
signed main(){
//    freopen("c.inp","r",stdin);
    scanf("%d%d",&n,&m); f.pb(0);
    while(n--){
        int w, v, a; scanf("%d%d%d",&w,&v,&a);
        vector<int> new_d = d;
        for(int i = 1,k = w;i <= a && k <= m;++i, k += w){
            bool ok = 1;
            for(auto j : f){
                if(j + k <= m){
                    if(maxx(new_d[j+k], d[j] + v*i))ok = 0;
                }
                else break;
            }
            if(ok)break;
        }
        if(!n){
            for(int i = 1;i <= m;++i)res = max(res, new_d[i]);
            printf("%d",res);
            break;
        }
        f.clear(); f.pb(0); d = new_d;
        for(int i = 1;i <= m;++i)if(d[i])f.pb(i);
    }
}
