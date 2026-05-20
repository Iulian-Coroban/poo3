#ifndef HARDWARE_H
#define HARDWARE_H


#include <iostream>
#include <string>
#include <memory>
#include <ostream>


class Hardware
{
    std::string nume;
    std::string producator;
    double pretBaza;
    int consumTDP;
    static int nrTotalComponente;

public:
    //constructori
    Hardware();
    Hardware(std::string n, std::string p, double pretIntrodus, int tdp);
    Hardware(const Hardware& data); 
    Hardware& operator=(const Hardware& data);
    virtual ~Hardware();

    //getere statice
    static int getNrTotalComponente();

    //metode
    void afisare(std::ostream& os) const; 
    virtual double calculeazaPerformanta() const = 0;
    virtual std::shared_ptr<Hardware> clone() const = 0;

protected:
    virtual void afisareVirtuala(std::ostream& os) const = 0;
    double getPretBaza() const;
    int getConsumTDP() const;

    //operator <<
    friend std::ostream& operator<<(std::ostream& os, const Hardware& h);
};




#endif
