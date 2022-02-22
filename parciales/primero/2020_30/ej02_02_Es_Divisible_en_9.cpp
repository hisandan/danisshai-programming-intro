#include <iostream>   
using namespace std;  

/*
TASK:
Solo se halla si el numero es divisible entre 9
Este programa sirve para verificar el resultado del  programa anterior  o version 1
*/

int main() {  
  int numero;
  cout << "Conocer si un número es divisible en 9 "<< endl;
  cout << "Ingresa un número Entero: ";
  cin >> numero;

  if (numero % 9 == 0)
  {
    cout << "Es divisible entre 9";
  } else {
    cout << "no es divisible entre 9";
  }
  
  return 0; 
}