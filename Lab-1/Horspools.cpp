/*********************************************************
Written by:  Jenil J Gandhi
Subject:     OS
Lab-no:      Lab-1
Description: Implmenting Horspools Algorithm for string matching
Guidance By: Prof Malay Bhatt
Date:        09/07/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

void intitialize_array(int *arr, int size, int len)
{
    for (int i = 0; i < len; i++)
    {
        arr[i] = size;
    }
}
void construct_shift_table(int *arr, string pattern)
{
    int size = pattern.size();
    for (int i = 0; i < size - 1; i++)
    {
        int cidx = pattern[i] - 'a';
        arr[cidx] = size - i - 1;
    }
}
void solve_horspools(string source, string pattern)
{
    // Constructing shift table for the pattern string
    int arr[26];

    int match = 0;
    // Initializing array with pattern size
    intitialize_array(arr, pattern.size(), 26);

    // Function call to make shift table
    construct_shift_table(arr, pattern);
    cout << "Shift table" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int src_size = source.size();
    int pattern_size = pattern.size();
    int src_ptr = pattern_size - 1;
    int pattern_ptr = pattern_size - 1;
    cout << "------------------------------------------------------------\n";
    while (src_ptr < src_size)
    {
        /* Visualization of algorithm */
        cout << "Comparing:" << pattern[pattern_ptr] << " " << source[src_ptr] << endl;
        cout << "Source: " << source << endl;
        cout << "Pattern:";
        for (int k = 0; k < (src_ptr - pattern_ptr); k++)
        {
            cout << " ";
        }
        cout << pattern << endl;
        /* End of visualization */

        // If the char at src ptr and pattern ptr are not same
        // we move the pattern pointer using the shift table
        if (pattern[pattern_ptr] != source[src_ptr])
        {
            cout << "Characters did not matched\n";

            // Now we get the shift table value for pattern alphabet

            // Getting the index of the alphabet from the source string
            int alphaindex = source[src_ptr] - 'a';

            // Getting the shift value from source string
            int shift = arr[alphaindex];

            // increment source ptr
            src_ptr += shift;
        }
        else
        {
            bool flag = false;

            // Pattern matching loop
            for (int j = 1; j < pattern_size; j++)
            {
                if (pattern[pattern_ptr - j] != source[src_ptr - j])
                {
                    flag = true;
                    break;
                }
            }

            if (flag == true)
            {

                // If the char donot match at any location then
                // we just shift the string by last char of source pattern
                int charid = source[src_ptr] - 'a';
                int shift = arr[charid];
                src_ptr += shift;
                cout << "Strings did not matched\n";
            }
            else
            {
                // Else there is a match of pattern
                // Now we increment the src_ptr by 1
                match++;
                src_ptr += 1;
                cout << "Match found\n";
            }
        }
        cout << "Matches:" << match << endl;
        cout << "------------------------------------------------------------\n";
    }
    cout << "Final matches:" << match;
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        string source, pattern;
        cin >> source >> pattern;
        solve_horspools(source, pattern);
    }
}