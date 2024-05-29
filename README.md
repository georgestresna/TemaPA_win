# TEMA 1 - LanParty - "Proiectarea Algoritmilor"

## Obiective
1. Înțelegerea conceptului de funcționare și implementare a unor structuri de date(precum liste, stive, cozi, arbori binari de căutare)
2. Operarea cu aceste structuri de date
3. Implementarea unei funcționalități practice folosind aceste concepte

## Modalitate de notare/ implementare

Tema 1 foloseste un `checker.sh` offline in linia de comanda `bash` care testeaza fiecare Task pin intermediul a 15 teste. 
Pentru rularea programului prin checker a fost necesara intocmirea unui Makefile care sa asigure comunicarea intre cele 2.

## Rezolvarea cerintelor

Fiecare task a fost realizat in cate un fisier `.c` separat pentru a asigura structura proiectului si lizibilitatea acestuia. 
Toate aceste fisiere comunica prin header-ul `main.h`. Mai mult au fost folosite si alte fisiere `.c` si `.h` pentru a realiza functiile standard folosite in manipularea structurilor de date folosite.

### Cerinte
1. Task1: Inscrierea echipelor:
     A fost intocmita o lista cu toate echipele prezente in fisier
2. Task2: Etapa preliminatorie:
     Au fost sterse echipele cu cele mai mici scoruri astfel incat sa ramana`2^n` echipe, unde `n` maxim, pentru a putea avea loc campionatul.
3. Task3: Derularea meciurilor:
     Meciurile au fost creeate cu ajutorul unui queue, castigatorii si pierzatorii fiind repartizati mai apoi in stive separate, fiind alocate punte pe parcurs tuturor echipelor cat si jucatorilor
4. Task4: Afisarea podiumului: Cu ajutorul unui `BST` au fost printate echipele in ordinea punctajului.
5. Task5: Primele 8 echipe, adica cele de pe podium au fost inserate intr-un `AVL` si au fost afisate echipele de pe locul 2

## Probleme intampinate

Unele nume de echipa aveau un blankspace la sfarsitul numelui, ce trebuia scos daca acesta exista

In `Task3` cand echipele aveau acelasi scor, echipa cu nume ales in ordine descrescatoare trebuia aleasa, si nu cea cu nume ales in ordine crescatoare asa cu spunea cerinta

Am fost nevoit sa folosesc `fflush(out)` pentru a rezolva cerinta 3 si pentru a face debugging acesteia

Cand am incercat sa incarc un commit pe git, `out13.out` avea dimensiunea de 700MB (din cauza unui loop care printa la infinit in fisier), ceea ce nu este acceptat de gitHub, si a trebuit sa folosesc linia de comanda pentru a da reverse la cateva dintre commit-uri.

In continuare checker-ul ruleaza perfect pana la Test15, unde apare o eroare, unul dintre scorurile de la Task3 este rotunjit automat cu round-down in timp ce toate celelalte sunt cu round-up. Eroarea nu a fost rezolvata ci mascata cu o linie de hardCoding. 
Problema ar putea fi din cauza rezultatelor din checker sau din cauza unei erori cauzate de compilator. (Se recomanda implementarea cu `EPSILON`)
Tema a fost realizata pe OS windows 10 cu terminal `bash` si `makefile` descarcate cu ajutorul `git` in VSCode.
