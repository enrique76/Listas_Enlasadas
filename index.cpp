#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>

using namespace std;

struct Nodo{
    float dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&,float);
void mostrarLista(Nodo *);
void Menu();
void Salir();
void Buscar(Nodo *,float);
void Eliminar(Nodo *&,float);
void EliminarLista(Nodo *&,float &);
void Borrando();

int opc;

int main(){

    Nodo *lista = NULL;
    float dato;
    bool V = true;
    
    while(V==true){
        system("cls");
        Menu();

        switch(opc){
//--------------------Agregar Elementos---------------
            case 1: 
                system("cls");
                cout<<"\n\tDigite un numero: "; cin>>dato;
                insertarLista(lista,dato);
                cout<<"\n\nPresione cualquier tecla para continuar";
                getch();
                system("cls");
            break;
//--------------Mostrar elementos-----------------
            case 2: 
                if(lista == NULL){
                    cout<<"\naun no hay elementos para mostrar";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    mostrarLista(lista);
                    cout<<"\n\nPresione cualquier tecla para continuar";
                    getch();
                    system("cls");
                }
            break;
//------------------Borrar elementos----------------
            case 3:
                if(lista == NULL){
                    cout<<"\nLa lista esta basia, no puedes borrar nada";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    do{
                        system("cls");
                        cout<<"\n\n\tMenu de borrar\n";
                        cout<<"\n\t1. Borrar todos los elementos";
                        cout<<"\n\t2. Borrar n cantidad de elementos";
                        cout<<"\n\nOpccion: "; cin>>opc;
                    }while(opc < 1 || opc > 2);

                    if(opc == 1){
                        while(lista != NULL){
                            EliminarLista(lista,dato);
                        }
                        Borrando();
                        cout<<"\n\nTodos los datos han sido eliminados corectamente";
                        getch();
                        system("cls");
                    }
                    else{
                        system("cls");
                        float elemento;
                        cout<<"\n\tBorrar n cantidad de elementos";
                        cout<<"\n\n\tCuantos elementos quieres borar: "; cin>>opc;

                        while(opc>0){
                            cout<<"\n\nQue elemento deceas borrar: "; cin>>elemento;
                            Eliminar(lista,elemento);
                            getch();
                            opc--;
                        }

                    }
                }
            break;
//--------------------Buscar elemento-----------------
            case 4:
                if(lista == NULL){
                    cout<<"\nLa lista esta basia, no puedes buscar nada";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    cout<<"\nQue dato decea buscar: "; cin>>dato;
                    Buscar(lista,dato);
                    getch();
                    system("cls");
                }
            break;
            case 5:
                Salir();
                V = false;
            break;
        }
        system("cls");
    }

    getch();
    return 0;
}

void insertarLista(Nodo *&lista,float n ){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) &&(aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;

    }
    else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cout<<"\n\tEl elemento "<<n<<" se inserto corectamente";

}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL){
        cout<<actual->dato;
        if(actual->siguiente != NULL){
            cout<<" -> ";
        }
        else{
            cout<<".";
        }
        actual = actual->siguiente;
    }
}

void Menu(){
    cout<<"\n\n\tMenu\n\n";
    cout<<"\t1. Agregar dato a la lista";
    cout<<"\n\t2. Mostrar listas";
    cout<<"\n\t3. Borrar elemento de la lista";
    cout<<"\n\t4. Buscar un elemento";
    cout<<"\n\t5. Salir";

    do{
        cout<<"\n\nOpccion: "; cin>>opc;
        if(opc < 1 || opc > 5){
            cout<<"\nDato invalido";
        }
    }while(opc < 1 || opc > 5);
}

void Salir(){
    cout<<"\nSaliendo";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
}

void Buscar(Nodo *lista,float n){
    bool band = false;
    Nodo *actual = new Nodo();
    actual = lista;

    while((actual!=NULL)&&(actual->dato <= n)){
        if(actual->dato == n){
            band = true;
        }
        actual = actual->siguiente;
    }

    if(band == true){
        cout<<"\nEl elemento "<<n<<" SI ha sido encontrado en lista";
    }
    else{
        cout<<"\nEl elemento "<<n<<" NO ha sido encontrado en lista";
    }

}

void Eliminar(Nodo *&lista,float n){
    Nodo *aux_borrar;
    Nodo *anterior = NULL;

    aux_borrar = lista;

    while((aux_borrar != NULL)&&(aux_borrar->dato != n)){
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }
    // Elemento no ha sido encontrado
    if(aux_borrar == NULL){
        cout<<"\n\nEl elemto "<<n<<" NO ha sido encontrado";
    }
    else if(anterior == NULL){
        lista = lista->siguiente;
        delete aux_borrar;

        cout<<"\n\nEl elemto "<<n<<" se ha borrado corectamente";
    }
    else{
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;

        cout<<"\n\nEl elemto "<<n<<" se ha borrado corectamente";
    }

}


void EliminarLista(Nodo *&lista,float &n){

    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;

}

void Borrando(){
    cout<<"\nBorrando";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
}