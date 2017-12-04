#pragma once
#include <iostream>
#include <string>
using namespace std;
class Usuario {
	private: 
		string Username;
		string Password;
		string Nombre;
		int Edad;
		string ID;
		string Telefono;
	public: 
		Usuario(string, string, string, int, string, string);
		void  setUsername(string);
		void  setPassword(string);
		void  setNombre(string);
		void  setEdad(int);
		void  setID(string);
		void  setTelefono(string);
		string getUsername();
		string getPassword();
		string getNombre();
		int getEdad();
		string getID();
		string getTelefono();
};
