#include <iostream>
#include <windows.h>
#include "grafo.cpp"
using namespace std;

int menu(){
    int opc;
    system("cls");
    cout<<"        GRAFO ";
    cout<<"\n-------------------------------";
    cout<<"\n(1)Insertar un Nodo";
    cout<<"\n(2)Insertar una Arista";
    cout<<"\n(3)Eliminar un Nodo";
    cout<<"\n(4)Eliminar una Arista";
    cout<<"\n(5)Verificar si el Grafo esta vacio";
    cout<<"\n(6)Verificar si existe un Nodo";
    cout<<"\n(7)Imprimir el caminio minimo";
    cout<<"\n(8)Imprimir el orden Topologico";
    cout<<"\n(9)Salir"<<endl;
    cout<<"\nOPCION: ";
    cin >>opc;
    cout<<endl;
    return opc;
}
int main(){
    Grafo<string> Malla;
    Malla.crearGrafo();
    int opcion;    
    Malla.insertarNodo("Fundamentos de Computacion");

    Malla.insertarNodo("Ciencia de la computacion I"); 

    Malla.insertarNodo("Ciencia de la computacion II");
    Malla.insertarNodo("Trabajo Interdisciplinar I");
    Malla.insertarNodo("Desarrollo Basado en Platafromas");
    
    Malla.insertarArista(Malla.getNodo("Fundamentos de Computacion"),Malla.getNodo("Ciencia de la computacion I"));
    do
    {
        opcion=menu();
        switch (opcion)
        {
            case 1:{
                string nombreCurso;
                system("cls");
                cout<<"Ingrese el nombre del curso: ";
                cin.ignore();
                getline(cin,nombreCurso,'\n');
                Malla.insertarNodo(nombreCurso);
                cin.get();
                cin.get();
                break;            
            }
            case 2:{
                string origen, destino;
                system("cls");
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    cout<<"Ingrese el nombre del nodo origen: ";
                    cin.ignore();
                    getline(cin,origen,'\n');
                    cout<<"Ingrese el nombre del nodo destino: ";
                    getline(cin,destino,'\n');
                    if(Malla.getNodo(origen)==NULL || Malla.getNodo(destino)==NULL){
                        cout<<"Uno de los dos nodos no es valido o no existe"<<endl;
                    }else{
                        Malla.insertarArista(Malla.getNodo(origen),Malla.getNodo(destino));
                    }
                }
                cin.get();
                cin.get();
                break;
            }

            case 3:{
                string nombre;
                system("cls");
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    cout<<"Ingrese el nombre del curso a eliminar: ";
                    cin.ignore();
                    getline(cin,nombre,'\n');
                    if(Malla.getNodo(nombre)==NULL)
                        cout<<"Nodo incorrecto o no existe"<<endl;
                    else
                        Malla.borrarNodo(Malla.getNodo(nombre));//
                }
                cin.get();
                break;         
            }
            case 4:{
                string origen, destino;
                system("cls");
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    cout<<"Ingrese el nombre del nodo origen: ";
                    cin.ignore();
                    getline(cin,origen,'\n');
                    cout<<"Ingrese el nombre del nodo destino: ";
                    getline(cin,destino,'\n');
                    if(Malla.getNodo(origen )==NULL ||Malla.getNodo(origen )==NULL )
                        cout<<"Nodo incorrecto"<<endl;
                    else
                        Malla.borrarArista(Malla.getNodo(origen),Malla.getNodo(destino));
                }
                cin.get();
                break;         
            }
            case 5:{
                system("cls");
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    cout<<"El grafo se encuentra con datos"<<endl;
                }
                break;         
            }
            case 6:{
                system("cls");
                string nombre;
                cout<<"Ingrese el nombre del nodo a encontrar: ";
                cin.ignore();
                getline(cin,nombre,'\n');
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    if(Malla.existeNodo(Malla.getNodo(nombre))){
                        cout<<"El nodo ingresado existe"<<endl;
                    }else
                        cout<<"No existe nodo"<<endl;
                }
                break;         
            }
            case 7:{
                string origen, destino;
                system("cls");
                cout<<"Ingrese el nombre del nodo origen: ";
                    cin.ignore();
                    getline(cin,origen,'\n');
                    cout<<"Ingrese el nombre del nodo destino: ";
                    getline(cin,destino,'\n');
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    Malla.caminoMinimo(Malla.getNodo(origen),Malla.getNodo(destino));
                }
                break;         
            }
            case 8:{
                system("cls");
                if (Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else{
                    Malla.ordenTopologico();
                }
                break;         
            }
            case 9:{
                opcion=9;
                break;     
            }

            default:
                break;
        }
    } while (opcion<=9);
    


    return 0;
}      
          /*
                //imprime lista adyacencia
                system("cls");
                if(Malla.esVacio())
                    cout<<"El grafo esta vacio"<<endl;
                else
                    Malla.ListaAdyacencia();
                */