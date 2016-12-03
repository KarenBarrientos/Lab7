#include "Usuarios.h"
#include "Administrador.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int MenuAdmin();
int MenuManager();
int MenuIntern();

int main(){
	string text="";
	vector <Usuarios*> users;
	int opcion = 0;
	string nom_user = "admin";
	string correo = "admin@lol.com";
	string passwoordd_user = "admin";
	string fecha = "2/12/16";
	string Tip_us="";
	Tip_us="Admin";
	Usuarios* user = new Administrador(nom_user, correo,passwoordd_user,Tip_us,fecha);
	users.push_back(user);

	int Opp = 0;

	while(Opp != 1){
		string passwoordd= "";
		string tipo = "";
		int posicion = 0;

		cout << endl << "Ingrese contraseña: ";
		cin >> passwoordd;

		for (int i = 0; i < users.size(); ++i){
			if(passwoordd_user == passwoordd){
				tipo = "Admin";
			} else 
			if( dynamic_cast<Supervisor*> (users.at(i)) != NULL){
				if(passwoordd == users.at(i) ->getPassword()){
					tipo = "Supervisor";
					posicion = i;
				}
				tipo = "Supervisor";
				posicion = i;
			} else 
			if( dynamic_cast<Intern*> (users.at(i)) != NULL){
				if(passwoordd == users.at(i) ->getPassword()){
					tipo = "Intern";
					posicion = i;
				}

			} else 
			if( dynamic_cast<Manager*> (users.at(i)) != NULL){
				if(passwoordd == users.at(i) ->getPassword()){
					tipo = "Manager";
					posicion = i;
				}
			}
	
		} // fin for

		if(tipo == "Admin"){
			while((opcion = MenuAdmin()) != 3){
					if(opcion==1){
						stringstream ss;
						ofstream archivo;
						archivo.open("Users.txt");
						string NomUserAdmin = "";
						string CorreoUserAdmin = "";
						string PassUserAdmin = "";
						int Tip_user = 0;
						cout<<" ***** AGREGAR USUARIO *****"<<endl;
						cout << endl << "Ingrese nombre: ";
						cin >> NomUserAdmin;
						cout << endl << "Ingrese correo: ";
						cin >> CorreoUserAdmin;
						cout << endl << "Ingrese contraseña: ";
						cin >> PassUserAdmin;
						cout << endl << "Ingrese el tipo usuario |1-Manager , 2-Intern , 3-Supervisor|: ";
						cin >> Tip_user;

						if(Tip_user > 3 || Tip_user <= 0){
							cout << endl << "Error" << endl;
						} else{
							//PARA MANAGER
							if(Tip_user == 1){
								string Tip_user2="";
								Tip_user2="Manager";
								double sueldo=0.0;
								cout << endl << "Ingrese sueldo del Manager: ";
								cin >> sueldo;

								if(sueldo < 0){
									cout << endl << "Sea serio ombeee";
								} else{
									Usuarios* mana= new Manager(NomUserAdmin, CorreoUserAdmin,PassUserAdmin,Tip_user2,sueldo);
									users.push_back(mana);
									cout << endl << "Manager agregado :D";
								}
								
							} else 
							//PARA INTERN
							if(Tip_user == 2){
								int dias = 0;
								string Tip_user2="";
								Tip_user2="Intern";
								cout<< endl << "Ingrese numero de dias: ";
								cin >> dias;
								cout<<endl;
								if(dias < 0){
									cout << "Sea serio";
								} else{
									Usuarios* inter = new Intern(NomUserAdmin, CorreoUserAdmin,PassUserAdmin,Tip_user2,dias);
									users.push_back(inter);
									cout<< "Intern agregado :D";
								} 

							} else 
							// PARA SUPERVISOR
							if(Tip_user == 3){
								string Tip_user2="";
								Tip_user2="Supervisor";
								Usuarios* supervis = new Supervisor(NomUserAdmin, CorreoUserAdmin,PassUserAdmin,Tip_user2,0);
								users.push_back(supervis);
								cout << endl << "Supervisor agregado :D";
							}
						}

						for (int i = 0; i < users.size(); ++i){
							Supervisor* supervisores = dynamic_cast<Supervisor*>(users.at(i));
							Administrador* administradores = dynamic_cast<Administrador*>(users.at(i));
							Manager* managers = dynamic_cast<Manager*>(users.at(i));
							Intern* interns = dynamic_cast<Intern*>(users.at(i));
							
							if(supervisores!=NULL){
								text+=supervisores->toString();
							}
							else 
								if(administradores!=NULL){
								text+=administradores->toString();
							}
							else 
								if(managers != NULL){
								text+=managers->toString();
							}
							else 
								if(interns != NULL){
								text+=interns->toString();
							}
						}
						archivo.open("Users.txt");
						archivo << text;
						archivo.close();

					} // fin if

					if(opcion==2){
						int eliminar = 0;
						stringstream ss;
						ofstream archivo;
						archivo.open("Users.txt");
						cout<<"***** ELIMINAR USUARIO *****"<<endl;
						cout << endl << "Ingrese posicion a eliminar: " << endl;
						for (int i = 0; i < users.size(); ++i){
							if(i == 0){
							} else{
								cout << i << ") " << users.at(i) -> getNom_Usuario() <<  "-- " << users.at(i) -> getTipo() << endl;
							}
						}
						cin >> eliminar;
						if(eliminar <= 0){
							cout << endl << "No se puede eliminar";
						} else{
							users.erase(users.begin() + eliminar);
							cout << endl << "Usuario eliminado";
						}
						archivo.open("Users.txt");
						for (int i = 0; i < users.size(); ++i){
							Supervisor* supervisores = dynamic_cast<Supervisor*>(users.at(i));
							Administrador* administradores = dynamic_cast<Administrador*>(users.at(i));
							Manager* managers = dynamic_cast<Manager*>(users.at(i));
							Intern* interns = dynamic_cast<Intern*>(users.at(i));
							
							if(supervisores!=NULL){
								text+=supervisores->toString();
							}
							else 
								if(administradores!=NULL){
								text+=administradores->toString();
							}
							else 
								if(managers != NULL){
								text+=managers->toString();
							}
							else 
								if(interns != NULL){
								text+=interns->toString();
							}
						}
						
						archivo << text;
						archivo.close();

					}

					if(opcion==3){
						cout << endl << "Saliendo..." << endl;
						break;
					}

			}

		} else 
		if(tipo == "Manager"){
			while((opcion = MenuManager()) != 3){
					if(opcion==1){
						string NomUserAdmin = "";
						string CorreoUserAdmin = "";
						string PassUserAdmin = "";
						stringstream ss;
						ofstream archivo;
						cout << endl << "Ingrese nombre: ";
						cin >> NomUserAdmin;
						cout << endl << "Ingrese correo: ";
						cin >> CorreoUserAdmin;
						cout << endl << "Ingrese contraseña: ";
						cin >> PassUserAdmin;
						int Tip_user = 0;
						cout << endl << "Ingrese el tipo |1- Supervisor , 2- Intern|: " << endl;
						cin >> Tip_user;

						if(Tip_user > 2 || Tip_user <= 0){
							cout << endl << "Error" << endl;
						} else{
							// PARA SUPERVISOR
							if(Tip_user == 1){ 
								string Tip_user2="";
								Tip_user2="Supervisor";
								Usuarios* supervise = new Supervisor(NomUserAdmin, CorreoUserAdmin,PassUserAdmin,Tip_user2,0);
								users.push_back(supervise);
								cout << endl << "Supervisor agredado :D";
							} else 
							// PARA INTERN
							if(Tip_user == 2){
								stringstream ss;
								ofstream archivo;
								int dias = 0;
								string Tip_user2="";
								Tip_user2="Intern";
								cout << endl << "Ingrese numero de dias: ";
								cin >> dias;

								if(dias < 0){
									cout << endl << "Sea seriooo";
								} else{
									Usuarios* internn = new Intern(NomUserAdmin, CorreoUserAdmin,PassUserAdmin,Tip_user2,dias);
									users.push_back(internn);
									cout << endl << "El intern se ha agredado exitosamente.";
								} 
							} 
						}
						archivo.open("Users.txt");
						for (int i = 0; i < users.size(); ++i){
							Supervisor* supervisores = dynamic_cast<Supervisor*>(users.at(i));
							Administrador* administradores = dynamic_cast<Administrador*>(users.at(i));
							Manager* managers = dynamic_cast<Manager*>(users.at(i));
							Intern* interns = dynamic_cast<Intern*>(users.at(i));
							
							if(supervisores!=NULL){
								text+=supervisores->toString();
							}
							else 
								if(administradores!=NULL){
								text+=administradores->toString();
							}
							else 
								if(managers != NULL){
								text+=managers->toString();
							}
							else 
								if(interns != NULL){
								text+=interns->toString();
							}
						}
						archivo.open("Users.txt");
						archivo << text;
						archivo.close();

					} // fin if 1

					if(opcion==2){ 
						int eliminar = 0;
						stringstream ss;
						ofstream archivo;
						cout << endl << endl << "Ingrese posicion a eliminar:" << endl << endl;
						for (int i = 0; i < users.size(); ++i){
							if(i == 0){
							} else 
							if(dynamic_cast<Manager*> (users.at(i)) != NULL){
							}else{
								cout << "Posicion a eliminar: " << i << ") " << users.at(i) -> getNom_Usuario() <<  "-- " 
								<< users.at(i) -> getTipo() << endl;
							}
						}
						
						cin >> eliminar;

						if(eliminar <= 0 || eliminar > users.size()){
							cout << endl << "No puede borrar esa posicion" << endl;
						} else if(posicion == eliminar){
							cout << endl << "No se puede borrar" << endl;
						}else{

							if(dynamic_cast<Manager*> (users.at(eliminar)) != NULL){
								cout << endl << "No puede borrar otros Managers";
							} else{
								users.erase(users.begin() + eliminar);
								cout << endl << "Usuario eliminado";
							}
						}

						for (int i = 0; i < users.size(); ++i){
							Supervisor* supervisores = dynamic_cast<Supervisor*>(users.at(i));
							Administrador* administradores = dynamic_cast<Administrador*>(users.at(i));
							Manager* managers = dynamic_cast<Manager*>(users.at(i));
							Intern* interns = dynamic_cast<Intern*>(users.at(i));
							
							if(supervisores!=NULL){
								text+=supervisores->toString();
							}
							else 
								if(administradores!=NULL){
								text+=administradores->toString();
							}
							else 
								if(managers != NULL){
								text+=managers->toString();
							}
							else 
								if(interns != NULL){
								text+=interns->toString();
							}
						}
						archivo.open("Users.txt");
						archivo << text;
						archivo.close();

					} // fin if 2
					if(opcion==3){
						cout << endl << "Saliendo..." << endl;
						break;
					}
		
			}

		} else 
		if(tipo == "Intern"){
			while((opcion = MenuIntern()) != 3){
					if(opcion==1){ 
						stringstream ss;
						ofstream archivo;
						for (int i = 0; i < users.size(); ++i){
							if(i == 0){
							} else 
							if(dynamic_cast<Manager*> (users.at(i)) != NULL){

							}else 
							if(dynamic_cast<Supervisor*> (users.at(i)) != NULL){

							} else{
								cout << "Posicion a eliminar: " << i << ") " << users.at(i) -> getNom_Usuario() <<  "-- "<< users.at(i) -> getTipo() << endl;
							}
						}
						
					}
					if(opcion==2){ 
						// ELIMINAR
						int eliminar = 0;
						stringstream ss;
						ofstream archivo;
						string text="";
						cout << endl << endl << "Ingrese posicion a eliminar" << endl;
						for (int i = 0; i < users.size(); ++i){
							if(i == 0){
							} else 
							if(dynamic_cast<Manager*>(users.at(i)) != NULL){
							}else 
							if(dynamic_cast<Supervisor*>(users.at(i)) != NULL){
							} else{
								cout << "Posicion para borrar: " << i << ") " << users.at(i) -> getNom_Usuario() <<  "-- "<< users.at(i) -> getTipo() << endl;
							}
						}
						
						cin >> eliminar;

						if(eliminar <= 0 || eliminar > users.size()){
							cout << endl << "No puede borrar esa posicion" << endl;
						} else if(posicion == eliminar){
							cout << endl << "No se puede borrar si mismo" << endl;
						}else{
							if( dynamic_cast<Intern*> (users.at(eliminar)) != NULL){
								users.erase(users.begin() + eliminar);
								cout << endl << "El usuario ha sido borrado exitosamente.";
							} else{
								cout << endl << "Solo puede borrar interns";
							}
							
						}

						for (int i = 0; i < users.size(); ++i){
							Supervisor* supervisores = dynamic_cast<Supervisor*>(users.at(i));
							Administrador* administradores = dynamic_cast<Administrador*>(users.at(i));
							Manager* managers = dynamic_cast<Manager*>(users.at(i));
							Intern* interns = dynamic_cast<Intern*>(users.at(i));
							
							if(supervisores!=NULL){
								text+=supervisores->toString();
							}
							else 
								if(administradores!=NULL){
								text+=administradores->toString();
							}
							else 
								if(managers != NULL){
								text+=managers->toString();
							}
							else 
								if(interns != NULL){
								text+=interns->toString();
							}
						}
						archivo.open("Users.txt");
						archivo << text;
						archivo.close();


					}
					if(opcion==3){
						cout << endl << "Saliendo..." << endl;
						break;
					}
			
			}
		} 

		cout << endl << "Esta seguro que desea salir? |1- si , 2- no" <<endl;
		cin >> Opp;
	}
	for (int i = 0; i < users.size(); ++i){
		delete users[i];
	}

	return 0;
}

int MenuAdmin(){
	int opcion = 0;
	cout << endl << endl << "******** Menu Administrador ********" << endl;
	cout<<endl<< "Ingrese su opcion: " << endl;
	cout<< "1. Crear usuario" << endl
		<< "2. Eliminar usuario" << endl
		<< "3. Salir" << endl << endl;
		cin >> opcion;

	return opcion;
}

int MenuManager(){
	int opcion = 0;
	cout << endl << endl << "******** Menu Manager********" << endl;
	cout<<endl<< "Ingrese su opcion: " << endl;
	cout<< "1. Crear " << endl
		<< "2. Eliminar" << endl
		<< "3. Salir" << endl << endl;
		cin >> opcion;

	return opcion;
}

int MenuIntern(){
	int opcion = 0;
	cout << endl << endl << "******** Menu Intern********" << endl;
	cout<<endl<< "Ingrese su opcion: " << endl;
	cout << "1. Listar " << endl
		<< "2. Eliminar " << endl
		<< "3. Salir" << endl << endl;
		cin >> opcion;
	return opcion;
}
