# funktions_argument_polymorphismus
Dieses Programm demonstriert, wie man in C++ einen Polymorphismus für
Funktions-Argumente realisieren kann.

**Ohne** Funktions-Argument-Polymorphismus werden bei der
Bestimmung einer aufzurufenden Funktion alle Pointer auf abgeleitete Objekte
so behandelt, als wären es Pointer auf ein Basis-Objekt. Der Typ des Pointers
bestimmt die Auswahl der aufgerufenen Funktion.

**Mit** Funktions-Argument-Polymorphismus werden alle Pointer
entsprechend dem Typ des Objektes behandelt, auf das der Pointer zeigt.
