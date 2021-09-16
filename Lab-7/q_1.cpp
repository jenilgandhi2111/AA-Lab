/*********************************************************
Written by:  Jenil J Gandhi
Subject:     Advanced Algorithms
Lab-no:      07
Description: Implementing Intersection of two line segments
Guidance by: Prof Ashish K Gor
Date:        13/09/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
bool onsegment(pair<int, int> pi, pair<int, int> pj, pair<int, int> pk)
{
    int xi, xj, xk, yi, yj, yk;
    xi = pi.first;
    xj = pj.first;
    xk = pk.first;

    yi = pi.second;
    yj = pj.second;
    yk = pk.second;

    if ((min(xi, xj) <= xk && xk <= max(xi, xj)) && (min(yi, yj) <= yk && yk <= max(yi, yj)))
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    bool isFile = true;
    cout << "-----------------------------------------------------\n";
    int cc = 0;
    while (tt--)
    {
        cout << "Case:#" << ++cc << endl;
        // Taking Inputs
        pair<int, int> p1, p2, p3, p4;
        int x, y;

        cin >> x >> y;
        p1.first = x;
        p1.second = y;

        cin >> x >> y;
        p2.first = x;
        p2.second = y;

        cin >> x >> y;
        p3.first = x;
        p3.second = y;

        cin >> x >> y;
        p4.first = x;
        p4.second = y;

        // end of inputs
        int d1, d2, d3, d4;

        int x1 = p1.first;
        int x2 = p2.first;
        int x3 = p3.first;
        int x4 = p4.first;

        int y1 = p1.second;
        int y2 = p2.second;
        int y3 = p3.second;
        int y4 = p4.second;

        d1 = (x1 - x3) * (y4 - y3) - (x4 - x3) * (y1 - y3);
        d2 = (x2 - x3) * (y4 - y3) - (x4 - x3) * (y2 - y3);
        d3 = (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
        d4 = (x4 - x1) * (y2 - y1) - (x2 - x1) * (y4 - y1);

        if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        {
            cout << "Segments intersects\n";
        }
        else if (d1 == 0 && onsegment(p3, p4, p1))
        {
            cout << "Segments intersects\n";
        }
        else if (d2 == 0 && onsegment(p3, p4, p2))
        {
            cout << "Segments intersects\n";
        }
        else if (d3 == 0 && onsegment(p1, p2, p3))
        {
            cout << "Segments intersects\n";
        }
        else if (d4 == 0 && onsegment(p1, p2, p4))
        {
            cout << "Segments intersects\n";
        }
        else
        {
            cout << "Segment do not intersect\n";
        }
        cout << "-----------------------------------------------------\n";
    }
}