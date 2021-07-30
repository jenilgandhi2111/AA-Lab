/*********************************************************
Written by:  Jenil J Gandhi
Subject:     AA
Lab-no:      Lab-03
Description: To implement transition table
Guidance by: Prof Malay Bhatt
Date:        28/07/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        map<int, pair<int, int>> transition_table;
        int n_states;
        cout << "Enter no of states:";
        cin >> n_states;
        for (int i = 0; i < n_states; i++)
        {
            cout << "Enter transition of state " << i << " in order a,b:" << endl;
            int a, b;
            cin >> a >> b;
            transition_table[i] = make_pair(a, b);
        }
        cout << "Enter accepting state:";
        int ac_state;
        cin >> ac_state;
        cout << endl;
        string src;
        cout << "Enter source string:";
        cin >> src;

        int cur_state = 0;
        int matches = 0;
        for (int i = 0; i < src.length(); i++)
        {
            if (src[i] == 'a')
            {
                cur_state = transition_table[cur_state].first;
            }
            else if (src[i] == 'b')
            {
                cur_state = transition_table[cur_state].second;
            }

            if (cur_state == ac_state)
            {
                matches++;
            }
        }
        cout << "Total matches:" << matches << endl;
    }
}