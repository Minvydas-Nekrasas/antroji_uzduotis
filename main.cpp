#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits> // numeric_limits

using namespace std; // kad nereiktų rašyt std::string

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

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Negalima kitko nei skaičiai
    }
    return true;
}

int main(){
    vector<Studentas> studentai;
    string vardas, pavarde, input;
    int pazymys;

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

        // Imame namų darbų pažymį
        cout << "Įrašykite namų darbų pažymius (nuo 0 iki 10). Norėdami baigti įvesti pažymius, paspauskite ENTER:\n";
        while (true) {
            cout << "Įrašykite pažymį: ";
            getline(cin, input);
            if (input.empty()) break; // Stabdom programą, jei 2 enter
            
            try {
                pazymys = stoi(input);
                if (pazymys < 0 || pazymys > 10) {
                    throw out_of_range("Pažymys turi būti tarp 0 ir 10.");
                }
                x.nd.push_back(pazymys); // Pridedam pažymį į vektorių
            } catch (invalid_argument&) {
                cout << "Įveskite teisingą pažymį (skaičių nuo 0 iki 10).\n";
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

        // Imame egzamino pažymį
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

        studentai.push_back(x);  // įdedam studentą į vektorių
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
