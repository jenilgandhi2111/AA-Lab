/*********************************************************
Written by:  Jenil J Gandhi
Subject:     Advanced Algorithms
Lab-no:      Lab-8
Description: Solve ConvexHull using JarvisMarch Algorithm
Guidance by: Prof Ashish K Gor
Date:        17/09/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;
void fin()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class Point
{
public:
    int x;
    int y;
    Point()
    {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setPoint(Point p)
    {
        this->x = p.x;
        this->y = p.y;
    }
    bool isSamePoint(Point a)
    {
        if (a.x == this->x && a.y == this->y)
        {
            return true;
        }
        return false;
    }
    void printPoint()
    {
        cout << "<" << this->x << "," << this->y << ">\n";
    }
};

// Handles all the PointList operations like finding the
// least x point printing point list etc..
class PointList
{
private:
    int leastIdx;

public:
    vector<Point> pointList;

    PointList(vector<Point> pointList)
    {
        this->pointList = pointList;
    }

    void printList(string message = "")
    {
        cout << message << endl;
        for (auto point : this->pointList)
        {
            cout << point.x << " " << point.y << endl;
        }
    }
    void setLowestXPoint()
    {
        int lowestX = INT_MAX;
        int idx = -1;
        int cntr = 0;
        for (auto point : this->pointList)
        {
            if (point.x < lowestX)
            {
                lowestX = point.x;
                idx = cntr;
            }
            cntr++;
        }
        // Now erase the point fron the vector and append it to the front.
        Point lowestXPoint(this->pointList[idx]);
        vector<Point>::iterator it = this->pointList.begin();
        this->pointList.erase(it + idx);
        this->pointList.insert(this->pointList.begin(), lowestXPoint);
    }
};

// This function check is the point c on left of line segment
// A and B returns 0 if no 1 if yes
bool isLeft(Point a, Point b, Point c)
{
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) > 0;
}

// function to solve ConvexHull by JarvisMarch
void solveJarvisMarch(PointList pointList)
{
    int idxCounter = 1;
    vector<Point> takenPoints;
    takenPoints.push_back(pointList.pointList[0]);
    int pointListLen = pointList.pointList.size();

    // Now we start iterating over points
    while (true)
    {
        Point bestPoint(pointList.pointList[0]);
        for (int i = 0; i < pointListLen; i++)
        {
            Point p1(takenPoints[takenPoints.size() - 1]);
            Point p2(bestPoint);
            Point p3(pointList.pointList[i]);
            // Now we check for is p3 left of p1 and p2.
            if (isLeft(p1, p2, p3) == 1)
            {
                // for Left turn.
                // we change bestPoint to p[i]
                bestPoint.setPoint(pointList.pointList[i]);
            }
            if (p1.isSamePoint(p2))
            {
                bestPoint.setPoint(pointList.pointList[i]);
            }
        }
        if (bestPoint.isSamePoint(takenPoints[0]))
        {
            break;
        }
        takenPoints.push_back(bestPoint);
    }
    cout << "\nConvex Hull points Are:" << endl;
    for (auto x : takenPoints)
    {
        x.printPoint();
    }
}

int main()
{
    fin();
    int tt;
    cin >> tt;
    cout << "-----------------------------------------------------\n";
    int n = 0;
    while (tt--)
    {
        // jarvis logic goes here
        int n_points;
        cin >> n_points;
        vector<Point> pointList;
        while (n_points--)
        {
            int x, y;
            cin >> x >> y;
            Point p(x, y);
            pointList.push_back(p);
        }
        PointList ptList(pointList);
        ptList.setLowestXPoint();
        cout << "Case:#" << ++n << endl;
        solveJarvisMarch(ptList);
        cout << "-----------------------------------------------------\n";
    }
    return 0;
}