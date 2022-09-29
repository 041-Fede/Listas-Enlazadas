/*Dada una lista doblemente encadenada de números enganchada solo por el puntero al siguiente y con todos los punteros al anterior en NULL, se pide hacer una rutina que la recorra y complete los punteros convenientemente incluyendo el puntero externo para recorrerla de atrás hacia adelante.*/

#include <iostream>

using namespace std;

struct Nodo
{
    int Info;
    Nodo *Ant,*Sgte;
};

void CargaDeDatos(Nodo*&Lista);
void InsertarAdelante(Nodo*&Lista,int Nro);
void UnirEnlances(Nodo*&Lista);
void MostrarListaInversa(Nodo*Lista);

int main()
{
    Nodo *Lista = NULL;

    CargaDeDatos(Lista);

    cout << "---------------------------------" << endl;

    UnirEnlances(Lista);

    cout << "Lista en manera inversa: " << endl;

    MostrarListaInversa(Lista);

    cout << "---------------------------------" << endl;

    return 0;
}

void CargaDeDatos(Nodo*&Lista)
{
    int Nro;

    cout << "INFORME numero a enlazar: ";
    cin >> Nro;

    while(Nro != 0)
    {
        InsertarAdelante(Lista,Nro);

        cout << "---------------------------------" << endl;
        cout << "INFORME el siguiente numero a enlazar: ";
        cin >> Nro;
    }
}

void InsertarAdelante(Nodo*&Lista,int Nro)
{
    Nodo *Nuevo = new Nodo;
    Nuevo->Info = Nro;
    Nuevo->Ant = NULL;
    Nuevo->Sgte = Lista;
    Lista = Nuevo;
}

void UnirEnlances(Nodo*&Lista)
{
    Nodo *Aux,*Antecesor;
    Aux = Lista;
    Antecesor = NULL;

    while(Aux != NULL)
    {
        Aux->Ant = Antecesor;
        Antecesor = Aux;
        Aux = Aux->Sgte;
    }
}

void MostrarListaInversa(Nodo*Lista)
{
    Nodo *Aux = Lista;

    while(Aux->Sgte != NULL)
    {
        Aux = Aux->Sgte;
    }

    while(Aux != NULL)
    {
        cout << "Numero: " << Aux->Info << endl;

        Aux = Aux->Ant;
    }
}
