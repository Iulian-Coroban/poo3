#include <iostream>
#include <memory>
#include "sistempc.h"
#include "exceptii.h"
#include "sistempc_builder.h"
#include "strategie_testare.h"

int main() 
{
    try 
    {
        SistemPCBuilder builder;
        
        SistemPC pcGaming = builder.setNume("Gaming Beast 2026")
                                   .adaugaProcesor("Ryzen 9", "AMD", 2500, 105, "AM5", 12, 4.2)
                                   .adaugaPlacaVideo("RTX 5090", "NVIDIA", 9000, 450, 24, true)
                                   .adaugaMemorieRAM("Vengeance", "Corsair", 800, 15, 32, 6000, "DDR5")
                                   .build();

        std::cout << pcGaming << "\n";
        std::cout << "Performanta totala: " << pcGaming.calculeazaPerformantaTotala() << "\n\n";
        
        TestareGaming testGaming;
        TestareOffice testOffice;

        std::cout << "--- Rezultate Testare ---\n";
        testGaming.evalueazaSistem(pcGaming);
        testOffice.evalueazaSistem(pcGaming);
    } 
    catch (const ExceptieHardware& e) 
    {
        std::cerr << "Eroare interceptata: " << e.what() << "\n";
    }

    return 0;
}