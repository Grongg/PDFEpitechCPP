#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>
#include <unistd.h>

using namespace std;

bool checkFile(string fileName)
{
    std::ifstream file(fileName);

    if (file) {
        cout << "Fichier valide" << endl;
        file.close();
        return true;
    }
    else
        return false;
}

void writeInFile(string fileName, string text)
{

    string wantWrite;

    cout << "Do you want to overwrite the file ?" << endl;
    cout << "Veuillez entrer Oui ou O/o pour confirmer et Non ou N/n pour refuser" << endl;
    getline(cin, wantWrite);
    for (int i = 0; i < wantWrite.length(); i++)
        wantWrite[i] = tolower(wantWrite[i]);
    if (wantWrite == "oui" || wantWrite == "o")
    {
        std::ofstream file(fileName);

        if (!file.is_open())
            cout << "Can't open" << endl;
        file << text << endl;
        file.close();
    }
    else if (wantWrite == "non" || wantWrite == "n")
    {
        cout << "Vous avez refusé. Ecriture à la fin du fichier..." << endl;
        sleep(1);
        std::ofstream file(fileName, ios::app);

        if (!file.is_open())
            cout << "Can't open" << endl;
        file << text << endl;
        file.close();
    }
    else
    {
        cout << "Veuillez entrer une entrée valide exemple: n" << endl;
        writeInFile(fileName, text);
    }

}

void readFile(string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
        cout << "Can't open File" << endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void wantReadFile(string fileName)
{
    string wantRead;

    cout << "Voulez vous voir le contenu du fichier ?" << endl;
    cout << "Veuillez entrer Oui ou O/o pour confirmer et Non ou N/n pour refuser" << endl;
    getline(cin, wantRead);
    for (int i = 0; i < wantRead.length(); i++)
        wantRead[i] = tolower(wantRead[i]);
    if (wantRead == "oui" || wantRead == "o")
    {
        readFile(fileName);
    }
    else if (wantRead == "non" || wantRead == "n")
        cout << "Vous avez refusé. Sorti du programme." << endl;
    else
    {
        cout << "Veuillez entrer une entrée valide exemple: n" << endl;
        wantReadFile(fileName);
    }
}

int main()
{
    string fileName, text;

    cout << "Veuillez entrer le nom du fichier:" << endl;
    getline(cin, fileName);
    cout << "Veuillez entrer le texte à enregistrer dans le fichier:" << endl;
    getline(cin, text);
    if (!checkFile(fileName))
    {
        cout << "Fichier invalide" << endl;
        return -1;
    }
    writeInFile(fileName, text);
    wantReadFile(fileName);
    cout << "Sortie du programme" << endl;
    sleep(1);

    return 0;
}
