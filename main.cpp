#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits> // numeric_limits
#include <fstream>
#include <sstream>

using namespace std; // kad nereiktų rašyt std::string

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

double formule(double bendras, int egz){ // panaudojama ta pati formulė ir medianai, ir vidurkiui
    double rez = 0.4 * bendras + 0.6 * egz;
    return rez;
}

// funkcija vidurkio paskaičiavimui
double vidurkis(const vector<int>& nd, int egz) { //taupom atmintį ir rodom į vektorių
    if (nd.empty()) return 0.00; 
    double sum = 0;
    for (double grade : nd) {
        sum += grade;
    }
    double vid = sum / nd.size();
    double rez = formule(vid, egz);
    return rez;
}

// Funkcija medianos paskaičiavimui
double mediana(vector<int> nd, int egz) {
    if (nd.empty()) return 0.0;

    // Surikiavimas, kad gautusi skaičių eilutė. Pridėti sorto algoritmą
    sort(nd.begin(), nd.end()); // naudojamas quicksort didėjimo tvarka

    int dydis = nd.size();
    double med;
    if (dydis % 2 == 0) {
        // Jeigu lyginis elementų skaičius
        med = (nd[dydis / 2 - 1] + nd[dydis / 2])/2;
        
    } else {
        // Jeigu nelyginis
        med = nd[dydis / 2];
    }
    double rez = formule(med, egz);
    return rez;
}

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Negalima kitko nei skaičiai
    }
    return true;
}

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
    ifstream file(failo_adresas);
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo!\n";
        return;
    }

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
}

// Funkcija studentų rūšiavimui pagal vardą arba pavardę
void rikiuotiStudentus(vector<Studentas>& studentai, bool pagalVarda) {
    if (pagalVarda) {
        // rikiuojam pagal vardą
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.vardas < b.vardas; //lyginama pagal ASCII vertes
        });
    } else {
        // rikiuojam pagal pavardę
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
        }); // [](funkcijos parametrai){funkcijos algoritmas}, su [] nurodom, kad tai lambda funkcija (kaip python lambda)
    }
}

int main(){
    vector<Studentas> studentai;
    string vardas, pavarde, input;
    int pazymys;

    cout << "Ar norite nuskaityti duomenis iš failo? (1 - Taip, 0 - Ne): ";
    int readFromFile;
    cin >> readFromFile;

    if (readFromFile == 1) {
        cin.ignore();
        string failo_adresas;
        cout << "Įveskite failo adresą: ";
        getline(cin, failo_adresas);
        skaitytiIsFailo(failo_adresas, studentai);
    } else {

        cout << "Norėdami baigti įvesti studentus, paspauskite ENTER du kartus.\n";
        
        while (true) {
            Studentas x;
            
            // Imame studento vardą
            cout << "\nĮrašykite studento vardą (ne daugiau nei 10 simbolių) arba paspauskite ENTER, kad baigtumėte: ";
            getline(cin, x.vardas);
            if (x.vardas.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.vardas)) {
                cout << "Netinkamas vardas. Bandykite dar kartą.\n";
                continue;
            }

            // Imame studento pavardę
            cout << "Įrašykite studento pavardę (ne daugiau nei 10 simbolių): ";
            getline(cin, x.pavarde);
            if (x.pavarde.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.pavarde)) {
                cout << "Netinkama pavardė. Bandykite dar kartą.\n";
                continue;
            }

            // Klausia, kokio suvedimo norime
            int choice;
            cout << "Ar norite atsitiktinai sugeneruoti namų darbų ir egzamino pažymius?\n";
            cout << "0 - Ne, įvesiu ranka\n";
            cout << "1 - Taip, sugeneruok atsitiktinai\n";     
            
            while (true) {
                cout << "Įveskite pasirinkimą (1 arba 0): ";
                if (!(cin >> choice) || (choice != 0 && choice != 1)) {
                    cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }
            
            if (choice == 1) {
                // Sugeneruojam atsitiktinus namų darbų ir egzamino rezultatus
                int nd_kiekis;
                cout << "Kiek norite sugeneruoti namų darbų pažymių?(Ne daugiau nei 10 000): ";
                while (!(cin >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) {
                    cout << "Įveskite teisingą skaičių: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                generuotiRandom(x, nd_kiekis);  // Kviečiam funkciją

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            } else {
                // Suvedame namų darbų rezultatus rankiniu būdu
                cout << "Įrašykite namų darbų pažymius (nuo 0 iki 10). Norėdami baigti įvesti pažymius, paspauskite ENTER:\n";
                cin.ignore();  // išvalom \n
                while (true) {
                    cout << "Įrašykite pažymį: ";
                    getline(cin, input);
                    if (input.empty()) break;

                    try {
                        pazymys = stoi(input);
                        if (pazymys < 0 || pazymys > 10) {
                            throw out_of_range("Pažymys turi būti tarp 0 ir 10.");
                        }
                        x.nd.push_back(pazymys);
                    } catch (invalid_argument&) {
                        cout << "Įveskite teisingą pažymį (skaičių nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }

                // Imame egzamino rezultatą
                cout << "Įrašykite egzamino pažymį: ";
                while (true) {
                    getline(cin, input);
                    try {
                        x.egz = stoi(input);
                        if (x.egz < 0 || x.egz > 10) {
                            throw out_of_range("Egzamino pažymys turi būti tarp 0 ir 10.");
                        }
                        break;
                    } catch (invalid_argument&) {
                        cout << "Įveskite teisingą egzamino pažymį (skaičių nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
            }

            studentai.push_back(x);  // įdedam studentą į vektorių
        }
    }
    int choice;
    cout << "\nPasirinkite, ką norite apskaičiuoti:\n";
    cout << "0 - Galutinis pažymys pagal vidurkį\n";
    cout << "1 - Galutinis pažymys pagal medianą\n";

    while(true){
        cout << "Įveskite pasirinkimą (1 arba 0): ";
        if(!(cin >> choice)||(choice != 0 && choice != 1)){
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else{
            break;
        }
    }

    string pasirinkimas_pav;
    double pasirinkimas;

    if (choice == 0){
        pasirinkimas_pav = "(Vid.)";
    }
    else{
        pasirinkimas_pav = "(Med.)";
    }

// Rikiavimo pasirinkimas
    int sort_choice;
    cout << "\nPasirinkite, pagal ką norite surikiuoti studentus:\n";
    cout << "0 - Rikiuoti pagal pavardę\n";
    cout << "1 - Rikiuoti pagal vardą\n";

    while(true){
        cout << "Įveskite pasirinkimą (0 arba 1): ";
        if(!(cin >> sort_choice)||(sort_choice != 0 && sort_choice != 1)){
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else{
            break;
        }
    }

    // Rikiuojam studentus pagal pasirinkimą
    rikiuotiStudentus(studentai, sort_choice == 1);

    // Atspausdinam studentų duomenis
    cout << "\n----------------------------------------------\n";
    cout << left << setw(15) << "Pavardė" //su setw nustatom tarpus
         << setw(15) << "Vardas" 
         << "Galutinis " 
         << pasirinkimas_pav << endl;
    cout << "----------------------------------------------\n";

    for (const auto& studentas : studentai) {
        if (choice == 0){
            pasirinkimas = vidurkis(studentas.nd, studentas.egz);
        }
        else{
            pasirinkimas = mediana(studentas.nd, studentas.egz);
        }
        cout << left << setw(15) << studentas.pavarde
             << setw(15) << studentas.vardas
             << setw(20) << fixed << setprecision(2) << pasirinkimas // setprecision(2) => du skaičiai po kablelio
             << endl;
    }
    return 0; //uždarom programą
}
