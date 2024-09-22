#include <iostream>
#include <cstring>

using namespace std;

class Carte {
public:
    char titlu[40], autor[25], ISBN[20];
    Carte(char* t,char* a,char* i) {
        strcpy(titlu, t);
        strcpy(autor, a);
        strcpy(ISBN, i);
    }
    void display() {
        cout<<"Titlu: "<<titlu<<endl;
        cout<<"Autor: "<<autor<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
    }
};
class Biblioteca {
    Carte *carti[100];
    int nr_de_carti;
public:
    Biblioteca() {
        nr_de_carti=0;
    }
    void adauga_carte(Carte *carte) {
        if(nr_de_carti<100) {
            carti[nr_de_carti]=carte;
            nr_de_carti++;
            cout<<"Cartea a fost adaugata"<<endl;
        }else {
            cout<<"Biblioteca este plina"<<endl;
        }
    }
    void elimina_carte(char *isbn) {
        for (int i = 0; i < nr_de_carti; i++) {
            if (strcmp(carti[i]->ISBN, isbn) == 0) {
                delete carti[i];
                for(int j = i; j < nr_de_carti-1; j++) {
                    carti[j] = carti[j+1];
                }nr_de_carti--;
                cout<<"Cartea cu ISBN: "<<isbn<<"a fost eliminata"<<endl;
                return;
            }
        }
        cout<<"Cartea cu ISBN"<<isbn<<"nu a fost gasita"<<endl;
    }
    void afisare_carti() {
        if(nr_de_carti==0) {
            cout<<"Biblioteca este goala"<<endl;
        }else {
            cout<<"Cartile din biblioteca: "<<endl;
            for(int i = 0; i < nr_de_carti; i++) {
                carti[i]->display();
                cout<<endl;
            }
        }
    }
};
int main() {
    Biblioteca biblioteca;
    int nr_de_carti;
    cout << "Cate carti doriti sa adaugati? "<<endl;
    cin >> nr_de_carti;
    cin.ignore();
    for(int i = 0; i < nr_de_carti; i++) {
        char titlu[40], autor[25], ISBN[20];
        cout << "Introduceti titlul cartii " << i + 1 << ": ";
        cin.getline(titlu, 40);
        cout << "Introduceti autorul cartii " << i + 1 << ": ";
        cin.getline(autor, 25);
        cout << "Introduceti ISBN-ul cartii " << i + 1 << ": ";
        cin.getline(ISBN, 20);
        Carte* carte = new Carte(titlu, autor, ISBN);
        biblioteca.adauga_carte(carte);
    }
    cout << "\nToate cartile din biblioteca:" << endl;
    biblioteca.afisare_carti();
    char isbn_de_eliminat[20];
    cout << "\nIntroduceti ISBN-ul cartii pe care doriti sa il eliminati: ";
    cin.getline(isbn_de_eliminat, 20);
    biblioteca.elimina_carte(isbn_de_eliminat);
    cout << "\nToate cartile din biblioteca dupa eliminare:" << endl;
    biblioteca.afisare_carti();
    return 0;
}