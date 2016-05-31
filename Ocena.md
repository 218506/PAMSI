# Lab2 - tablica dynamiczna

Sposób pomiaru czasu nie jest właściwy.
``static_cast <double>(clock()) /CLOCKS_PER_SEC;``
Proszę korzystać z ``gettimeofday()`` http://linux.die.net/man/2/gettimeofday

Sprawozdanie napisane bardzo lakonicznie, praktycznie brak wniosków. + za wykorzystanie LaTeXa.

Ocena: 4

# Lab3 - projektowanie obiektowe

Program poprawnie zaprojektowany obiektowo, wykorzystuje interfejsy.
Brak dyskusji złożoności O(n).
W sprawozdaniu pojawiają się wykresy ale brak na nich krzywych wzorcowych.
Ilustracje łatwiej byłoby odczytać gdyby znalazły się w jednym układzie współrzędnych.

Ocena: 4,5

# Lab4 - ADT, lista / kolejka / stos

Kod programu poprawny, zastosowane interfejsy i zasady projektowania obiektowego.
Uzupełniona dokumentacja kodu.
Sprawozdanie bardzo lakoniczne, brak polskich znaków w sprawozdaniu.

Ocena: 4


# Lab5 - sortowanie

# Lab6 - tablica asocjacyjna

Sprawozdanie urwane, ale to co widzę budzi moją obawę:

złożoność obliczeniowa O(n) dla operacji wstawiania jest podejrzana, bo o ile
odczyt wiąże się z ewentualnym przeszukaniem listy elementów o jednakowej,
wartości funkcji skrótu, o tyle wstawianie jest po prostu dopisaniem elementu do listy,
w związku z tym musi być O(1).

Ocena: 3,5

# Lab7 - drzewa

Sprawozdanie pokazuje dane i wykres dla zapisu. Bardziej interesuje nas odczyt,
który w sprawozdaniu jest prawie pominięty. Fakt, że otrzymane w trakcie eksperymentów
czasy wyszukiwania były bliskie 0 oznacza najprawdopodboniej zbyt niską dokładność
zegara lub zbyt mały zbiór danych.

Dodatkowo nie zostało zaimplementowane drzewo czerwono-czarne tylko DSW.

Ocena: 3,5

# Lab8 - grafy (dfs,bfs)

Sprawozdanie po raz kolejny napisane niestarannie. Roi się w nim od literówek,
wnioski są przeklejone ze sprawozdania z wcześniejszych laboratoriów.
Sam kod i wyniki - OK.

Ocena: 4,5

# Lab9 - grafy (b&b)

brak zadania
Ocena: 2

# Lab10

Prezentacja: 4,5
Projekt: 5
