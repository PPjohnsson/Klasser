#pragma once
#include <iostream>
#include <string>
using namespace std;
class Bil {

private:
	string Bilnummer;
	int Årsmodell;
	string Märke;
	string Senaste_servicedatum;
	int Hyrpris;

public:
	Bil();
	Bil(string Bilnummer, int Årsmodell, string Märke, string S_s, int Hyrpris);
	~Bil();
	
	string fåNamn();

	string toString();

};