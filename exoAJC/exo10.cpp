#include <iostream>
#include <string>

using namespace std;

const int MAX_ETUDIANTS = 100;
string listeEtudiants[MAX_ETUDIANTS][2];
int nombreEtudiants = 0;

void ajouterEtudiant(string nom) {
    if (nombreEtudiants < MAX_ETUDIANTS) {
        listeEtudiants[nombreEtudiants][0] = nom;
        nombreEtudiants++;
        cout << "Etudiant ajouté avec succès !" << endl;
    } else {
        cout << "La liste est pleine. Impossible d'ajouter plus d'étudiants." << endl;
    }
}

void calcMoyenne()
{
    double ttl = 0, ttlEleves = 0;

    for (int i = 0; i < nombreEtudiants; i++) {
        if (!listeEtudiants[i][0].empty() && !listeEtudiants[i][1].empty())
        {
            ttl += stof(listeEtudiants[i][1]);
            ttlEleves++;
        }
    }
    cout << "La moyenne des eleves est de: " << ttl /  ttlEleves << endl;
}

void ajouterNoteToEtudiant(string nom, string note) {
    bool studentFound = false;

    for (int i = 0; i < nombreEtudiants; i++) {
        if (listeEtudiants[i][0] == nom) {
            listeEtudiants[i][1] = note;
            studentFound = true;
            break;
        }
    }
    if (!studentFound)
        cout << "Entudiant pas trouvé dans la liste des étudiants." << endl;
}

bool rechercherEtudiant(string nom) {
    for (int i = 0; i < nombreEtudiants; i++) {
        if (listeEtudiants[i][0] == nom) {
            return true;
        }
    }
    return false;
}

void afficherListe() {
    cout << "Liste des étudiants : " << endl;
    for (int i = 0; i < nombreEtudiants; i++) {
        cout << "Nom: " << listeEtudiants[i][0] << " Note: " << listeEtudiants[i][1] << endl;
    }
}

void trierListe() {
    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = i + 1; j < nombreEtudiants; j++) {
            if (listeEtudiants[i] > listeEtudiants[j]) {
                swap(listeEtudiants[i], listeEtudiants[j]);
            }
        }
    }
    cout << "Liste triée avec succès !" << endl;
}

int main() {
    int choix;
    string nom;
    string note;

    do {
        cout << "\nMenu : " << endl;
        cout << "1. Ajouter un étudiant" << endl;
        cout << "2. Ajouter une note à un étudiant" << endl;
        cout << "3. Rechercher un étudiant" << endl;
        cout << "4. Afficher la liste des étudiants" << endl;
        cout << "5. Afficher la moyenne des notes des étudiants" << endl;
        cout << "6. Trier la liste des étudiants" << endl;
        cout << "7. Quitter" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "Entrez le nom de l'étudiant : ";
                cin.ignore();
                getline(cin, nom);
                ajouterEtudiant(nom);
                break;
            case 2:
                cout << "Entrez le nom de l'étudiant : ";
                cin.ignore();
                cin.clear();
                getline(cin, nom);
                cout << "Entrez la note de l'étudiant : ";
                getline(cin, note);
                ajouterNoteToEtudiant(nom, note);
                break;
            case 3:
                cout << "Entrez le nom de l'étudiant à rechercher : ";
                cin.ignore();
                getline(cin, nom);
                if (rechercherEtudiant(nom)) {
                    cout << "L'étudiant est dans la liste." << endl;
                } else {
                    cout << "L'étudiant n'est pas dans la liste." << endl;
                }
                break;
            case 4:
                afficherListe();
                break;
            case 5:
                calcMoyenne();
                break;
            case 6:
                trierListe();
                break;
            case 7:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
        }

    } while (choix != 7);

    return 0;
}