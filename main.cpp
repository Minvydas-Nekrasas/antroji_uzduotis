#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

// Function to calculate the mean of homework grades
double rezultatas(const vector<int>& nd, int egz) { //taupom atmintį ir rodom į vektorių
    if (nd.empty()) return 0.00; 
    int sum = 0;
    for (int grade : nd) {
        sum += grade;
    }
    double vid = sum / nd.size();
    double rez = 0.4 * vid + 0.6 * egz;
    return rez;
}

int main(){
    vector<Studentas> studentai;
    int darbai, pazymys, stud_skaicius;

    cout << "Kiek bus studentų? ";
    cin >> stud_skaicius;

    //Prašom duomenų ir juos įrašom į struktūrą kiekvienam studentui
    for (int i = 0; i < stud_skaicius; ++i) {
        Studentas x;
        cout << "\nDuomenys studento nr. " << i + 1 << ":\n";

        cin.ignore(); //išvengiam \n bug'os

        cout << "Įrašyk studento vardą: ";
        getline(cin, x.vardas);

        cout << "įrašyk studento pavardę: ";
        getline(cin, x.pavarde);

        cout << "Kiek namų darbų? ";
        cin >> darbai;
        x.nd.resize(darbai);  // Resize the vector to hold the homework grades

        for (int j = 0; j < darbai; ++j) {
            cout << "Įrašyk namų darbo pažymį " << j + 1 << ": ";
            cin >> x.nd[j];  // Įdedam į vektorių
        }

        cout << "Įrašyk egzamino rezultatą: ";
        cin >> x.egz;

        studentai.push_back(x);  // Įdedam studentą į vektorių
    }
    // Atspausdinam studentų duomenis
    cout << "\nPavardė\tVardas\tGalutinis (Vid.)\n";
    for (const auto& studentas : studentai) {
        double vidurkis = rezultatas(studentas.nd, studentas.egz);
        cout << "--------------------------------" << endl;
        cout << studentas.pavarde 
             << "\t " << studentas.vardas
             << "\t" << vidurkis 
             << endl;
    }
    return 0; //uždarom programą
}