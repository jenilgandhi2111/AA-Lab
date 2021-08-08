/*********************************************************
Written by:  Jenil J Gandhi
Subject:     Advanced Algorithm
Lab-no:      Lab-04
Description: Implementing Convex Hull Using Graham Scan Algoritm
Guidance by: Prof Malay Bhatt
Date:        08/08/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

// Class Point to represent a point on the graph
class Point
{
public:
    double x, y;
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point() {}
    // Setpoint method to modify if required
    void setPoints(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    // Setpoint from any other point
    void setPoints(Point p)
    {
        this->x = p.x;
        this->y = p.y;
    }

    // Util method to print a point
    void print_point()
    {
        cout << "<" << this->x << "," << this->y << ">";
    }
};
// End of class Point

// Generic Class Stack
template <class T>
class Stack
{
private:
    vector<T> point_stack;
    int current_count = -1;

public:
    // Pushes an element to the top of the stack
    void push(T elem)
    {
        point_stack.push_back(elem);
        current_count++;
    }

    // Normal pop method used to remove top of stack
    T pop()
    {
        vector<Point>::iterator it = point_stack.begin();
        if (current_count == -1)
        {
            throw "OutOfBoundsException";
        }
        T ret_val = this->point_stack[current_count];

        this->point_stack.erase(it + current_count);
        current_count--;
        return ret_val;
    }

    // The pop method with id removes the nth element
    // from the top of the stack
    // ex: stack = |1,2,3,4 ->
    // pop(2) removes 3 from stack
    T pop(int idx)
    {
        vector<Point>::iterator it = point_stack.end();
        if (current_count == -1 || idx < -1 || idx > current_count)
        {
            throw "OutOfBoundsException";
        }
        T ret_val = this->point_stack[idx];
        this->point_stack.erase(it - idx);
        current_count--;
        return ret_val;
    }

    // Returns the size of the stack
    int size()
    {
        return this->current_count + 1;
    }

    // If the stack is empty it returns true else false
    bool isEmpty()
    {
        if (this->current_count == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // The getTopNElements method returns the
    // top n elements of the stack
    // Ex: Stack: |1,2,3,4,5
    // getTopNElements(3) -> returns(3,4,5)
    vector<T> getTopNElments(int n)
    {
        if (n - 1 > current_count)
        {
            throw "OutOfBoundsException";
        }
        else
        {
            vector<T> *temp_nums = new vector<T>;

            for (int i = 0; i < n; i++)
            {
                // point_stack[current_count - i].print_point();
                temp_nums->push_back(point_stack[current_count - i]);
            }
            return *temp_nums;
        }
    }

    // This is a utility method to print stack
    void printStack()
    {
        if (this->current_count == -1)
        {
            cout << "Stack Empty";
        }
        else
        {
            for (auto i : this->point_stack)
            {

                i.print_point();
            }
        }
    }
};
// End of class Stack

Point lowest_point;

// This function is a util of a sort
// comparator function
int is_left_turn(Point a, Point b)
{
    double x0 = lowest_point.x;
    double y0 = lowest_point.y;
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;
    double cross_product = (x2 - x0) * (y1 - y0) - (x1 - x0) * (y2 - y0);
    if (cross_product == 0)
    {
        // points are colinear
        return 2;
    }
    else if (cross_product < 0)
    {
        //Yes the point a->b takes a left turn
        return 1;
    }
    else
    {
        //The points a->b takes a right turn.
        return 0;
    }
}

// Used to check left turn for 3 points
// Supply a as the base point
// rest b and c are the points to be compared
int is_left_turn_util(Point a, Point b, Point c)
{
    double x0 = a.x;
    double y0 = a.y;
    double x1 = b.x;
    double y1 = b.y;
    double x2 = c.x;
    double y2 = c.y;
    double cross_pdt = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (cross_pdt < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Comparator function used to sort the points
bool compare_points(Point a, Point b)
{
    if (is_left_turn(a, b) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve_convexhull(vector<Point> points, int lower_id)
{

    lowest_point.setPoints(points[lower_id]);
    vector<Point>::iterator it = points.begin();
    // Removing the lowest point from the ooriginal vector as
    // It would cause a DivideByZeroException
    points.erase(it + lower_id);

    // Sorting points based on their polar angles
    sort(points.begin(), points.end(), compare_points);

    Stack<Point> point_stack;
    // Adding the lowest point and the
    // first point of the sorted vector
    // to the stack
    point_stack.push(lowest_point);
    point_stack.push(points[0]);
    for (int i = 1; i < points.size(); i++)
    {
        point_stack.push(points[i]);

        // Looping unitl we get a left turn
        // Else we go on popping the second last point
        // from the stack.
        // There are 3 conditions possible
        // 1.) We get a left turn we break.
        // 2.) We are left with 3 elements
        // 3.) We donot get a left turn we pop.
        while (point_stack.size() > 3)
        {

            vector<Point> pts = point_stack.getTopNElments(3);
            Point x0 = pts[0];
            Point x1 = pts[1];
            Point x2 = pts[2];

            if (is_left_turn_util(x0, x1, x2) == 1)
            {
                break;
            }
            else
            {
                point_stack.pop(2);
            }
        }
    }

    // Printing the final result
    cout << "Convex Hull points:";
    point_stack.printStack();
    cout << "\n";
}

// Main function
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n_points;
        cin >> n_points;
        int lower_y_idx;
        double lowest_y = INFINITY;
        vector<Point> points;
        for (int i = 0; i < n_points; i++)
        {
            double x, y;
            cin >> x >> y;
            if (y < lowest_y)
            {
                lowest_y = y;
                lower_y_idx = i;
            }
            Point *p = new Point(x, y);
            points.push_back(*p);
        }
        solve_convexhull(points, lower_y_idx);
    }
    return 0;
}