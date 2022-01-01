#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int m,n;
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
}
struct node
{
    int vtri,val;
};
node x[2001];
bool cmp(node t,node f)
{
    if(t.val >  f.val)
    {
        return false;
    }
    return true;
}
void solve()
{
    fu(i,1,n,1)
    {
        if(sl-x[i].val!=sr)
        {
            vec.pb(x[i].vtri);
            int sz=vec.size();
            cout << sz<<endl;
            fu(f,0,sz-1,1)
            {
                cout << vec[f] << " ";
            }
            return;
        }
        else
        {
            fd(k,n,g+1,1)
            {
                if(sr-x[i].val!=sl)
                {
                    vec.pb(x[k].vtri);
                    int sz=vec.size();
                    cout << sz <<endl;
                    fu(f,0,sz-1,1)
                    {
                        cout << vec[f] << " ";
                    }
                    return;
                }

            }
        }
        sl-=x[i].val;

    }
}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        cin>>x[i].val;
        x[i].vtri=i;
    }
    sort(x+1,x+n+1,cmp);
//fu(i,1,n,1)cout << x[i].val <<" ";
    int sl=0,sr=0;
    int g=n/2;
    vector<int>vec;
    if(n==2)
    {
        if(x[1].val==x[2].val)
        {
            cout << 1 <<endl;
            cout << x[1].vtri ;

        }
        else
        {
            cout << "0" <<endl;
        }
        return;
    }

    fd(i,n,g,1)
    {
        sr+=x[i];
        sl=0;
        fu(j,1,i-1,1)
        {
            sl+=x[j];

        }
        if(sl==sr)
        {
            fu(i,1,n,1)
            {
                if(sl-x[i].val!=sr)
                {
                    vec.pb(x[i].vtri);
                    int sz=vec.size();
                    cout << sz<<endl;
                    fu(f,0,sz-1,1)
                    {
                        cout << vec[f] << " ";
                    }
                    return;
                }
                else
                {
                    fd(k,n,g+1,1)
                    {
                        if(sr-x[i].val!=sl)
                        {
                            vec.pb(x[k].vtri);
                            int sz=vec.size();
                            cout << sz <<endl;
                            fu(f,0,sz-1,1)
                            {
                                cout << vec[f] << " ";
                            }
                            return;
                        }

                    }
                }
                sl-=x[i].val;

            }
        }

    }
}
int main()
{
    IOS
//inti()
    nhap();

}

