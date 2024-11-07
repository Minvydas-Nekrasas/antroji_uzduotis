#include "duomenys.h"


using namespace std;
using namespace std::chrono;

void generuotiDuomenis(int studentuSk, const string &failoPavadinimas) {

    auto start = high_resolution_clock::now(); // fiksuojam laiką (pradžia)
    ofstream file(failoPavadinimas);
    file << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n"; // Pirma failo eilutė

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);  // Generuojam pažymius nuo 1 iki 10

    for (int i = 0; i < studentuSk; ++i) {
        string pavarde = "Pavarde" + to_string(i + 1);
        string vardas = "Vardas" + to_string(i + 1);

        // Generuojam 5 namų darbų pažymius
        int nd1 = dist(gen);
        int nd2 = dist(gen);
        int nd3 = dist(gen);
        int nd4 = dist(gen);
        int nd5 = dist(gen);

        // Generuojam egzamino pažymį
        int egzaminas = dist(gen);

        // Įrašom duomenis į failą
        file << pavarde << " " << vardas << " "
             << nd1 << " " << nd2 << " " << nd3 << " " << nd4 << " " << nd5 << " "
             << egzaminas << "\n";
    }

    file.close();

    // fiksuojam laiką (pabaiga)
    auto end = high_resolution_clock::now();
    
    // Paskaičiuojam trukmę
    auto duration_ms = duration_cast<milliseconds>(end - start);

    // Milisekundes paverčiam į sekundes
    double duration_sec = duration_ms.count() / 1000.0;


    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSk << " studentais.\n";
    cout << "Sugeneravimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundes\n";
}
void skaiciavimai(list<Studentas>& studentai, int choice) {
    for (auto& studentas : studentai) {
        if (choice == 0) {
            studentas.galutinis = vidurkis(studentas.nd, studentas.egz); // Galutinis pagal vidurkį
        } else {
            studentas.galutinis = mediana(studentas.nd, studentas.egz); // Galutinis pagal medianą
        }
    }
}
void padalintiStudentus(list<Studentas>& studentai, list<Studentas>& vargsiukai) {
    auto start = high_resolution_clock::now();
    
    // Naudojame iteratorių, kad galėtume iteruoti ir trinti elementus iš sąrašo
    for (auto it = studentai.begin(); it != studentai.end();) {
        if (it->galutinis < 5.0) {
            vargsiukai.push_back(*it); // Pridedame į "vargšiukai" sąrašą
            it = studentai.erase(it);  // Ištrinome iš "studentai" sąrašo ir atnaujiname iteratorių
        } else {
            ++it; // Jei tai "kietiakas", tiesiog pereiname prie kito elemento
        }
    }
    
    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0;
    cout << "Padalinimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundes\n";
}

void isvestiIFailus(list<Studentas>& studentai, list<Studentas>& vargsiukai, int sort_choice) {
    auto start = high_resolution_clock::now();

    // Atidarome failą binariniu režimu, kad paspartintume įrašymo greitį
    ofstream vargsiukaiFile("vargsiukai.txt", ios::out | ios::trunc | ios::binary);
    ofstream kietiakaiFile("kietiakai.txt", ios::out | ios::trunc | ios::binary);

    // Rūšiavimas (vykdomas tik po padalijimo, kad nesikartotų)
    rikiuotiStudentus(studentai, sort_choice);
    rikiuotiStudentus(vargsiukai, sort_choice);

    // Išvedame duomenis į failą

    vargsiukaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas.pavarde << " " << studentas.vardas << " " << studentas.galutinis << "\n";
    }
    vargsiukaiFile.close();
    kietiakaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : studentai) {
        kietiakaiFile << studentas.pavarde << " " << studentas.vardas << " " << studentas.galutinis << "\n";
    }
    kietiakaiFile.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0;
    cout << "Failu isvedimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundes\n";
}

// Funkcija atsitiktinių rezultatų generavimui
void generuotiRandom(Studentas& x, int nd_kiekis) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);  // Pažymiai generuojami nuo 1 iki 10

    std::cout << "Atsitiktinai sugeneruoti namu darbu pazymiai: ";
    for (int i = 0; i < nd_kiekis; i++) {
        int random_pazymys = dist(gen);
        x.nd.push_back(random_pazymys);
        cout << random_pazymys << " ";
    }

    x.egz = dist(gen);  // Atsitinktinai sugeneruojame ir egzamino pažymį
    cout << "\nSugeneruotas egzamino pazymys: " << x.egz << "\n";
}
// Funkcija skirta perskaityti studento duomenis iš failo
void skaitytiIsFailo(const string& failo_adresas, list<Studentas>& studentai) {

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