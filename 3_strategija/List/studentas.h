#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <vector>
#include <numeric>
#include <algorithm>

class Studentas : public Zmogus {
private:
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

    ~Studentas();

    // Getteriai
    vector<int> getNd() const;
    int getEgz() const;
    double& getGalutinis();
    const double& getGalutinis() const;

    // Setteriai
    void setNd(const vector<int>& n);
    void setEgz(int e);

    // Metodai
    void addNd(int grade);

    // Overridden pure virtual method
    void printInfo(ostream& out) const override;

    // Draugai operatoriai
    friend istream& operator>>(istream& in, Studentas& s);
};

#endif