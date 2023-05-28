#include "Bilfirm.h"

Bil::Bil() {

	this->Bilnummer = "";
	this->Årsmodell = 0;
	this->Märke = "";
	this->Senaste_servicedatum = "";
	this->Hyrpris = 0;

}

Bil::Bil(string Bilnum, int Årsm, string Märk, string S_s, int Hyrp) {

	this->Bilnummer = Bilnum;
	this->Årsmodell = Årsm;
	this->Märke = Märk;
	this->Senaste_servicedatum = S_s;
	this->Hyrpris = Hyrp;

}

Bil::~Bil() {

	

}

string Bil::fåNamn() {

	return this->Bilnummer;

}

string Bil::toString(){

	return this->Bilnummer + "," + to_string(this->Årsmodell) + "," + this->Märke + "," + this->Senaste_servicedatum + "," + to_string(this->Hyrpris);

}
