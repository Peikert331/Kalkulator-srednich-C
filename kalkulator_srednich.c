#include <stdio.h> /*Biblioteka potrzebna do operacji wejścia i wyjścia*/
#include <stdlib.h> /*Biblioteka potrzebna do utworzenia tablicy o rozmiarze zadeklarowanym przez użytkownika*/
int main(void) /*Funkcja zwraca 0 przy pomyślnym zakończeniu programu, nie przyjmuje żadnych argumentów*/
{
    int n; /*Deklaracja zmiennej, do której zostanie wpisana ilość liczb, które użytkownik chce podać*/
    printf("Ile liczb chcesz podac?\n"); /*Wyświetlenie zapytania użytkownika o ilość liczb, które chce podać*/
    scanf_s("%d", &n); /*Pobranie podanej przez użytkownika liczby i wpisanie jej do zmiennej n*/
    float* liczby = (float*)malloc(n * sizeof(float)); /*Za pomocą funkcji malloc, komputer przydziela odpowiednią ilość pamięci, użytkownik może podać liczby zmiennoprzecinkowe, zatem odpowiednia ilość pamięci to ilość liczb pomnożona przez rozmiar liczb zmiennoprzecinkowych float, czyli n*sizeof(float)*/
    /*Malloc zwraca adres w pamięci, * wskazuje na ten adres ale komputer nie wie co będzie w pamięci przechowywane, więc wskazujemy mu na liczby zmiennoprzecinkowe float*, adres przypisujemy do zmiennej liczby, która jest wskaźnikiem typu float*/
    for(int i = 0; i < n; i++) /*Pętla, która iteruje po indeksach tablicy, aby wpisać do niej liczby podane przez użytkownika*/
    {
        printf("Podaj liczbe %d:\n", i + 1); /*Prośba do użytkownika o podanie kolejnej liczby, d oznacza liczbę całkowitą*/
        scanf("%f", &liczby[i]); /*Pobranie liczby od użytkownika i wpisanie jej na kolejne miejsce w tabeli, f oznacza liczbę zmiennoprzecinkową*/
    }
}