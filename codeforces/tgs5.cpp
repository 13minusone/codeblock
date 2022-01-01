#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int  j=1;
    for(int i = 1 ; i <=n ; i++)
    {
        int o=i;
        for(int k =1 ; k<=j ; ++k)
        {
            cout << o << " ";
            o++;
            if(o>n)
            {
                o=o-n;
            }

        }
        j++;
        cout << endl;
    }
}
