#### Programare generica

- Utilizați minim o clasă șablon (template) definită de voi. Trebuie să fie
parametrizată de cel puțin un tip de date generic (cel puțin un typename),
care să fie folosit în mod util în interiorul clasei (e.g. pentru a defini un
atribut, o metodă etc.).
  - TODO
- Definiți și apelați minim o funcție șablon (poate fi funcție liberă sau metodă
a unei clase care nu este neapărat generică). Trebuie să fie parametrizată de
cel puțin un tip de date generic (cel puțin un typename), care să fie folosit
în definirea funcției (e.g. parametru, tip de date returnat).
  - freeVector
- Definiți cel puțin o implementare specializată pentru clasa șablon sau
funcția șablon (nu neapărat pentru ambele)
  - fac o functie care face downcasting, si o specializez sa faca downcasting pt mostenirea diamant superuser

#### Design patterns
- Identificați minim 2 object-oriented design patterns diferite în clasele implemen-
tate de voi.
  - TODO
  
#### Biblioteca standard 
- Utilizarea a minim două tipuri de date container diferite din STL
  - vector, string
- Utilizarea a minim două funcții utilitare diferite din biblioteca standard
(funcții libere, nu metode) - [biblioteca algorithm](https://cplusplus.com/reference/algorithm/)
  - move la constructori
  - random_shuffle pe un string ca sa fac un user id

#### Smart pointers
- Utilizați în mod corespunzător minim două tipuri diferite de smart pointers din
biblioteca standard.
Prin smart pointer ne referim la una dintre clasele std::reference_wrapper3,
std::unique_ptr, std::shared_ptr sau std::weak_ptr.
Puteți să folosiți aceste clase în locul referințelor sau pointerilor obișnuiți din codul
vostru.
  - reference_wrapper in clasa superuser pentru subscription
  - shared_ptr si/sau unique_ptr pentru pointerii din user

#### Bonus
Fiecare cerință bonus valorează 1 punct.
- Utilizarea modificatorului const în mod corect, peste tot unde este po-
sibil și are sens în program (pe date membre, pe metode, la transmiterea
parametrilor prin referință etc.).
  - TODO  
- Folosirea unei biblioteci utilitare din biblioteca standard, în afară de cele cu
care am lucrat la laborator. Puteți alege (în funcție de specificul proiectului)
dintre:
    – chrono: lucru cu date și timp.
    – regex: lucru cu expresii regulate (pentru căutarea/înlocuirea de text).
    – random: generare de numere aleatoare.
    – thread: execuție paralelă a codului.
Pentru a fi punctați, trebuie să instanțiați și să utilizați cel puțin câteva tipuri
de date din biblioteca aleasă
  - Am afisat cand a fost apelat un constructor de tip User
