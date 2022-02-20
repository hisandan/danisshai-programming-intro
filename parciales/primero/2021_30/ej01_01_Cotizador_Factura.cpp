#include <iostream>   
using namespace std;  

/*
TASK:
Realizar un cotizador de factura para una compañia de cable local

Existen clientes Residenciales 'R' o 'r' y de Negocios 'N' o 'n'

Cargos para Clientes Residenciales (R):
  - procesamiento de la factura: $4.50 
  - servicio básico: $20.50 
  - Canales Premium: $7.50 por canal 

Cargos para Clientes Residenciales (R):
  - procesamiento de la factura: $15.00 
  - servicio básico: $70.00 primeras 10 conexiones + $5.0 por cada adicional
  - Canales Premium: $50.00 por canal para cualquier # de conexiones

Al inicio del programa también se debe pedir el # de cuenta del cliente y al final se debe mostrar el # de cuenta y el importe total a pagar.
*/

int main() {  
  int numeroCuenta, canalesPremium, conexionesBasicas;    
  char tipoCliente;
  float importePagar;

  cout << "Bienvenido al cotizador de factura del Servicio por cable \n";
  cout << "Por favor digita los siguientes datos: \n \n";

  cout << "# de Cuenta: ";
  cin >> numeroCuenta;

  cout << "# de Canales Premium: ";
  cin >> canalesPremium;

  cout << "Tipo de Cliente. 'R' o 'r' para residencial,  'N' o 'n' para Negocio: ";
  cin >> tipoCliente;


  if (tipoCliente == 'R' || tipoCliente == 'r'){
    importePagar += 4.5; // procesamiento de factura
    importePagar += 20.5; // servicio básico
    importePagar += canalesPremium*7.5; // canales premium
    
  }else if (tipoCliente == 'N' || tipoCliente == 'n'){
    cout << "# de Conexiones Básicas: ";
    cin >> conexionesBasicas;

    importePagar += 15.0; // procesamiento de factura
    importePagar += 75.0; // Primeras 10 Conexiones Básicas 
    if ( conexionesBasicas > 10 )
    {
      importePagar += 5.0*(conexionesBasicas-10); // Conexiones basicas luego de las 10 primeras
    }
    importePagar += canalesPremium*50.0; // Canales Premium
  }else{
    cout << "No se pudo reconocer el Tipo de Cliente";
  }
  cout << "\n Cliente # "<< numeroCuenta << " su importe a pagar es de ($) "<< importePagar << endl;
  cout << "Gracias por utilizar el cotizador.\n";

  return 0; 
}