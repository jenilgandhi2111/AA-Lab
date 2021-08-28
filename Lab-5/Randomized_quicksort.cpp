/*********************************************************
Written by:  Jenil J Gandhi
Subject:     AA
Lab-no:      Lab-05
Description: Implementing Randomized Quicksort.
Guidance by: Prof Ashish Gor
Date:        13/08/2021
*********************************************************/

#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;
class sorting_algos
{
private:
    int len;
    int *arr;
    int comparisions = 0;
    /***********************************
    Helper Functions
    --> Below listed are the helper functions to perform
        sorting operations effectievely
    --> These are declared privately so that only class
        methods can access them
    ************************************/

    /*****************************************
     * This helper function takes two pointer arguments
       and swaps it
    ******************************************/
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    /******************************************
    This function takes low and high as arguments 
    This function is used by "Quick Sort"
    returns the sorted index
    ******************************************/
    int partition(int low, int high)
    {
        int start = low;
        int end = high;
        unsigned int c = 200;
        srand(time(0));
        int pivot = int((rand() % (high - low)) + low);
        while (start < end)
        {

            while (arr[start] <= arr[pivot])
            {
                comparisions++;
                start++;
            }
            while (arr[end] > arr[pivot])
            {
                comparisions++;
                end--;
            }
            if (start < end)
            {
                swap(&arr[start], &arr[end]);
            }
        }

        swap(&arr[pivot], &arr[end]); //swapping with pivot

        return end;
    }

    /****************************************************
    End of helper functions
    ****************************************************/

public:
    //This constructor takes an array and its length as arguments
    sorting_algos(int length, int array[])
    {
        len = length;
        arr = array;
    }

    //default constructor to notify that provide arguments
    sorting_algos()
    {
        cout << "Please call parameterized constructor";
    }

    /***************************************
     * Code for bubble sort
     * Time Complexity worst case O(N^2)
     * Time Complexity Average case O(NlogN)
    ***************************************/
    void quick_sort(int low, int high)
    {
        if (low < high)
        {
            int part = partition(low, high);
            quick_sort(low, part - 1);
            quick_sort(part + 1, high);
        }
    }

    /***************************************
     * Code for Printing Array
     * This function prints array in space separated manner
    ***************************************/
    void print_arr()
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nTotal comparisions:" << comparisions << endl;
        cout << "NLogN comparisions:" << 2 * int(log2(len) * len) - 2 * len << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sorting_algos s1(n, arr);

    //Uncomment the code to see
    s1.quick_sort(0, n);

    s1.print_arr();
}