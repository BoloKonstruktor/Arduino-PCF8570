# Arduino-PCF8570
Biblioteka do obsługi szeregowej pamięci RAM  i2c

Szęść Boże!

Klasa zawiera typową obsługę pamięci PCF8570 z wykorzystaniem biblioteki Wire. Jednak na uwagę zasługują metody
"readMemory" i "writeMemory"

Metoda "readMemory" pozwala na odczyt danych z PCF8570 do zmiennej wielobajtowej,
tablicy bajtów jak również struktury. Analogicznie metoda "writeMemory" pozwala
na zapis zmiennej wielobajtowej, tablicy bajtów lub struktury do PCF8570. Metody
te mają identyczne argumenty. Pierwszy "offset" to adres komórki, drugi "data"
to wskaźnik do danych i trzeci "size" to rozmiar danych.

Zwracana wartość przez w/w metody to adres do następnej komórki.

Jako, że PCF8570 posiada trzy linie adresowe: "A0, A1, A2" co umożliwia podłączenie
do ośmiu układów do jednego interfejsu i2c to adres sprzętowy danego układu można
przypisać w momencie tworzenia obiektu klasy.

Domyślnie ustawiony jest adres 0x50 - wszystkie linie A0, A1, A2 zwarte do masy.
