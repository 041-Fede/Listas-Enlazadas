#include <iostream>

using namespace std;

struct Inscriptos
{
    int DNI;
    string Nombre;
};

struct NodoLista
{
    Inscriptos Info;
    NodoLista*Sig;
};

void Punto1(NodoLista*&Primero);
void Punto2(NodoLista*&Primero,int Nro);
void Punto3(NodoLista*&Primero);
void Punto4(NodoLista*&Primero);
void Encolar(NodoLista*&Primero,Inscriptos Dato);

int main()
{
    int DNI;
    NodoLista *Primero = NULL;

    Punto1(Primero);

    cout << "---------------------------------" << endl;
    cout << "INFORME dni de la persona que no asistira al curso: ";
    cin >> DNI;

    Punto2(Primero,DNI);

    cout << "---------------------------------" << endl;
    cout << "Lista actualizada: " << endl;

    Punto3(Primero);

    cout << "---------------------------------" << endl;

    return 0;
}

void Punto1(NodoLista*&Primero)
{
    Inscriptos I;

    cout << "INFORME dni del alumno: ";
    cin >> I.DNI;

    while(I.DNI != 0)
    {
        cout << "INFORME nombre del alumno: ";
        cin >> I.Nombre;

        Insertar(Primero,I);

        cout << "---------------------------------" << endl;
        cout << "INFORME dni del siguiente alumno (0 para finalizar): ";
        cin >> I.DNI;
    }
}


void Punto2(NodoLista*&Primero,int Nro)
{
    NodoLista *Aux;
    NodoLista *Aux2;
    Aux = Primero;

    while(Aux != NULL)
    {
        if(Aux->Info.DNI == Nro)
        {
            if(Aux == Primero)
            {
                Primero = Aux->Sig;
            }
            else
            {
                Aux2->Sig = Aux->Sig;
            }

            delete Aux;
        }

        Aux2 = Aux;
        Aux = Aux->Sig;
    }
}

void Punto3(NodoLista*&Primero)
{
    NodoLista *Aux;
    Aux = Primero;

    while(Aux != NULL)
    {
        cout << "DNI del alumno: " << Aux->Info.DNI << " - " << "Nombre del alumno: " << Aux->Info.Nombre << endl;

        Aux = Aux->Sig;
    }
}

void Insertar(NodoLista*&Primero,Inscriptos Dato)//Inserta elementos a la lista conservando el orden
{
    NodoLista *Nuevo,*Antecesor,*Aux;
    Nuevo = new NodoLista;
    Nuevo->Info = Dato;
    Aux = Primero;

    while(Aux != NULL && Aux->Info.DNI < Dato.DNI)
    {
        Antecesor = Aux;
        Aux = Aux->Sig;
    }

    Nuevo->Sig = Aux;

    if(Aux != Primero)
    {
        Antecesor->Sig = Nuevo;
    }
    else
    {
        Primero = Nuevo;
    }

}
