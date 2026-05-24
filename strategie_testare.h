#ifndef STRATEGIE_TESTARE_H
#define STRATEGIE_TESTARE_H

#include "sistempc.h"
#include <iostream>

class StrategieTestare
{
public:
    virtual void evalueazaSistem(const SistemPC& sistem) = 0;
    
    virtual ~StrategieTestare() 
    {
    }
};

class TestareGaming : public StrategieTestare
{
public:
    void evalueazaSistem(const SistemPC& sistem) override
    {
        if (sistem.calculeazaPerformantaTotala() > 15000)
        {
            std::cout << "Scor Gaming: Capabil de 4K Ultra Settings\n";
        }
        else
        {
            std::cout << "Scor Gaming: Recomandat pentru 1080p\n";
        }
    }
};

class TestareOffice : public StrategieTestare
{
public:
    void evalueazaSistem(const SistemPC& sistem) override
    {
        if (sistem.calculeazaPerformantaTotala() > 5000)
        {
            std::cout << "Scor Office: Excelent pentru multitasking masiv si baze de date\n";
        }
        else
        {
            std::cout << "Scor Office: Perfect pentru pachetul Office si browsing\n";
        }
    }
};

#endif