#ifndef HARDWARE_FACTORY_H
#define HARDWARE_FACTORY_H

#include <memory>
#include <string>
#include "procesor.h"
#include "placavideo.h"
#include "memorieram.h"
#include "hardware.h"

class HardwareFactory
{
private:
    HardwareFactory()
    {
    }

public:
    HardwareFactory(const HardwareFactory&) = delete;
    HardwareFactory& operator=(const HardwareFactory&) = delete;

    static HardwareFactory& getInstance()
    {
        static HardwareFactory instance;
        return instance;
    }

    std::shared_ptr<Hardware> createProcesor(std::string n, std::string p, double pret, int tdp, std::string s, int nuclee, double frecv)
    {
        return std::make_shared<Procesor>(n, p, pret, tdp, s, nuclee, frecv);
    }

    std::shared_ptr<Hardware> createPlacaVideo(std::string n, std::string p, double pret, int tdp, int vram, bool rayTracing)
    {
        return std::make_shared<PlacaVideo>(n, p, pret, tdp, vram, rayTracing);
    }

    std::shared_ptr<Hardware> createMemorieRAM(std::string n, std::string p, double pret, int tdp, int cap, int frecv, std::string ddr)
    {
        return std::make_shared<MemorieRAM>(n, p, pret, tdp, cap, frecv, ddr);
    }
};

#endif