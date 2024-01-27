// Wiktoria Nierobot
#include <iostream>
using namespace std;

int DlugoscSzescianuDanych; // l pion, p panel, v poziom


bool CzyJestWCzworoscianie(int l, int v, int p, int i, int j, int k, int e){
    int PolowaDlugosciSzescianu = DlugoscSzescianuDanych / 2;
    int Pp = p - i;
    int Pl = l - j;
    int Pv = k - v;
    if(Pp < 0){
        Pp = Pp * (-1);
    }
    if(Pl < 0){
        Pl = Pl * (-1);
    }
    if(Pv < 0){
        Pv = Pv * (-1);
    }
    if(Pp + Pl + Pv <= e){
        if (p < PolowaDlugosciSzescianu)
        { // 5, 8, 1, 4//panele
            if (l < PolowaDlugosciSzescianu)
            {                                    // 5 8//pion
                if (v < PolowaDlugosciSzescianu) // 5//poziom
                {
                    if (i >= p && j >= l && k >= v)
                        return 1;
                }
                else
                { // 8
                    if (i >= p && j >= l && k <= v)
                        return 1;
                }
            }
            else
            { // 1 4
                if (v < PolowaDlugosciSzescianu)
                { // 1//poziom
                    if (i >= p && j <= l && k >= v)
                        return 1;
                }
                else
                { // 4
                    if (i >= p && j <= l && k <= v)
                        return 1;
                }
            }
        }
        else
        { // 2, 3, 6, 7
            if (l < PolowaDlugosciSzescianu)
            { // 6 i 7
                if (v < PolowaDlugosciSzescianu)
                { // 6
                    if (i <= p && j >= l && k >= v)
                        return 1;
                }
                else
                { // 7
                    if (i <= p && j >= l && k <= v)
                        return 1;
                }
            }
            else
            {
                if (v < PolowaDlugosciSzescianu)
                { // 2
                    if (i <= p && j <= l && k >= v)
                        return 1;
                }
                else
                { // 3
                    if (i <= p && j <= l && k <= v)
                        return 1;
                }
            }
        }
    }
    return 0;
}
bool CzyJestWProstopadloscianie(int l, int v, int p, int dlugosc, int szerokosc, int glebokosc, int i, int k, int j)
{ // TO JUZ DZIALA

    // sprawdzam teraz kolejno wspolrzedne pionu, poziomu, panelu
    int PolowaDlugosciSzescianu = DlugoscSzescianuDanych / 2;
    if (p < PolowaDlugosciSzescianu)
    { // 5, 8, 1, 4//panele
        if (l < PolowaDlugosciSzescianu)
        {                                    // 5 8//pion
            if (v < PolowaDlugosciSzescianu) // 5//poziom
            {
                if (i >= p && i <= (p + glebokosc) && j >= l && j <= (l + dlugosc) && k >= v && k <= (v + szerokosc))
                    return 1;
            }
            else
            { // 8
                if (i >= p && i <= (p + glebokosc) && j >= l && j <= (l + dlugosc) && k <= v && k >= (v - szerokosc))
                    return 1;
            }
        }
        else
        { // 1 4
            if (v < PolowaDlugosciSzescianu)
            { // 1//poziom
                if (i >= p && i <= (p + glebokosc) && j <= l && j >= (l - dlugosc) && k >= v && k <= (v + szerokosc))
                    return 1;
            }
            else
            { // 4
                if (i >= p && i <= (p + glebokosc) && j <= l && j >= (l - dlugosc) && k <= v && k >= (v - szerokosc))
                    return 1;
            }
        }
    }
    else
    { // 2, 3, 6, 7
        if (l < PolowaDlugosciSzescianu)
        { // 6 i 7
            if (v < PolowaDlugosciSzescianu)
            { // 6
                if (i <= p && i >= (p - glebokosc) && j >= l && j <= (l + dlugosc) && k >= v && k <= (v + szerokosc))
                    return 1;
            }
            else
            { // 7
                if (i <= p && i >= (p - glebokosc) && j >= l && j <= (l + dlugosc) && k <= v && k >= (v - szerokosc))
                    return 1;
            }
        }
        else
        {
            if (v < PolowaDlugosciSzescianu)
            { // 2
                if (i <= p && i >= (p - glebokosc) && j <= l && j >= (l - dlugosc) && k >= v && k <= (v + szerokosc))
                    return 1;
            }
            else
            { // 3
                if (i <= p && i >= (p - glebokosc) && j <= l && j >= (l - dlugosc) && k <= v && k >= (v - szerokosc))
                    return 1;
            }
        }
    }
    return 0;
}

bool CzyJestWOktalu(int l, int v, int p, int r, int i, int j, int k)
{
    // warunek do wszytskich z odlegloscia r*r <= ((v - k)*(v - k) + (l - j)*(l - j) + (p - i)*(p - i))
    int PolowaDlugosciSzescianu = DlugoscSzescianuDanych / 2;
    if (p < PolowaDlugosciSzescianu)
    { // 5, 8, 1, 4//panele
        if (l < PolowaDlugosciSzescianu)
        {                                    // 5 8//pion
            if (v < PolowaDlugosciSzescianu) // 5//poziom
            {
                if (i >= p && j >= l && k >= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
            else
            { // 8
                if (i >= p && j >= l && k <= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
        }
        else
        { // 1 4
            if (v < PolowaDlugosciSzescianu)
            { // 1//poziom
                if (i >= p && j <= l && k >= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
            else
            { // 4
                if (i >= p && j <= l && k <= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
        }
    }
    else
    { // 2, 3, 6, 7
        if (l < PolowaDlugosciSzescianu)
        { // 6 i 7
            if (v < PolowaDlugosciSzescianu)
            { // 6
                if (i <= p && j >= l && k >= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
            else
            { // 7
                if (i <= p && j >= l && k <= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
        }
        else
        {
            if (v < PolowaDlugosciSzescianu)
            { // 2
                if (i <= p && j <= l && k >= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
            else
            { // 3
                if (i <= p && j <= l && k <= v && r * r >= ((v - k) * (v - k) + (l - j) * (l - j) + (p - i) * (p - i)))
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{

    cin >> DlugoscSzescianuDanych;
    int SzescianDanych[DlugoscSzescianuDanych][DlugoscSzescianuDanych][DlugoscSzescianuDanych];
    // wczytuje tearaz szescian danych
    // panel poziom pion
    int WspolrzednaPoziom = 0;
    int WspolrzednaPion = 0;
    int WspolrzednaPanel;

    // wpisuje dane za pomoca petli for
    for (WspolrzednaPanel = 0; WspolrzednaPanel < DlugoscSzescianuDanych; WspolrzednaPanel++)
    {
        for (WspolrzednaPion = 0; WspolrzednaPion < DlugoscSzescianuDanych; WspolrzednaPion++)
        {
            for (WspolrzednaPoziom = 0; WspolrzednaPoziom < DlugoscSzescianuDanych; WspolrzednaPoziom++)
            {
                cin >> SzescianDanych[WspolrzednaPoziom][WspolrzednaPion][WspolrzednaPanel];
            }
        }
    }
    // pobiera mi trzei input czyli operacje
    char ZnakOperacji, k;
    int h, w, d, e, r, i, l, v, p; // operacje do figur
    cin >> ZnakOperacji;           // pobiera mi znak operacji pierwszy raz i wchodzi do petli jesli od razu nie dalam E
    while (ZnakOperacji != 'E')
    { // powtarza mi petle dopoki znak nie bedzie E
        if (ZnakOperacji == 'C')
        {                                      // kostka
            cin >> l >> v >> p >> h >> w >> d; // l - wsp.poziomu v - wsp.pionu p - wsp. panel h - wysokosc w - szerokosc d - glebokosc
            int suma = 0;
            for (int i = 0; i < DlugoscSzescianuDanych; i++)
            { // panel
                for (int j = 0; j < DlugoscSzescianuDanych; j++)
                { // pion
                    for (int k = 0; k < DlugoscSzescianuDanych; k++)
                    { // poziom
                        if (CzyJestWProstopadloscianie(l, v, p, h, w, d, i, k, j) == 1)
                        {
                            suma += SzescianDanych[k][j][i];
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        else if (ZnakOperacji == 'T')//petle musze poprawic
        {                            // Czworoscian
            cin >> l >> v >> p >> e; // l - wsp. poziomu v - wsp.pionu p wsp.panelu e - dlugosc prostopadlych krwawedzi czworoscianu
            int suma = 0;
            for (int i = 0; i < DlugoscSzescianuDanych; i++)
            { // panel
              
                for (int j = 0; j < DlugoscSzescianuDanych; j++)
                { // pion
                  
                    for (int k = 0; k < DlugoscSzescianuDanych; k++)
                    { // poziom
                       
                        if (CzyJestWCzworoscianie(l, v, p, i, j, k, e) == 1)
                        {
                            suma += SzescianDanych[k][j][i];
                        }
                    }
                }
            }
            cout << suma << endl;
          
        }
        else if (ZnakOperacji == 'O')
        {                            // Oktal
            cin >> l >> v >> p >> r; // l - wsp. poziomu v - wsp.pionu p - wsp. panelu r - promien
            int suma = 0;
            for (int i = 0; i < DlugoscSzescianuDanych; i++)
            { // panel
                for (int j = 0; j < DlugoscSzescianuDanych; j++)
                { // pion
                    for (int k = 0; k < DlugoscSzescianuDanych; k++)
                    { // poziom
                        if (CzyJestWOktalu(l, v, p, r, i, j, k) == 1)
                        {
                            suma += SzescianDanych[k][j][i];
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        else if (ZnakOperacji == 'D')
        { // Wyznacznik
            long long Macierz[DlugoscSzescianuDanych][DlugoscSzescianuDanych];
            cin >> k; // pobieram k i teraz sprawdzam czt bede liczyla wyznaczniuk po panelach pionach czy poziomach
            if (k == 'l')
            {             // biore sobie i - ty pion i z niego licze wyznacznik
                cin >> i; // poziom na panel
                l = i;
                for (int m = 0; m < DlugoscSzescianuDanych; m++)
                { // poziom pion panel w tablicy a w petli panel pion poziom
                    for (int d = 0; d < DlugoscSzescianuDanych; d++)
                    {
                        Macierz[m][d] = SzescianDanych[m][i][d];
                    }
                }
            }
            else if (k == 'v')
            {             // biore sobie i - ty poziom i z niego licze wyznacznik
                cin >> i; // pion na panel
                v = i;

                for (int m = 0; m < DlugoscSzescianuDanych; m++)
                { // poziom pion panel w tablicy a w petli panel pion poziom
                    for (int d = 0; d < DlugoscSzescianuDanych; d++)
                    {
                        Macierz[m][d] = SzescianDanych[i][m][d];
                    }
                }
            }
            else if (k == 'p')
            { // biore sobie i - ty panel i z niego licze wyznacznik
                cin >> i;
                p = i; // poziom na pion
                for (int m = 0; m < DlugoscSzescianuDanych; m++)
                { // poziom pion panel w tablicy a w petli panel pion poziom
                    for (int d = 0; d < DlugoscSzescianuDanych; d++)
                    {
                        Macierz[m][d] = SzescianDanych[m][d][i];
                    }
                    
                }
            }
                
                long long int wyznacznik = 1;
                int s = 1;

                for (int k = 0; k < DlugoscSzescianuDanych - 1 && wyznacznik; k++)
                {
                    if (Macierz[k][k] == 0)
                    {
                        int m = 0;
                        
                        for (m = k + 1; m < DlugoscSzescianuDanych; m++)
                        {
                            if (Macierz[m][k] != 0)
                            {
                                for (int j = 0; j < DlugoscSzescianuDanych; ++j){
                                    
                                    long long temp = Macierz[m][j];
                                    Macierz[m][j] = Macierz[k][j];
                                    Macierz[k][j] = temp;
                                }
                                
                                s = -s;
                                break;
                            }
                        }
                        
                        if (m == DlugoscSzescianuDanych)
                            wyznacznik = 0;
                        
                    }
                    if(wyznacznik){
                        for(int i = k + 1; i < DlugoscSzescianuDanych; i ++){
                            for(int j = k + 1; j < DlugoscSzescianuDanych; j++){
                                Macierz[i][j] = Macierz[k][k] * Macierz[i][j] - Macierz[i][k] * Macierz[k][j];
                                if(k != 0){
                                    Macierz[i][j] /= Macierz[k - 1][k -1];
                                }
                            }
                            
                        }
                    }
                }
                if(wyznacznik){
                    wyznacznik = s * Macierz[DlugoscSzescianuDanych - 1][DlugoscSzescianuDanych - 1];
                }
                cout << wyznacznik << endl;
            }

        
        cin >> ZnakOperacji; // pod koniec petli pobiera mi od nowa znak operacji
    }
}


