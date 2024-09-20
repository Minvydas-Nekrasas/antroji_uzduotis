#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

// funkcija vidurkio paskaičiavimui
double rezultatas(const vector<int>& nd, int egz) { //taupom atmintį ir rodom į vektorių
    if (nd.empty()) return 0.00; 
    double sum = 0;
    for (double grade : nd) {
        sum += grade;
    }
    double vid = sum / nd.size();
    double rez = 0.4 * vid + 0.6 * egz;
    return rez;
}

// Funkcija medianos paskaičiavimui
double mediana(vector<int> nd) {
    if (nd.empty()) return 0.0;

    // Surikiavimas, kad gautusi skaičių eilutė. Pridėti sorto algoritmą
    sort(nd.begin(), nd.end()); // naudojamas quicksort didėjimo tvarka

    int dydis = nd.size();
    
    if (dydis % 2 == 0) {
        // Jeigu lyginis elementų skaičius
        double rez = nd[dydis / 2 - 1] + nd[dydis / 2];
        return rez / 2;
    } else {
        // Jeigu nelyginis
        return nd[dydis / 2];
    }
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
    cout << "\n------------------------------------------------------------------\n";
    cout << left << setw(15) << "Pavardė" //su setw nustatom tarpus
         << setw(15) << "Vardas" 
         << setw(20) << "Galutinis (Vid.)"
         << setw(20) << "Galutinis (Med.)" << endl;
    cout << "------------------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        double vidurkis = rezultatas(studentas.nd, studentas.egz);
        double med = mediana(studentas.nd);
        cout << left << setw(15) << studentas.pavarde
             << setw(15) << studentas.vardas
             << setw(20) << fixed << setprecision(2) << vidurkis // setprecision(2) => du skaičiai po kablelio
             << setw(20) << fixed << setprecision(2) << med
             << endl;
    }
    return 0; //uždarom programą
}