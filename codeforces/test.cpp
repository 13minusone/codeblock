#include<bits/stdc++.h>
using namespace std;
long long a,s,t,x,y,z,cnt,i;
string b;
void fre(){
    if(fopen("c9.inp","r")){
        freopen("c9.inp","r",stdin);
        freopen("c9.out","w",stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void solve(){
    b.clear();
    while(a>0){
        x=a%10;
        if(x>s%10&&(s/10)%10!=1){
            cout<<-1<<endl;
            return;
        }
        a/=10;
        y=0;
        if(x==0){
            y=s%10;
            s/=10;
        }
        else if(s%10==0){
            y=10;
            s/=100;
        }
        while(y<x&&s>0){
            if(y==0)y=s%10;
            else y=s%10*10+y;
            s/=10;
        }
        if(s<a){
            // cout<<s<<' '<<a<<endl;
            cout<<-1<<endl;
            return;
        }
        b=to_string(y-x)+b;
        // cout<<x<<' '<<y<<' '<<a<<' '<<b<<' '<<s<<endl;
    }
    // cout<<x<<' '<<y<<' '<<a<<' '<<b<<' '<<s<<endl;
    if(b.size()>1)for(i=0;i<b.size();i++)if(b[i]!='0')break;
    if(s>0)cout<<s<<b<<endl;
    else if(b.size()>1) cout<<b.substr(i,b.size()-i)<<endl;
    else cout<<b<<endl;
}
main(){
    fre();
    for(cin>>t;t--;){
        cin>>a>>s;
        solve();
    }
}
