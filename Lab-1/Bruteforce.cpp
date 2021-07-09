/*********************************************************
Written by:  Jenil J Gandhi
Subject:     OS
Lab-no:      Lab-1 
Description: Implementing Bruteforce string matching Algorithm
Guidance By: Prof Malay Bhatt
Date:        09/07/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string source, pattern;
        int match = 0;
        cin >> source >> pattern;
        for (int i = 0; i < source.size(); i++)
        {
            if (pattern[0] == source[i])
            {
                bool flag = true;
                for (int j = 1; j < pattern.size(); j++)
                {
                    if (pattern[j] != source[i + j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    match++;
                }
            }
        }
        cout << "> The match occured " << match << " times\n";
    }
}