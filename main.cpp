#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits> // for numeric_limits

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

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Negalima kitko nei skaičiai
    }
    return true;
}

int main(){
    vector<Studentas> studentai;
    int darbai, pazymys, stud_skaicius;

    cout << "Kiek bus studentų? ";
    
    while (true) {
        try {
            if (!(cin >> stud_skaicius)) {
                throw runtime_error("Įveskite teisingą studentų skaičių (skaičių).");
            }
            if (stud_skaicius <= 0 || stud_skaicius > 1000) { 
                throw runtime_error("Studentų skaičius turi būti teigiamas skaičius ir negali būti daugiau nei 1000.");
            }
            break;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pakartokite studentų skaičių: ";
        }
    }

    //Prašom duomenų ir juos įrašom į struktūrą kiekvienam studentui
    for (int i = 0; i < stud_skaicius; ++i) {
        Studentas x;
        cout << "\nDuomenys studento nr. " << i + 1 << ":\n";

        cin.ignore(); //išvengiam \n bug'os

        while (true) {
            cout << "Įrašyk studento vardą (ne daugiau nei 10 simbolių): ";
            getline(cin, x.vardas);
            if (arTeisinga(x.vardas)) {
                break;
            } else {
                cout << "Netinkamas vardas. Vardas turi būti ne tuščias, sudarytas tik iš raidžių ir ne ilgesnis nei 10 simbolių. Bandykite dar kartą.\n";
            }
        }


        while (true) {
            cout << "Įrašyk studento pavardę (ne daugiau nei 10 simbolių): ";
            getline(cin, x.pavarde);
            if (arTeisinga(x.pavarde)) {
                break;
            } else {
                cout << "Netinkama pavardė. Pavardė turi būti ne tuščia, sudaryta tik iš raidžių ir ne ilgesnė nei 10 simbolių. Bandykite dar kartą.\n";
            }
        }

        cout << "Kiek namų darbų? ";

        while (true) {
            try {
                if (!(cin >> darbai)) {
                    throw runtime_error("Įveskite teisingą namų darbų skaičių (skaičių).");
                }
                if (darbai <= 0 || darbai > 1000) {
                    throw runtime_error("Namų darbų skaičius turi būti teigiamas skaičius ir ne didesnis už 1000.");
                }
                break;
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
                cout << "Pakartokite namų darbų skaičių: ";
            }
        }

        x.nd.resize(darbai);  // kad laikytume nd pažymius

        for (int j = 0; j < darbai; ++j) {
            while (true) {
                try {
                    cout << "Įrašyk namų darbo pažymį " << j + 1 << ": ";
                    if (!(cin >> pazymys)) {
                        throw runtime_error("Įveskite teisingą pažymį (skaičių).");
                    }
                    if (pazymys < 0 || pazymys > 10) {
                        throw out_of_range("Pažymys turi būti tarp 0 ir 10.");
                    }
                    x.nd[j] = pazymys;  // Įdedam į vektorių
                    break;
                } catch (runtime_error& e) {
                    cout << e.what() << endl;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
            }
        }

        cout << "Įrašyk egzamino rezultatą: ";
        while (true) {
            try {
                if (!(cin >> x.egz)) {
                    throw runtime_error("Įveskite teisingą egzamino pažymį (skaičių).");
                }
                if (x.egz < 0 || x.egz > 10) {
                    throw out_of_range("Egzamino pažymys turi būti tarp 0 ir 10.");
                }
                break;
            } catch (runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
        }

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
