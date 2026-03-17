#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int maxTempMin = 0;
double tempMin[4];
int maxTempMax = 0;
double tempMax[4];
int maxPrec = 0;
double prec[4];

int totalPrec()
{
    int res = 0;

    for (int i = 0; i < 4; i++)
    {
        res += prec[i];
    }
    return res;
}

int calcTempMaxAvg()
{
    int res = 0;

    for (int i = 0; i < 4; i++)
    {
        res += tempMax[i];
    }
    return res / 3;
}

int calcTempMinAvg()
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        res += tempMin[i];
    }
    return res / 3;
}

void dispTabs()
{
    cout << "TempMin:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << tempMin[i] << endl;
    }
    cout << "TempMax:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << tempMax[i] << endl;
    }
    cout << "Prec:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << prec[i] << endl;
    }
}

bool checkAndReadFile(string fileName)
{
    ifstream file(fileName);
    string line, token;
    int ctn = 0;
    int skip = 0;

    if (!file.is_open())
    {
        cout << "Can't open File" << endl;
        return false;
    }
    while (getline(file, line)) {
        istringstream iss(line);
        while(ctn != 0 && getline(iss, token, ','))
        { 
            switch (skip)
            {
            case 1:
                tempMin[maxTempMin] = stod(token);
                maxTempMin++;
                break;
            case 2:
                tempMax[maxTempMax] = stod(token);
                maxTempMax++;
                break;
            case 3:
                prec[maxPrec] = stod(token);
                maxPrec++;
                break;
            default:
                break;
            }
            skip++;
        }
        ctn++;
        skip = 0;
    }
    file.close();
    return true;
}

int main ()
{
    string fileName;

    cout << "Entrer le nom du csv:" << endl;
    getline(cin, fileName);
    if (!checkAndReadFile(fileName))
    {
        cout << "Invalid file or can't read file" << endl;
        return -1;
    }
    // dispTabs();
    cout << "Moyenne temp min: " << calcTempMinAvg() << endl;
    cout << "Moyenne temp max: " << calcTempMaxAvg() << endl;
    cout << "Total des precipitations: " << totalPrec() << endl;

    return 0;    
}