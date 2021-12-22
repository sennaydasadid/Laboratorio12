#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template  <typename T>
class Arista;
template  <typename T>
class Nodo{
    public:
        Nodo<T> *sig;
        Arista<T> *ady;
        T dato;
        friend class Grafo<T>;
};
template  <typename T>
class Arista{
    public:
    Arista<T> *sig;

    Nodo<T> *destino;//adyacente  
    Nodo<T> *origen;//
    friend class Grafo<T>;
};
template  <typename T>
class Grafo{
    public:
    Nodo<T> *raiz;
    int nroN;//numero de nodos
    int nroA;//numero de aristas
    Grafo(); 
    Grafo<T>* crearGrafo();  
    void insertarNodo(T dato_); 
    void insertarArista(Nodo<T> *origen, Nodo<T> *destino); 
    void borrarArista(Nodo<T> *origen, Nodo<T> *destino); 
    void borrarNodo(Nodo<T> * nodo_);
    bool esVacio(); //-
    bool existeNodo(Nodo<T>*nodo_);
    void caminoMinimo(Nodo<T> *origen, Nodo<T> *destino); 
    void ordenTopologico(); 

    void paso2Dijkstra ();
    int tamaño(); 
    Nodo<T> *getNodo(T dato_); 
    void eliminarGrafo(); 
};

template  <typename T>
Grafo<T>::Grafo(){
    raiz=NULL;
    raiz->dato=0;
    raiz->ady=NULL;
    raiz->sig=NULL;
    nroA=0;
    nroN=0;
}

template  <typename T>
Grafo<T>* Grafo<T>::crearGrafo(){
    Grafo *G =new Grafo<T>();
    G->nroN=0;
    G->nroA=0;
    G->raiz=NULL;
    
}

template  <typename T>
bool Grafo<T>::esVacio(){
    return  (raiz==NULL)
}

template  <typename T>
int Grafo<T>::tamaño(){
    Nodo<T> *aux;
    int c=0;
    aux=raiz;
    while (aux!=NULL){
        c++;
        aux=aux->sig;
    }
    return c;
}

template  <typename T>
Nodo<T> *Grafo<T>::getNodo(T dato_){
    Nodo<T> *aux=raiz;
    while (aux != NULL) {
        if (aux->dato==dato_){
            return aux;
        }
        aux=aux->sig;
    }
    return NULL;
}

template  <typename T>
void Grafo<T>::insertarNodo(T dato_){
    Nodo<T> *nuevo=new Nodo<T>;
    nuevo->dato=dato_;
    nuevo->sig=NULL;
    nuevo->ady=NULL;
    if (this->esVacio()){
        this->raiz=nuevo;
    }else{
        Nodo<T> *aux=raiz;
        while (aux->sig!=NULL){
            
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
    
}

template  <typename T>
void Grafo<T>::insertarArista(Nodo<T> *origen, Nodo<T> *destino){
    Arista<T> *nueva= new Arista<T>;
    nueva->sig=NULL;
    nueva->origen=NULL;
    nueva->destino=NULL;
    Arista<T> * aux= origen->ady;
    if(aux==NULL){
        origen->ady=nueva;
        nueva->destino=destino;
    }else{
        while (aux->sig!=NULL) {
            aux=aux->sig;
        }
        aux->sig=nueva;
        nueva->destino=destino;
    }
}

template  <typename T>
void Grafo<T>::ordenTopologico(){
    Nodo<T> *auxNodo=raiz;
    Arista<T> *auxArista;
    while (auxNodo != NULL)
    {
        cout<<auxNodo->dato<<"->";
        auxArista=auxNodo->ady;
        while (auxArista !=NULL){
            cout<<auxArista->destino->dato<<"->";
            auxArista=auxArista->sig;
        }
        auxNodo=auxNodo->sig;
        cout<<endl;
    }
}

template  <typename T>
void Grafo<T>::eliminarGrafo(){
    Nodo<T> * aux;
    while (this->raiz!=NULL)
    {
        aux=raiz;
        raiz=raiz->sig;
        delete(aux);
    }
}

template  <typename T>
void Grafo<T>::borrarArista(Nodo<T> *origen, Nodo<T> *destino){
    Arista<T> *actual, *anterior;
    bool esta=false;
    actual=origen->ady;
    if (actual== NULL){
        cout<<"El vertice origen no tiene aristas"<<endl;
    }else if(actual->destino==destino){
        origen->ady=actual->sig;
        delete(actual);
    }else{
        while (actual!=NULL){
            if (actual->destino==destino){
                esta=true;
                anterior->sig=actual->sig;
                delete(actual);
                break;
            }
            anterior=actual;
            actual=actual->sig;
        }
        if (!esta)
            cout<<"Los dos nodos no estan conectados"<<endl;
    }
}
template  <typename T>
void Grafo<T>::borrarNodo(Nodo<T> * nodo_){
    Nodo<T> *actual,*anterior;
    Arista<T> *aux;
    actual=raiz;
    while (actual !=NULL)
    {
        aux=actual->ady;
        while (aux!=NULL)
        {
            if(aux->destino==nodo_){
                borrarArista(actual,aux->destino);
                break;
            }
            aux=aux->sig
        }
        actual=actual->sig;
    }
    actual=raiz;
    if(raiz==nodo_){
        raiz=raiz->sig;
        delete(actual);
    }else{
        while(actual != nodo_){
            anterior=actual;
            actual=actual->sig;
        }
        anterior->sig=actual->sig;
        delete(actual);
    }
}

template  <typename T>
bool Grafo<T>::existeNodo(Nodo<T> *nodo_){
    Nodo<T> *aux=raiz;
    bool esta=false;
    while (aux!=NULL)
    {
        if(aux->dato==nodo_->dato){
            esta=true;
            break;
        }
        aux=aux.sig;
    }
    return esta;
}

template  <typename T>
void Grafo<T>::caminoMinimo(Nodo<T> *auxNod, Nodo<T> *destino){
    Nodo<T> aux;
    Arista<T> auxArc;
     int ban =0;
     if (raiz != NULL){
        ban = 0;
        while (ban == 0){
            aux = raiz;
            while (aux != NULL){
                if (aux->nod == auxNod){
                        ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 0){
                    cout << "\nNo existe un nodo con esa letra.";
                    aux = raiz;
                    cout << "\n---Lista de Nodos---\n";
                    while (aux != NULL){
                        cout << aux->nod << " ";
                        aux = aux->sig;
                    }
                    cout << "\nDigite uno de los anteriores nodos: ";
                    cin >> auxNod;
            }
        }
        aux = raiz;
        while (aux->nod != auxNod){
            aux = aux->sig;
        }
        aux->marca = 1;
        auxArc = aux->arc;
        while (auxArc != NULL){
            auxArc->marca = 1;
            auxArc->suma = auxArc->clave;
            auxArc = auxArc->sig;
        }
        int ban2 = 1;
        while (ban2 == 1){
            ban2 = 0;
            aux = raiz;
            while (aux != NULL){
                if (aux->marca == 0){
                    ban2 = 1;
                }
                aux = aux->sig;
            }
        }
     }
}
