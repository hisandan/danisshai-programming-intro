#include <iostream>   
using namespace std;  

/*
TASK:
Decir la cantidad de casilleros abiertos y cerrados al final del juego
---------------------------

Se le pedira al usuario que ingrese un numero de casilleros 
el cual tambien corresponde al número de estudiantes en el juego.

Al inicio todos los casilleros estan cerrados

Se le va pidiendo a cada estudiante 'n'  (por orden) que 
    ** si el casillero esta abierto lo cierre 
    ** y si el casillero esta cerrado lo abra
    ** pero que solo revisara casilleros cada n unidades 
    ** comenzando en el casillero 'n' hasta acabar
    n comienza en 1, va aumentando hasta llegar al numero de casilleros

  Ejm: el estudiante 5 puede revisar el casillero 5,10,15, ... ,100, ...
Lo anterior se repite hasta que pasen todos los estudiantes.

-----------------------------------
METODOLOGIA A USAR:

Para conocer cuantas veces fue visitado por algun estudiante 
un casillero número 'x', basta con hallar cuantos divisores tiene el nñumero 'x'.

Si la cantidad de divisores es par el casillero queda cerrado
Si la cantidad de divisores es impar el casillero queda abierto

Se determinara por cada casillero si queda abierto o serrado y se iran sumando los resultados.
*/

int main() {  
  
  int cantCasilleros, casillerosCerrados=0, casillerosAbiertos=0;

  cout << "BIENVENIDO AL JUEGO DE LOS CASILLEROS: \n";
  cout << "Ingresa el # de estudiantes y casilleros: ";
  cin >> cantCasilleros;

  for (int casillero = 1; casillero <= cantCasilleros; casillero++)
  {
    bool state = false; // False si el casillero esta cerrado, True si esta abierto
    for (int estudiante = casillero; estudiante > 0; estudiante--)
    {
      if (casillero % estudiante == 0) // El estudiante pasa por el casillero
      {
        state = !state; // el casillero cambia de cerrado a abierto o de abierto a cerrado
      }
    }
    state == false? casillerosCerrados+=1 // si esta cerrado añadirlo a la cuenta de casilleros cerrados
      : casillerosAbiertos+=1; // si no esta cerrado se añade a la cuenta de casilleros abiertos
  }
  
  cout << "RESULTADOS\n" ;
  cout << "Casilleros Cerrados: " << casillerosCerrados << endl;
  cout << "Casilleros Abiertos: " << casillerosAbiertos << endl;
  cout << "FIN DEL JUEGO\n" ;
  return 0; 
}