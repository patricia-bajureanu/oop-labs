#include <iostream>
#include <cstring>
using namespace std;
class Student {
private:
    char nume[30];
    int varsta;
public:
    Student() {
        strcpy(nume, "Necunoscut");
        varsta = 0;
    }
    char* get_nume() {
        return nume;
    }
    int get_varsta() {
        return varsta;
    }
    void set_nume(char* nume_nou) {
        strcpy(nume, nume_nou);
    }
    void set_varsta(int varsta_noua) {
        varsta = varsta_noua;
    }
    void afiseaza_student() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << " ani" << endl;
    }
};
int main() {
    Student student;
    char nume[30];
    int varsta;
    cout << "Introduceti numele studentului: ";
    cin.getline(nume, 30);
    cout << "Introduceti varsta studentului: ";
    cin >> varsta;
    student.set_nume(nume);
    student.set_varsta(varsta);
    student.afiseaza_student();
    return 0;
}
