#include "Bilfirm.h"

Bil::Bil() {

	this->Bilnummer = "";
	this->�rsmodell = 0;
	this->M�rke = "";
	this->Senaste_servicedatum = "";
	this->Hyrpris = 0;

}

Bil::Bil(string Bilnum, int �rsm, string M�rk, string S_s, int Hyrp) {

	this->Bilnummer = Bilnum;
	this->�rsmodell = �rsm;
	this->M�rke = M�rk;
	this->Senaste_servicedatum = S_s;
	this->Hyrpris = Hyrp;

}

Bil::~Bil() {

	

}

string Bil::f�Namn() {

	return this->Bilnummer;

}

string Bil::toString(){

	return this->Bilnummer + "," + to_string(this->�rsmodell) + "," + this->M�rke + "," + this->Senaste_servicedatum + "," + to_string(this->Hyrpris);

}
