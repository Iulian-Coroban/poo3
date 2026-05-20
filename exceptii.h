#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class ExceptieHardware : public std::exception 
{
protected:
    std::string mesaj;

public:
    //constructori
    ExceptieHardware(std::string m);
    virtual ~ExceptieHardware() throw();

    //metode
    virtual const char* what() const throw() override;
};

class PretInvalidException : public ExceptieHardware 
{
public:
    //constructori
    PretInvalidException();
    PretInvalidException(std::string m);
};

class ParametruInvalidException : public ExceptieHardware 
{
public:
    //constructori
    ParametruInvalidException();
    ParametruInvalidException(std::string m);
};

#endif