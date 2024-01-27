// Wiktoria Nierobot

#include <iostream>
using namespace std;

int main()
{
    char A = 'a', B = 'b', C = 'c', D = 'd', E = 'e', G1, G2;
    float PrzegranaG1 = 0, PrzegranaG2 = 0, WygranaG1 = 0, WygranaG2 = 0, RemisG1 = 0, RemisG2 = 0;
    float PrzegranaA = 0, WygranaA = 0, RemisA = 0;
    float PrzegranaB = 0, WygranaB = 0, RemisB = 0;
    float PrzegranaC = 0, WygranaC = 0, RemisC = 0;
    float PrzegranaD = 0, WygranaD = 0, RemisD = 0;
    float PrzegranaE = 0, WygranaE = 0, RemisE = 0;
    float PierwszyRzutG1 = 0, DrugiRzutG1 = 0, TrzeciRzutG1 = 0, CzwartyRzutG1 = 0, PierwszyRzutG2 = 0, DrugiRzutG2 = 0, TrzeciRzutG2 = 0, CzwartyRzutG2 = 0;

    float WynikG1 = 0, WynikG2 = 0;
    float IloscRozgrywek;
    cin >> IloscRozgrywek;

    while (IloscRozgrywek > 0)
    {

        // Wyzerowanie wartosci dla G1 i G2

        PrzegranaG1 = 0;
        PrzegranaG2 = 0;
        WygranaG1 = 0;
        WygranaG2 = 0;
        RemisG1 = 0;
        RemisG2 = 0;
        // input

        cin >> G1 >> PierwszyRzutG1 >> DrugiRzutG1 >> TrzeciRzutG1 >> CzwartyRzutG1;
        cin >> G2 >> PierwszyRzutG2 >> DrugiRzutG2 >> TrzeciRzutG2 >> CzwartyRzutG2;

        // 4 jendakowe  TO JEST OKI
        if (PierwszyRzutG1 == DrugiRzutG1 && DrugiRzutG1 == TrzeciRzutG1 && TrzeciRzutG1 == CzwartyRzutG1) // jesli pierwsz gracz wyrzcuil czworke
        {
            if (PierwszyRzutG2 == DrugiRzutG2 && DrugiRzutG2 == TrzeciRzutG2 && TrzeciRzutG2 == CzwartyRzutG2) // jesli drugi tez wyrzucil czworke
            {
                WynikG1 = PierwszyRzutG1 + DrugiRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                WynikG2 = PierwszyRzutG2 + DrugiRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;
                // porownuje wynik sumaryczny rzutow
                if (WynikG1 > WynikG2) // jesli pierwszy gracz mial wiecej
                {
                    WygranaG1 = WygranaG1 + 1;
                    PrzegranaG2 = PrzegranaG2 + 1;
                }
                else if (WynikG1 < WynikG2) // jesli drugi gracz mial wiecej
                {
                    WygranaG2 = WygranaG2 + 1;
                    PrzegranaG1 = PrzegranaG1 + 1;
                }
                else // jesli byl remis
                {
                    RemisG1 = RemisG1 + 1;
                    RemisG2 = RemisG2 + 1;
                }
            }
            else // jesli drugi gracz nie wyrzucil czworki
            {
                WygranaG1 = WygranaG1 + 1;
                PrzegranaG2 = PrzegranaG2 + 1;
            }
        } // koniec 4 jednakowe G1
        // 4 jednakowe G2
        else if (PierwszyRzutG2 == DrugiRzutG2 && DrugiRzutG2 == TrzeciRzutG2 && TrzeciRzutG2 == CzwartyRzutG2) // jesi pierwszy nie wyrzucil czworki, a drugi juz tak
        {
            WygranaG2 = WygranaG2 + 1;
            PrzegranaG1 = PrzegranaG1 + 1;
        }
        // koniec 4 jednakowe
        /*cztery rozne TO JEST OKI*/
        else if (PierwszyRzutG1 != DrugiRzutG1 && PierwszyRzutG1 != TrzeciRzutG1 && PierwszyRzutG1 != CzwartyRzutG1 && DrugiRzutG1 != TrzeciRzutG1 && DrugiRzutG1 != CzwartyRzutG1 && TrzeciRzutG1 != CzwartyRzutG1) // jesli pierwszy gracz ma cztery rozne
        {
            if (PierwszyRzutG2 != DrugiRzutG2 && PierwszyRzutG2 != TrzeciRzutG2 && PierwszyRzutG2 != CzwartyRzutG2 && DrugiRzutG2 != TrzeciRzutG2 && DrugiRzutG2 != CzwartyRzutG2 && TrzeciRzutG2 != CzwartyRzutG2) // jesli drugi gracz tez ma rozne
            {
                RemisG1 = RemisG1 + 1;
                RemisG2 = RemisG2 + 1;
            }
            else
            { // jesli tylko gracz pierwszy ma rozne
                WygranaG1 = WygranaG1 + 1;
                PrzegranaG2 = PrzegranaG2 + 1;
            }
        }
        // koniec 4 rozne G1
        // 4 rozne G2
        else if (PierwszyRzutG2 != DrugiRzutG2 && PierwszyRzutG2 != TrzeciRzutG2 && PierwszyRzutG2 != CzwartyRzutG2 && DrugiRzutG2 != TrzeciRzutG2 && DrugiRzutG2 != CzwartyRzutG2 && TrzeciRzutG2 != CzwartyRzutG2) // jesli tylko gracz drugi ma rozne
        {
            PrzegranaG1 = PrzegranaG1 + 1;
            WygranaG2 = WygranaG2 + 1;
        }
        //koniec 4 rozne
        /*dwie rozne pary Jest okej*/
        else if ((PierwszyRzutG1 == DrugiRzutG1 && TrzeciRzutG1 == CzwartyRzutG1) || (PierwszyRzutG1 == TrzeciRzutG1 && DrugiRzutG1 == CzwartyRzutG1) || (PierwszyRzutG1 == CzwartyRzutG1 && DrugiRzutG1 == TrzeciRzutG1)) // jesli pierwszy gracz ma dwie rozne pary, nie trzeba sprawdzac ze sa rozne bo to by bylo w pierwszym ifie
        {
            // tu wchodzi
            if ((PierwszyRzutG2 == DrugiRzutG2 && TrzeciRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2 && DrugiRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == CzwartyRzutG2 && DrugiRzutG2 == TrzeciRzutG2))
            {
                // tu tez
                // sprawdzam ktore dwojki byly wieksze i na tej podstawie sprawdzam wynik
                if (PierwszyRzutG1 == DrugiRzutG1 && TrzeciRzutG1 == CzwartyRzutG1)
                {
                    if ((PierwszyRzutG1 + DrugiRzutG1) > (TrzeciRzutG1 + CzwartyRzutG1))
                        WynikG1 = PierwszyRzutG1 + DrugiRzutG1;
                    else
                        WynikG1 = TrzeciRzutG1 + CzwartyRzutG1;
                }
                else if (PierwszyRzutG1 == TrzeciRzutG1 & DrugiRzutG1 == CzwartyRzutG1)
                {
                    if ((PierwszyRzutG1 + TrzeciRzutG1) > (DrugiRzutG1 + CzwartyRzutG1))
                        WynikG1 = PierwszyRzutG1 + TrzeciRzutG1;
                    else
                        WynikG1 = DrugiRzutG1 + CzwartyRzutG1;
                }
                else if (PierwszyRzutG1 == CzwartyRzutG1 && DrugiRzutG1 == TrzeciRzutG1)
                {
                    if ((PierwszyRzutG1 + CzwartyRzutG1) > (DrugiRzutG1 + TrzeciRzutG1))
                        WynikG1 = PierwszyRzutG1 + CzwartyRzutG1;
                    else
                        WynikG1 = DrugiRzutG1 + TrzeciRzutG1;
                }

                // to samo dla drugiego gracza

                if (PierwszyRzutG2 == DrugiRzutG2 && TrzeciRzutG2 == CzwartyRzutG2)
                {
                    if ((PierwszyRzutG2 + DrugiRzutG2) > (TrzeciRzutG2 + CzwartyRzutG2))
                        WynikG2 = PierwszyRzutG2 + DrugiRzutG2;
                    else
                        WynikG2 = TrzeciRzutG2 + CzwartyRzutG2;
                }
                else if (PierwszyRzutG2 == TrzeciRzutG2 & DrugiRzutG2 == CzwartyRzutG2)
                {
                    if ((PierwszyRzutG2 + TrzeciRzutG2) > (DrugiRzutG2 + CzwartyRzutG2))
                        WynikG2 = PierwszyRzutG2 + TrzeciRzutG2;
                    else
                        WynikG2 = DrugiRzutG2 + CzwartyRzutG2;
                }
                else if (PierwszyRzutG2 == CzwartyRzutG2 && DrugiRzutG2 == TrzeciRzutG2)
                {
                    if ((PierwszyRzutG2 + CzwartyRzutG2) > (DrugiRzutG2 + TrzeciRzutG2))
                        WynikG2 = PierwszyRzutG2 + CzwartyRzutG2;
                    else
                        WynikG2 = DrugiRzutG2 + TrzeciRzutG2;
                }

                // porownuje wyniki

                if (WynikG1 > WynikG2)
                { // to działa
                    WygranaG1 = WygranaG1 + 1;
                    PrzegranaG2 = PrzegranaG2 + 1;
                }
                else if (WynikG1 < WynikG2)
                { // tu tez
                    WygranaG2 = WygranaG2 + 1;
                    PrzegranaG1 = PrzegranaG1 + 1;
                }
                else // tu tez dziala
                {
                    // w sytuacji remisu od nowa obliczam wynik uwzgledniajac czwarty rzut ktory nie byly w parach
                    WynikG1 = WynikG2 = 0;
                    WynikG1 = PierwszyRzutG1 + DrugiRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                    WynikG2 = PierwszyRzutG2 + DrugiRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;

                    if (WynikG1 > WynikG2)
                    {
                        WygranaG1 = WygranaG1 + 1;
                        PrzegranaG2 = PrzegranaG2 + 1;
                    }
                    else if (WynikG1 < WynikG2)
                    {
                        WygranaG2 = WygranaG2 + 1;
                        PrzegranaG1 = PrzegranaG1 + 1;
                    }
                    else
                    {
                        RemisG1 = RemisG1 + 1;
                        RemisG2 = RemisG2 + 1;
                    }
                }
            }
        }
        // koniec 2 pary G1
        else if ((PierwszyRzutG2 == DrugiRzutG2 && TrzeciRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2 && DrugiRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == CzwartyRzutG2 && DrugiRzutG2 == TrzeciRzutG2)) // jesli tylko drugi gracz mial dwie rozne dwojki
        {
            WygranaG2 = WygranaG2 + 1;
            PrzegranaG1 = PrzegranaG1 + 1;
        }
        /*dokladnie trzy; jednakowe wyniki; CHYBA DZIALA*/
        // mozna uproscic i nie sprawdzac nierownosci
        else if ((PierwszyRzutG1 == DrugiRzutG1 && PierwszyRzutG1 == TrzeciRzutG1) || (DrugiRzutG1 == TrzeciRzutG1 & DrugiRzutG1 == CzwartyRzutG1) || (PierwszyRzutG1 == TrzeciRzutG1 && PierwszyRzutG1 == CzwartyRzutG1) || (DrugiRzutG1 == PierwszyRzutG1 & DrugiRzutG1 == CzwartyRzutG1)) // jesli pierwszy ma trojke
        {
            // tu wchodzi

            if ((PierwszyRzutG2 == DrugiRzutG2 && PierwszyRzutG2 == TrzeciRzutG2) || (DrugiRzutG2 == TrzeciRzutG2 & DrugiRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2 && PierwszyRzutG2 == CzwartyRzutG2) || (DrugiRzutG2 == PierwszyRzutG2 & DrugiRzutG2 == CzwartyRzutG2)) // gracz 2 tez mial trojke
            {
                // tu wchodzi
                // mam sytuacje remisu wiec zliczam wyniki gracza 1 i 2
                // wynik dla gracza pierwszego
                if (PierwszyRzutG1 == DrugiRzutG1 && PierwszyRzutG1 == TrzeciRzutG1)
                {
                    WynikG1 = PierwszyRzutG1 + DrugiRzutG1 + TrzeciRzutG1;
                }
                else if (DrugiRzutG1 == TrzeciRzutG1 && DrugiRzutG1 == CzwartyRzutG1)
                {
                    WynikG1 = DrugiRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                }
                else if (PierwszyRzutG1 == TrzeciRzutG1 && PierwszyRzutG1 == CzwartyRzutG1)
                {
                    WynikG1 = PierwszyRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                }
                else if (DrugiRzutG1 == PierwszyRzutG1 && CzwartyRzutG1 == PierwszyRzutG1)
                {
                    WynikG1 = DrugiRzutG1 + PierwszyRzutG1 + CzwartyRzutG1;
                }

                // wynik dla gracza 2
                if (PierwszyRzutG2 == DrugiRzutG2 && PierwszyRzutG2 == TrzeciRzutG2)
                {
                    WynikG2 = PierwszyRzutG2 + DrugiRzutG2 + TrzeciRzutG2;
                }
                else if (DrugiRzutG2 == TrzeciRzutG2 && DrugiRzutG2 == CzwartyRzutG2)
                {
                    WynikG2 = DrugiRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;
                }
                else if (PierwszyRzutG2 == TrzeciRzutG2 && PierwszyRzutG2 == CzwartyRzutG2)
                {
                    WynikG2 = PierwszyRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;
                }
                else if (DrugiRzutG2 == PierwszyRzutG2 && CzwartyRzutG2 == PierwszyRzutG2)
                {
                    WynikG2 = DrugiRzutG2 + PierwszyRzutG2 + CzwartyRzutG2;
                }
                // teraz porownuje wyniki gracza 1 i 2 i oceniam kto wygral

                if (WynikG1 > WynikG2)
                {
                    // tu jest okej
                    WygranaG1 = WygranaG1 + 1;
                    PrzegranaG2 = PrzegranaG2 + 1;
                }
                else if (WynikG1 < WynikG2)
                {
                    // tu jest okej
                    WygranaG2 = WygranaG2 + 1;
                    PrzegranaG1 = PrzegranaG1 + 1;
                }
                else if (WynikG1 == WynikG2)
                {
                    // tu tez jest w teorii okej

                    // w sytuacji remisu od nowa obliczam wynik uwzgledniajac czwarty rzut ktory nie byly w parach
                    WynikG1 = WynikG2 = 0;
                    WynikG1 = PierwszyRzutG1 + DrugiRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                    WynikG2 = PierwszyRzutG2 + DrugiRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;

                    if (WynikG1 > WynikG2)
                    {
                        WygranaG1 = WygranaG1 + 1;
                        PrzegranaG2 = PrzegranaG2 + 1;
                    }
                    else if (WynikG1 < WynikG2)
                    {
                        WygranaG2 = WygranaG2 + 1;
                        PrzegranaG1 = PrzegranaG1 + 1;
                    }
                    else
                    {
                        RemisG1 = RemisG1 + 1;
                        RemisG2 = RemisG2 + 1;
                    }
                }
            }
            else
            { // sytuacja kiedy tylko gracz 1 miał trojke
                WygranaG1 = WygranaG1 + 1;
                PrzegranaG2 = PrzegranaG2 + 1;
            }
        }
        // koniec trojka G1
        else if ((PierwszyRzutG2 == DrugiRzutG2 && PierwszyRzutG2 == TrzeciRzutG2) || (DrugiRzutG2 == TrzeciRzutG2 & DrugiRzutG2 == CzwartyRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2 && PierwszyRzutG2 == CzwartyRzutG2) || (DrugiRzutG2 == PierwszyRzutG2 & DrugiRzutG2 == CzwartyRzutG2)) // sytacja kiedy tylko gracz drugi mial trojke
        {

            WygranaG2 = WygranaG2 + 1;
            PrzegranaG1 = PrzegranaG1 + 1;
        }
        // koniec trojka
        /*jedna dwojka NIE DZIALA*/
        else if ((PierwszyRzutG1 == DrugiRzutG1) || (PierwszyRzutG1 == TrzeciRzutG1) || (PierwszyRzutG1 == CzwartyRzutG1) || (DrugiRzutG1 == TrzeciRzutG1) || (DrugiRzutG1 == CzwartyRzutG1) || (TrzeciRzutG1 == CzwartyRzutG1))
        {

            if ((PierwszyRzutG2 == DrugiRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2) || (PierwszyRzutG2 == CzwartyRzutG2) || (DrugiRzutG2 == TrzeciRzutG2) || (DrugiRzutG2 == CzwartyRzutG2) || (TrzeciRzutG2 == CzwartyRzutG2))
            {
                // sytuacja remisu wiec musze obliczyc wyniki i je porownac
                if (PierwszyRzutG1 == DrugiRzutG1)
                {
                    WynikG1 = PierwszyRzutG1 + DrugiRzutG1;
                }
                else if (PierwszyRzutG1 == TrzeciRzutG1)
                {
                    WynikG1 = PierwszyRzutG1 + TrzeciRzutG1;
                }
                else if (PierwszyRzutG1 == CzwartyRzutG1)
                {
                    WynikG1 = PierwszyRzutG1 + CzwartyRzutG1;
                }
                else if (DrugiRzutG1 == TrzeciRzutG1)
                {
                    WynikG1 = DrugiRzutG1 + TrzeciRzutG1;
                }
                else if (DrugiRzutG1 == CzwartyRzutG1)
                {
                    WynikG1 = DrugiRzutG1 + CzwartyRzutG1;
                }
                else if (TrzeciRzutG1 == CzwartyRzutG1)
                {
                    WynikG1 = TrzeciRzutG1 + CzwartyRzutG1;
                }

                if (PierwszyRzutG2 == DrugiRzutG2)
                {
                    WynikG2 = PierwszyRzutG2 + DrugiRzutG2;
                }
                else if (PierwszyRzutG2 == TrzeciRzutG2)
                {
                    WynikG2 = PierwszyRzutG2 + TrzeciRzutG2;
                }
                else if (PierwszyRzutG2 == CzwartyRzutG2)
                {
                    WynikG2 = PierwszyRzutG2 + CzwartyRzutG2;
                }
                else if (DrugiRzutG2 == TrzeciRzutG2)
                {
                    WynikG2 = DrugiRzutG2 + TrzeciRzutG2;
                }
                else if (DrugiRzutG2 == CzwartyRzutG2)
                {
                    WynikG2 = DrugiRzutG2 + CzwartyRzutG2;
                }
                else if (TrzeciRzutG2 == CzwartyRzutG2)
                {
                    WynikG2 = TrzeciRzutG2 + CzwartyRzutG2;
                }

                // porownuje teraz wyniki

                if (WynikG1 > WynikG2)
                {
                    WygranaG1 = WygranaG1 + 1;
                    PrzegranaG2 = PrzegranaG2 + 1;
                }
                else if (WynikG1 < WynikG2)
                {
                    PrzegranaG1 = PrzegranaG1 + 1;
                    WygranaG2 = WygranaG2 + 1;
                }
                else if (WynikG1 == WynikG2)
                {
                    // sytuacja remisu porownuje teraz wszytskie wyniki
                    WynikG1 = WynikG2 = 0;
                    WynikG1 = PierwszyRzutG1 + DrugiRzutG1 + TrzeciRzutG1 + CzwartyRzutG1;
                    WynikG2 = PierwszyRzutG2 + DrugiRzutG2 + TrzeciRzutG2 + CzwartyRzutG2;

                    if (WynikG1 > WynikG2)
                    {
                        WygranaG1 = WygranaG1 + 1;
                        PrzegranaG2 = PrzegranaG2 + 1;
                    }
                    else if (WynikG1 < WynikG2)
                    {
                        WygranaG2 = WygranaG2 + 1;
                        PrzegranaG1 = PrzegranaG1 + 1;
                    }
                    else if (WynikG1 == WynikG2)
                    {
                        RemisG1 = RemisG1 + 1;
                        RemisG2 = RemisG2 + 1;
                    }
                }
            }
            else
            {

                WygranaG1 = WygranaG1 + 1;
                PrzegranaG2 = PrzegranaG2 + 1;
            }
        }
        // koniec 1 para G1
        else if ((PierwszyRzutG2 == DrugiRzutG2 && DrugiRzutG2 != TrzeciRzutG2 && DrugiRzutG2 != CzwartyRzutG2) || (PierwszyRzutG2 == TrzeciRzutG2 && PierwszyRzutG2 != DrugiRzutG2 && PierwszyRzutG2 != CzwartyRzutG2) || (PierwszyRzutG2 == CzwartyRzutG2 && PierwszyRzutG2 != TrzeciRzutG2 && PierwszyRzutG2 != DrugiRzutG2) || (DrugiRzutG2 == TrzeciRzutG2 && DrugiRzutG2 != PierwszyRzutG2 && DrugiRzutG2 != CzwartyRzutG2) || (DrugiRzutG2 == CzwartyRzutG2 && DrugiRzutG2 != PierwszyRzutG2 && DrugiRzutG2 != TrzeciRzutG2) || (TrzeciRzutG2 == CzwartyRzutG2 && TrzeciRzutG2 != PierwszyRzutG2 && TrzeciRzutG2 != DrugiRzutG2))
        {

            WygranaG2 = WygranaG2 + 1;
            PrzegranaG1 = PrzegranaG1 + 1;
        }
        // koniec 1 para

        if (G1 == A)
        {
            WygranaA = WygranaA + WygranaG1;
            PrzegranaA = PrzegranaA + PrzegranaG1;
            RemisA = RemisA + RemisG1;
        }
        if (G1 == B)
        {
            WygranaB = WygranaB + WygranaG1;
            PrzegranaB = PrzegranaB + PrzegranaG1;
            RemisB = RemisB + RemisG1;
        }
        if (G1 == C)
        {
            WygranaC = WygranaC + WygranaG1;
            PrzegranaC = PrzegranaC + PrzegranaG1;
            RemisC = RemisC + RemisG1;
        }
        if (G1 == D)
        {
            WygranaD = WygranaD + WygranaG1;
            PrzegranaD = PrzegranaD + PrzegranaG1;
            RemisD = RemisD + RemisG1;
        }
        if (G1 == E)
        {
            WygranaE = WygranaE + WygranaG1;
            PrzegranaE = PrzegranaE + PrzegranaG1;
            RemisE = RemisE + RemisG1;
        }
        if (G2 == A)
        {
            WygranaA = WygranaA + WygranaG2;
            PrzegranaA = PrzegranaA + PrzegranaG2;
            RemisA = RemisA + RemisG2;
        }
        if (G2 == B)
        {
            WygranaB = WygranaB + WygranaG2;
            PrzegranaB = PrzegranaB + PrzegranaG2;
            RemisB = RemisB + RemisG2;
        }
        if (G2 == C)
        {
            WygranaC = WygranaC + WygranaG2;
            PrzegranaC = PrzegranaC + PrzegranaG2;
            RemisC = RemisC + RemisG2;
        }
        if (G2 == D)
        {
            WygranaD = WygranaD + WygranaG2;
            PrzegranaD = PrzegranaD + PrzegranaG2;
            RemisD = RemisD + RemisG2;
        }
        if (G2 == E)
        {
            WygranaE = WygranaE + WygranaG2;
            PrzegranaE = PrzegranaE + PrzegranaG2;
            RemisE = RemisE + RemisG2;
        }

        IloscRozgrywek = IloscRozgrywek - 1;
    }

    // wypisywanie statystyk dla gracza B jesli wzial udzial w rozgrywce
    if (WygranaA != 0 || PrzegranaA != 0 || RemisA != 0)
    {

        cout << "gracz " << A << endl;
        if (WygranaA != 0)
        {
            cout << "    "
                 << "wygrane: " << ((WygranaA / (PrzegranaA + WygranaA + RemisA)) * 100) << "%" << endl;
        }
        if (RemisA != 0)
        {
            cout << "    "
                 << "remisy: " << ((RemisA / (PrzegranaA + WygranaA + RemisA)) * 100) << "%" << endl;
        }
        if (PrzegranaA != 0)
        {
            cout << "    "
                 << "przegrane: " << ((PrzegranaA / (PrzegranaA + WygranaA + RemisA)) * 100) << "%" << endl;
        }
        if (WygranaB != 0 || PrzegranaB != 0 || RemisB != 0 || WygranaC != 0 || PrzegranaC != 0 || RemisC != 0 || WygranaD != 0 || PrzegranaD != 0 || RemisD != 0 || WygranaE != 0 || PrzegranaE != 0 || RemisE != 0)
        {
            cout << endl;
        }
    }

    if (WygranaB != 0 || PrzegranaB != 0 || RemisB != 0)
    {

        cout << "gracz " << B << endl;
        if (WygranaB != 0)
        {
            cout << "    "
                 << "wygrane: " << ((WygranaB / (PrzegranaB + WygranaB + RemisB)) * 100) << "%" << endl;
        }
        if (RemisB != 0)
        {
            cout << "    "
                 << "remisy: " << ((RemisB / (PrzegranaB + WygranaB + RemisB)) * 100) << "%" << endl;
        }
        if (PrzegranaB != 0)
        {
            cout << "    "
                 << "przegrane: " << ((PrzegranaB / (PrzegranaB + WygranaB + RemisB)) * 100) << "%" << endl;
        }
        if (WygranaC != 0 || PrzegranaC != 0 || RemisC != 0 || WygranaD != 0 || PrzegranaD != 0 || RemisD != 0 || WygranaE != 0 || PrzegranaE != 0 || RemisE != 0)
        {
            cout << endl;
        }
    }

    // wypisywanie statystyk G2la gracza G2 jesli wzial uG2zial w rozgrtywce
    if (WygranaC != 0 || PrzegranaC != 0 || RemisC != 0)
    {

        cout << "gracz " << C << endl;
        if (WygranaC != 0)
        {
            cout << "    "
                 << "wygrane: " << ((WygranaC / (PrzegranaC + WygranaC + RemisC)) * 100) << "%" << endl;
        }
        if (RemisC != 0)
        {
            cout << "    "
                 << "remisy: " << ((RemisC / (PrzegranaC + WygranaC + RemisC)) * 100) << "%" << endl;
        }
        if (PrzegranaC != 0)
        {
            cout << "    "
                 << "przegrane: " << ((PrzegranaC / (PrzegranaC + WygranaC + RemisC)) * 100) << "%" << endl;
            if (WygranaD != 0 || PrzegranaD != 0 || RemisD != 0 || WygranaE != 0 || PrzegranaE != 0 || RemisE != 0)
            {
                cout << endl;
            }
        }
    }
    // wypisywanie statystyk G2la gracza G2 jesli wzial uG2zial w rozgrtywce
    if (WygranaD != 0 || PrzegranaD != 0 || RemisD != 0)
    {

        cout << "gracz " << D << endl;
        if (WygranaD != 0)
        {
            cout << "    "
                 << "wygrane: " << ((WygranaD / (PrzegranaD + WygranaD + RemisD)) * 100) << "%" << endl;
        }
        if (RemisD != 0)
        {
            cout << "    "
                 << "remisy: " << ((RemisD / (PrzegranaD + WygranaD + RemisD)) * 100) << "%" << endl;
        }
        if (PrzegranaD != 0)
        {
            cout << "    "
                 << "przegrane: " << ((PrzegranaD / (PrzegranaD + WygranaD + RemisD)) * 100) << "%" << endl;
        }
        if (WygranaE != 0 || PrzegranaE != 0 || RemisE != 0)
        {
            cout << endl;
        }
    }
    if (WygranaE != 0 || PrzegranaE != 0 || RemisE != 0)
    {

        cout << "gracz " << E << endl;
        if (WygranaE != 0)
        {
            cout << "    "
                 << "wygrane: " << ((WygranaE / (PrzegranaE + WygranaE + RemisE)) * 100) << "%" << endl;
        }
        if (RemisE != 0)
        {
            cout << "    "
                 << "remisy: " << ((RemisE / (PrzegranaE + WygranaE + RemisE)) * 100) << "%" << endl;
        }
        if (PrzegranaE != 0)
        {
            cout << "    "
                 << "przegrane: " << ((PrzegranaE / (PrzegranaE + WygranaE + RemisE)) * 100) << "%" << endl;
        }
    }
}
