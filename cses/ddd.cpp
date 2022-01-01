#include<bits/stdc++.h>
#define   ll                          long long int
#define   fo(number1,number2,number3) for(int number1=number2;number1<=number3;++number1)
#define   pi                          pair<int,int>
#define   vi                          vector<int>
#define   pb                          push_back
#define   fastio                      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define   cps                         CLOCKS_PER_SEC
#define   decimal(k)                  fixed<<setprecision(k)
#define   PI                          3.14159265359
#define   F                           first
#define   S                           second
#define   all(A)                      (A).begin(),(A).end()
#define   mymax                       1000000000000000001
#define   mymin                      -1000000000000000001
#define   mod                         (ll)1000000007ll
#define   SZ                          sizeof
#define   test(t_case)                "Case #"<<t_case<<": "
//#include <unordered_set>
using namespace std;
//int dx[]={0,1,0,-1};
//int dy[]={1,0,-1,0};
//int dx[]={0,1,1,-1,0,-1,1,-1};
//int dy[]={1,0,1,0,-1,-1,-1,1};
//int dx[]={1,1,2,2,-1,-1,-2,-2};
//int dy[]={2,-2,1,-1,2,-2,1,-1};

ll power(ll x,ll y,ll m){            //power(x,y)=x^y  %m;
    if(y==0)return 1;
    ll a=power(x,y/2,m);
    if(y%2){
        return (a*((a*x)%m))%m;
    }
    else{
        return (a*a)%m;
    }
}
ll mod_inverse(ll x,ll m){
    return power(x,m-2,m);
}
ll fact(ll n,ll m){
    if(n<=1)return 1;
    return (fact(n-1,m)*n)%m;
}
ll ncr(ll n,ll r,ll m){
    if(r>n || r<0)return 0;
    if(n<0)return 0;
    ll n1=1,d1=1,d2=1;
    n1=fact(n,m);d1=fact(r,m);d2=fact(n-r,m);
    ll ans=mod_inverse((d1*d2)%m,m);
    ans=(ans*n1)%m;
    return ans;
}

/***************************code begins here*****************************/

class solver{
	public:
	vi vec;
	ll n;
	int k;
	vi ans;
	int taken[10];

	bool recur(int i,int rem){
		if(i<0){
			return true;
		}
		bool fg=false;
		int b=vec[i];
		ans[i]=b;
		if(rem!=0){
			if(taken[b]) fg = recur(i-1,rem);
			else {
				taken[b]=1;
				fg = recur(i-1,rem-1);
				taken[b]=0;
			}
			if(fg)return true;
			if(b!=9){
				ans[i]=b+1;
				if(rem>1 || taken[b+1]==1){
					taken[0]=1;
				}
				taken[b+1]=1;
				fun(i-1);
				return true;
			}
		}
		else{
			if(taken[b]){
				fg = recur(i-1,rem);
				if(fg)return true;
			}
			fo(j,b+1,9){
				if(taken[j]){
					fun(i-1);
					ans[i]=j;
					return true;
				}
			}
		}
		if(fg)return true;
		return false;
	}
	void fun(int i){
		fo(j,0,9){
			if(taken[j]){
				fo(u,0,i)ans[u]=j;
				return;
			}
		}
	}
	void solve(){
		cin>>n>>k;
		ll x=n;
		while(x!=0){
			int b = (int)(x%10ll);
			vec.pb(b);
			x/=10ll;
		}
		int len=vec.size();
		ans.resize(len);
		fo(i,0,9)taken[i]=0;
		recur(len-1,k);
		for(int i=len-1;i>=0;--i)cout<<ans[i];
		cout<<'\n';
	}
};

int main(){
	fastio
	int test=1;
	cin>>test;
	while(test--){
		solver o;
		o.solve();
	}
}




