#include <iostream>
#include <vector>
#include <memory>
#include "procesor.h"
#include "placavideo.h"
#include "memorieram.h"
#include "sistempc.h"
#include "exceptii.h"
#include "hardware_factory.h"

int main() 
{
    try 
    {
        std::cout << "Testare Validare Date\n";
        auto p1 = HardwareFactory::getInstance().createProcesor("Core i7", "Intel", -500, 65, "LGA1700", 8, 3.6);
    } 
    catch (const ExceptieHardware& e) 
    {
        std::cerr << "Capturat exceptie: " << e.what() << "\n\n";
    }

    SistemPC sistemulMeu("Gaming Beast 2026");

    try 
    {
        auto cpu = HardwareFactory::getInstance().createProcesor("Ryzen 9", "AMD", 2500, 105, "AM5", 12, 4.2);
        auto gpu = HardwareFactory::getInstance().createPlacaVideo("RTX 5090", "NVIDIA", 9000, 450, 24, true);
        auto ram = HardwareFactory::getInstance().createMemorieRAM("Vengeance", "Corsair", 800, 15, 32, 6000, "DDR5");

        sistemulMeu.adaugaPiesa(cpu);
        sistemulMeu.adaugaPiesa(gpu);
        sistemulMeu.adaugaPiesa(ram);
    } 
    catch (const ExceptieHardware& e) 
    {
        std::cerr << "Eroare la crearea componentelor: " << e.what() << "\n";
    }

    std::cout << sistemulMeu << "\n";
    std::cout << "Performanta totala a sistemului: " << sistemulMeu.calculeazaPerformantaTotala() << "\n";

    return 0;
}