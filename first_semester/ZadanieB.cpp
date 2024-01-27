//Wiktoria Nierobot
#include <iostream>
using namespace std;

int main(){
    
    char komenda = 'A';
    int IloscSesji;
    int zakres, indeks, pomocnicza = 0;
    
    cin >> IloscSesji;
    
    while (IloscSesji != 0) {
        
        int DlugoscTablicy;
        cin >> DlugoscTablicy;
        int tab[DlugoscTablicy];
        
        int i = 0;
        while (DlugoscTablicy != i){
            cin >> tab[i];
        i = i + 1;
        }//while dlugosc tablicy
        
        i = 0;
        while (DlugoscTablicy != i){
            if((DlugoscTablicy - 1) == i ){
                cout << tab[i];
            }else
            cout << tab[i] << " ";
            i = i + 1;
        }//while dlugosc tablicy
        
        cout << endl;
        cin >> komenda;
        
        while(komenda != 'F'){
            if(komenda == 'R'){//odwracanie DZIALA XD
                
                cin >> indeks;
                cin >> zakres;
                if(zakres != 0){
                    //zamienianie indeksu na indeks rzeczywisty
                    indeks = indeks % DlugoscTablicy;
                    if(indeks < 0){
                        indeks = indeks + DlugoscTablicy;
                    }
                    
                    int j = 0;
                    while (DlugoscTablicy/zakres > j){
                        i = 0;
                        //sam algorytm zmieniania miejsc
                        while(i < (zakres/2)){
                            
                            
                            pomocnicza = tab[(indeks + i) % DlugoscTablicy];
                            tab[(indeks + i) % DlugoscTablicy] = tab[(indeks + zakres - 1 - i) % DlugoscTablicy];
                            tab[(indeks + zakres - 1 - i) % DlugoscTablicy] = pomocnicza;
                            
                            
                            i = i + 1;
                            
                        }
                        
                        indeks = (indeks + zakres) % DlugoscTablicy;
                        j = j + 1;
                    }
                    
                    
                    
                }
            }/*koniec if do odwracania*/
            else if(komenda == 'M'){//to bedzie pozniej
                int przesuniecie;
                int o_przesuniecie;
                cin >> indeks;
                indeks = indeks % DlugoscTablicy;
                if (indeks < 0)
                {
                    indeks = indeks + DlugoscTablicy;
                }
                cin >> zakres;
                cin >> o_przesuniecie;
                przesuniecie = o_przesuniecie;
                
                int zakresreszta, pomocnicza1 = 0, pomocnicza2;
                int iloscfragment = 1;
                if (zakres != 0)
                {
                    przesuniecie = przesuniecie % zakres;
                    if (przesuniecie < 0)
                    {
                        przesuniecie = przesuniecie + zakres;
                    }
                    iloscfragment = DlugoscTablicy / zakres;
                    int j = 0;
                    
                    while (iloscfragment > j)
                    {
                        int k = 0;
                        while (przesuniecie > k)
                        {
                            int l = 0;
                            while (zakres > l){
                                if (l == 0)
                                {
                                    pomocnicza1 = tab[(indeks + (1 % zakres)) % DlugoscTablicy];
                                    tab[(indeks + (1 % zakres)) % DlugoscTablicy] = tab[indeks];
                                }
                                else
                                {
                                    pomocnicza2 = tab[(indeks + (l + 1) % zakres) % DlugoscTablicy];
                                    tab[(indeks + (l + 1) % zakres) % DlugoscTablicy] = pomocnicza1;
                                    pomocnicza1 = pomocnicza2;
                                }
                                l = l + 1;
                            }
                            k = k + 1;
                        }
                        indeks = (indeks + zakres) % DlugoscTablicy;
                        j = j + 1;
                    }
                    
                    zakresreszta = DlugoscTablicy - zakres * iloscfragment;
                    przesuniecie = o_przesuniecie;
                    if (zakresreszta != 0){
                        przesuniecie = przesuniecie % zakresreszta;
                        if (przesuniecie < 0)
                        {
                            przesuniecie = przesuniecie + zakresreszta;
                        }
                        int k = 0;
                        while (przesuniecie > k)
                        {
                            int l = 0;
                            while (zakresreszta > l){
                                if (l == 0)
                                {
                                    pomocnicza1 = tab[(indeks + (1 % zakresreszta)) % DlugoscTablicy];
                                    tab[(indeks + (1 % zakresreszta)) % DlugoscTablicy] = tab[indeks];
                                }
                                else
                                {
                                    pomocnicza2 = tab[(indeks + (l + 1) % zakresreszta) % DlugoscTablicy];
                                    tab[(indeks + (l + 1) % zakresreszta) % DlugoscTablicy] = pomocnicza1;
                                    pomocnicza1 = pomocnicza2;
                                }
                                l = l + 1;
                            }
                            k = k + 1;
                        }
                    }
                }
            }//koniec if do przesuwania
            else if(komenda == 'C'){//zamiana - wydaje sie byc okej, poprawione
                cin >> indeks;
                indeks = indeks % DlugoscTablicy;
                if(indeks < 0){
                    indeks = indeks + DlugoscTablicy;
                }
                cin >> zakres;
    
                    if(zakres != 0){
                       
                        int j = 0;
                        while (DlugoscTablicy/(2 * zakres) > j){
                            //sam algorytm zmieniania miejsc
                            i = 0;
                            while (i < zakres){
                                
                                pomocnicza = tab[(indeks + i) % DlugoscTablicy];
                                tab[(indeks + i) % DlugoscTablicy] = tab[(indeks + i + zakres) % DlugoscTablicy];
                                tab[(indeks + i + zakres) % DlugoscTablicy] = pomocnicza;
                                i = i + 1;
                            }
                            j = j + 1;
                            indeks = (indeks + 2 * zakres) % DlugoscTablicy;
                        }
                    }
                }
            else if (komenda == 'S'){//dziala na 100
                cin >> indeks;
                indeks = indeks % DlugoscTablicy;
                if(indeks < 0){
                    indeks = indeks + DlugoscTablicy;
                }
                cin >> zakres;
                if(zakres != 0){
                    int zakresmodul;
                    if(zakres < 0)
                        zakresmodul = zakres * -1;
                    else
                        zakresmodul = zakres;
                    int iloscfragment = DlugoscTablicy / zakresmodul;
                    int j = 0;
                    while (iloscfragment > j){//to dziala
                        int i = 0;
                        while(i < (zakresmodul - 1)){
                            int k = 0;
                            while(k < (zakresmodul - 1)){
                                if(zakres > 0){
                                    if(tab[(indeks + k) % DlugoscTablicy] > tab[(indeks + k + 1)  % DlugoscTablicy]){
                                        pomocnicza = tab[(indeks + k) % DlugoscTablicy];
                                        tab[(indeks + k) % DlugoscTablicy] = tab[(indeks + k + 1) % DlugoscTablicy];
                                        tab[(indeks + k + 1) % DlugoscTablicy] = pomocnicza;
                                    }
                                }
                                else{
                                    if(tab[(indeks + k) % DlugoscTablicy] < tab[(indeks + k + 1)  % DlugoscTablicy]){
                                        pomocnicza = tab[(indeks + k) % DlugoscTablicy];
                                        tab[(indeks + k) % DlugoscTablicy] = tab[(indeks + k + 1) % DlugoscTablicy];
                                        tab[(indeks + k + 1) % DlugoscTablicy] = pomocnicza;
                                    }
                                }
                                k = k + 1;
                            }
                            i = i + 1;
                        }
                        indeks = (indeks + zakresmodul) % DlugoscTablicy;
                        j = j + 1;
                    }//koniec while do dlugosci
                    
                    
                    zakresmodul = DlugoscTablicy - iloscfragment * zakresmodul;
                    int i = 0;
                    while(i < (zakresmodul - 1)){
                        int k = 0;
                        while(k < (zakresmodul - 1)){
                            if(zakres > 0){
                                if(tab[(indeks + k) % DlugoscTablicy] > tab[(indeks + k + 1)  % DlugoscTablicy]){
                                    pomocnicza = tab[(indeks + k) % DlugoscTablicy];
                                    tab[(indeks + k) % DlugoscTablicy] = tab[(indeks + k + 1) % DlugoscTablicy];
                                    tab[(indeks + k + 1) % DlugoscTablicy] = pomocnicza;
                                }
                            }
                            else{
                                if(tab[(indeks + k) % DlugoscTablicy] < tab[(indeks + k + 1)  % DlugoscTablicy]){
                                    pomocnicza = tab[(indeks + k) % DlugoscTablicy];
                                    tab[(indeks + k) % DlugoscTablicy] = tab[(indeks + k + 1) % DlugoscTablicy];
                                    tab[(indeks + k + 1) % DlugoscTablicy] = pomocnicza;
                                }
                            }
                            k = k + 1;
                        }
                        i = i + 1;
                    }
                }
            }//s
                    
        cin >> komenda;

        }//koniec while do F

        IloscSesji = IloscSesji - 1;
        
        i = 0;
        while (DlugoscTablicy != i){
            if((DlugoscTablicy - 1) == i ){
                cout << tab[i];
            }else
            cout << tab[i] << " ";
            i = i + 1;
        }
        cout << endl;
        
  }//while ilosc sesji
    
}
