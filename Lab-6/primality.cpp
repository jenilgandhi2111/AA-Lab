/*********************************************************
Written by:  Jenil J Gandhi
Subject:     AA
Lab-no:      Lab-06
Description: Implement fermats primality testing algorithm
Guidance by: Prof Ashish K Gor
Date:        28/08/2021
*********************************************************/
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int count_steps = 0;
void printLine()
{
    cout << "\n-------------------------------------------------\n";
}
ll getRandomNum()
{
    srand(time(0));

    return rand();
}

ll customPower(ll a, ll n, ll p, bool print = false)
{

    ll res = 1;
    a = a % p;
    while (n > 0)
    {
        count_steps++;
        if (n & 1)
        {
            res = (res * a) % p;
        }
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}
ll gcd(int a, int b, bool p = false)
{
    count_steps++;
    if (a < b)
    {
        return gcd(b, a);
    }
    else if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

bool check_prime(ll no, ll k = 100)
{
    // Now we try randomly for K numbers
    if (no <= 1 || no == 4)
        return false;
    if (no == 3)
        return true;
    while (k > 0)
    {
        int a = 2 + getRandomNum() % (no - 4);
        if (gcd(no, a) != 1)
        {
            // Number is composite
            gcd(no, a, true);
            return false;
        }
        if (customPower(a, no - 1, no) != 1)
        {
            return false;
        }
        k--;
    }
    return true;
}
ll count_digit(ll no)
{
    return (ll)(log10(no) + 1);
}
int main()
{
    freopen("ip2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int tt;
    cin >> tt;
    int c = 0;
    printLine();
    while (tt--)
    {
        count_steps = 0;
        cout << "Case:#" << c + 1 << endl;
        c++;
        ll no, k;
        cin >> no >> k;
        bool res = check_prime(no, k);
        if (res)
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Mostly not Prime" << endl;
        }
        int nlogn = (ll)log2(count_digit(no)) * k;
        cout << "Steps taken theoretically (K*log(n)):" << nlogn << endl
             << "Steps taken practically:" << count_steps << endl;
        printLine();
    }
}