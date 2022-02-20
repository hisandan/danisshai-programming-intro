#include <iostream>   
using namespace std;  

/*
TASK:
Hallar número de meses en que una población de hormagas Rojas (A) sobre pasa
el numero de una población de hormigas Enanas (B).

El usuario ingresa:
  - Catidad de Hormigas (A)
  - Tasa de crecimiento por mes de Hormigas (A)
  - Catidad de Hormigas (B)
  - Tasa de crecimiento por mes de Hormigas (B)
  ** La cantidad de Hormigas A debe ser menor a la cantidad de Hormigas B
        CASO: La poblacion seria mayor desde el mes 0
  ** La cantidad de Tasa de Crecimiento A debe ser mayor a la taza de crecimiento de Hormigas B
        CASO: La poblacion nunca seria mayor que la otra.


METODOLOGIA:
  - Mientras la cantidad de Hormigas A 
    sea menor a las B aumentar cada población por su tasa de crecimiento.
  - Ir guardando el # de iteraciones anteriores en la variable numeroMeses.
  - Mostrar el numero del mes en que la poblacion A paso a la B 
      y la cantidad de hormigas en ese mes en cada población.
*/

int main() {  
  int hormigasA, hormigasB; // catidad de hormigas
  float crecimientoA, crecimientoB; // tasa de crecimiento de 0-100 %
  int mes = 0;

  cout << "# inicial de Hormigas Rojas: ";
  cin >> hormigasA;
  cout << "Tasa de Crecimiento mensual Hormigas Rojas en % : ";
  cin >> crecimientoA;

  cout << "# inicial de Hormigas Enanas: ";
  cin >> hormigasB;
  cout << "Tasa de Crecimiento mensual Hormigas Enanas en % : ";
  cin >> crecimientoB;
  cout << endl;
  
  if (crecimientoA > crecimientoB || hormigasA > hormigasB) // verifica si en algun momento las hormigas A sobrepasan a las hormigas B
  {
    while (hormigasA < hormigasB)
    {
      /* code */
      hormigasA *= 1 + crecimientoA/100;
      hormigasB *= 1 + crecimientoB/100;
      mes +=1;
    }
    cout << "Cantidad Hormigas Rojas SOBREPASO a Hormigas Enanas\n";
    cout << "MES: "<< mes << endl ;
    cout << "Hormigas Rojas: "<< hormigasA << endl;
    cout << "Hormigas Enanas: " << hormigasB << endl;
    
  }else{
    cout << "La población de hormigas Rojas siempre sera menor que la de hormigas Enanas." << endl;
  }
  

  return 0; 
}