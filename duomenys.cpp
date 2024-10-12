#include "duomenys.h"
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Funkcija atsitiktinių rezultatų generavimui
void generuotiRandom(Studentas& x, int nd_kiekis) {
    cout << "Atsitiktinai sugeneruoti namų darbų pažymiai: ";
    for (int i = 0; i < nd_kiekis; i++) {
        int random_pazymys = (rand() % 10) + 1;  // Generuoja skaičių nuo 1 iki 10
        x.nd.push_back(random_pazymys);
        cout << random_pazymys << " "; 
    }
    x.egz = (rand() % 10) + 1;  // Generuoja skaičių nuo 1 iki 10
    cout << "\nSugeneruotas egzamino pažymys: " << x.egz << "\n";
}
// Funkcija skirta perskaityti studento duomenis iš failo
void skaitytiIsFailo(const string& failo_adresas, vector<Studentas>& studentai) {

    auto start = high_resolution_clock::now();

    ifstream file(failo_adresas);
    string eilute;
    getline(file, eilute); // Praleidžiam pirmą eilutę

    while (getline(file, eilute)) {
        stringstream ss(eilute); // Kad lengviau nuskaityčiau duomenis
        Studentas studentas;
        ss >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        vector<int> pazymiai;

        // Nuskaitom visus skaičius iki paskutinio (egzamino)
        while (ss >> pazymys) {
            pazymiai.push_back(pazymys);
        }

        if (!pazymiai.empty()) {
            studentas.egz = pazymiai.back(); // pasiimam paskutinį egzamino pažymį
            pazymiai.pop_back();             // Panaikinam jį iš namų darbų pažymių
            studentas.nd = pazymiai;         // Sudedam likusius pažymius į struktųrą
        }

        studentai.push_back(studentas);
    }

    file.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0;
    cout << "Failo nuskaitymo laikas: " << fixed << setprecision(3) << duration_sec << " sekundės\n";
}