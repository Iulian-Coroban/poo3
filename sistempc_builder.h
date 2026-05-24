#ifndef SISTEMPC_BUILDER_H
#define SISTEMPC_BUILDER_H

#include "sistempc.h"
#include "hardware_factory.h"
#include <string>

class SistemPCBuilder
{
private:
    SistemPC sistem;

public:
    SistemPCBuilder()
    {
        sistem = SistemPC("Sistem Custom");
    }

    SistemPCBuilder& setNume(std::string nume)
    {
        sistem = SistemPC(nume);
        return *this;
    }

    SistemPCBuilder& adaugaProcesor(std::string n, std::string p, double pret, int tdp, std::string s, int nuclee, double frecv)
    {
        sistem.adaugaPiesa(HardwareFactory::getInstance().createProcesor(n, p, pret, tdp, s, nuclee, frecv));
        return *this;
    }

    SistemPCBuilder& adaugaPlacaVideo(std::string n, std::string p, double pret, int tdp, int vram, bool rayTracing)
    {
        sistem.adaugaPiesa(HardwareFactory::getInstance().createPlacaVideo(n, p, pret, tdp, vram, rayTracing));
        return *this;
    }

    SistemPCBuilder& adaugaMemorieRAM(std::string n, std::string p, double pret, int tdp, int cap, int frecv, std::string ddr)
    {
        sistem.adaugaPiesa(HardwareFactory::getInstance().createMemorieRAM(n, p, pret, tdp, cap, frecv, ddr));
        return *this;
    }

    SistemPC build()
    {
        return sistem;
    }
};

#endif