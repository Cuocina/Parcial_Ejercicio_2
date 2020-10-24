#include <iostream>
using namespace std;

// Precondicion: @items es un vector que tiene un rango valido entre @indiceComienzo y @indiceFin
// Postcondicion: Devuelve la cantidad de elementos en @items que que tienen como valor true
// desde @indiceComienzo a @indiceFin
int ContarPositivos(bool items[], int indiceComienzo, int indiceFin);

/* Pruebas unitarias */
void EjecutarPruebasUnitarias();
void TestEjemplo1();
void TestEjemplo2();
void TestEjemplo3();
void TestEjemplo4();
void TestEjemplo5();

/* Auxiliares */
void MostrarResultado(int valorObtenido, int valorEsperado, const char nombreDeEjemplo[]);


int main() {
	EjecutarPruebasUnitarias();

	return 0;
}

int ContarPositivos(bool items[], int indiceComienzo, int indiceFin) {
	int positivos = 0;
	if (indiceComienzo >= indiceFin) {
		if (items[indiceComienzo] == true)
			positivos++;
	}
	else {
		int indiceMitad =  indiceComienzo + (indiceFin - indiceComienzo) /2;
		int positivosPrimeraMitad = ContarPositivos(items, indiceComienzo, indiceMitad);
		int positivosSegundaMitad = ContarPositivos(items, indiceMitad + 1, indiceFin);
		positivos = positivos + positivosPrimeraMitad + positivosSegundaMitad;
	}
	return positivos;
}

void EjecutarPruebasUnitarias()
{
	TestEjemplo1();
	TestEjemplo2();
	TestEjemplo3();
	TestEjemplo4();
	TestEjemplo5();
}

void TestEjemplo1()
{
	bool items[] = {1,0,1,0,0,1,0,1,0};
	int valorEsperado = 4;
	int valorObtenido=ContarPositivos(items,0,9);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo1");
}

void TestEjemplo2()
{
	bool items[] = { 0,0,0,1,1,1,0,0,1,0,1 };
	int valorEsperado = 3;
	int valorObtenido = ContarPositivos(items, 3, 5);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo2");
}

void TestEjemplo3()
{
	bool items[] = { 0 };
	int valorEsperado = 0;
	int valorObtenido = ContarPositivos(items, 0, 0);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo3");
}

void TestEjemplo4()
{
	bool items[] = { 0,0,0,0,0,1,0,0,0,0, };
	int valorEsperado = 1;
	int valorObtenido = ContarPositivos(items, 0, 5);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo4");
}

void TestEjemplo5()
{
	bool items[] = { 0,0,0,0,0,1,0,0,0,0, };
	int valorEsperado = 0;
	int valorObtenido = ContarPositivos(items, 0, 4);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo5");
}

void MostrarResultado(int valorObtenido, int valorEsperado, const char nombreDeEjemplo[])
{
	bool funciona = true;
	if (valorObtenido == valorEsperado)
	{
		cout << nombreDeEjemplo << ": OK." << endl;
	}
	else
	{
		cout << nombreDeEjemplo << ": Error." << endl;
		cout << "Se esperaba obtener " << endl;
		cout << valorEsperado << endl;
		cout << " se obtuvo " << endl;
		cout << valorObtenido << endl;
	}
}