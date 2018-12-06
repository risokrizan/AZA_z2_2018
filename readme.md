Máme reťazec R nad abecedou {a, b, c}. Reťazec Q vznikol z podreťazca R' reťazca R vykonaním nejakého množstva nasledujúcich operácií vykonaných na disjunktných miestach reťazca R' (t.j. každé písmenko sa môže zúčastniť iba jednej operácie, a písmenká ktoré vznikli niektorou z operácií sa už nemôžu zúčastňovať ďalších operácií):

Pravidlo 1: aa->aaa
Pravidlo 2: abac->abaac
Pravidlo 3: baabaabaa->a
Preto napríklad reťazec baabaabaabacbaabaaac môžeme pomocou operácií zmeniť na reťazec abacbaaabaaac Pravidlo 3, Pravidlo 1; ale nie na reťazec abaacbaabaaac, pretože to by vyžadovalo aby sa jedno z a-čok zúčastnilo dvoch operácií.

Nájdite polohu podreťazca R' z ktorého reťazec Q mohol vzniknúť a počet operácií potrebných na zmenu reťazca R' na reťazec Q. Spomedzi všetkých kandidátov na poreťazec R' vyberte tento poreťazec tak, aby bol celkový počet operácií potrebných na získanie reťazca Q z R' minimálny. V prípade rovnakého počtu operácií vráťte polohu reťazca R' najbližšie k začiatku reťazca R.

Reťazec R je podreťazcom reťazca P (je súčasťou zadania), ktorý nie je ničím špeciálny (pre vyriešenie úlohy nie je potrebné vedieť nič špecifické o reťazci P, pre vyriešenie extra ťažkého zadania je relevantá informácia, že P nie je nijak špeciálne zákerný).

Formát vstupu:
Reťazec R nie je súčasťou vstupu. Namiesto toho si ho vygenerujte nasledujúcou funkciou. Reťazec R obsahuje prvých n znakov reťazca P.

int Plength=1000000;
char P[1000001];
void generateP(){
    P[0]='a';
    long read=0,write=1;
    while(Plength>write) {
        if (read % 39 ==38) read++;
        char r=P[read++];
        if (r=='a') {P[write++]='b';P[write++]='a';P[write++]='a';}
        else if (r=='b') {P[write++]='a';P[write++]='c';}
        else if (r=='c') {P[write++]='b';};
    }
    P[Plength]=0;
}
Prvy riadok obsahuje počet podvstupov. Následne každý ďalší riadok obsahuje jeden podvstup. Podvstup sa začína číslom n udávajúci dĺžku reťazca R a nasleduje reťazec Q. Za posledným podvstupom nasleduje prázdny riadok. Môžete predpokladať, že 0<=n<=1000000 a dĺžka Q je <=1000.

Formát výstupu:
Výstupný súbor obsahuje pre každý podvstup jeden riadok s dvoma čísalami oddelenými čiarkou. Prvé číslo udáva polohu polohu reťazca R' v R, druhé číslo udáva počet vykonaných operácií. Ak takýto reťazec R' neexistuje, vypíše sa na výstup reťazec No solution. Posledný riadok je prázdny.

Pamäťový limit: cca 128 MB