#include <iostream>
#include "Bilfirm.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <conio.h>
using namespace std;

void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}


vector<Bil>Bil_register;

vector<string> delaStr�ng(string str, char delare);

int GetInput() {

	int choice;
	cin >> choice;
	return choice;

}

int main() {

	setWesternEuropeanCodePage();


	ifstream file("register.txt");
	

	vector<string> temp; //Skapar en tempor�r vector

	string rad = "";

	while (getline(file, rad))
	{
		if (rad != "")
		{
			temp = delaStr�ng(rad, ',');	//Ger en "text" och tecknet komma till delaStr�ng. Efter delaStr�ng har gjort sitt kommer det skickas in i temp.
			Bil_register.push_back(Bil(temp[0], stoi(temp[1]), temp[2], temp[3], stoi(temp[4]))); //Skapar ett objekt av klassen Bil genom att mata in parametrarna av temp positionerna [1], [2], [3], [4]
			//in i konstruktorn f�r klassen Bil. Sedan l�gger den det nya v�rdet in i vektorn Bil_register.
		}
	}

	file.close();

	
	int choice = 0;

	bool loop = true;

	while(loop){

	cout << "Det finns " << Bil_register.size() << " bilar i bilregistret: " << endl << endl;
	cout << endl << "Bil register:" << endl;
	cout << "1. L�gg till ny bil     " << endl;
	cout << "2. Ta bort bil          " << endl;
	cout << "3. Lista bilar          " << endl;
	cout << "4. L�s in bilar fr�n fil" << endl;
	cout << "5. Spara bilar till fil " << endl;
	cout << "0. Avsluta              " << endl;

	cout << "V�lj alternativ: ";

	choice = GetInput();

	switch (choice) {
	case 0: {
		loop = false;
		break;
	}
	case 1: {

		string Bilnummer_ny;

		cout << "Registering nummer: ";
		cin >> Bilnummer_ny;

		int �rsmodell_ny;
		cout << "�rmodel: ";
		cin >> �rsmodell_ny;

		string M�rke_ny;
		cout << "M�rke: ";
		cin >> M�rke_ny;

		string Senaste_servicedatum_ny;
		cout << "Senaste servicedatum: ";
		cin >> Senaste_servicedatum_ny;

		int Hyrpris_ny;
		cout << "Hyr pris: ";
		cin >> Hyrpris_ny;

		Bil_register.push_back(Bil(Bilnummer_ny, �rsmodell_ny, M�rke_ny, Senaste_servicedatum_ny, Hyrpris_ny)); //Skapar ett nytt objekt av klassen Bil genom att man matar in parametrarna i konstruktorn f�r klassen bil.
																												//Sedan l�ggs det nya objektet in i vektorn Bil_register.
		cout << endl << "Du har lagt till en bil i registret" << endl;

		Sleep(5000);
		break;
	}
	case 2: {
		cin.ignore(); // Ignorera kvarvarande newline-tecken
		string namn;
		cout << "Vilken bil vill du ta bort? : ";
		getline(cin, namn); // L�s in hela raden som en str�ng
		
		bool removed = false;
		for (int i = 0; i < Bil_register.size(); i++) {

			if (Bil_register[i].f�Namn() == namn) { //Kollar ifall bilens registerings nummet som �r p� plats [i] i vektorn �r samma som registerings nummret man angav.
				Bil_register.erase(Bil_register.begin() + i); //Tar bort registerings nummet som �r p� plats [i] i vektorn
				removed = true;
				break;

			}

		}
		if (removed) {
			cout << "Bilen har tagits bort." << endl;
		}
		else {
			cout << "Ingen bil med det namnet hittades." << endl;
		}

		break;
	}
	case 3: {

		cout << endl << "H�r �r en lista p� alla bilar i registret: " << endl << endl;
		
		for (int i = 0; i < Bil_register.size(); i++) {

			cout << Bil_register[i].toString() << endl; //Skriver ut alla bilar i Bil_registerings vektorn med hj�lp av toString().

		}

		break;
	}
	case 4: {
	
		string filnamn;
		cout << "Ange filnamn: ";
		cin >> filnamn;

		ifstream fil(filnamn);

		vector<string> temp; //Skapar en tempor�r vector

		string rad = "";

		while (getline(fil, rad))
		{
			if (rad != "")
			{
				temp = delaStr�ng(rad, ',');	//Ger en "text" och tecknet komma till delaStr�ng. Efter delaStr�ng har gjort sitt kommer det skickas in i temp.
				Bil_register.push_back(Bil(temp[0], stoi(temp[1]), temp[2], temp[3], stoi(temp[4]))); //Skapar ett objekt av klassen Bil genom att mata in parametrarna av temp positionerna [1], [2], [3], [4]
																									  //in i konstruktorn f�r klassen Bil. Sedan l�gger den det nya v�rdet in i vektorn Bil_register.
			}
		}
		fil.close();

		break;
	}
	case 5: {


		ofstream file("register.txt");

		if (file.is_open()) {

			for (int i = 0; i < Bil_register.size(); i++) {
				file << Bil_register[i].toString() << endl; //Kommer att g� igenom vektorn Bil_register och L�gga till bilarna den hittar till en fil.
															//Anv�nder sig utav toString() (konstruktorn toString()???) f�r att g�r "raden" till en str�ng.
			}

		}

		file.close();
		break;
	}
	}
	
	}
}
vector<string> delaStr�ng(string str, char delare) //Skapar en vector som tar in en string och en char.
{
	vector<string> resultat;
	string nuvarande = "";

	for (int i = 0; i < str.size(); i++) //En for loop som kommer att g� tills str tar slut med bokst�ver.
	{
		if (str[i] == delare) //Kollar ifall str[i] en bokstav �r lika med parametern som kom in i char delare.
		{
			if (nuvarande != "") //Om nuvarande inte �r lika med "" s� �r if ok.
			{
				resultat.push_back(nuvarande); //Tar det som finns p� str�ngen nuvarande och skickar in det i vectorn resultat.
				nuvarande = "";				   //Sedan tar du bort det som finns i nuvarande get att s�ga att nuvarande �r like med "".
			}
			continue;	//Ifall nuvarande �R LIKA MED "" forts�tt.
		}
		nuvarande += str[i]; //Ifall en bokstav (str[i]) inte �r lika med parameterns i char delare. Ger skickar man bokstaven (str[i]) till str�ngen nuvarande.
	}

	if (nuvarande.size() != 0)
	{
		resultat.push_back(nuvarande);
	}
	return resultat; //returnerar vectorn resultat
}