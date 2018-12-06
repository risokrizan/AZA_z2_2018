
// uloha2-bonus.c -- Richard Križan, 12.5.2018 23:01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int Plength = 1000000;
char P[1000001];
int Ppravidlo[3][1000001];
int Qpravidlo[3][1001];
int prvyIndex=2000000;


void generateP() {
    P[0] = 'a';
    long read = 0, write = 1;
    while (Plength > write) {
        if (read % 39 == 38) read++;
        char r = P[read++];
        if (r == 'a') {
            P[write++] = 'b';
            P[write++] = 'a';
            P[write++] = 'a';
        } else if (r == 'b') {
            P[write++] = 'a';
            P[write++] = 'c';
        } else if (r == 'c') { P[write++] = 'b'; };
    }
    P[Plength] = 0;
}

int check(char *pattern, int dlzkaPattern, int p, int q, int pocetOp, int pln,bool *koniec) {
    int min = 2000000;
    int vysledok = 2000000;
    if (q == dlzkaPattern){
        *koniec = true;
        return pocetOp;
    }
    if (q > dlzkaPattern || p > pln)
        return 2000000;


    if (P[p] == pattern[q]) {
        vysledok = check(pattern, dlzkaPattern, p + 1, q + 1, pocetOp, pln, koniec);
        if (vysledok < min) {
            min = vysledok;
            if(p<prvyIndex)
                prvyIndex=p;
            if (*koniec){
                return min;
            }
        }
    }

    if (Ppravidlo[0][p] == 1 && Qpravidlo[0][q] == 1) {
        vysledok = check(pattern, dlzkaPattern, p + 2, q + 3, pocetOp + 1, pln,koniec);
        if (vysledok < min) {
            min = vysledok;
            if(p<prvyIndex)
                prvyIndex=p;
            if (*koniec){
                return min;
            }
                
        }
        
    }
    if (Ppravidlo[1][p] == 1 && Qpravidlo[1][q] == 1) {
        vysledok = check(pattern, dlzkaPattern, p + 4, q + 5, pocetOp + 1, pln,koniec);
        if (vysledok < min) {
            min = vysledok;
            if(p<prvyIndex)
                prvyIndex=p;
            if (*koniec){
                return min;
            }
        }
    }
    if (Ppravidlo[2][p] == 1 && Qpravidlo[2][q] == 1) {
        vysledok = check(pattern, dlzkaPattern, p + 9, q + 1, pocetOp + 1, pln,koniec);
        if (vysledok < min) {
            min = vysledok;
            if(p<prvyIndex)
                prvyIndex=p;
            if (*koniec){
                return min;
            }
        }

    }
    return min;

}

void prefixy(char *retazec, int dlzkaPref, int *pref) {
    int zhoda;
    pref[0] = -1;
    for (int i = 0; i < dlzkaPref; i++) {
        zhoda = pref[i];
        while (zhoda >= 0 && retazec[zhoda] == retazec[i])
            zhoda = pref[zhoda];
        pref[i + 1] = zhoda + 1;
    }
}

void KMP(char *pattern, int dlzkaPattern, char *target, int dlzkaTarget, int prvyIndex, int pole) {

    int *f = (int *) calloc(dlzkaPattern + 1, sizeof(int));
    prefixy(pattern, dlzkaPattern, f);
    int position = 0;
    for (int i = 0; i < dlzkaTarget; i++) {
        while (position >= 0 && target[i] != pattern[position]) position = f[position];
        position++;
        if (position == dlzkaPattern) {
            if (pole == 1)
                Ppravidlo[prvyIndex][i + 1 - dlzkaPattern] = 1;
            if (pole == 0)
                Qpravidlo[prvyIndex][i + 1 - dlzkaPattern] = 1;
            position = f[position];
        }
    }
}

int main() {


    int n, i, len;
    scanf("%d", &n);
    generateP();
    KMP("aa", 2, P, Plength + 1, 0, 1);
    KMP("abac", 4, P, Plength + 1, 1, 1);
    KMP("baabaabaa", 9, P, Plength + 1, 2, 1);
    char Q[1001];
    while (n--) {
        int dlzkaQ = 0;
        int vysledok=2000000;
        bool koniec= false;
        prvyIndex=2000000;
        scanf("%d %s", &dlzkaQ, &Q);
        KMP("aaa", 3, Q, strlen(Q), 0, 0);
        KMP("abaac", 5, Q, strlen(Q), 1, 0);
        KMP("a", 1, Q,strlen(Q), 2, 0);
        for (int i=0;i<dlzkaQ;i++) {
            int a = check(Q, strlen(Q), i, 0, 0, dlzkaQ,&koniec);
            if(a<vysledok)
                vysledok=a;

        }
        if (vysledok==2000000)
            printf("No solution.\n");
        else {
            printf("%d,%d\n",prvyIndex,vysledok);

        }

    }

    return 0;
}