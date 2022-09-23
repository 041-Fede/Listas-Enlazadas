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

int main()
{
    Nodo *Lista = NULL;

    CargaDeDatos(Lista);

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

        Insertar(Primero,I);

        cout << "---------------------------------" << endl;
        cout << "INFORME dni del siguiente alumno (0 para finalizar): ";
        cin >> I.DNI;
    }
}


void Insertar(Nodo*&Lista,Alumnos Dato)
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

