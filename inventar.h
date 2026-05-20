#ifndef INVENTAR_H
#define INVENTAR_H

#include <vector>
#include <memory>
#include <iostream>
#include <string>

template <typename T>
class Inventar;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Inventar<T>& inv);

template <typename T>
class Inventar
{
private:
    std::vector<std::shared_ptr<T>> elemente;
    std::string categorie; 

public:
    Inventar(std::string cat = "Componente Generale") : categorie(cat) 
    {
    }

    void adaugaElement(std::shared_ptr<T> element)
    {
        if (element)
        {
            elemente.push_back(element);
        }
    }

    double calculeazaPerformantaTotala() const
    {
        double total = 0.0;
        for (const auto& el : elemente)
        {
            if (el)
            {
                total += el->calculeazaPerformanta();
            }
        }
        return total;
    }

    const std::vector<std::shared_ptr<T>>& getElemente() const
    {
        return elemente;
    }

    friend std::ostream& operator<< <>(std::ostream& os, const Inventar<T>& inv);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Inventar<T>& inv)
{
    os << "Inventar [ Categorie: " << inv.categorie << " ]\n";
    os << "-------------------------------------------\n";
    
    if (inv.elemente.empty())
    {
        os << "  (fara elemente)\n";
    }
    else
    {
        for (const auto& el : inv.elemente)
        {
            if (el)
            {
                os << " * " << *el << "\n";
            }
        }
    }
    
    os << "-------------------------------------------";
    return os;
}

#endif