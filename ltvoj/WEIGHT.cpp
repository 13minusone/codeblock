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
#define task "WEIGHT"
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
int l1[1000005],r1[1000005],l2[1000005],r2[1000005];
long long a[1000005];
int n;
void minleft()
{
	stack<int>st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>a[i])st.pop();
		if(st.empty())l1[i]=0;
		else l1[i]=st.top();
		st.push(i);
	}
}
void minright()
{
	stack<int>st;
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i])st.pop();
		if(st.empty())r1[i]=n+1;
		else r1[i]=st.top();
		st.push(i);
	}
}

void maxleft()
{
	stack<int>st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<a[i])st.pop();
		if(st.empty())l2[i]=0;
		else l2[i]=st.top();
		st.push(i);
	}
}
void maxright()
{
	stack<int>st;
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]<=a[i])st.pop();
		if(st.empty())r2[i]=n+1;
		else r2[i]=st.top();
		st.push(i);
	}
}
void nhap()
{
    cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	minleft(),minright(),maxleft(),maxright();
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long l=i-l2[i]-1;
		long long r=r2[i]-i-1;
		ans+=(l*r+l+r)*a[i];

	}
	for(int i=1;i<=n;i++){
		long long l=i-l1[i]-1;
		long long r=r1[i]-i-1;
		ans-=(l*r+l+r)*a[i];

	}
	cout<<ans;
}
int main()
{

    fastio();
    inti();
    nhap();
}




