#include "Personal.h"
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;
	Personal::Personal(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Ano, double Sueldo) : Usuario(Username, Password, Nombre, Edad, ID, Telefono) { 
		setAno(Ano);
		setSueldo(Sueldo);
	}
	void Personal::setAno(string a) {
		this->Ano = a;
	}
	void Personal::setSueldo(double a) {
		this->Sueldo = a;
	}
	string Personal::getAno() {
		return this->Ano;
	}
	double Personal::getSueldo() {
		return this->Sueldo;
	}
	string Personal::RefID() {
		string ref = "0:";
		ref += getUsername() + ";";
		ref += getPassword() + ";";
		ref += getNombre() + ";";
		ref += to_string(getEdad()) + ";";
		ref += getID() + ";";
		ref += getTelefono() + ";";
		ref += getAno() + ";";
		ref += to_string(getSueldo()) + ";";
		return ref;
	}
	int Personal::getType() {
		return 0;
	}
	string Personal::toString() {
		string ref = "";
		ref += "Usuario: " + getUsername() + ", ";
		ref += "Nombre: " + getNombre() + ", ";
		ref += "Edad: " + to_string(getEdad()) + ", ";
		ref += "ID: " + getID() + ", ";
		ref += "Telefono: " + getTelefono() + ", ";
		ref += "Fecha de contratacion: " + getAno() + ", ";
		ref += to_string(getSueldo()) + "";
		return ref;
	}
	void Personal::Special(int a) {

	}
