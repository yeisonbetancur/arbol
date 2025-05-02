#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>  
using namespace std;

struct Nodo{
	int info;
	Nodo* der;
 	Nodo* izq;
};


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void agregarNodo(Nodo** raiz,int x){
	Nodo* nuevo=new Nodo;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	
	if(*raiz==NULL){
		nuevo->info=x;
		(*raiz)=nuevo;
		cout<<"Se agrego el dato al arbol\n";
		return;
	}
	int dir;
	cout<<"El contenido del nodo actual es: "<<(*raiz)->info<<endl;
	cout<<"El contenido de los hijos: \n";
	if((*raiz)->izq==NULL){
		cout<<"izq: NULL";
	}else{
		cout<<"izq: "<<(*raiz)->izq->info;
	}
	if((*raiz)->der==NULL){
		cout<<"der: NULL";
	}else{
		cout<<"der: "<<(*raiz)->der->info;
	}
	cout<<"Si el nodo esta vacio lo agregara en ese nodo, si no, se explorara ese nodo del arbol\n";
	cout<<"Deseas agregarlo a la izquierda o a la derecha?(1 o 2)\n";
	cin>>dir;
	while(dir<1||dir>2){
		cout<<"Ingresa valores 1 o 2 para izquierda o derecha, respectivamente\n";
		cin>>dir;
	}
	if(dir==1){
		agregarNodo(&((*raiz)->izq),x);
		return;
	}else{
		agregarNodo(&((*raiz)->der),x);
		return;
	}
}
void agregarValor(Nodo** raiz){
	int x;
	cout<<"Ingresa el valor del contenido del nodo\n";
	cin>>x;
	agregarNodo(raiz,x);
}


void imInorden(Nodo *p){
	if(p!=NULL){
		imInorden(p->izq);
		cout<<p->info<<" ";
		imInorden(p->der);
	}
}

void dibujarArbol(Nodo* raiz, int x, int y, int espacio) {
    if (raiz == NULL) {
        return;
    }

    // Dibuja el nodo (su valor)
    gotoxy(x, y);
    cout << raiz->info;

    // Dibuja las ramas hacia los hijos
    if (raiz->izq) {
        // Dibuja la rama izquierda
        gotoxy(x - espacio / 2, y + 2);
        cout << "/";
        dibujarArbol(raiz->izq, x - espacio, y + 3, espacio / 2);
    }

    if (raiz->der) {
        // Dibuja la rama derecha
        gotoxy(x + espacio / 2, y + 2);
        cout << "\\";
        dibujarArbol(raiz->der, x + espacio, y + 3, espacio / 2);
    }
}

void controlarArbol(Nodo* raiz){
	system("CLS");
	dibujarArbol(raiz, 40, 1,10);
	cout<<"\nPresiona cualquier tecla para continuar\n";
	getch();
}

int main(){
	int x;
	Nodo *raiz=NULL;
	
	do{
		cout<<"Menu manejo arboles binarios\n";
		cout<<"1. Agregar Nodo\n";
		cout<<"2. Mostrar el contenido del arbol en inorden\n";
		cout<<"3. Dibujar el arbol\n";
		cout<<"4. Salir\n";
		cin>>x;
		switch(x){
			case 1: agregarValor(&raiz);break;
			case 2: imInorden(raiz);break;
			case 3: controlarArbol(raiz);
		}
	}while(x!=4);
}

