//------------------------------------------------------------------------------
// Dieses Programm demonstriert, wie man in C++ einen Polymorphismus für
// Funktions-Argumente realisieren kann.
//
// Ohne Funktions-Argument-Polymorphismus (FKT_ARG_POL=0) werden bei der
// Bestimmung einer aufzurufenden Funktion alle Pointer auf abgeleitete Objekte
// so behandelt, als wären es Pointer auf ein Basis-Objekt. Der Typ des Pointers
// bestimmt die Auswahl der aufgerufenen Funktion.
//
// Mit Funktions-Argument-Polymorphismus (FKT_ARG_POL=1) werden alle Pointer
// entsprechend dem Typ des Objektes behandelt, auf das der Pointer zeigt.
//
// Hinweis:
// Bei einer rein abstrakten Basis-Klasse braucht man keine Alias-Namen.
//------------------------------------------------------------------------------
#include <iostream>

#define FKT_ARG_POL 1

class A {};
class B {};

void sub(A*  a)  { std::cout << "Parameter: A*"  << std::endl; }
void sub(B*  b)  { std::cout << "Parameter: B*"  << std::endl; }

#if !FKT_ARG_POL
class C {};
class C1 : public C {};
class C2 : public C {};
#else
// Die Klassen mit Vererbung müssen erst mal nur deklariert werden.
class C;
class C1;
class C2;
#endif

#if !FKT_ARG_POL
void sub(C*  c)  { std::cout << "Parameter: C*"  << std::endl; }
#else
// Die Funktion, die über den Parameter-Polymorphismus ausgewählt werden soll,
// muss erst mal nur deklariert werden. Ihre Definition erhält einen Alias-
// Namen.
void sub(C*  c);
void Sub(C*  c)  { std::cout << "Parameter: C*"  << std::endl; }
#endif

void sub(C1* c1) { std::cout << "Parameter: C1*" << std::endl; }
void sub(C2* c2) { std::cout << "Parameter: C2*" << std::endl; }

#if FKT_ARG_POL
// In den Klassen mit Vererbung muss eine Funktion so definiert werden, dass sie
// die eigentliche Funktion aufruft; in der Basis-Klasse muss es stattdessen die
// Funktion mit dem Alias-Namen sein. Der Name der neu definierten Funktion kann
// mit dem Alias-Namen der eigentlichen Funktion übereinstimmen, muss es aber
// nicht. Bei der Funktions-Definition entfällt der Auswahl-Parameter. 
class C             { public: virtual void SUb()          { ::Sub(this); } };
class C1 : public C { public:         void SUb() override { ::sub(this); } };
class C2 : public C { public:         void SUb() override { ::sub(this); } };

// Dann muss noch die eigentliche Funktion für die Basis-Klasse der Vererbungs-
// Hierarchie so definiert werden, dass sie die Funktion mit dem Alias-Namen
// ohne den Auswahl-Parameter aufruft.
void sub(C*  c)  { c->SUb(); }
#endif

int main() {
  A  a;
  B  b;
  C  c;
  C1 c1;
  C2 c2;

  sub(&a);
  sub(&b);
  sub(&c);
  C* pc1 = &c1; sub(pc1);
  C* pc2 = &c2; sub(pc2);

  return 0;
}
