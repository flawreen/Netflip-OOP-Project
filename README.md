# Netflip
## University OOP Project

<img src="https://user-images.githubusercontent.com/83332450/225131324-68d665ae-befa-48e3-9db4-891c9ced8b7c.png" width=100% height=70%>

### Cerinte etapa 1
#### Clase
- [x] Trebuie să respectați principiul encapsulări (nu aveți voie să aveți date
membre publice). Metodele pot fi publice sau private.
- [ ] Trebuie să definiți minim 5 clase, relevante pentru tema aleasă.
- [ ] Minim 3 dintre clase trebuie să fie corelate prin compunere (ex. să aveți o
dată membru de tip Adresă în clasa Contact, să aveți un vector de Angajat
în clasa Companie etc.)

#### Metode
- [x] Minim 3 getteri și 3 setteri pentru datele membru (pot fi pentru câmpuri
diferite, din clase diferite).
- [x] Minim 2 metode de „logică de business” care să aibă sens pentru tema
voastră (e.g.: calculează prețul unui produs aplicând o reducere, returnează
salariul mediu al angajaților din firmă etc.)
- [x] Pentru minim 2 clase trebuie să implementați o metodă de afișare pe ecran
a datelor din acea clasă (în ce format vreți voi).
Alternativ, se acceptă și doar să supraîncărcați operator<< pentru aceste
clase și să implementați acolo afișarea.
- [x] Pentru minim o clasă trebuie să supraîncărcați operator<< pentru afișare
(dacă ați făcut acest lucru la subpunctul anterior, nu este nevoie să o mai
faceți încă o dată).

#### Constructori
- [x] Minim 3 clase trebuie să aibă constructori fără parametru, respectiv para-
metrizați, care să inițializeze datele membre.

#### Constructori de copiere si operator=
- [x] Pentru minim două clase trebuie să implementați explicit constructorul de
copiere și să supraîncărcați operator=.
- [x] Cel puțin una dintre aceste clase trebuie să fie dintre cele care folosesc
alocare dinamică.

#### Alocare dinamica
- [x] Minim o clasă trebuie să facă alocare dinamică de memorie (fie pentru un
singur obiect, fie pentru un vector de obiecte).
- [x] Toată memoria alocată dinamic trebuie eliberată corespunzător. Veți fi de-
punctați pentru memory leaks
- [x] Minim o clasă trebuie să aibă un destructor (netrivial).

#### Bonus
Fiecare cerință bonus valorează 1 punct. Puteți rezolva la alegere oricare două
dintre cele trei pentru a obține punctajul maxim.
Implementați un meniu interactiv în main, care să permită:
- [ ] Citirea de la tastatură și crearea a cel puțin 3 tipuri de obiecte dintre
cele definite de voi;
- [ ] Afișarea acestor obiecte, după ce au fost citite de aplicație;
- [ ] Apelarea unei metode pe ele (alta în afară de cea de afișare).
- [ ] Implementați constructorul de mutare și supraîncărcați operator= de
mutare pentru cel puțin o clasă care gestionează memorie alocată dinamic.
- [ ] Definiți și utilizați o clasă imbricată, asemănător cu clasa Nod de la exerci-
țiul 2 din laboratorul 1 (dar trebuie să aibă sens pentru tema voastră).

[v0.1-alpha](https://github.com/flawreen/Netflip/releases/tag/v0.1-alpha):
- Added String class.
- Added Movie class with basic functionalities.
