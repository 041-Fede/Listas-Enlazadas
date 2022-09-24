/*Hacer una función que devuelva la lista del ejercicio 2 ordenada alfabéticamente.*/

#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

struct Inscriptos
{
    int DNI;
    string Nombre;
};

struct Nodo
{
    Inscriptos Info;
    Nodo *Sig;
};

void CargaDeDatos(Nodo*&Lista);
void Insertar(Nodo*&Lista,Inscriptos Dato);
void OrdenarLista(Nodo*&Lista);
void MostrarLista(Nodo*Lista);

int main()
{
    Nodo *Lista = NULL;

    CargaDeDatos(Lista);

    OrdenarLista(Lista);

    cout << "Lista actualizada:" << endl;

    MostrarLista(Lista);

    cout << "---------------------------------" << endl;

    return 0;
}

void CargaDeDatos(Nodo*&Lista)
{
    Inscriptos I;

    cout << "INFORME dni del alumno: ";
    cin >> I.DNI;

    while(I.DNI != 0)
    {
        cout << "INFORME nombre del alumno: ";
        cin >> I.Nombre;

        Insertar(Lista,I);

        cout << "---------------------------------" << endl;
        cout << "INFORME dni del siguiente alumno (0 para finalizar): ";
        cin >> I.DNI;
    }
}


void Insertar(Nodo*&Lista,Inscriptos Dato)
{
    Nodo *Aux;
    Nodo *Nuevo = new Nodo;
    Nuevo->Info = Dato;
    Nuevo->Sig = NULL;

    if(Lista != NULL)
    {
        Aux = Lista;

        while(Aux->Sig != NULL)
        {
            Aux = Aux->Sig;
        }

        Aux->Sig = Nuevo;
    }
    else
    {
        Lista = Nuevo;
    }
}

void OrdenarLista(Nodo*&Lista)
{
    Nodo *Actual,*Siguiente;
    Inscriptos I;

    Actual = Lista;

    while(Actual->Sig != NULL)//Nos aseguramos que haya dos nodos para comparar
    {
        Siguiente = Actual->Sig;

        while(Siguiente != NULL)
        {
            if(Actual->Info.DNI > Siguiente->Info.DNI)
            {
                I = Siguiente->Info;
                Siguiente->Info = Actual->Info;
                Actual->Info = I;
            }

            Siguiente = Siguiente->Sig;
        }

        Actual = Actual->Sig;
    }
}

void MostrarLista(Nodo*Lista)
{
    Nodo *Aux = Lista;

    while(Aux != NULL)
    {
        cout << "DNI del alumno: " << Aux->Info.DNI << " - " << "Nombre del alumno: " << Aux->Info.Nombre << endl;

        Aux = Aux->Sig;
    }
}
