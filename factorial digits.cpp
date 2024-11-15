#include <bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int findDigits1(int n)
{
    // factorial exists only for n>=0
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // else iterate through n and calculate the
    // value
    double digits = 0;
    for (int i=2; i<=n; i++)
        digits += log10(i);

    return floor(digits) + 1;
}

int findDigits2(int n)
{
    int r;
    if(n<0)
        r=0;
    else if(n<=3)
        r=1;
    else if(n>3 && n<=5)
        r=n-2;
    else
        r=n-3;
    return r;
}
int main()
{
    optimize();
    int n,r;
    cin >> n;
    cout << "Ans-1:" << findDigits1(n) << endl;//find the Number of digits of n!-rule-1
    cout << "Ans-2:" << findDigits2(n) << endl;//find the Number of digits of n!-rule-2
    return 0;
}
