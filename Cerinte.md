### Mostenire
- Definiți minim două ierarhii diferite de moștenire (două ierarhii de moștenire sunt considerate diferite dacă nu au aceeași clasă de bază 
și aceeași clasă care moștenește clasa/clasele de bază).
  - Ierarhia Person
  - Ierarhia Content
- Utilizați minim doi modificatori de acces diferiți pe clasa care se moștenește (public/protected/private); alegerea vă aparține, dar trebuie să
fie justificată în funcție de nevoile proiectului.
  - User mosteneste public Person
  - Movie mosteneste protected Content
- Minim o clasă care să folosească moștenire multiplă (să extindă mai multe clase/interfețe).
  - SuperUser
- Apelați cel puțin o dată un constructor (cu parametri) dintr-o clasă de bază, folosind o listă de inițializare în constructorul clasei copil.
  - Constructorul parametrizat al clasei User
- Minim două date membru și minim o metodă care să aibă modificatorul de acces protected (în mod util, să fie accesate/apelate dintr-o clasă care le moștenește).
  - Clasa Person -> User

### Interfete si metode virtuale
- Definiți și extindeți (moșteniți) minim o interfață (clasă fără date membru, doar metode pur virtuale și un destructor virtual) care să aibă minim două
metode (alternativ: minim două interfețe, fiecare cu cel puțin o metodă).
  - Clasa Content
- Definiți și extindeți (moșteniți) minim o clasă de bază abstractă (clasă care poate avea date membru, dar are cel puțin o metodă pur virtuală).
  - Clasa Person -> User
- Trebuie să aveți / să identificați în proiect cel puțin o situație în care să fie nevoie de și să se apeleze destructorul virtual (i.e. să ștergeți un obiect
alocat dinamic de tipul unei clase moștenitoare, la care să vă referiți prin intermediul unui pointer la clasa de bază).
  - Mostenirea in diamant SuperUser
- Definiți cel puțin 4 metode virtuale care să fie suprascrise în clasele moștenitoare. Pot fi pur virtuale sau cu o implementare implicită. 
Se iau în considerare și metodele definite la celelalte subpuncte, exceptând destructorii
virtuali.
  - whoAmI in Person
  - addAward in Content
  - increaseViewCount in Content
  - advertiseProduct in Subscription
 
### Polimorfism la executie
- Identificați minim 4 locuri în care să aibă loc polimorfism la execuție (dynamic dispatch) în proiectul vostru (e.g. apelul unor metode virtuale prin intermediul unor pointeri/referințe către clasa de bază).
  - TODO
- Identificați minim 4 instanțe de upcasting în codul vostru (e.g. atribuirea unor obiecte de tipul unor clase moștenite la pointeri/referințe către clasa de bază).
  - TODO
- Realizarea downcasting-ului în cel puțin o situație în codul vostru (unde are sens), folosind dynamic_cast sau RTTI.
  - TODO

### Exceptii
- Definiți minim un tip de excepție custom, care să extindă clasa exception
din biblioteca standard.
  - InvalidPhoneNumber
  - InvalidAward
  - NegativeBalance
  - InexistentAccount
  - ExistingObject
- Aruncați excepții în minim 4 funcții/metode diferite (folosiți tipuri de ex-
cepții definite de voi sau cele din biblioteca standard).
  - functia setPhone din User
    - invalid_argument 
    - InvalidPhoneNumber
  - functia addAward din Movie
    - InvalidAward
  - functia addBalance din User
    - NegativeBalance
    - InexistentAccount
  - functia buySubscription din User
    - NegativeBalance
    - ExistingObject
    - InexistentAccount
- Implementați minim un bloc try...catch care să prindă o excepție arun-
cată de voi (cu mențiunea explicită a tipului acesteia) și să o trateze într-un
fel (în funcție de specificul erorii).
  - in functia setPhone din User
- Implementați minim un bloc try...catch care să prindă o excepție, să o
proceseze și să re-arunce un alt tip de excepție din blocul catch.
  - in functia setPhone din User

### Variabile si metode statice
- Definiți o variabilă membru statică în cel puțin o clasă + cealalta cerinta
  - movieCount in Director
  - increaseMovieCount()
  - getMovieCount()

### Bonus
- Minim o situație de moștenire în diamant (trebuie să aibă sens pentru tema voastră). Moștenirea în diamant se referă la a avea o clasă de bază, pe care
o moștenesc cu virtual două clase distincte, iar apoi aveți o clasă care moștenește ambele clase intermediare.
  - SuperUser
- Utilizarea unei lambda expresii pentru a parametriza funcționalitatea unei funcții sau a unei clase. Puteți transmite ca parametru sau reține o lambda
expresie folosind tipul de date std::function. Se acordă punctaj parțial dacă doar folosiți lambda expresii pentru apelarea
unor funcții care deja există în biblioteca standard (de exemplu, std::sort), fără să definiți voi o funcție/clasă care să primească un obiect de acest tip.
  - TODO

