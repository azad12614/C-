#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();
    long long int n,a[105],q,x,l,r,m,i;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    cin >> q;
    while(q--)
    {
        cin >> x;
        l=0;
        r=n-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(a[m]==x)
            {
                cout << "found" << endl;
                break;
            }
            else if(a[m]>x)
                l=m+1;
            else if(a[m]<x)
                r=m-1;
        }
        if(l>r)
            cout << "not found" << endl;
    }
    return 0;
}
