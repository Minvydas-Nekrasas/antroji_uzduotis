#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinis;

public:
    // Constructors
    Studentas() : vardas(""), pavarde(""), egz(0), galutinis(0.0) {}
    Studentas(const string& v, const string& p, const vector<int>& n, int e)
        : vardas(v), pavarde(p), nd(n), egz(e) {
        calculateGalutinis();
    }

    // Getters and setters
    string getVardas() const { return vardas; }
    void setVardas(const string& v) { vardas = v; }

    string getPavarde() const { return pavarde; }
    void setPavarde(const string& p) { pavarde = p; }

    vector<int> getNd() const { return nd; }
    void setNd(const vector<int>& n) { nd = n; calculateGalutinis(); }

    int getEgz() const { return egz; }
    void setEgz(int e) { egz = e; calculateGalutinis(); }

    double& getGalutinis() { return galutinis; } // Non-const version
    const double& getGalutinis() const { return galutinis; } // Const version

    // Methods
    void calculateGalutinis() {
        if (!nd.empty()) {
            double nd_avg = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
            galutinis = 0.4 * nd_avg + 0.6 * egz;
        } else {
            galutinis = 0.6 * egz;
        }
    }

    void addNd(int grade) {
        nd.push_back(grade);
        calculateGalutinis();
    }
};

#endif
