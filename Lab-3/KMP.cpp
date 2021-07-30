/*********************************************************
Written by:  Jenil J Gandhi
Subject:     AA
Lab-no:      Lab-03
Description: Implementing KMP Algorithm for String Matching
Guidance by: Prof Malay Bhatt
Date:        23/07/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
void generate_pi_table(vector<int> &arr, string pattern)
{
    int k = -1;
    for (int i = 1; i < pattern.length(); i++)
    {
        while (k >= 0 && pattern[k + 1] != pattern[i])
        {
            k = arr[k];
        }
        arr[i] = ++k;
    }
}
void solve_KMP(string pattern, string source, vector<int> &pitable)
{
    int pattern_ptr = 0;
    int source_ptr = 0;
    int match = 0;
    for (int i = 0; source_ptr != source.length() + 1; i++)
    {
        if (pattern[pattern_ptr + 1] == source[source_ptr])
        {
            source_ptr++;
            pattern_ptr++;

            if (pattern_ptr == pattern.length() - 1)
            {
                pattern_ptr = pitable[pattern_ptr];
                cout << "Match found at index:"
                     << source_ptr - pattern.length() + 1 << endl;
                match++;
            }
        }
        else
        {
            if (pattern_ptr != 0)
            {
                pattern_ptr = pitable[pattern_ptr];
            }
            else
                source_ptr++;
        }
    }
    cout << "Total Matches:" << match << endl;
    cout << "------------------------------------------------\n";
}
int main()
{
    int tt;
    cin >> tt;
    cout << "------------------------------------------------\n";
    while (tt--)
    {
        string source, pattern;
        cin >> source >> pattern;
        pattern = '#' + pattern;
        vector<int> pie_table(pattern.length(), 0);
        pie_table[0] = -1;
        generate_pi_table(pie_table, pattern);
        solve_KMP(pattern, source, pie_table);
    }
    return 0;
}