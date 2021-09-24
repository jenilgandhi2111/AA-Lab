#include <bits/stdc++.h>
using namespace std;
void fin()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class input
{

public:
    vector<vector<int>> vecTable;
    vector<int> originVector;
    input(vector<int> originVector)
    {
        this->originVector = originVector;
    }
    void addVector(vector<int> v)
    {
        this->vecTable.push_back(v);
    }
    void printVec(vector<int> v1)
    {
        for (auto x : v1)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    void printData()
    {
        cout << "Origin Vector:" << endl;
        printVec(originVector);
        for (auto x : vecTable)
        {
            printVec(x);
        }
    }

    // Optimized method to subtract two vectors
    vector<int> subtractVectors(vector<int> v1, vector<int> v2)
    {
        vector<int> contextVector = v2;
        vector<int> compareVector = v1;

        for (int i = 0; i < contextVector.size(); i++)
        {
            vector<int>::iterator it;
            it = find(compareVector.begin(), compareVector.end(), contextVector[i]);
            if (it != compareVector.end())
            {
                compareVector.erase(it);
            }
        }
        return compareVector;
    }

    vector<int> findIntersection(vector<int> v1, vector<int> v2)
    {
        vector<int> final_vec;
        for (int i = 0; i < v1.size(); i++)
        {
            vector<int>::iterator it;
            it = find(v2.begin(), v2.end(), v1[i]);
            if (it != v2.end())
            {
                final_vec.push_back(v1[i]);
            }
        }
        return final_vec;
    }
};
void solveVertexCover(input ip)
{
    int count = 0;
    vector<int> contextVector = ip.originVector;
    vector<int> finalVec;
    vector<vector<int>> finalsVec;
    while (count != ip.originVector.size())
    {
        // first we do a context vector comparision
        vector<int> bestChoice;
        int cmp = -1;
        int idx = -1;
        for (int i = 0; i < ip.vecTable.size(); i++)
        {
            vector<int> temp = ip.vecTable[i];
            // now find intersection between context vector and temp
            vector<int> ret = ip.findIntersection(temp, contextVector);
            int size = ret.size();
            if (size > cmp && size != 0)
            {
                cmp = ret.size();
                bestChoice = temp;
                idx = i;
            }
        }
        // now erase the vector at the idx index of the ip.vecTable;
        if (idx == -1)
        {
            break;
        }
        finalVec.push_back(idx);
        finalsVec.push_back(bestChoice);
        count += cmp;

        // now subtract the contextVector from the bestChoice;
        contextVector = ip.subtractVectors(contextVector, bestChoice);
        vector<vector<int>>::iterator it = ip.vecTable.begin();
        ip.vecTable.erase(it + idx);
    }
    for (auto x : finalsVec)
    {
        ip.printVec(x);
    }
}

int main()
{
    fin();
    int tt;
    cin >> tt;
    cout << "-----------------------------------------------------------\n";
    int nn = 0;
    while (tt--)
    {
        int n_elem;
        cin >> n_elem;
        vector<int> v;
        for (int i = 0; i < n_elem; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        input ip(v);
        int n_sets;
        cin >> n_sets;
        for (int i = 0; i < n_sets; i++)
        {
            int set_len;
            cin >> set_len;
            vector<int> v1;
            for (int j = 0; j < set_len; j++)
            {
                int temp;
                cin >> temp;
                v1.push_back(temp);
            }
            ip.addVector(v1);
        }
        cout << "Case: #" << ++nn << endl;
        solveVertexCover(ip);
        cout << "-----------------------------------------------------------\n";
    }
    return 0;
}