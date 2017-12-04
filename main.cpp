#include <string>
#include <iostream>
#include "Usuario.h"
#include "Personal.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Chef.h"
#include "Lavaplatos.h"
#include "Mesero.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <exception>
#include <limits>

using namespace std;
bool isLogin(vector<Personal*>*, string, string, Personal*, vector<Administrador*>*);
string CurrentTime();
double SueldoProm(vector<Personal*>* List);
double SueldoMenor(vector<Personal*>* List);
double SueldoMayor(vector<Personal*>* List);
vector<Personal*>* UpdateList(vector<Personal*>*, vector<Administrador*>*, vector<Chef*>*, vector<Lavaplatos*>*, vector<Mesero*>*);
void save(vector<Personal*>*);
void load(vector<Personal*>*, vector<Administrador*>*, vector<Chef*>*, vector<Lavaplatos*>*, vector<Mesero*>*);
int main() {
	vector<Cliente*>* vCliente = new vector<Cliente*>();

	vector<Personal*>* vPersonal = new vector<Personal*>();
	vector<Mesero*>* vMesero = new vector<Mesero*>();
	vector<Administrador*>* vAdmin = new vector<Administrador*>();
	vector<Chef*>* vChef = new vector<Chef*>();
	vector<Lavaplatos*>* vLavaplatos = new vector<Lavaplatos*>();
	Personal* UsuarioActual;
	int op = 0;
	int opA = 0;
	int opB = 0;
	bool End = true;
	string Usuario;
	string Password;
	while (End) {
		cout << "Ingrese password y Contraseña \n";
		cin >> Usuario;
		cin >> Password;
		load(vPersonal, vAdmin, vChef, vLavaplatos, vMesero);
		cout << "Entre Aqui! \n";
		if (isLogin(vPersonal, Usuario, Password, UsuarioActual, vAdmin)) {
			bool login = true;
			for (int i = 0;i<vPersonal->size();i++) {
				if (Usuario==vPersonal->at(i)->getUsername()) {
					UsuarioActual = vPersonal->at(i);
				}
			}
			while (login) {
				switch (UsuarioActual->getType()) {
					case 1: {
						cout << "1) Contratar Empleado\n";
						cout << "2) Despedir Empleado\n";
						cout << "3) Conseguir Empleado con Menor Sueldo\n";
						cout << "4) Agregar Platillo Al Mesero\n";
						cout << "5) Conseguir el empleado con mayor Sueldo\n";
						cout << "6) Conseguir el promedio de todos los empleados\n";
						cin >> op;
						switch (op) {
							case 1: {
								cout << "De que tipo? \n";
								cout << "1) Administrador\n";
								cout << "2) Chef \n";
								cout << "3) Lavaplatos \n";
								cout << "4) Mesero \n";
								cout << "5) Cliente \n";
								cin >> opA;
								string Username;
								string Password;
								int Edad;
								string ID;
								string Telefono;
								string Nombre;
								double Sueldo;
								cout << "Ingrese Usuario \n";
								cin >> Username;
								cout << "Ingrese Password \n";
								cin >> Password;
								cout << "Ingrese Nombre \n";
								cin >> Nombre;
								cout << "Ingrese Edad \n";
								cin >> Edad;
								ID = "1";
								cout << "Ingrese Telefono \n";
								cin >> Telefono;
								cout << "Ingrese Sueldo \n";
								cin >> Sueldo;
								switch (opA) {
									case 1: {
		Administrador* A = new Administrador(Username, Password, Nombre, Edad, "123", Telefono, CurrentTime(), Sueldo, 0, 0);
										vAdmin->push_back(A);
										vPersonal->push_back(A);
										UsuarioActual->Special(1);
									} break;
									case 2: {
										string Platillo;
										cout << "Ingrese Platillo: \n";
										cin >> Platillo;
				Chef* A = new Chef(Username, Password, Nombre, Edad, ID, Telefono, CurrentTime(), Sueldo, Platillo);
										vChef->push_back(A);
										vPersonal->push_back(A);
										UsuarioActual->Special(1);
									} break;
									case 3: {
				Lavaplatos* A = new Lavaplatos(Username, Password, Nombre, Edad, ID, Telefono, CurrentTime(), Sueldo, 50);
										vLavaplatos->push_back(A);
										vPersonal->push_back(A);
										UsuarioActual->Special(1);
									} break;
									case 4: {
				Mesero* A = new Mesero(Username, Password, Nombre, Edad, ID, Telefono, CurrentTime(), Sueldo);
										vMesero->push_back(A);
										vPersonal->push_back(A);
										UsuarioActual->Special(1);
									} break;
								}
							} break;
							case 2: {
							
							} break;
							case 3: {
								vPersonal = UpdateList(vPersonal, vAdmin, vChef, vLavaplatos, vMesero);
								cout << "El empleado con menor Sueldo es: " << SueldoMenor(vPersonal) << "\n";	
							} break;
							case 4: {
								string Platillo;
								int opC;
								cout << "Ingrese Platillo a entregar: \n";
								cin >> Platillo;
								cout << "A quien? \n";
								for (int i = 0;i<vMesero->size();i++) {
									cout << i << ") " << vMesero->at(i)->toString() << "\n";
								}
								cin >> opC;
								vMesero->at(opC)->getPlatillos()->push_back(Platillo);
							} break;
							case 5: {
								vPersonal = UpdateList(vPersonal, vAdmin, vChef, vLavaplatos, vMesero);
								cout << "El sueldo promedio es de: " << SueldoProm(vPersonal) << "\n";
							} break;
							case 6: {
								vPersonal = UpdateList(vPersonal, vAdmin, vChef, vLavaplatos, vMesero);
								cout << "El empleado con mayor Sueldo es: " << SueldoMayor(vPersonal) << "\n";
							} break;
							case 7: { 
								login = false; 
							} break;
						}
					} break;
					case 2: {
						int Motivacion;
						int EoG;
						for (int i = 0;i<vLavaplatos->size();i++) {
							cout << i <<") " << vLavaplatos->at(i)->toString() << "\n";
						}
						cout << "\n";
						cout << "Elegir cual lavaplatos? \n";
						cin >> opB;
						Lavaplatos* LP = vLavaplatos->at(opB);
						cout << "Gritar o elogiar? \n";
						cout << "1) Elogiar, 2) Gritar 3) logout \n";
						cin >> EoG;
						if (EoG != 3) {
							cout << "Cuantos puntos de Motivacion?\n";
							cin >> Motivacion;
						} else  {
							Motivacion = 0;
						}
						switch (EoG) {
							case 1: {
								LP->setMotivacion(LP->getMotivacion()+Motivacion);	
							} break;
							case 2: {
								LP->setMotivacion(LP->getMotivacion()-Motivacion);
							} break;
							case 3: { 
								login = false; 
							} break;
						}
					} break;
					case 3: {
						int Cantidad;
						//Lavaplatos* UA = dynamic_cast<Lavaplatos*>(UsuarioActual);
						cout << "Ingrese opcion \n";
						cout << "1) Pedir Aumento \n";
						cout << "2) Renunciar \n";
						cout << "3) logout \n";
						cin >> op;
						switch (op) {
							case 1: {
								cout << "A cuanto? \n";
								cin >> Cantidad;
								if (UsuarioActual->getSueldo()>Cantidad) {
									UsuarioActual->setSueldo(Cantidad);
								} 
							} break;
							case 2: {

							} break;
							case 3: {
								login = false;
							} break;
						}
					} break;
					case 4: {
						Mesero* M = dynamic_cast<Mesero*>(UsuarioActual);
						cout << "Bienvenido Mesero \n";
						cout << "Platos por entregar: \n";
						UsuarioActual->Special(1);
						cout << "1) Entregar todo?, 2) Entregar especifico, 3) logout\n";
						cin >> op;
						switch (op) {
							case 1: {
								M->getPlatillos()->clear();
							} break;
							case 2: {
								int opD;
								cout << "Cual platillo? \n";
								cin >> opD;
								M->getPlatillos()->erase(M->getPlatillos()->begin()+opD);
							} break;
							case 3: {
								login = false;
							} break;
						}
					} break;
				}
			}
		} else {
			cout << "Login incorrecto \n";
		}
		cout << "Salir? 1) si, 2) no \n";
		int Salir;
		cin >> Salir;
		End = (Salir == 2);
	}
	cout << "Cerrando \n";
	vPersonal = UpdateList(vPersonal, vAdmin, vChef, vLavaplatos, vMesero);
	save(vPersonal);
	for (int i = 0;i<vCliente->size();i++) {
		delete vCliente->at(i);
	}
	for (int i = 0;i<vPersonal->size();i++) {
		delete vPersonal->at(i);
	}
	delete vCliente;
	delete vPersonal;

	return 0;
}
bool isLogin(vector<Personal*>* List, string Usuario, string Password, Personal* UserActual, vector<Administrador*>* vAdmin) {
	if (List->empty()) {
		cout << "La lista esta vacia, se va crear un nuevo usuario \n";
		cout << "Se usara los Campos ingresados como Usuario, Password, y Nombre\n";
		bool NoError = true;
		int Edad;
		string ID;
		string Telefono;
		double Sueldo;
		int Despedidos;
		int Contratados;
		while (NoError) {
			try {
				cout << "Ingrese Edad \n";
				cin >> Edad;
				ID = "0";
				cout << "Ingrese Telefono \n";
				cin >> Telefono;
				cout << "Ingrese Sueldo \n";
				cin >> Sueldo;
				Despedidos = 0;
				Despedidos = 0;
				NoError = false;
			} catch (exception e) {
				cout << "Error, ingrese otra vez";
			}
		}
		Administrador* A = new Administrador(Usuario, Password, Usuario, Edad, ID, Telefono, CurrentTime(), Sueldo, Despedidos, Contratados);
		vAdmin->push_back(A);
		List->push_back(A);
		return true;
	}
	//cout << "Size: " << List->size() << "\n";
	for (int i = 0;i<List->size();i++) {
		//cout << List->at(i)->getUsername() +"=="+Usuario + "\n";
		//cout << List->at(i)->getPassword() +"=="+Password + "\n";
		if ((Usuario == List->at(i)->getUsername())&&(Password == List->at(i)->getPassword())) {
			UserActual = List->at(i);		
			return true;
		}
	}
	return false;
}
string CurrentTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
	std::string str(buffer);
	return str;
}
void load(vector<Personal*>* list, vector<Administrador*>* vAdmin, vector<Chef*>* vChef, vector<Lavaplatos*>* vLav, vector<Mesero*>* vMesero) {
	ifstream Archivo;
	Archivo.open("SaveData.txt");
	string line;
	while(getline(Archivo, line)) {
		int ID;
		string b;
		b += line.at(0);
		ID = stoi(b);
		//cout << "ID: " << ID << "\n";
		vector<string> Atr;
		string a = "";
		//cout << line.size();
		for (int i = 2;i<line.size();i++) {
			if (line.at(i) == ';') {
				Atr.push_back(a);
				a = "";
			} else {
				a += line.at(i);
			}
		}
		switch (ID) {
			case 1: {
				string Username = Atr.at(0);
				string Password = Atr.at(1);
				string Nombre = Atr.at(2);
				int Edad = stoi(Atr.at(3));
				string ID = Atr.at(4);
				string Telefono = Atr.at(5);
				string Ano = Atr.at(6);
				double Sueldo = stod(Atr.at(7));
				int Despedidos = stoi(Atr.at(8)); 
				int Contratados = stoi(Atr.at(9));
				Administrador* p = new Administrador(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo, Despedidos, Contratados);
				list->push_back(p);
				vAdmin->push_back(p);
				
			} break;
			case 2: {
				string Username = Atr.at(0);
				string Password = Atr.at(1);
				string Nombre = Atr.at(2);
				int Edad = stoi(Atr.at(3));
				string ID = Atr.at(4);
				string Telefono = Atr.at(5);
				string Ano = Atr.at(6);
				double Sueldo = stod(Atr.at(7));
				string Platillo = Atr.at(8); 
				Chef* p = new Chef(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo, Platillo);
				list->push_back(p);
				vChef->push_back(p);
			} break;
			case 3: {
				string Username = Atr.at(0);
				string Password = Atr.at(1);
				string Nombre = Atr.at(2);
				int Edad = stoi(Atr.at(3));
				string ID = Atr.at(4);
				string Telefono = Atr.at(5);
				string Ano = Atr.at(6);
				double Sueldo = stod(Atr.at(7));
				int Motivacion = stoi(Atr.at(8));
				Lavaplatos* p = new Lavaplatos(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo, Motivacion);
				vLav->push_back(p);
				list->push_back(p);
			} break;
			case 4: {
				string Username = Atr.at(0);
				string Password = Atr.at(1);
				string Nombre = Atr.at(2);
				int Edad = stoi(Atr.at(3));
				string ID = Atr.at(4);
				string Telefono = Atr.at(5);
				string Ano = Atr.at(6);
				double Sueldo = stod(Atr.at(7));
				Mesero* p = new Mesero(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo);
				vMesero->push_back(p);
				list->push_back(p);
			} break;
		}
	}

}
void save(vector<Personal*>* List) {
	ofstream Archivo;
	Archivo.open("SaveData.txt");
	for (int i = 0;i<List->size();i++) {
		Archivo << List->at(i)->RefID() << "\n";
	}
	Archivo.close();
}
double SueldoProm(vector<Personal*>* List) {
	double prom = 0;
	for (int i = 0;i<List->size();i++) {
		prom += List->at(i)->getSueldo();
	}
	return (prom/List->size());
}
double SueldoMenor(vector<Personal*>* List) {
	double Menor = std::numeric_limits<double>::max();
	double d = 0;
	for (int i = 0;i<List->size();i++) {
		d = List->at(i)->getSueldo();
		if (d < Menor) {
			Menor = d;
		}
	}
	return Menor;
}
double SueldoMayor(vector<Personal*>* List) {
	double Mayor = 0;
	double d = 0;
	for (int i = 0;i<List->size();i++) {
		d = List->at(i)->getSueldo();
		if (d > Mayor) {
			Mayor = d;
		}
	}
	return Mayor;
}
 vector<Personal*>* UpdateList(vector<Personal*>* List, vector<Administrador*>* a, vector<Chef*>* b, vector<Lavaplatos*>* c, vector<Mesero*>* d) {
	List->clear();
	/*cout << "updating list \n";
	cout << "size a:"+a->size();
	cout << "size b:"+b->size();
	cout << "size c:"+c->size();
	cout << "size d:"+d->size();*/

	for (int i = 0;i<a->size();i++) {
		List->push_back(dynamic_cast<Personal*>(a->at(i)));
		//cout << a->at(i)->RefID();
	}
	for (int i = 0;i<b->size();i++) {
		List->push_back(dynamic_cast<Personal*>(b->at(i)));
		//cout << b->at(i)->RefID();
	}
	for (int i = 0;i<c->size();i++) {
		List->push_back(dynamic_cast<Personal*>(c->at(i)));
		//cout << c->at(i)->RefID();
	}
	for (int i = 0;i<d->size();i++) {
		List->push_back(dynamic_cast<Personal*>(d->at(i)));
		//cout << d->at(i)->RefID();
	}
	for (int i = 0;i<List->size();i++) {
		//cout << List->at(i)->RefID();
	}
	return List;
}
