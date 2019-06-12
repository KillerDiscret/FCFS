#include<iostream>
using namespace std;
int main() {
	int  Espera[100], Arrivo[100], Duracion[100];
	int i, j, np, temp, temp1, suma, sumaEspera;
	float media;
	temp = temp1 = suma = sumaEspera = 0;

	//------------------Ingreso de valores en los vectores---------------------------
	cout << "Ingrese el numero de procesos: "; cin >> np;
	for (i = 0; i < np; i++)
	{
		cout << "\nIngrese el tiempo de llegada del proceso " << i + 1 << " :";
		cin >> Arrivo[i];
		cout << "Ingrese el tiempo de duracion del proceso " << i + 1 << " :";
		cin >> Duracion[i];
	}
	//-----------------Ordenamiento basado al tiempo de llegada---------------------
	for (j = 0; j < np - 1; j++)
	{
		for (i = 0; i < np - 1; i++)
		{
			if (Arrivo[i] > Arrivo[i + 1])
			{
				temp = Arrivo[i];
				Arrivo[i] = Arrivo[i + 1];
				Arrivo[i + 1] = temp;
				temp1 = Duracion[i];
				Duracion[i] = Duracion[i + 1];
				Duracion[i + 1] = temp1;
			}
		}
	}
	//-------------Imprimiendo los contenidos de los vectores ordenados-----------
	cout << "\n Tiempo de llegada: ";
	for (j = 0; j < np; j++)
	{
		cout << Arrivo[j];
	}
	cout << "\n Tiempo de espera: ";
	for (j = 0; j < np; j++)
	{
		cout << Duracion[j];
	}
	cout << endl;
	Espera[0] = 0;

	for (j = 1; j < np; j++)
	{
		suma += Duracion[j - 1];
		Espera[j] = suma - Arrivo[j];
		sumaEspera += Espera[j];
	}


	//------------------------Calculo del tiempo promedio--------------------------
	media = (sumaEspera / (np - 1));
	cout << " El tiempo promedio es: " << media << endl;

	system("PAUSE");
	return 0;
}




