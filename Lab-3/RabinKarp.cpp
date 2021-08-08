/*********************************************************
Written by:  Jenil J Gandhi
Subject:     AA
Lab-no:      Lab-03
Description: Rabin Karp Algorithm Implementation
Guidance by: Prof Malay Bhatt
Date:        23/07/2021
*********************************************************/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll int gethashvalue(int base, int power)
{
    ll int x = (pow(float(base), float(power)));
    return x;
}
void solve_rabin_karp(string source, string pattern)
{
    int d = pattern.size();
    ll int hashvalue = 0;

    // Defining initial hash value for the pattern;
    for (int i = 0; i < pattern.size(); i++)
    {
        hashvalue += gethashvalue(10, d - i - 1) * (pattern[i] - 'a' + 1);
    }
    ll int src_hash = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        src_hash += gethashvalue(10, d - i - 1) * (source[i] - 'a' + 1);
    }
    int end_ptr = pattern.size() - 1;
    int match = 0;
    for (int i = 0; end_ptr != source.size(); i++)
    {
        if (hashvalue == src_hash)
        {
            int cont = 0;
            bool flag = false;
            for (int j = i; j != end_ptr + 1; j++, cont++)
            {
                if (pattern[cont] != source[j])
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Match found at index:" << i << endl;
                match++;
            }
        }
        src_hash -= gethashvalue(10, pattern.size() - 1) * (source[i] - 'a' + 1);
        src_hash *= 10;
        end_ptr++;
        src_hash += (source[end_ptr] - 'a' + 1);
    }
    cout << "Total Matches:" << match << endl;
    cout << "----------------------------------------------------\n";
}
int main()
{
    int tt;
    cout << "Enter Testcase:";
    cin >> tt;
    cout << "------------------------------------------------\n";
    while (tt--)
    {
        cout << "Enter source and pattern string" << endl;
        string source, pattern;
        cin >> source >> pattern;
        solve_rabin_karp(source, pattern);
    }
}