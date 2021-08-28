#include <bits/stdc++.h>
using namespace std;
int cmp = 0;
void print_ar(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
int getRandomNumber(int high, int low)
{
    srand(time(NULL));
    int randn = (rand() % (high - low)) + low;
    return randn;
}
int find(vector<int> &arr, int k)
{
    vector<int> small, large;
    int ar_len = arr.size();
    int seed = getRandomNumber(ar_len, 0);
    int y = arr[seed];
    for (int i = 0; i < arr.size(); i++)
    {
        cmp++;
        if (arr[i] == y)
        {
            continue;
        }
        if (arr[i] < y)
        {
            small.push_back(arr[i]);
        }
        else
        {
            large.push_back(arr[i]);
        }
    }
    if (small.size() == (k - 1))
    {
        return y;
    }
    else if (small.size() < (k - 1))
    {
        return find(large, k - (small.size() + 1));
    }
    else if (small.size() > (k - 1))
    {
        return find(small, k);
    }
}
void solve_rand_find(vector<int> &arr, int k)
{

    int num = find(arr, k);
    cout << "Num is :" << num << endl;
}
int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int tt;
    cin >> tt;
    int cnt = 0;
    cout << "----------------------------------------------------\n";
    while (tt--)
    {
        cnt++;
        cmp = 0;
        int n_elem, k;
        cin >> n_elem >> k;
        vector<int> arr;
        for (int i = 0; i < n_elem; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << "Case #" << cnt << endl;
        solve_rand_find(arr, k);
        cout << "NLogN comparisons:" << int(n_elem * log2(n_elem)) << endl;
        cout << "Total comparisons:" << cmp << endl;
        cout << "----------------------------------------------------\n";
    }
    return 0;
}