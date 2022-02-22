# include <iostream>
using namespace std;

/*

Se tiene:
	Información Inicial de los despachos = {1134,1,12, ...   ,21322, 0, 8} // {cedula, categoria, cantidad, ..., cedula, categoria, cantidad}
		// se va a suponer que los despachos estan organizados por el numero de cédula de menor a mayor para poder aplicar algoritmo de busqueda (Aparece en el pensún)
		// asi aparece en el ejemplo del parcial.
	Información de los pedidos = {2134, 2, ... , 13211, 3} // {cedula, cantidad, ..., cedula, cantidad}
	Cantidad de Clientes (int)
	Catidad de pedidos (Int)

Se nescesita:
	Calcular la cantidad total a despachar a cada cliente al final del mes --> colocarla en el arreglo de despachos

Restricciones:
	Si la cantidad total a despachar a un cliente es > 1000 && su categoria == 1 se le envian 10 unidades más al cliente

La función debe retornar el valor del despacho más grande a un cliente, con el fin de
que la empresa pueda organizar adecuadamente el transporte en camione.
Por esto entiendo que toca mostrar al usuario la información del despacho mas grande de todos.

*/

int busquedaPosCedulaEnDespachos(int despachos[], int cedula, int cantidadPersonas);

int main() {

	//////////////////////// DECLARACIÓN VARIABLES INICIALES///////////////////
	int cantidadPersonas = 6; // El arrego 'despachos' tendria  tamaño de cantidadClientes*3'

	// int* despachos = new int[cantidadClientes*3]
	// despachos = {...}
	int despachos[18] = {
		111, 1, 22, // cedula , categoria, cantidad
		222, 1, 32,
		333, 1, 8,
		444, 0, 200,
		555, 0, 900,
		666, 1, 945
	};

	// Por ahora se van a tomar solo 7 pedidos 
	int catidadPedidos = 7;
	// int* pedidos = new int[catidadPedidos*2]
	// pedidos = {...}
	int pedidos[14] = {
		666, 100,
		444, 300,
		666, 10,
		555, 300,
		222, 980,
		333, 200,
		222, 900,
	};
	int despachoMayor[2] = { 0,0 }; // [cedula, cantidad] Aqui va a ir el despacho mas grande
	/////////////////////////////////////////////////////////////////////
	
	
	for (int pedido = 0; pedido < catidadPedidos; pedido++)
	{
		int cedula = pedidos[pedido * 2];
		int position = busquedaPosCedulaEnDespachos(despachos, cedula, cantidadPersonas);
		if (position != -1) { despachos[position + 2] += pedidos[(pedido * 2) + 1]; }
		//Descomentar la siguiente linea si se quiere ver cada paso
		//cout << "Cedula: " << despachos[position] << "--> " << despachos[position + 1] << "--> " << despachos[position + 2] << " pedidos." << endl;
	};
	cout << endl;
	
	cout << "DESPACHOS FINALES:" << endl;
	// Mostrar Valores finales y encontrar el despacho mas grande
	for (int cliente = 0; cliente < cantidadPersonas; cliente++){
		//obtener cada valor del cliente:
		int cantidad = despachos[(cliente * 3) + 2];
		int cedula = despachos[cliente * 3];
		int categoria = despachos[(cliente * 3) + 1];
		// Si el cliente pidio mas de 1000 unidades y tiene la categoria 1 se le aumentan 10 unidades
		if (categoria == 1 && cantidad > 1000)
		{
			despachos[(cliente * 3) + 2] += 10; cantidad += 10;
		}

		//
		if (cantidad > despachoMayor[1]) {
			despachoMayor[0] = cedula;
			despachoMayor[1] = cantidad;
		}

		cout << "Cedula: " << despachos[(cliente * 3)] << " --> " << despachos[((cliente * 3) + 2)] << " pedidos." << endl;
	};

	cout << endl << "El despacho mas grande fue: \n ";
	cout << "Cedula: " << despachoMayor[0] << " --> " << despachoMayor[1] << " pedidos." << endl;

	return 0;
}


int busquedaPosCedulaEnDespachos(int despachos[], int cedula, int cantidadPersonas) {
	/*
	BUSQUEDA BINARIA ADAPTADA:

	Buscar poscicion de cédula en array de Despachos.
	La poscición va de 0 hasta el tamañoDelarray-1

	Se debe tener en cuenta que el array despacho cuenta con {cedula , categoria, cantidad ... cedula , categoria, cantidad}
	Por lo que en el algoritmo de busqueda se debe ignorar la categoria y la cantidad.


	*/
	int min = 0, max = cantidadPersonas * 3 - 1;
	int position;


	do {
		// Cambia la poscicion a un valor intermedio.
		position = min + ((max - min) / 2);

		// Asegura que la posición sea unn indice de una cedula y no de una categoria o cantidad
		if (position % 3 != 0 && !(position < 3)) { position -= position % 3; }
		if (position < 3) { position = 0; }

		// Verifica si las cédulas coinciden
		if (despachos[position] == cedula) { return position; }
		if (position == 0) { break; }
		/////////////////////////////////

		// Determina el nuevo rango de posciciones
		if (despachos[position] < cedula) min = position + 3; else max = position;

	} while (min <= max);

	cout << "no se encontro la cedula " << cedula << endl;
	return -1;

}
