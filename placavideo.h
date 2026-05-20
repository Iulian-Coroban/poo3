#ifndef PLACAVIDEO_H
#define PLACAVIDEO_H

#include "hardware.h"
#include <string>
#include <memory>

class PlacaVideo : public Hardware
{
    int memorieVRAM;
    bool areRayTracing;

public:
    //constructori
    PlacaVideo();
    PlacaVideo(std::string n, std::string p, double pret, int tdp, int vram, bool rayTracing);
    ~PlacaVideo() override;

    //getere
    int getMemorieVRAM() const;
    bool getAreRayTracing() const;

    //metode
    double calculeazaPerformanta() const override;
    std::shared_ptr<Hardware> clone() const override;

protected:
    //afisare
    void afisareVirtuala(std::ostream& os) const override;
};

#endif