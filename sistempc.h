#ifndef SISTEMPC_H
#define SISTEMPC_H

#include <string>
#include <memory>
#include <iostream>
#include "hardware.h"
#include "inventar.h"

class SistemPC
{
private:
    std::string numeSistem;
    Inventar<Hardware> piese;

public:
    SistemPC(std::string nume = "Sistem Implicit") : numeSistem(nume), piese("Piese Sistem")
    {
    }

    void adaugaPiesa(std::shared_ptr<Hardware> piesa)
    {
        piese.adaugaElement(piesa);
    }

    double calculeazaPerformantaTotala() const
    {
        return piese.calculeazaPerformantaTotala();
    }

    std::string getNumeSistem() const
    {
        return numeSistem;
    }

    const Inventar<Hardware>& getPiese() const
    {
        return piese;
    }

    friend std::ostream& operator<<(std::ostream& os, const SistemPC& pc)
    {
        os << "Sistem: " << pc.numeSistem << "\n" << pc.piese;
        return os;
    }
};

#endif