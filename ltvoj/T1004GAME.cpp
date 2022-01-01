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
#define task "T1005GAME"
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
const int MAX_N = 2500;
int N, sum[MAX_N+1][MAX_N+1];
ii P[MAX_N];
 bool ycomp(ii p, ii q) { return p.second < q.second; }
int rsum(int x1, int y1, int x2, int y2)
{
  return sum[x2+1][y2+1] - sum[x2+1][y1] - sum[x1][y2+1] + sum[x1][y1];
}
void nhap()
{
cin >> N;
  for (int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    P[i] = make_pair(x,y);
  }
  sort(P, P+N);
  for (int i=0; i<N; i++) P[i].first = i+1;
  sort(P, P+N, ycomp);
  for (int i=0; i<N; i++) P[i].second = i+1;
  for (int i=0; i<N; i++) sum[P[i].first][P[i].second] = 1;
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
      sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
  long long answer = 0;
  for (int i=0; i<N; i++)
    for (int j=i; j<N; j++) {
      int x1 = min(P[i].first, P[j].first) - 1;
      int x2 = max(P[i].first, P[j].first) - 1;
      answer += rsum(0,i,x1,j) * rsum(x2,i,N-1,j);
    }
  cout << answer + 1 << "\n";
}
int main()
{

    fastio();
     inti();
    nhap();
}




