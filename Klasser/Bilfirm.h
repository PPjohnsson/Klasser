#pragma once
#include <iostream>
#include <string>
using namespace std;
class Bil {

private:
	string Bilnummer;
	int �rsmodell;
	string M�rke;
	string Senaste_servicedatum;
	int Hyrpris;

public:
	Bil();
	Bil(string Bilnummer, int �rsmodell, string M�rke, string S_s, int Hyrpris);
	~Bil();
	
	string f�Namn();

	string toString();

};