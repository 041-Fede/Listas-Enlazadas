/*Dada la lista definida en el ejercicio 1 conteniendo productos repetidos, hacer una función que deje en la lista un solo nodo por producto con el stock sumado. */

#include <iostream>

using namespace std;

struct Productos
{
    int CodDeProducto,Importe,Stock;
    string Descripcion;
};

struct Nodo
{
    Productos Info;
    Nodo *Sgte;
};

void CargaDeDatos(Nodo*&Lista);
void Insertar(Nodo*&Lista,Productos Dato);
void CorteDeControlListas(Nodo*Lista,Nodo*&ListaResultante);
void MostrarLista(Nodo*Lista);

int main()
{
    Nodo *Lista = NULL,*ListaResultante = NULL;

    CargaDeDatos(Lista);

    CorteDeControlListas(Lista,ListaResultante);

    cout << "Lista resultante:" << endl;

    MostrarLista(ListaResultante);

    cout << "---------------------------------" << endl;

    return 0;
}

void CargaDeDatos(Nodo*&Lista)
{
    Productos P;

    cout << "INFORME codigo del producto: ";
    cin >> P.CodDeProducto;

    while(P.CodDeProducto != 0)
    {
        cout << "INFORME descripcion del producto: ";
        cin >> P.Descripcion;

        cout << "INFORME importe del producto: ";
        cin >> P.Importe;

        cout << "INFORME stock del producto: ";
        cin >> P.Stock;

        Insertar(Lista,P);

        cout << "---------------------------------" << endl;
        cout << "INFORME codigo del siguiente producto (0 para finalizar): ";
        cin >> P.CodDeProducto;
    }
}

void Insertar(Nodo*&Lista,Inscriptos Dato)
{
    Nodo *Aux;
    Nodo *Nuevo = new Nodo;
    Nuevo->Info = Dato;
    Nuevo->Sgte = NULL;

    if(Lista != NULL)
    {
        Aux = Lista;

        while(Aux->Sgte != NULL)
        {
            Aux = Aux->Sgte;
        }

        Aux->Sgte = Nuevo;
    }
    else
    {
        Lista = Nuevo;
    }
}

void CorteDeControlListas(Nodo*Lista,Nodo*&ListaResultante)
{
    int Stock = 0;
    Nodo *Actual = Lista;
    Nodo *Siguiente;

    while(Actual != NULL)
    {
        Siguiente = Actual->Sgte;

        while(Siguiente != NULL && Actual->Info.CodDeProducto == Siguiente->Info.CodDeProducto)
        {
            Stock = Stock + Siguiente->Info.Stock;
            Siguiente = Siguiente->Sgte;
        }

        Actual->Info.Stock = Actual->Info.Stock + Stock;

        Insertar(ListaResultante,Actual->Info);

        Actual = Siguiente;
        Stock = 0;
    }
}

void MostrarLista(Nodo*Lista)
{
    Nodo *Aux = Lista;

    while(Aux != NULL)
    {
        cout << "Codigo del producto: " << Aux->Info.CodDeProducto << " - " << "Descripcion del producto: " << Aux->Info.Descripcion << " - " << "Stock del producto: " << Aux->Info.Stock << " (Unidades)" << " - " << "Importe del producto: " << "$" << Aux->Info.Importe << endl;

        Aux = Aux->Sgte;
    }
}
