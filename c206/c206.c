	
/* c206.c **********************************************************}
{* Téma: Dvousměrně vázaný lineární seznam
**
**                   Návrh a referenční implementace: Bohuslav Křena, říjen 2001
**                            Přepracované do jazyka C: Martin Tuček, říjen 2004
**                                            Úpravy: Kamil Jeřábek, říjen 2017
**
** Implementujte abstraktní datový typ dvousměrně vázaný lineární seznam.
** Užitečným obsahem prvku seznamu je hodnota typu int.
** Seznam bude jako datová abstrakce reprezentován proměnnou
** typu tDLList (DL znamená Double-Linked a slouží pro odlišení
** jmen konstant, typů a funkcí od jmen u jednosměrně vázaného lineárního
** seznamu). Definici konstant a typů naleznete v hlavičkovém souboru c206.h.
**
** Vaším úkolem je implementovat následující operace, které spolu
** s výše uvedenou datovou částí abstrakce tvoří abstraktní datový typ
** obousměrně vázaný lineární seznam:
**
**      DLInitList ...... inicializace seznamu před prvním použitím,
**      DLDisposeList ... zrušení všech prvků seznamu,
**      DLInsertFirst ... vložení prvku na začátek seznamu,
**      DLInsertLast .... vložení prvku na konec seznamu, 
**      DLFirst ......... nastavení aktivity na první prvek,
**      DLLast .......... nastavení aktivity na poslední prvek, 
**      DLCopyFirst ..... vrací hodnotu prvního prvku,
**      DLCopyLast ...... vrací hodnotu posledního prvku, 
**      DLDeleteFirst ... zruší první prvek seznamu,
**      DLDeleteLast .... zruší poslední prvek seznamu, 
**      DLPostDelete .... ruší prvek za aktivním prvkem,
**      DLPreDelete ..... ruší prvek před aktivním prvkem, 
**      DLPostInsert .... vloží nový prvek za aktivní prvek seznamu,
**      DLPreInsert ..... vloží nový prvek před aktivní prvek seznamu,
**      DLCopy .......... vrací hodnotu aktivního prvku,
**      DLActualize ..... přepíše obsah aktivního prvku novou hodnotou,
**      DLSucc .......... posune aktivitu na další prvek seznamu,
**      DLPred .......... posune aktivitu na předchozí prvek seznamu, 
**      DLActive ........ zjišťuje aktivitu seznamu.
**
** Při implementaci jednotlivých funkcí nevolejte žádnou z funkcí
** implementovaných v rámci tohoto příkladu, není-li u funkce
** explicitně uvedeno něco jiného.
**
** Nemusíte ošetřovat situaci, kdy místo legálního ukazatele na seznam 
** předá někdo jako parametr hodnotu NULL.
**
** Svou implementaci vhodně komentujte!
**
** Terminologická poznámka: Jazyk C nepoužívá pojem procedura.
** Proto zde používáme pojem funkce i pro operace, které by byly
** v algoritmickém jazyce Pascalovského typu implemenovány jako
** procedury (v jazyce C procedurám odpovídají funkce vracející typ void).
**/

#include "c206.h"

int solved;
int errflg;

void DLError() {
/*
** Vytiskne upozornění na to, že došlo k chybě.
** Tato funkce bude volána z některých dále implementovaných operací.
**/	
    printf ("*ERROR* The program has performed an illegal operation.\n");
    errflg = TRUE;             /* globální proměnná -- příznak ošetření chyby */
    return;
}

void DLInitList (tDLList *L) {
/*
** Provede inicializaci seznamu L před jeho prvním použitím (tzn. žádná
** z následujících funkcí nebude volána nad neinicializovaným seznamem).
** Tato inicializace se nikdy nebude provádět nad již inicializovaným
** seznamem, a proto tuto možnost neošetřujte. Vždy předpokládejte,
** že neinicializované proměnné mají nedefinovanou hodnotu.
**/

 /*porovede inizializaciu zoznamu teda nastavi potrebne prvky zoznamu na null*/
    L->Act = NULL;
    L->Last = NULL;
    L->First = NULL;
}

void DLDisposeList (tDLList *L) {
/*
** Zruší všechny prvky seznamu L a uvede seznam do stavu, v jakém
** se nacházel po inicializaci. Rušené prvky seznamu budou korektně
** uvolněny voláním operace free. 
**/
 struct tDLElem *elem; //zavedieme si pomocnu "premennu" typu ukazatel
 struct tDLElem *tmp; //zavedieme si pomocnu "premennu" typu ukazatel
 elem = L->First; //priradime premennej elm hodnotu first
 while(elem != NULL) { //pokial sa elem  nevyprazdni tak
   tmp = elem->rptr; //priradime tmp hodnotu rptr z elem teda ukazatel na dalsi prvok
   free(elem); //korektne uvolnime elem cez free
   elem = tmp; //do elem dame ukazatel na dalsi prvok
 }
 /*uvede seznam do stavu, v jakém se nacházel po inicializaci*/
 L->Act = NULL;
 L->Last = NULL;
 L->First = NULL;
}

void DLInsertFirst (tDLList *L, int val) {
/*
** Vloží nový prvek na začátek seznamu L.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
 tDLElemPtr newElem = malloc(sizeof(struct tDLElem)); //zaalokujeme pamet pre novy prvok
 if (newElem != NULL) { //ak bola alokace uspesna tak vlozi novy prvok na zaciatok zoznamu
  newElem->data = val;
  newElem->rptr = L->First;
  newElem->lptr = NULL;
  if (L->First != NULL) {
   L->First->lptr = newElem;
  }
  else {
   L->Last = newElem;
  }
  L->First = newElem;
 }
 else { // V případě, že není dostatek paměti pro nový prvek při operaci malloc, volá funkci DLError()
  DLError();
 }
}

void DLInsertLast(tDLList *L, int val) {
/*
** Vloží nový prvek na konec seznamu L (symetrická operace k DLInsertFirst).
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/

 /*to samé čo DLInsertFirst ibaže vklada prvok na koniec teda hodnoty First,Last a rptr,lptr sú prehodené */
 tDLElemPtr newElem = malloc(sizeof(struct tDLElem));
 if (newElem != NULL) {
  newElem->data = val;
  newElem->lptr = L->Last;
  newElem->rptr = NULL;
  if (L->Last != NULL) {
   L->Last->rptr = newElem;
  }
  else {
   L->First = newElem;
  }
  L->Last = newElem;
 }
 else {
  DLError();
 }
}

void DLFirst (tDLList *L) {
/*
** Nastaví aktivitu na první prvek seznamu L.
** Funkci implementujte jako jediný příkaz (nepočítáme-li return),
** aniž byste testovali, zda je seznam L prázdný.
**/
	L->Act = L->First; //Nastaví aktivitu na první prvek seznamu L.
}

void DLLast (tDLList *L) {
/*
** Nastaví aktivitu na poslední prvek seznamu L.
** Funkci implementujte jako jediný příkaz (nepočítáme-li return),
** aniž byste testovali, zda je seznam L prázdný.
**/
    L->Act = L->Last; //Nastaví aktivitu na poslední prvek seznamu L.
}

void DLCopyFirst (tDLList *L, int *val) {
/*
** Prostřednictvím parametru val vrátí hodnotu prvního prvku seznamu L.
** Pokud je seznam L prázdný, volá funkci DLError().
**/
 if(L == NULL) { //Pokud je seznam L prázdný, volá funkci DLError()
  DLError();
 }
 else {
  *val = L->First->data; //Prostřednictvím parametru val vrátí hodnotu prvního prvku seznamu L
 }
}

void DLCopyLast (tDLList *L, int *val) {
/*
** Prostřednictvím parametru val vrátí hodnotu posledního prvku seznamu L.
** Pokud je seznam L prázdný, volá funkci DLError().
**/
 if(L == NULL) { //Pokud je seznam L prázdný, volá funkci DLError()
  DLError();
 }
 else {
  *val = L->Last->data; //Prostřednictvím parametru val vrátí hodnotu posledního prvku seznamu L
 }
}

void DLDeleteFirst (tDLList *L) {
/*
** Zruší první prvek seznamu L. Pokud byl první prvek aktivní, aktivita 
** se ztrácí. Pokud byl seznam L prázdný, nic se neděje.
**/
 struct tDLElem *elem; //zadefinujeme pomocny prvok typu ukazatel
 if (L->First != NULL){  //ak zoznam nie je prazdny tak
  elem = L->First; //do elem vlozime hodnotu prveho prvku
  if (L->Act == L->First){ //první byl aktivní
   L->Act = NULL; //ruší se aktivita
  }
  if (L->First == L->Last){//seznam měl jediný prvek–zruší se
   L->First = NULL;
   L->Last = NULL;
  }
  else {
   L->First = L->First->rptr; //aktualizace začátku seznamu
   L->First->lptr = NULL; //ukazatel prvního doleva na NULL
  }
  free(elem); //korektne uvolnime elem
 }
}

void DLDeleteLast (tDLList *L) {
/*
** Zruší poslední prvek seznamu L. Pokud byl poslední prvek aktivní,
** aktivita seznamu se ztrácí. Pokud byl seznam L prázdný, nic se neděje.
**/
 /*to same co DLDeleteFirst iba rusime posledny prvok*/
 struct tDLElem *elem;
 if (L->Last != NULL){
  elem = L->Last;
  if (L->Act == L->Last){ //posledni byl aktivní
   L->Act = NULL; //ruší se aktivita
  }
  if (L->Last == L->First){//seznam měl jediný prvek–zruší se
   L->Last = NULL;
   L->First = NULL;
  }
  else {
   L->Last = L->Last->lptr; //aktualizace konce seznamu
   L->Last->rptr = NULL; //ukazatel posledniho doprava na NULL
  }
  free(elem);
 }
}

void DLPostDelete (tDLList *L) {
/*
** Zruší prvek seznamu L za aktivním prvkem.
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** posledním prvkem seznamu, nic se neděje.
**/
	if(L->Act != NULL) { //overenie či sa nachadza aktivny prvok
     if(L->Act->rptr != NULL) { //ak ano tak kontrola či posledny prvok nie je aktivny prvok a nasledne zrusenie prvku za aktivnym
      struct tDLElem *elem; 
      elem = L->Act->rptr;
      L->Act->rptr = elem->rptr;
      if(elem == L->Last) { //porovnava hodnoty pomocnej premennej a posledneho prvku v zozname a nasledne sa stava posledny prvok aktivnym
       L->Last = L->Act;
      }
      else {
       elem->rptr->lptr = L->Act;
      }
      free(elem);
     }
    }
}

void DLPreDelete (tDLList *L) {
/*
** Zruší prvek před aktivním prvkem seznamu L .
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** prvním prvkem seznamu, nic se neděje.
**/

/*to same co DLPostDelete akurat ze sa vykonava zprava dolava*/
    if(L->Act != NULL) {
     if(L->Act->lptr != NULL) {
      struct tDLElem *elem;
      elem = L->Act->lptr;
      L->Act->lptr = elem->lptr;
      if(elem == L->First) {
       L->First = L->Act;
      }
      else {
       elem->lptr->rptr = L->Act;
      }
      free(elem);
     }
    }
}

void DLPostInsert (tDLList *L, int val) {
/*
** Vloží prvek za aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se neděje.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
	if(L->Act != NULL) { //kontrolujeme ci prvok nie je aktivny a ak nie tak
     tDLElemPtr newElem = malloc(sizeof(struct tDLElem)); //alokujeme pamet pre novy prvok
     if(newElem != NULL) { //ak je alokacia uspesna tak vlozime novy prvok za aktivny
      newElem->data = val;
      newElem->rptr = L->Act->rptr;
      newElem->lptr = L->Act;

      if (L->Act == L->Last) { //ak je aktivny prvok zaroven poslednym tak hodnoty noveho prvku priradi do posledneho
       L->Last = newElem;
      } 
	  else {
       newElem->rptr->lptr = newElem;
      }
     }
     else {
      DLError(); //V případě, že není dostatek paměti pro nový prvek při operaci malloc, volá funkci DLError()
     }
    }
}

void DLPreInsert (tDLList *L, int val) {
/*
** Vloží prvek před aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se neděje.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/

/*to same co DLPostInsert akurat vkladame pred aktivny prvok teda par premennych je v kode naopak, popis viz DLPostInsert*/
    if(L->Act != NULL) {
     tDLElemPtr newElem = malloc(sizeof(struct tDLElem));
     if(newElem != NULL) {
      newElem->data = val;
      newElem->lptr = L->Act->lptr;
      newElem->rptr = L->Act;

      if (L->Act == L->First) {
       L->First = newElem;
      } else {
       newElem->lptr->rptr = newElem;
      }
     }
     else {
      DLError();
     }
    }
}

void DLCopy (tDLList *L, int *val) {
/*
** Prostřednictvím parametru val vrátí hodnotu aktivního prvku seznamu L.
** Pokud seznam L není aktivní, volá funkci DLError ().
**/
 if(L->Act == NULL) { //Pokud seznam L není aktivní, volá funkci DLError ()
  DLError();
 }
 else { //Prostřednictvím parametru val vrátí hodnotu aktivního prvku seznamu L
  *val = L->Act->data;
 }
}

void DLActualize (tDLList *L, int val) {
/*
** Přepíše obsah aktivního prvku seznamu L.
** Pokud seznam L není aktivní, nedělá nic.
**/
	if(L->Act != NULL) { //ak je zoznam aktivny
     L->Act->data = val; //Přepíše obsah aktivního prvku seznamu L hodnout vo val
    }
 //ak nie zoznam je aktivny nerobí nič
}

void DLSucc (tDLList *L) {
/*
** Posune aktivitu na následující prvek seznamu L.
** Není-li seznam aktivní, nedělá nic.
** Všimněte si, že při aktivitě na posledním prvku se seznam stane neaktivním.
**/
	if(L->Act != NULL) { //ak je zoznam aktivny tak
     L->Act = L->Act->rptr; //Posune aktivitu na následující prvek seznamu L cez rptr  Act prvku
    }
 //ak nie je zoznam aktivny nerobi nič
}


void DLPred (tDLList *L) {
/*
** Posune aktivitu na předchozí prvek seznamu L.
** Není-li seznam aktivní, nedělá nic.
** Všimněte si, že při aktivitě na prvním prvku se seznam stane neaktivním.
**/
    if(L->Act != NULL) { //ak je zoznam aktivny
     L->Act = L->Act->lptr; //Posune aktivitu na předchozí prvek seznamu L
    }
 //inak nič nerobí
}

int DLActive (tDLList *L) {
/*
** Je-li seznam L aktivní, vrací nenulovou hodnotu, jinak vrací 0.
** Funkci je vhodné implementovat jedním příkazem return.
**/
 return (L->Act != NULL ? 1 : 0); //Je-li seznam L aktivní, vrací nenulovou hodnotu, jinak vrací 0
}

/* Konec c206.c*/
