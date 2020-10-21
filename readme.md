# Popis úkolu
## Zadání 

V první domácí úloze, kterou najdete v Souborech k předmětům / Algoritmy / Projekty / ial_2017_du1.tar.gz,  na vás čekají následující tři příklady:
1. C202: zásobník znaků v poli za 3 body,
2. C204: převod infixového výrazu na postfixový 3 body a
3. C206: dvousměrně vázaný lineární seznam za 4 body.
Vaším úkolem je v souborech c202.c, c204.c a c206.c doplnit těla funkcí a odevzdat je prostřednictvím IS FIT (nezapakované a s kódováním diakritiky v UTF8). Pozor, v příkladu c204 budete potřebovat zásobník znaků implementovaný v příkladu c202.

Správnost implementace si můžete ověřit pomocí základní testovací aplikace (např. c202-test.c), pro jejíž překlad máte připravený makefile (make all / make clean). Do hlaviček funkcí ani do hlavičkových souborů nezasahujte!

Jestliže implementace daného příkladu dává správné výsledky pro základní testovací aplikaci při překladu a spuštění na serveru eva.fit.vutbr.cz (správné výsledky najdete např. v souboru c202-test.out), získáváte za příklad 2 body. Jestliže Vaše implementace vyhoví i pokročilým testům (ty v zadání domácí úlohy nenajdete), získáváte za příklad i zbývající body (tedy 1 bod za příklad C202 a C204 a 2 body za příklad C206).

Doporučuji Vám proto, abyste si zkusili základní testovací aplikaci rozšířit a odhalit tak co nejvíce chyb ve své implementaci. Upravenou testovací aplikaci ale do IS FIT neodevzdávejte. Pokud se dostanete do časové tísně, nesnažte se řešit všechny příklady najednou v naději, že za částečné řešení něco dostanete. V takovém případě je výhodnější dokončit alespoň jeden či dva příklady pořádně.

## Důležitá upozornění!

Domácí úlohy budou hodnoceny automatickými skripty na serveru eva. Nedodržení zadání  (např. zásahy do kostry, přejmenování souborů s řešením, zapakování odevzdaných souborů, ap.) bude mít za následek ztrátu všech bodů za domácí úlohu!

Stejně tak budou 0 body hodnoceny příklady nepřeložitelné a ty, které se nekonečně zacyklí - příklad se se zlou potáže (přesněji řečeno s "kill -9"), pokud bude potřebovat k řešení více jak 15 s.

Domácí úlohu vypracovávejte, prosím, samostatně a své řešení si dobře chraňte! V případě odhalení plagiátorství či nedovolené spolupráce, nebude udělen zápočet a dále bude zváženo zahájení disciplinárního řízení.

# Hodnocení
7/10b

## Komentář učitele k hodnocení
Vážená studentko, vážený studente, 

zasílám Vám veškeré informace relevantní pro hodnocení 1. domácí úlohy. Měly by Vám pomoci odhalit chyby, které vedly k případné ztrátě bodů. 

Pokud je některý ze souborů *.output prázdný nebo výpis končí uprostřed testu, je to způsobeno tím, že příslušný test při hodnocení zhavaroval a část výpisu byla ztracena, protože se ještě nedostala z vyrovnávací paměti na disk. Hodnocení probíhalo na serveru eva, kde se projevují některé chyby, které se na jiných počítačích neprojevují (např. alokace paměti pro ukazatel místo pro prvek seznamu). Při hledání příčin, které vedly ke ztrátě bodů, si proto své řešení zkuste přeložit a spustit právě na tomto serveru. 

Prosím také, abyste si přiložené soubory pečlivě prostudoval(a) dříve, než začnete své hodnocení reklamovat. Reklamace je možná pouze osobně v kanceláři C306 (přes e-mail se reklamace nedají rozumně vyřídit), a to v konzultačních hodinách ve středu 22.11 od 8:00 do 9:00, budu zde minimalne do 10:00 (když mě zastihnete v kanceláři, lze i mimo tyto vyhlášené hodiny). Děkuji za pochopení! 

-------------------------- Přiložené soubory -------------------------------- 

tests.tar.gz - soubor testovacích programů napsaných v C. S těmito soubory byly Vaše projekty kompilovány. 
template-outputs.tar.gz - vzorové výstupy z testovacích skriptů. S těmito soubory byly porovnávány výstupy z Vašeho programu. 
xlogin00.tar.gz - výstupy Vašich skiptů (*.output), výsledky porovnávání (*.results), logy z kompilace (*.log) a makefily, se kterými byly příklady kompilovány (Makefile.*). 

----------------------------- Bodovací tabulka ------------------------------ 

Příklady v úloze: c202 až 3 body, c204 až 3 body, c206 až 4 body
Jednotlivé testy:
c202-test(max_9_OK):
	0<=pocet_OK<8: 0 b.
	8<=pocet_OK<9: 1 b.
	9<=pocet_OK: 2 b.
c202-advanced-test(max_19_OK):
	0<=pocet_OK<19: 0 b.
	19<=pocet_OK: 1 b.
c204-test(max_15_OK):
	0<=pocet_OK<13: 0 b.
	13<=pocet_OK<15: 1 b.
	15<=pocet_OK: 2 b.
c204-advanced-test(max_19_OK):
	0<=pocet_OK<19: 0 b.
	19<=pocet_OK: 1 b.
c206-test(max_18_OK):
	0<=pocet_OK<16: 0 b.
	16<=pocet_OK<18: 1 b.
	18<=pocet_OK: 2 b.
c206-advanced-test(max_58_OK):
	0<=pocet_OK<46: 0 b.
	46<=pocet_OK<58: 1 b.
	58<=pocet_OK: 2 b. 

------------------------ Bodové hodnocení pro xvanic09-----------------------
c202-test(max_9_OK) - počet získaných bodů: 2 (9 sections OK)
c202-advanced-test(max_19_OK) - počet získaných bodů: 0 (15 sections OK)
c204-test(max_15_OK) - počet získaných bodů: 2 (15 sections OK)
c204-advanced-test(max_19_OK) - počet získaných bodů: 1 (19 sections OK)
c206-test(max_18_OK) - počet získaných bodů: 2 (18 sections OK)
c206-advanced-test(max_58_OK) - počet získaných bodů: 0 (0 sections OK)

Celkem: 7 bodů

