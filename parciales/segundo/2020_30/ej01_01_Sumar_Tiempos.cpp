#include <iostream>  
using namespace std;  

/*
TASK:
Escribir función llamada timeAdd()
Sumar 2 tiempos. Cada uno consiste de un:
		int days; 0 - Infinity
		int horas; 0-23
		int minutes; 0 - 59
		int seconds; 0-59


En la primera y segunda linea de código del main() se pueden cambiar los valores de cada uno de los tiempos a ser sumados
Esto se hace para no alargar el programa pidiendole al usuario los datos uno por uno

Se muestra el resultado de la suma.
*/

//Los tiempos tambien se pueden crear por clases
// Para actualizar las variables tambien se pueden utilizar pointers


// calling by reference
void timeAdd (int& days1,int& hours1,int& minutes1,int& seconds1,int days2,int hours2,int minutes2,int seconds2 );

int main() {  

	int days=22, hours=12, minutes= 53 , seconds=40;
	timeAdd(days, hours, minutes, seconds, 10, 21, 20, 15); // ver parametros de función.
	
	cout << "The time adition is: \n" ;
	cout << "Days: " << days << endl ;
	cout << "Hours: "<< hours << endl;
	cout << "Minutes: "<< minutes << endl;
	cout << "Seconds: "<< seconds << endl;
	
	 

  return 0;
}



void timeAdd (int& days1,int& hours1,int& minutes1,int& seconds1,int days2,int hours2,int minutes2,int seconds2 ){
	
	// A estas se les va a asignar el tiempo resultante.
	int days= 0, hours = 0, minutes= 0, seconds= 0; 
	
	// añade los tiempo sin tener en cuenta limites de cada uno
	seconds = seconds1 + seconds2;
	minutes = minutes1 + minutes2;
	hours = hours1 + hours2;
	days = days1 + days2;
	
	// Se va limitando cada parte del tiempo correspondientemente
	if (seconds >= 60){
		minutes += seconds / 60;
		seconds = seconds % 60;
	}
	if ( minutes >= 60 ){
		hours += minutes / 60;
		minutes %= 60;
	}
	if ( hours >= 24){
		days += hours / 24;
		hours %= 24 ;
	}
	
	// Asigna la suma del tiempo a las variables que hacen parte del main()
	seconds1 = seconds;
	minutes1 = minutes;
	hours1 = hours;
	days1 = days;
	
	return;
}
