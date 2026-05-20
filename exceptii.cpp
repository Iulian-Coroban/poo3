#include "exceptii.h"



//constructori
ExceptieHardware::ExceptieHardware(std::string m) 
{
    this->mesaj = m;
}

ExceptieHardware::~ExceptieHardware() throw() {}

//metode
const char* ExceptieHardware::what() const throw() 
{
    return this->mesaj.c_str();
}


//constructori
PretInvalidException::PretInvalidException() : ExceptieHardware("Eroare: Pretul nu poate fi negativ sau zero!") {}

PretInvalidException::PretInvalidException(std::string m) : ExceptieHardware(m) {}



//constructori
ParametruInvalidException::ParametruInvalidException() : ExceptieHardware("Eroare: Parametrul introdus este invalid!") {}

ParametruInvalidException::ParametruInvalidException(std::string m) : ExceptieHardware(m) {}