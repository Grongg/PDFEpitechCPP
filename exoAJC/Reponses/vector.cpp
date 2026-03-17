#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dispVect(vector<int> vect)
{
    for (int elem : vect)
        cout << elem << " ";
    cout << endl;
}

void sumVec(vector<int> vect1, vector<int> vect2)
{
    vector<int> vecres;
    
    vecres.resize(vect1.size());
    vecres.shrink_to_fit();

    for (int i = 0; i < vect1.size(); i++)
        vecres[i] = vect1[i] + vect2[i];
    dispVect(vecres);
}

vector<int> suppDup(vector<int> vect)
{
    std::vector<int>::iterator it;

    for (int i = 0; i < vect.size(); i++)
    {
        while (find(vect.begin() + i + 1, vect.end(), vect[i]) != vect.end())
        {
            it = find(vect.begin() + i + 1, vect.end(), vect[i]);
            vect.erase(vect.begin() + (it - vect.begin()));
        }
    }
    

    return vect;
}

int main()
{
    vector<int> vect1 = {1, 2, 3, 4};
    vector<int> vect2 = {5, 6, 7, 8};
    vector<int> vect3 = {1, 2, 2, 4, 0, 0, 4};

    sumVec(vect1, vect2);
    vect3 = suppDup(vect3);
    dispVect(vect3);

    return 0;
}