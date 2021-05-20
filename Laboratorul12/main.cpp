#include <iostream>
#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

int main() {
    Agenda agenda;
    Coleg c1, c2;
    c1.setData("Rares", "0722222222", "Kaufland", "str. Varlaam");
    c2.setData("Adrian", "0733333333", "Mega Image", "bd. Socola");
    Cunoscut c11,c12;
    c11.setData("Alexandru", "0744444444");
    c12.setData("Amalia", "0755555555");
    Prieten p1, p2;
    p1.setData("Razvan", "0766666666", "01.01.2001", "bd. Carol I");
    p2.setData("Stefana", "0777777777", "02.02.2002", "bd Nicolae Iorga");
    agenda.addContact(&c1);
    agenda.addContact(&c2);
    agenda.addContact(&c11);
    agenda.addContact(&c12);
    agenda.addContact(&p1);
    agenda.addContact(&p2);
    agenda.show();
    agenda.deleteContact("Amalia");
    agenda.show();
    cout << "Lista prieteni" << '\n';
    for (auto prieten : agenda.listaprieteni())
        cout << prieten->GetName() << '\n';
    cout << "Test cunoscut: " << c11.GetName() << " " << c11.GetTelefon(c11.GetName()) << '\n';
    cout << "Test coleg: " << c1.GetName() << " " << c1.GetPhoneNr(c1.GetName()) << " " << c1.GetWorkplace(c1.GetName()) << " " << c1.GetAdress(c1.GetName()) << '\n';
    cout << "Test prieten: " << p1.GetName() << " " << p1.GetPhoneNr(c1.GetName()) << " " << p1.GetBirthDate(p1.GetName()) << " " << p1.GetPhoneNr(p1.GetName()) << " " << p1.GetAdress(p1.GetName()) << '\n';
    return 0;
}