#include "hardware.h"
#include "exceptii.h"
#include <iostream>
#include <string>
#include <memory>
#include <ostream>




int Hardware::nrTotalComponente = 0;

//constructori

Hardware::Hardware()
{
    this->nume = "Necunoscut";
    this->producator = "Necunoscut";
    this->pretBaza = 0.0;
    this->consumTDP = 0;
    Hardware::nrTotalComponente++;
}

Hardware::Hardware(std::string n, std::string p, double pretIntrodus, int tdp)
{
    if (pretIntrodus <= 0)
    {
        throw PretInvalidException("Eroare: Pretul pentru " + n + " trebuie sa fie pozitiv!");
    }
    if (tdp < 0)
    {
        throw ParametruInvalidException("Eroare: Consumul TDP nu poate fi negativ!");
    }

    this->nume = n;
    this->producator = p;
    this->pretBaza = pretIntrodus;
    this->consumTDP = tdp;
    Hardware::nrTotalComponente++;
}

Hardware::Hardware(const Hardware& data)
{
    this->nume = data.nume;
    this->producator = data.producator;
    this->pretBaza = data.pretBaza;
    this->consumTDP = data.consumTDP;
    Hardware::nrTotalComponente++;
}

Hardware& Hardware::operator=(const Hardware& data)
{
    if (this == &data)
    {
        return *this;
    }

    this->nume = data.nume;
    this->producator = data.producator;
    this->pretBaza = data.pretBaza;
    this->consumTDP = data.consumTDP;

    return *this;
}

Hardware::~Hardware()
{
    Hardware::nrTotalComponente--;
}

//getere statice

int Hardware::getNrTotalComponente()
{
    return Hardware::nrTotalComponente;
}

//metode

void Hardware::afisare(std::ostream& os) const
{
    os << "Componenta: " << this->nume << " [" << this->producator << "]"
       << " | Pret: " << this->pretBaza << " RON"
       << " | TDP: " << this->consumTDP << "W";
    
    this->afisareVirtuala(os);
}

//supraincarcare operator afisare

std::ostream& operator<<(std::ostream& os, const Hardware& h)
{
    h.afisare(os);
    return os;
}