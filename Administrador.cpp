#include "Administrador.h"
#include <iostream>
#include <string>
#include "Personal.h"
using namespace std;
	Administrador::Administrador(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Ano, double Sueldo, int Despedidos, int Contratados) : Personal (Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo) { 
		setDespedidos(Despedidos);
		setContratados(Contratados);
	}
	void Administrador::setDespedidos(int a) {
		this->Despedidos = a;
	}
	void Administrador::setContratados(int a) {
		this->Contratados = a;
	}
	int Administrador::getDespedidos() {
		return this->Despedidos;
	}
	int Administrador::getContratados() {
		return this->Contratados;
	}
	string Administrador::RefID() {
		string ref = "1:";
		ref += getUsername() + ";";
		ref += getPassword() + ";";
		ref += getNombre() + ";";
		ref += to_string(getEdad()) + ";";
		ref += getID() + ";";
		ref += getTelefono() + ";";
		ref += getAno() + ";";
		ref += to_string(getSueldo()) + ";";
		ref += to_string(getDespedidos()) + ";";
		ref += to_string(getContratados()) + ";";
		return ref;
	}
	int Administrador::getType() {
		return 1;
	}
	void Administrador::Special(int a) {
		setContratados(getContratados()+a);
	}
