# Parking_Management

## Descriere proiect
Am creat un program care doreste gestionarea unei parcari.
## Milestone #0

- [ ] Nume proiect (poate fi schimbat ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Milestone #1

#### Pentru codul original: `https://github.com/blank648/Parking-Management` 
- 
- [ ] Clasa `incasari`
- avem int A,B,C,D,total care sunt membri privati
- constructorul incasari initializeaza toate valorile cu 0
- metoda input permite setarea datelor pentru variabilele clasei incasari
- metoda display afiseaza incasarile pentru ficare categorie folosind `setw()`
- 
- [ ] Clasa `tip_vehicul`
- constructorul `tip_vehicul` initializeaza tipul vehiculului cu valoarea `vehicul`
- metoda `setare_tip_vehicul` permite selectarea categoriei vehiculului
- metda `display_tip_vehicul` afiseaza tipul vehiculului
- 
- [ ] Clasa `vehicul`
- int nr_vehicul: numarul unic de identificare al vehiculului.
- char nr_matriculare[10]: numarul de inmatriculare al vehiculului.
- char culoare[10], char marca[20], char model[20]: informatii despre vehicul.
- char ora_intrare[10], char ora_iesire[10]: orele de intrare si iesire ale vehiculului.
- incasari Incasari: un obiect al clasei incasari care tine incasarile vehiculului.
- constructorul `vehicul` initializeaza datele vehiculului cu valori implicite
- metoda `intrare` permite introducrea datelor vehicului, plus categoria de incasari
- metoda `iesire` afiseaza detaliile vehiculului la iesire, inclusiv orele de intrare si iesire
- metoda `afisare_vehicul` afiseaza detaliile vehicului si incasarile asociate
- metoda `adauga_in_lista` incarca si afiseaza toate vehiculele salvare in fisier
- metoda `cautare_vehicul` cauta un vehicul dupa numarul unic de indentificare
- metoda `stergere_vehicul` sterge vehiculul din fisier
- metoda `update` actualizeaza starea unui vehicul


## Milestone #2

#### Pentru inceput, am schimbat denumirea claselor din romana in engleza pentru a crea un standard
- 
- [ ] clasa `earnings`
- gestioneaza incasarile din parcare, pe baza categoriei vehiculelor 
- folosim constructorul implicit `earnings()` pentru a initializa toate campurile clasei cu 0
- folosim constructorul de copiere `earnings(const earnings &other)` pentru crearea unei copii a unui obiect existent cu toate valorile campurilor
- metoda virtuala `virtual ~earnings()` permite stergerea corecta a obiectelor derivate din clasa
- metoda `get_money` - getter
- functia `friend void add_money(earnings, earnings &)` permite accesul la membrii privati ai clasei pentru adaugarea incasarilor unui obiect altuia
- 
- [ ] clasa `vehicle_type`
- are scopul gestionarii tipurilor de vehicul in sistem
- constructorul implicit `vehicle_type() : vehicle_type_name("vehicle")` initializeaza atributul `vehicle_type_name` cu valoarea implicita
- constructorul de copiere `vehicle_type(const vehicle_type &other)` permite crearea unei copii a unui obiect de tip `vehicle_type` 
- metoda `std::string get_vehicle_type_name()` returneaza tipul vehiculului stocat in `vehicle_type_name`
- metoda `set_vehicle_type` seteaza categoria vehiculului si actualizeaza valorile incasarilor in functie de categorie
- destructorul virtual `virtual ~vehicle_type()` permite stergerea corecta a obiectelor derivate din clasa
- 
- [ ] clasa `vehicle`
- extinde funtionalitatea clasei `vehicle_type` prntru a gestiona informatiile in detaliu despre vehicule
- constructorul de copiere `vehicle(const vehicle &other)` creaza o copie a unui obiect `vehicle` copiind toti membrii acesteia
- metoda `int get_vehicle_number()` returneaza numarul vehiculului
- 
- [ ] clasa `levels`
- extinde funtionarea clasei `vehicle` cu scopul organizarii si gestionariivehiculelor pe niveluri
- constructorul implicit `levels` nu efectueaza initializari
- metoda `void add_to_level(int lvl, const vehicle &v)` adauga vehiculul la un anumit nivel
- metoda `void remove_from_level(int lvl, int vno)` elimina un vehicul de la un anumit nivel
- metoda `void show_all_vehicles()` afiseaza toate vehiculele de pe un anumit nivel
- 
- [ ] clsasa `bicicleta`
- extinde funtionalitatea clasei `vehicle_type` reprezentand o categorie noua de vehicule
- constructorul implicit `bicicleta` nu realizeaza initializari
- metoda `void display() override` afiseaza numele `bicicleta`
- avem destructorul `~bicicleta()`

## Milestone #3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse
- https://www.youtube.com/watch?v=qbfs4Hgn_-c
- https://www.youtube.com/@VashishthMuniSingh
