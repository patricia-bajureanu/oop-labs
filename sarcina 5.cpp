#include <iostream>
#include <cstring>

using namespace std;

class Profesor;

class Student {
private:
    char nume[50];
    int varsta;

public:
    Student(char* nume_initial, int varsta_initiala) {
        strcpy(nume, nume_initial);
        varsta = varsta_initiala;
    }
    friend class Profesor;
    void afiseaza_student() {
        cout << "Student: " << nume << ", Varsta: " << varsta << endl;
    }
};
class Profesor {
private:
    char nume[50];
    int experienta;

public:
    Profesor(char* nume_initial, int experienta_initiala) {
        strcpy(nume, nume_initial);
        experienta = experienta_initiala;
    }
    friend class Student;
    void afiseaza_profesor() {
        cout << "Profesor: " << nume << ", Experienta: " << experienta << " ani" << endl;
    }
    void verifica_student(Student& student) {
        cout << "Verificare student: " << student.nume << " are varsta de " << student.varsta << " ani." << endl;
    }
};
int main() {
    char nume_student[50];
    char nume_profesor[50];
    int varsta_student;
    int experienta_profesor;
    cout << "Introduceti numele studentului: ";
    cin.getline(nume_student, 50);
    cout << "Introduceti varsta studentului: ";
    cin >> varsta_student;
    cin.ignore(); // Ignorăm newline-ul rămas
    cout << "Introduceti numele profesorului: ";
    cin.getline(nume_profesor, 50);
    cout << "Introduceti experienta profesorului (in ani): ";
    cin >> experienta_profesor;
    Student student1(nume_student, varsta_student);
    Profesor profesor1(nume_profesor, experienta_profesor);
    student1.afiseaza_student();
    profesor1.afiseaza_profesor();
    profesor1.verifica_student(student1);
    return 0;
}
