# Lab2 - tablica dynamiczna

Sposób pomiaru czasu nie jest właściwy.
``static_cast <double>(clock()) /CLOCKS_PER_SEC;``
Proszę korzystać z ``gettimeofday()`` http://linux.die.net/man/2/gettimeofday

# Lab3 - projektowanie obiektowe

Program poprawnie zaprojektowany obiektowo. Brak dyskusji złożoności O(n).


# Lab4 - ADT, lista / kolejka / stos

Sprawozdanie poprawne, brak polskich znaków w sprawozdaniu.

# Lab5 - sortowanie

# Lab6 - tablica asocjacyjna

Sprawozdanie urwane, ale to co widzę budzi moją obawę:

złożoność obliczeniowa O(n) dla operacji wstawiania jest podejrzana, bo o ile
odczyt wiąże się z ewentualnym przeszukaniem listy elementów o jednakowej
wartości funkcji skrótu, o tyle wstawianie jest po prostu dopisaniem elementu do listy,
w związku z tym musi być O(1).
