//Wiktoria Nierobot
#include <iostream>
using namespace std;
void Add(int a, int tab[]){//funkcja przechodzi
    int Dlugosc = 0;
    int z = 0;
    while(tab[z] != (-1))
    {
        if (tab[z] == (-1)) {
            break;
        }
        z ++;
    }//sprawdzam czy a analezy do uniwersum
    Dlugosc = z;
        if(a <= 4095 && a >= 1)
        {
            int i = 0, k = 0;
            //element nalezy do uniwersum wiec teraz sprawdzam czy juz wystapil w tablicy
            while(i < Dlugosc){
                if(tab[i] == a){
                    k = 1;
                }
                i++;
            }
            //jesli element wystapil to mam k = 1, a jesli nie to k pozostaje rowne 0
            if(k != 1){//interesuje mnie tylko gdy k = 0 bo wtedy znaczy ze element na pewno sie nie powtorzyl
                //tu wchodzi
                //przystepuje do przypisania elementu tablicy na ktorej bylo -1 waryosci a, a na miejscu o 1 dalej wartosci -1
                tab[Dlugosc] = a;//przypisanie elementu na ktorym stoi -1 wartosci a
                tab[Dlugosc + 1] = -1;//przypisanie kolejnemu elementowi w tablicy wartosci -1
       //do tego miejsca jest okej
                //teraz zostalo mi sortowanie i w teorii to tyle
                //sortowanie
                int k = 0;
                    while (k < Dlugosc) {
                        int l = 0;
                        while (l < Dlugosc - k) {
                            if (tab[l] > tab[l + 1]) {
                                // Zamiana miejscami, jeśli elementy są w złej kolejności
                                int x = tab[l];
                                tab[l] = tab[l + 1];
                                tab[l + 1] = x;
                            }
                            l++;
                        }
                        k++;
                    }
                tab[Dlugosc + 1] = (-1);
            }
        }
    
}
bool Empty(int tab[]){//funkcja przechodzi
    if(tab[0] == (-1))//zbior bedzie pusty jesli na 0 elemencie znajduje sie -1
    {
        return 1;
    }else
        return 0;
}
bool Nonempty(int tab[]){//funkcja przechodzi
    if(tab[0] != (-1))
    {
        return 1;
    }else
        return 0;
}
void MinMax(int tab[],int *min, int &max){//funkcja przechodzi
    //okreslanie dlugosci
    int Dlugosc = 0;
    int z = 0;
    while(tab[z] != (-1))
    {
        if (tab[z] == (-1)) {
            break;
        }
        z ++;
    }//sprawdzam czy a analezy do uniwersum
    Dlugosc = z;
    //sprawdzam czy zbior pusty
    if(tab[0] != (-1)){
        //funkcja minimum
        *min = tab[0];
        for(int i = 1; i < Dlugosc; i ++){
            if(tab[i] < *min){
                *min = tab[i];
            }
        }
        //funkcja maximum
        max = tab[0];
        int i = 0;
        while( i < Dlugosc){
            if(tab[i] > max){
                max = tab[i];
            }
            i ++;
        }
    }
}
void Union(int tab[],int tab2[],int tabS[]){//funkcja przechodzi
    int Dlugosc1 = 0;
    int z = 0;
    while(tab[z] != (-1))
    {
        if (tab[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc1 = z + 1;
    
    //sprawdzam dlugosc tab;icy ktora dodaje do pierwszej
    int Dlugosc2 = 0;
    z = 0;
    while(tab2[z] != (-1))
    {
        if (tab2[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc2 = z + 1;
    int DlugoscS = 0;
    tabS[0] = (-1);
    int l1 = 0;
    while(l1 < Dlugosc1)
    {
            int z = 0;
            while(tabS[z] != (-1))
            {
                if (tabS[z] == (-1)) {
                    break;
                }
                z ++;
            }
            DlugoscS = z;
            if(tab[l1] <= 4095 && tab[l1] >= 1)
            {
                int k = 0,i = 0;
                //element nalezy do uniwersum wiec teraz sprawdzam czy juz wystapil w tablicy
                while(i < DlugoscS){
                    if(tabS[i] == tab[l1]){
                        k = 1;
                    }
                    i++;
                }
                //jesli element wystapil to mam k = 1, a jesli nie to k pozostaje rowne 0
                if(k != 1){//interesuje mnie tylko gdy k = 0 bo wtedy znaczy ze element na pewno sie nie powtorzyl
                    //tu wchodzi
                    //przystepuje do przypisania elementu tablicy na ktorej bylo -1 waryosci a, a na miejscu o 1 dalej wartosci -1
                    tabS[DlugoscS] = tab[l1];//przypisanie elementu na ktorym stoi -1 wartosci a
                    tabS[DlugoscS + 1] = -1;//przypisanie kolejnemu elementowi w tablicy wartosci -1
                    
                }//przekopiowac add bez sortowania !!!!!!!!!!
                
            }
        l1++;
        
    }
    int l2 = 0;
        while(l2 < Dlugosc2)
        {
            int DlugoscS = 0;
            int z = 0;
            while(tabS[z] != (-1))
            {
                if (tabS[z] == (-1)) {
                    break;
                }
                z ++;
            }
            DlugoscS = z;
            if(tab2[l2] <= 4095 && tab2[l2] >= 1)
            {
                int k = 0,i = 0;
                //element nalezy do uniwersum wiec teraz sprawdzam czy juz wystapil w tablicy
                while(i < DlugoscS){
                    if(tabS[i] == tab2[l2]){
                        k = 1;
                    }
                    i++;
                }
                //jesli element wystapil to mam k = 1, a jesli nie to k pozostaje rowne 0
                if(k != 1){//interesuje mnie tylko gdy k = 0 bo wtedy znaczy ze element na pewno sie nie powtorzyl
                    //tu wchodzi
                    //przystepuje do przypisania elementu tablicy na ktorej bylo -1 waryosci a, a na miejscu o 1 dalej wartosci -1
                    tabS[DlugoscS] = tab2[l2];//przypisanie elementu na ktorym stoi -1 wartosci a
                    tabS[DlugoscS + 1] = -1;//przypisanie kolejnemu elementowi w tablicy wartosci -1
                    
                }//przekopiowac add bez sortowania !!!!!!!!!!
                
            }
           l2++;
        }
    //sortowanie
    z = 0;
    while(tabS[z] != (-1))
    {
        if (tabS[z] == (-1)) {
            break;
        }
        z ++;
    }
    DlugoscS = z;
    int k = 0;
        while (k < (DlugoscS - 1)) {
            int l = 0;
            while (l < DlugoscS - k - 1) {
                if (tabS[l] > tabS[l + 1]) {
                    // Zamiana miejscami, jeśli elementy są w złej kolejności
                    int x = tabS[l];
                    tabS[l] = tabS[l + 1];
                    tabS[l + 1] = x;
                }
                l++;
            }
            k++;
        }
    
            
        
    
}
void Create(int x, int tabZ[], int tabK[]){//przechodzi
            tabK[0] = -1;
            int l = 0;
            while(l < x){
                Add(tabZ[l],tabK);
                l++;
            }
            
}
void Intersection(int tab1[],int tab2[],int tabI[]){//funkcja przechodzi
    int l = 0;
    int k = 0;
    int j = 0;
    int Dlugosc1 = 0;
    int z = 0;
    while(tab1[z] != (-1))
    {
        if (tab1[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc1 = z + 1;
    
    
    
    //sprawdzam dlugosc tab;icy ktora dodaje do pierwszej
    int Dlugosc2 = 0;
    z = 0;
    while(tab2[z] != (-1))
    {
        if (tab2[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc2 = z + 1;
    k = 0;
    while (k < Dlugosc1){
        j = 0;
        while(j < Dlugosc2){
            if(tab1[k] == tab2[j]){
                tabI[l] = tab1[k];
                l++;
            }
            j++;
        }
        k++;
    }
    k = 0;
    int DlugoscI = 0;
    z = 0;
    while(tabI[z] != (-1))
    {
        if (tabI[z] == (-1)) {
            break;
        }
        z ++;
    }
    DlugoscI = z + 1;
    
}
void Difference(int Odjemna[], int Odjemnik[], int Roznica[]){//funkcja przechodzi
    int Dlugosc1 = 0;
    int z = 0;
    while(Odjemna[z] != (-1))
    {
        if (Odjemna[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc1 = z + 1;
    int Dlugosc2 = 0;
    z = 0;
    while(Odjemnik[z] != (-1))
    {
        if (Odjemnik[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc2 = z + 1;
    //przepisywanie do 3 tablicy
    int przepisz = 1;
    int k = 0, j = 0, l = 0;
    while (Odjemna[k] != (-1)){
        j = 0;
        przepisz = 1;
        while(Odjemnik[j] != (-1)){
            if(Odjemna[k] == Odjemnik[j]){
                przepisz = 0;
                break;
            }
            j++;
        }
        if(przepisz){
            Roznica[l] = Odjemna[k];
            l++;
        }
        k++;
    }
    Roznica[l] = (-1);
    
    //obliczanie dlugosci tablicy Roznica
    int DlugoscR = 0;
    z = 0;
    while(Roznica[z] != (-1))
    {
        if (Roznica[z] == (-1)) {
            break;
        }
        z ++;
    }
    DlugoscR = z + 1;
    
    //sortowanie
    for (int i = 0; i < DlugoscR- 2; i++) {// -2 bo nie uwzgledniam -1
        for (int j = 0; j < DlugoscR - i - 2; j++) {
            if (Roznica[j] > Roznica[j + 1]) {
                
                int pomocnicza = Roznica[j];
                Roznica[j] = Roznica[j + 1];
                Roznica[j + 1] = pomocnicza;
            }
        }
    }
}
void Complement(int tab1[], int tabD[]){//przechodzi
    int Dlugosc1 = 0;
    int z = 0;

    while(tab1[z] != (-1))
    {
        if (tab1[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc1 = z;
    z = 0;
    int DlugoscD = 0;
    int powtorzenie;
    if(tab1[0] == (-1)){
        int i = 1;
        while(i <= 4095){
            tabD[i - 1] = i;
            i++;
        }
        tabD[4095] = (-1);
    }else{
        int i = 1;
        while(i <= (4095)){
            powtorzenie = 0;
            z = 0;
            //sprawdzam czy liczba sie powtorzyla w pierwszej tablicy
            while(z < Dlugosc1){
                if(i == tab1[z]){
                    powtorzenie = 1;
                }
                
                z++;
            }
            if(powtorzenie != 1){//Add(i,tabD)
                tabD[DlugoscD] = i;
                DlugoscD++;
            }
            i++;
        }
        //sortowanie
        
        
        
        
        tabD[DlugoscD] = -1;
    }
    
}
bool Element(int a ,int tab1[]){//przechodzi
    //obliczam rozmiar tablicy
    int Dlugosc1;
    int z = 0;
    if(a != (-1)){
        while(tab1[z] != (-1))
        {
            if (tab1[z] == (-1)) {
                break;
            }
            z ++;
        }
        Dlugosc1 = z + 1;
        z = 0;
        int wystapil = 0;
        while(z < Dlugosc1){
            if(a == tab1[z]){
                wystapil ++;
            }
            z++;
        }
        if(wystapil != 0){
            return 1;
        }else return 0;
    }else return 0;
}
double Arithmetic(int tab[]){//przechodzi xd
    int z = 0;
    double suma = 0;
    double Arytmetyczna;
    //obliczanie dlugpsci tablicy
    double Dlugosc = 0;

    Dlugosc = z;
    if(tab[0] != (-1)){
        while(tab[z] != (-1)){
            suma = suma + tab[z];
            z++;
        }
        Dlugosc = z;
        Arytmetyczna = suma/Dlugosc;
        return Arytmetyczna;
    }else
    {
        Arytmetyczna = 0;
        return Arytmetyczna;
    }
}
double Harmonic(int tab[]){// ZLA ODPOWIEDZ ???
    int z = 0;
    double suma = 0;
    //obliczanie dlugpsci tablicy
    double Dlugosc = 0;
    int k = 0;
    while(tab[z] != (-1))
    {
        if (tab[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc = z;
    double zmiennoprzecinkowa;
    double jeden = 1;
    if(tab[0] != (-1)){
        while(tab[k] != (-1)){
            zmiennoprzecinkowa = tab[k];
            suma = suma + (jeden/zmiennoprzecinkowa);
            k++;
        }
        double Harmoniczna = 0;
        Harmoniczna = Dlugosc / suma;
        return Harmoniczna;
    }else return 1;
}
void Symmetric(int tab1[],int tab2[],int tabS[]){//BLAD KOMPILACJI???
    int Dlugosc1 = 0;
    int z = 0;
    while(tab1[z] != (-1))
    {
        if (tab1[z] == (-1)) {
            break;
        }
        z ++;
    }
    Dlugosc1 = z;
    int Dlugosc2 = 0;
    z = 0;
    while(tab2[z] != (-1)){
        if (tab2[z] == (-1)) {
            break;
        }
        z ++;
    }

    Dlugosc2 = z;
    int DlugoscS = 0;
    int ZnalezioneW1, ZnalezioneW2;
    z = 0;
    int y = 0;
    while (z < Dlugosc1){
        y = 0;
        ZnalezioneW2 = 0;
        while(y < Dlugosc2){
            if(tab1[z] == tab2[y]){
                ZnalezioneW2 = 1;
            }
            y++;
        }
        
        if(ZnalezioneW2 == 0){
         
            tabS[DlugoscS] = tab1[z];
            DlugoscS++;
        }
            z++;
    }

    z = 0;
    while (z < Dlugosc2){
        y = 0;
        ZnalezioneW1 = 0;
        while(y < Dlugosc1){
            if(tab2[z] == tab1[y]){
                ZnalezioneW1 = 1;
            }
            y++;
        }
        
        if(ZnalezioneW1 == 0){
            tabS[DlugoscS] = tab2[z];
            DlugoscS++;
        }
            z++;
    }
    

    int k = 0;
        while (k < DlugoscS - 1) {
            int l = 0;
            while (l < DlugoscS - 1) {
                if (tabS[l] > tabS[l + 1]) {
                    // Zamiana miejscami, jeśli elementy są w złej kolejności
                    int x = tabS[l];
                    tabS[l] = tabS[l + 1];
                    tabS[l + 1] = x;
                }
                l++;
            }
            k++;
        }
    tabS[DlugoscS] = (-1);
    
 
    
}

void Cardinality(int tab[],int* moc)//przechodzi
{
    int z = 0;
    while(tab[z] != (-1)){
        z++;
    }
    *moc = z;
}
bool Equal(int tab1[], int tab2[]){//tez za chuja nie wiem czemu nie dziala
        //obliczam dlugosc 1 tab;licy i dlugosc 2 tablicy jesli sa sonie rozne to od razu moge powiedziec ze sa nie rowne
    int z = 0;
    for(int k = 0; tab1[k] != (-1); k ++){
        z++;
    }
    int Dlugosc1 = z;
    z = 0;
    for(int k = 0; tab2[k] != (-1); k++){
        z++;
    }
    int Dlugosc2 = z;
    
    if(Dlugosc1 == Dlugosc2){
        //speawdzam czy elementy sa takie same
        if(Dlugosc1 == 0 && Dlugosc2 == 0){
            return 1;
        }else{
        int l = 0;
        int k = 0; z = 0;
        while(k < Dlugosc1){
            z = 0;
            while(z < Dlugosc2){
                if(tab1[k] == tab2[z]){
                    l++;
                }
                z++;
            }
            k++;
        }
        if(l == (Dlugosc1))
            return 1;
        else return 0;
    }
    }else return 0;//nie sa sobie rozne bo maja rozne dlugosci
}
bool Subset(int tab1[], int tab2[]){//ZLA ODPOWIEDZ
    //zawieranie sie czyli w sumie equel tylko ich dlugosci nie musza byc takien same
    int z = 0;
    for(int k = 0; tab1[k] != (-1); k ++){
        z++;
    }
    int Dlugosc1 = z;
    z = 0;
    for(int k = 0; tab2[k] != (-1); k++){
        z++;
    }
    int Dlugosc2 = z;
    if(Dlugosc1 == 0){
        if(Dlugosc2 == 0){
            return 1;
        }else
        return 1;
    }else if(Dlugosc2 == 0){
        return 0;
    }else{
        //speawdzam czy elementy sa takie same
        int l = 0;
        int k = 0; z = 0;
        while(k < Dlugosc1){
            z = 0;
            while(z < Dlugosc2){
                if(tab1[k] == tab2[z]){
                    l++;
                }
                z++;
            }
            k++;
        }
        if(l == (Dlugosc1))
            return 1;
        else return 0;
        
    }
}
void Properties(int tab1[], char tab[], double &sredniaA, double *sredniaH, int &min,int *max,int &moc){//TO TEZ NIE BEDZIE DZIALAL BO FUNKCJE UZYTE NIE DZIALAJA
    int z = 0;
    while(tab[z] != 0){
        if(tab[z] == 'a'){
            sredniaA = Arithmetic(tab1);
        }
        if(tab[z] == 'h'){
            *sredniaH = Harmonic(tab1);
        }
        if(tab[z] == 'm'){
            MinMax(tab1, &min, *max);
            
        }
        if(tab[z] == 'c'){
            Cardinality(tab1, &moc);
        }
        z++;
    }
}
