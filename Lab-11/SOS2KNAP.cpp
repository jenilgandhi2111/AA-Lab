/*********************************************************
Written by:  Jenil J Gandhi
Subject:     Advanced Algorithms
Lab-no:      Lab-11
Description: Reduce sum of subset problem to solve 0/1 Knapsack
Guidance by: Prof Ashish K Gor
Date:        03/10/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
void fin()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
int solve_knapsack(vector<vector<int>> &dp, vector<int> w, vector<int> p, int c)
{
	int n = p.size();
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= c; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j < w[i - 1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
			}
		}
	}
	if (dp[n][c] == c)
	{
		cout << "Possible Subset" << endl;
		vector<int> ans;
		int i = n;
		while (c > 0 && i > 0)
		{
			if (w[i - 1] <= c && dp[i - 1][c - w[i - 1]] == (c - w[i - 1]))
			{
				ans.push_back(w[i - 1]);
				c -= w[i - 1];
			}
			i--;
		}
		for (auto k : ans)
			cout << k << " ";
		cout << endl;
	}
	else
	{
		cout << "Not Possible" << endl;
	}

	return dp[n][c];
}
int main()
{
	fin();
	int t;
	cin >> t;
	int cntr = 0;
	cout << "-----------------------------------------------------\n";
	while (t--)
	{
		int n, c;
		cin >> n >> c;
		vector<int> w(n), p(n);
		for (int i = 0; i < n; i++)
			cin >> w[i] >> p[i];
		vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
		cout << "Case #" << ++cntr << endl;
		solve_knapsack(dp, w, p, c);
		cout << "-----------------------------------------------------\n";
	}
}