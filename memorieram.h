#ifndef MEMORIERAM_H
#define MEMORIERAM_H

#include "hardware.h"
#include <string>
#include <memory>

class MemorieRAM : public Hardware
{
    int capacitateGB;
    int frecventaMHz;
    std::string tipDDR;

public:
    //constructori
    MemorieRAM();
    MemorieRAM(std::string n, std::string p, double pret, int tdp, int cap, int frecv, std::string ddr);
    ~MemorieRAM() override;

    //getere
    int getCapacitateGB() const;
    int getFrecventaMHz() const;
    std::string getTipDDR() const;

    //metode
    double calculeazaPerformanta() const override;
    std::shared_ptr<Hardware> clone() const override;

protected:
    //afisare
    void afisareVirtuala(std::ostream& os) const override;
};

#endif