#include <iostream>
#include <cstring>
using namespace std;
class Persoana {
protected:
    char nume[50];
    int varsta;
public:
    Persoana(char* nume_initial, int varsta_initiala) {
        strcpy(nume, nume_initial);
        varsta = varsta_initiala;
    }
    void afiseaza_persoana() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << " ani" << endl;
    }
    char* get_nume() {
        return nume;
    }
    int get_varsta() {
        return varsta;
    }
};
class Student : public Persoana {
private:
    char universitate[50];

public:
    Student(char* nume_initial, int varsta_initiala, const char* universitate_initiala)
        : Persoana(nume_initial, varsta_initiala) {
        strcpy(universitate, universitate_initiala);
    }
    void afiseaza_student() {
        afiseaza_persoana();
        cout << "Universitate: " << universitate << endl;
    }
    void set_universitate(char* universitate_noua) {
        strcpy(universitate, universitate_noua);
    }
};

int main() {
    char nume[50];
    int varsta;
    char universitate[50];

    cout << "Introduceti numele studentului: ";
    cin.getline(nume, 50);
    cout << "Introduceti varsta studentului: ";
    cin >> varsta;
    cin.ignore();
    cout << "Introduceti universitatea studentului: ";
    cin.getline(universitate, 50);
    Student student1(nume, varsta, universitate);
    cout << "\nDatele studentului sunt:\n";
    student1.afiseaza_student();
    return 0;
}
