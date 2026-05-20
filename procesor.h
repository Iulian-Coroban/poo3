#ifndef PROCESOR_H
#define PROCESOR_H

#include "hardware.h"
#include <string>
#include <memory>

class Procesor : public Hardware
{
    std::string socket;
    int nrNuclee;
    double frecventaGHz;

public:
    //constructori
    Procesor();
    Procesor(std::string n, std::string p, double pret, int tdp, std::string s, int nuclee, double frecv);
    ~Procesor() override;

    //getere
    std::string getSocket() const;
    int getNrNuclee() const;
    double getFrecventaGHz() const;

    //metode
    double calculeazaPerformanta() const override;
    std::shared_ptr<Hardware> clone() const override;

protected:
    //afisare
    void afisareVirtuala(std::ostream& os) const override;
};

#endif