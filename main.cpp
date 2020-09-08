#include <iostream>
#include <fstream>
using namespace std;
void ordenar(int arr[], int tam);
void ingresar(int arr[], int tam);
void imprimir(int arr[],int tam);
const string nombre="bd.txt";  
int main()
{

  ofstream datos;
  datos.open(nombre.c_str(),ios::out);
  int tam, arr[100];
  cout << "ingrese el tamaño del arreglo: ";
  datos << "elementos sin ordenar" << endl;
  cin >> tam;
  ingresar(arr,tam);
  for(int i=1;i<tam;i++)
  {
    datos << arr[i] << endl;
  }
  ordenar(arr,tam);
  imprimir(arr,tam);
  datos << "elementos ordenados" << endl;
  for(int i=2;i<=tam;i++)
  {
    datos << arr[i] << endl;
  }
  datos << "algoritmo utilizado: heapsort" << endl; 
  datos.close();
}
void ingresar(int arr[], int tam)
{
  int i,x=1;
  for(i=1;i<tam;i++)
  {
    cout << "valor "<< x << ": ";
    cin >> arr[i];
    x++;
  }
}
void ordenar(int arr[], int tam)
{
  
   int valor,temp,a;

    for(int i=tam; i>0; i--)
    {
        for(int j=1; j<=i; j++)
        {
            valor=arr[j];
            a=j/2;
            while(a>0 && arr[a]<valor)
            {
                arr[j]=arr[a];
                j=a;
                a=a/2;
            }
            arr[j]=valor;
        }
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
    }
}
void imprimir(int arr[],int tam)
{
  cout << "elemenos ordenados" << endl;
  for(int i=2;i<=tam;i++)
  {
    cout << arr[i] << endl;
  }
}