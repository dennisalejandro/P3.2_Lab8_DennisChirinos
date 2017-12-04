#include "Chef.h"
#include <iostream>
#include <string>
#include "Personal.h"
using namespace std;
	Chef::Chef(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Ano, double Sueldo, string Platillo) : Personal(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo) { 
		setPlatillo(Platillo);
	}
	void Chef::setPlatillo(string a) {
		this->Platillo = a;
	}
	string Chef::getPlatillo() {
		return this->Platillo;
	}
	string Chef::RefID() {
		string ref = "2:";
		ref += getUsername() + ";";
		ref += getPassword() + ";";
		ref += getNombre() + ";";
		ref += to_string(getEdad()) + ";";
		ref += getID() + ";";
		ref += getTelefono() + ";";
		ref += getAno() + ";";
		ref += to_string(getSueldo()) + ";";
		ref += getPlatillo() + ";";
		return ref;
	}
	int Chef::getType() {
		return 2;
	}
