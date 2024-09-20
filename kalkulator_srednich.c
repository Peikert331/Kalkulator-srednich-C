#include <stdio.h> /*Biblioteka potrzebna do operacji wejścia i wyjścia*/
#include <stdlib.h> /*Biblioteka potrzebna do utworzenia tablicy o rozmiarze zadeklarowanym przez użytkownika*/
#include <math.h> /*Biblioteka potrzebna do funkcji pow(), NAN*/
float SredniaArytmetyczna(float*liczby, int n) /*Funkcja licząca średnię arytmetyczną, jako argumenty przyjmuje wskaźnik do tablicy liczb i ilość tych liczb*/
{
    float suma = 0.0; /*Deklaracja zmiennej, do której będą wpisywane kolejne sumy liczb z tablicy*/
    for(int i = 0; i < n; i++) /*Pętla, która iteruje po wszystkich liczbach w tablicy*/
    {
        suma += liczby[i]; /*Do zmiennej suma wpisujemy dodane do siebie kolejne liczby, aby uzyskać ich sumę*/
    }
    return suma / n; /*Funkcja zwraca obliczoną ze wzoru średnię arytmetyczną, dzielimy tutaj sumę liczb z tablicy przez ich ilość*/
}
float SredniaGeometryczna(float*liczby, int n) /*Funkcja licząca średnię geometryczną, jako argumenty przyjmuje wskaźnik do tablicy liczb i ilość tych liczb*/
{
    float iloczyn = 1.0; /*Deklaracja zmiennej, do której będą wpisywane kolejne iloczyny liczb z tablicy*/
    for(int i = 0; i < n; i++) /*Pętla, która iteruje po wszystkich liczbach w tablicy*/
    {
        if(liczby[i] <= 0) /*Instrukcja warunkowa, która sprawdza po kolei wszystkie podane liczby przez użytkownika, czy są mniejsze od zera*/
        {
            printf("Wszystkie liczby musza byc wieksze od zera dla sredniej geometrycznej.\n"); /*Aby obliczyć średnią geometryczną, wszystkie liczby muszą być większe od zera, jeśli tak nie jest, zostanie zwrócowna informacja, że nie można wykonać obliczeń*/
            return -1.0; /*Koniec funkcji, -1.0 jest umowną wartością typu float, która oznacza, że wystąpił błąd*/
        }
        iloczyn *= liczby[i]; /*Do zmiennej iloczyn wpisujemy pomnożone do siebie kolejne liczby, aby uzyskać ich iloczyn*/
    }
    return pow(iloczyn, (1.0 / n)); /*Funkcja zwraca obliczoną ze wzoru średnię geometryczną, pow to funkcja, która potęguje, przyjmuje dwa argumenty, podstawę potęgi oraz wykładnik*/
}
float SredniaHarmoniczna(float*liczby, int n) /*Funkcja licząca średnię harmoniczną, jako argumenty przyjmuje wskaźnik do tablicy liczb i ilość tych liczb*/
{
    float sumaodwrotnosci = 0.0; /*Deklaracja zmiennej, do której będą wpisywane kolejne sumy liczb odwrotnych z tablicy*/
    for(int i = 0; i < n; i++) /*Pętla, która iteruje po wszystkich liczbach w tablicy*/
    {
        if(liczby[i] == 0.0)
        {
            printf("Liczba nie moze byc zerem dla sredniej harmonicznej.\n"); /*Aby obliczyć średnią harmoniczną, wszystkie liczby muszą być różne od zera*/
            return NAN; /*Koniec funkcji, NAN jest nie-liczbowym wynikiem, który oznacza, że wystąpił błąd, liczba -1.0 może być prawidłowym wynikiem funkcji*/
        }
        sumaodwrotnosci += 1.0 / liczby[i]; /*Do zmiennej sumaodwrotnosci wpisujemy dodane do siebie odwrotności kolejnych liczb, aby uzyskać sumę ich odwrotności*/
    }
    return n / sumaodwrotnosci; /*Funkcja zwraca obliczoną ze wzoru średnię harmoniczną, dzielimy ilość liczb przez sumę ich odwrotności*/
}
int main(void) /*Funkcja zwraca 0 przy pomyślnym zakończeniu programu, nie przyjmuje żadnych argumentów*/
{
    int n; /*Deklaracja zmiennej, do której zostanie wpisana ilość liczb, które użytkownik chce podać*/
    do /*Początek pętli do while, która będzie pytać użytkownika o n, dopóki ten nie poda liczby większej od zera*/
    {
        printf("Ile liczb chcesz podac?\n"); /*Wyświetlenie zapytania użytkownika o ilość liczb, które chce podać*/
        scanf_s("%d", &n); /*Pobranie podanej przez użytkownika liczby i wpisanie jej do zmiennej n*/
        if (n <= 0) /*Instrukcja warunkowa, która sprawdza, czy podana liczba jest mniejsza lub równa zero*/
        {
            printf("Liczba nie moze byc mniejsza lub rowna zero. Sprobuj ponownie.\n"); /*Wyświetlenie komunikatu z informacją, że liczba nie może być mniejsza lub równa zero.*/
        }
    } while (n <= 0); /*Warunek while, pętla wykonuje się dopóki n jest mniejsze lub równe zero*/
    float* liczby = (float*)malloc(n * sizeof(float)); /*Za pomocą funkcji malloc, komputer przydziela odpowiednią ilość pamięci, użytkownik może podać liczby zmiennoprzecinkowe, zatem odpowiednia ilość pamięci to ilość liczb pomnożona przez rozmiar liczb zmiennoprzecinkowych float, czyli n*sizeof(float)*/
    /*Malloc zwraca adres w pamięci, * wskazuje na ten adres ale komputer nie wie co będzie w pamięci przechowywane, więc wskazujemy mu na liczby zmiennoprzecinkowe float*, adres przypisujemy do zmiennej liczby, która jest wskaźnikiem typu float*/
    for(int i = 0; i < n; i++) /*Pętla, która iteruje po indeksach tablicy, aby wpisać do niej liczby podane przez użytkownika*/
    {
        printf("Podaj liczbe %d:\n", i + 1); /*Prośba do użytkownika o podanie kolejnej liczby, d oznacza liczbę całkowitą*/
        scanf("%f", &liczby[i]); /*Pobranie liczby od użytkownika i wpisanie jej na kolejne miejsce w tabeli, f oznacza liczbę zmiennoprzecinkową*/
    }
    float arytmetyczna = SredniaArytmetyczna(liczby,n); /*Przypisanie wyniku funkcji do zmiennej arytmetyczna*/
    float geometryczna = SredniaGeometryczna(liczby,n); /*Przypisanie wyniku funkcji do zmiennej geometryczna*/
    float harmoniczna = SredniaHarmoniczna(liczby,n); /*Przypisanie wyniku funkcji do zmiennej harmoniczna*/
    printf("Srednia arytmetyczna: %f\n", arytmetyczna); /*Wyświetlenie wyniku funkcji obliczającej średnią arytmetyczną*/
    if(geometryczna != -1.0) /*Sprawdzenie wartości zwróconej przez funkcję*/
    {
        printf("Srednia geometryczna: %f\n", geometryczna); /*Wyświetlenie wyniku funkcji obliczającej średnią geometryczną, jeśli funkcja nie zwróciła -1*/
    }
    if(!isnan(harmoniczna)) /*Funkcja isnan sprawdza, czy funkcja obliczająca średnią harmoniczną zwróciła NAN, funckja isnan zwraca true lub false*/
    {
        printf("Srednia harmoniczna: %f\n", harmoniczna); /*Jeśli isnan zwraca false, to zwrócony został poprawny wynik funkcji, czyli poprzez zaprzeczenie następuje wejście do pętli i wyświetlenie wyniku funkcji obliczającej średnią harmoniczną*/
    }
    return 0; /*Funkcja int zwraca liczbę całkowitą, a zero oznacza, że program zakończył się poprawnie*/
}