#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinis;

    void calculateGalutinis();

public:
    // Konstruktoriai
    Studentas();
    Studentas(const string& v, const string& p, const vector<int>& n, int e);

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    // Destruktorius
    ~Studentas();

    friend istream& operator>>(istream& in, Studentas& s);
    friend ostream& operator<<(ostream& out, const Studentas& s);

    // Getteriai
    string getVardas() const;
    string getPavarde() const;
    vector<int> getNd() const;
    int getEgz() const;
    double& getGalutinis();
    const double& getGalutinis() const;

    // Setteriai
    void setVardas(const string& v);
    void setPavarde(const string& p);
    void setNd(const vector<int>& n);
    void setEgz(int e);

    // Metodai
    void addNd(int grade);
};

#endif
