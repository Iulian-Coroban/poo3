# Gestiune Componente Hardware PC - Proiect POO Tema 3

Acest proiect reprezinta un sistem avansat pentru gestiunea si evaluarea componentelor hardware dintr-un PC, implementat in C++. Arhitectura aplicatiei utilizeaza concepte moderne orientate pe obiecte, precum programarea generica (templates), gestionarea automata a memoriei prin smart pointers (std::shared_ptr), tratarea granulara a erorilor prin exceptii custom si integrarea mai multor sabloane de proiectare (Design Patterns).

---

## Descrierea Claselor din Proiect

### 1. Clasa Hardware
Este clasa de baza a intregii ierarhii de componente si este o clasa abstracta.
* **Rol:** Defineste atributele comune tuturor pieselor (nume, producator, pret de baza, consum TDP) si pastreaza un contor static (`nrTotalComponente`) pentru a monitoriza numarul total de piese active in memorie.
* **Detalii tehnice:** Implementeaza idiomul NVI (Non-Virtual Interface) prin metoda publica `afisare()`, care apeleaza o metoda protejata virtuala pura `afisareVirtuala()`. Obliga toate clasele derivate sa implementeze metodele virtuale pure `calculeazaPerformanta()` si `clone()`.

### 2. Clasa Procesor
Moosteneste in mod public clasa `Hardware`.
* **Rol:** Modeleaza un procesor de calculator, adaugand atribute specifice: tipul de socket, numarul de nuclee si frecventa exprimata in GHz.
* **Detalii tehnice:** Suprascrie metoda `calculeazaPerformanta()` (calculata ca produs intre numarul de nuclee si frecventa) si metoda `clone()`, actionand ca un Prototip (Prototype Pattern) pentru copierea in profunzime (Deep Copy).

### 3. Clasa PlacaVideo
Moosteneste in mod public clasa `Hardware`.
* **Rol:** Modeleaza o placa video, avand ca atribute specifice cantitatea de memorie VRAM (in GB) si un indicator boolean pentru suportul tehnologiei Ray Tracing.
* **Detalii tehnice:** Implementeaza propria logica de performanta, unde scorul primeste un bonus semnificativ daca placa video are suport activ pentru Ray Tracing. Suprascrie si ea metodele de afisare si clonare.

### 4. Clasa MemorieRAM
Moosteneste in mod public clasa `Hardware`.
* **Rol:** Modeleaza o placuta de memorie RAM, stocand capacitatea (in GB), frecventa de lucru (in MHz) si tipul generatiei (de exemplu: DDR4, DDR5).
* **Detalii tehnice:** Calculeaza performanta ca un raport intre capacitate si frecventa, oferind o imagine clara asupra vitezei de raspuns a memoriei.

### 5. Ierarhia de Exceptii (ExceptieHardware, PretInvalidException, ParametruInvalidException)
Reprezinta sistemul de aparare si validare al aplicatiei.
* **Rol:** `ExceptieHardware` moosteneste clasa standard `std::exception`. Din ea se ramifica exceptii specifice pentru situatii in care utilizatorul introduce date incorecte (de exemplu, un pret negativ sau zero, ori un numar de nuclee egal cu zero).
* **Detalii tehnice:** Constructorii claselor hardware verifica datele primite si arunca aceste exceptii daca regulile de business sunt incalcate, impiedicand crearea de obiecte invalide.

### 6. Clasa Sablon Inventar<T> (Template Class)
Este clasa generica introdusa pentru a gestiona colectii de obiecte.
* **Rol:** Inlocuieste vectorii simpli din cod, oferind o structura reutilizabila care poate stoca pointeri de tipul generic `T`. In proiect, este instantiata ca `Inventar<Hardware>`.
* **Detalii tehnice:** Contine un atribut dependent de `T` (`std::vector<std::shared_ptr<T>>`) si metode dependente de `T` (`adaugaElement`). Include o functie libera template (`operator<<`) declarata ca friend folosind sintaxa avansata cu unghiuri `<>`, permitand afisarea automata a intregului container.

### 7. Clasa HardwareFactory
Centralizeaza si controleaza crearea tuturor componentelor din sistem, combinand doua sabloane de proiectare.
* **Design Pattern Singleton:** Constructorul este privat, iar constructorul de copiere si operatorul de atribuire sunt sterse prin `= delete`. Exista o singura instanta globala accesibila prin metoda `getInstance()`, oferind aceeasi garantie de unicitate ca si obiectul `std::cout`.
* **Design Pattern Factory:** Ofera metode clare (`createProcesor`, `createPlacaVideo`, `createMemorieRAM`) care primesc parametrii necesari, aloca intern memoria prin `std::make_shared` si returneaza un pointer catre clasa de baza `Hardware`. Acest lucru decupleaza complet functia `main` de detaliile claselor derivate.

### 8. Clasa SistemPC
Este clasa care defineste un calculator complet.
* **Rol:** Are un nume de sistem si contine piese. In loc sa foloseasca un vector brut, ea integreaza clasa sablon `Inventar<Hardware>`.
* **Detalii tehnice:** Deleaga calculul performantei totale si afisarea datelor direct catre metodele din clasa template `Inventar`.

### 9. Clasa SistemPCBuilder
Implementeaza design pattern-ul **Builder** pentru construirea configuratiilor.
* **Rol:** Ofera o interfata extrem de curata pentru crearea unui `SistemPC`, scapand functia `main` de adaugari repetitive de piese.
* **Detalii tehnice:** Permite inlantuirea metodelor (method chaining) prin returnarea unei referinte la constructorul curent (`return *this`). In spate, Builder-ul apeleaza automat metodele din `HardwareFactory`.

### 10. Ierarhia Strategy (StrategieTestare, TestareGaming, TestareOffice)
Implementeaza design pattern-ul **Strategy** pentru evaluarea sistemelor.
* **Rol:** Separa logica de analiza a performantei de clasa `SistemPC`. Astfel, un calculator poate fi testat dupa reguli diferite de performanta fara a modifica codul masinii.
* **Detalii tehnice:** `StrategieTestare` este o interfata cu o metoda virtuala pura `evalueazaSistem()`. Clasele derivate `TestareGaming` si `TestareOffice` interpreteaza valoarea performantei totale din perspective diferite, respectand principiul Open/Closed din SOLID.

---

## Concepte OOP Avansate Evidentiate

1. **Polimorfism Dinamic:** Utilizat peste tot prin vectorul de pointeri de baza (`Hardware`) si apelurile metodelor virtuale la rulare.
2. **Prototype Pattern:** Implementat prin functia `clone()` pentru a permite copierea sigura a obiectelor fara a le cunoaste tipul exact in momentul apelului.
3. **Incapsulare Rigoasa:** Toate atributele sunt private sau protejate, iar interactiunea se face exclusiv prin metode sau interfete dedicate.
4. **Garantia Memoriei:** Utilizarea `std::shared_ptr` elimina complet riscul de memory leaks (scurgeri de memorie) si dangling pointers, lasand managementul resurselor in seama numaratorului de referinte.
