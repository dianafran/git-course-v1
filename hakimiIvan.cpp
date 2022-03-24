#include <iostream>
using namespace std;

void menuPrincipal();
void mostrarA(int arr[], int nroElementos, int contCout);
void llenarArreglo(int arre[], int &nroElementos);
void hakimi(int arr[], int nroElementos);
void metodoBurbuja(int arr[], int nroElementos);
bool hayNumeroNegativo(int arr[], int nroElementos);
bool numeroDiferenteCeroPositivo(int arr[], int nroElementos);

int main(){
    menuPrincipal();
    system("PAUSE");
}

void menuPrincipal(){
	int opc;
	do{
		do{
			system("cls");
				cout<<"\n\t************************************************************";
				cout<<"\n\t*                     MENU PRINCIPAL                       *";
				cout<<"\n\t************************************************************";
				cout<<"\n\t*                                                          *";
				cout<<"\n\t*     1. Teorema Havel-Hakimi                              *";
                cout<<"\n\t*     0. Salir                                             *";
				cout<<"\n\t*                                                          *";
				cout<<"\n\t************************************************************";
				cout<<"\n\tSeleccione una opcion: ";
				cin>>opc;
				cout<<"\n\n";
				system("cls");
		} while(opc>2 || opc<0);
		
		switch(opc){
			case 1: {                  
                    int arr[100], nroElementos=0;
                    llenarArreglo(arr, nroElementos);
                    hakimi(arr,nroElementos);
                    system("PAUSE");
					break;
                    }
		}
	}while (opc!=0);
	cout<<"\n\n\tGracias por utilizar el programa!\n\n"<<endl;
}


void llenarArreglo(int arre[], int &nroElementos){
    cout<<"\n\tIngrese el numero de elementos que desea ingresar: ";cin>>nroElementos;
    for(int i=0;i<nroElementos;i++){
        cout<<"\nIngrese el valor para la posicion ["<<i<<"]: ";cin>>arre[i];
    }
}

void mostrarA(int arr[], int nroElementos, int contCout){
	int i=0;
    cout<<"\n";
    for(int j=0;j<contCout;j++)
        cout<<"  ";
            
	for(i;i<nroElementos;i++){
		cout<<arr[i]<<" ";
	}
}

void hakimi(int arr[], int nroElementos){
    metodoBurbuja(arr,nroElementos);
    mostrarA(arr,nroElementos,0);
    int contCout=0;

    //Si todos los numeros son diferentes y mayores que cero, entonces: 
    while(numeroDiferenteCeroPositivo(arr,nroElementos)){
        for(int i=1;i<=arr[0];i++){
            arr[i]=arr[i]-1;
        }
        arr[0]=0;
        mostrarA(arr,nroElementos,contCout);
        metodoBurbuja(arr,nroElementos);
        contCout++; // Solo para darle un mejor aspecto
        mostrarA(arr,nroElementos,contCout);
    }
    if(hayNumeroNegativo(arr,nroElementos))
        cout<<"\n\n\tNO SE PUEDE GRAFICAR\n";
    else 
        cout<<"\n\n\tSI SE PUEDE GRAFICAR\n";
}

void metodoBurbuja(int arr[], int nroElementos){ // Ordena de mayor a menor
	int i,k,aux;
	for(k=0;k<nroElementos;k++)
		for(i=0;i<nroElementos-1;i++)
			if(arr[i]<arr[i+1]){
				aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
	        }
}

bool hayNumeroNegativo(int arr[], int nroElementos){
    bool p=false;
    for(int i=0;i<nroElementos;i++){
		if(arr[i]<0)
            return true;
	}
    return p;
}

//Revisa que todos los numeros del arreglo sean mayores y diferentes que 0.
bool numeroDiferenteCeroPositivo(int arr[], int nroElementos){
    bool p=false;
    for(int i=0;i<nroElementos;i++){
		if(arr[i]!=0 && arr[i]>0) //Si todos los numeros son 0, no entra aqui.
            return true;
	}
    return p;
}