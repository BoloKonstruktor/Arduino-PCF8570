# Arduino-PCF8570
Biblioteka do obsługi szeregowej pamięci RAM  i2c

Szęść Boże!

Bilioteka zawiera typową obsługę pamięci PCF8570.

Metoda "read" pozwala na odczyt danych z PCF8570 do zmiennej wielobajtowej, tablicy
bajtów jak również struktury. Analogicznie metoda write pozwala na zapis zmiennej
wielobajtowej, tablicy bajtów lub struktury do PCF8570. Metody te mają identyczne
argumenty. Pierwszy "offset" to adres komórki, drugi "data" to wskaźnik do danych
i trzeci "size" to rozmiar danych.
