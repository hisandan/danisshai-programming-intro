#include <iostream>   
using namespace std;  

/*
TASK:
Hallar si un numero es divisible entre 9 mediante el siguiente procedimiento: 

  - sumar los digitos del numero y si es nescesario del numero resultante 
    cuantas veces sea nescesario hasta que se reduzca a un solo numero.
  - si ese numero es igual a 9 si es divisible entre 9 o si no No lo es.

Nota: Se utilizaron bucles for para reemplazar la operoción de la potencia 10^n
Nota: No es muy complicado adaptar este código para que no utilize funciones
      sin embargo me parecio que queda mucho mas organizado si se deja asi,
      por lo que creo que quiza en ese año alcanzaron a ver funciones en este corte?.
*/


int sumarDigitos (int numero){
  int cantDigitos, contador = 0;
  // HALLAR EL NUMERO DE DIGITOS
  int numeroTemp = numero;
  while (numeroTemp != 0 ){
    numeroTemp /= 10;
    cantDigitos+=1;
  };

  //SUMA DE LOS DIGITOS:
  for (int i = (cantDigitos-1); i >= 0; i--)
  {
    int exponente = 1;
    //Este for equivale a 10^i
    for( int position = 1; position <= i; position++ ){
      exponente *= 10;
    }

    int digito = numero / exponente;

    cout << digito;
    i != 0 ? cout << " + ": NULL;

    // Se le quita el numero en la posición del bucle al numero original
    numero = numero - digito*(exponente);

    contador += digito;
  }
  cout << " = " << contador<< endl; // muestra la suma de los digitos
  return contador;
}

int main() {  
  int numero;
  int numeroTemp;
  cout << "Ingresa un numero: ";
  cin >> numero;

  numeroTemp = sumarDigitos(numero);
  while (numeroTemp /10 != 0)
  {
    numeroTemp = sumarDigitos(numeroTemp);
  }
  cout << "El numero "<< numero<< " ";
  numeroTemp == 9? cout << "SI": cout << "NO";
  cout << " es divisible entre 9"<< endl;

  return 0; 
}