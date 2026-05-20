#include "memorieram.h"
#include "exceptii.h"
#include <iostream>

//constructori

MemorieRAM::MemorieRAM() : Hardware()
{
    this->capacitateGB = 0;
    this->frecventaMHz = 0;
    this->tipDDR = "Necunoscut";
}

MemorieRAM::MemorieRAM(std::string n, std::string p, double pret, int tdp, int cap, int frecv, std::string ddr)
    : Hardware(n, p, pret, tdp)
{
    if (cap <= 0)
    {
        throw ParametruInvalidException("Eroare: Capacitatea RAM trebuie sa fie mai mare de 0 GB!");
    }
    if (frecv <= 0)
    {
        throw ParametruInvalidException("Eroare: Frecventa RAM trebuie sa fie pozitiva!");
    }

    this->capacitateGB = cap;
    this->frecventaMHz = frecv;
    this->tipDDR = ddr;
}

MemorieRAM::~MemorieRAM() {}

//getere

int MemorieRAM::getCapacitateGB() const
{
    return this->capacitateGB;
}

int MemorieRAM::getFrecventaMHz() const
{
    return this->frecventaMHz;
}

std::string MemorieRAM::getTipDDR() const
{
    return this->tipDDR;
}

//metode

double MemorieRAM::calculeazaPerformanta() const
{
    // calculam performanta in functie de capacitate si viteza
    return (double)this->capacitateGB * (this->frecventaMHz / 1000.0);
}

std::shared_ptr<Hardware> MemorieRAM::clone() const
{
    // returnam o copie a memoriei RAM
    return std::make_shared<MemorieRAM>(*this);
}

//afisare

void MemorieRAM::afisareVirtuala(std::ostream& os) const
{
    os << "\nCapacitate:  " << this->capacitateGB << " GB"
       << "\nFrecventa:   " << this->frecventaMHz << " MHz"
       << "\nTip DDR:     " << this->tipDDR;
}