#include "Usuarios.h"
#include "Administrador.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

int menu();


int main(){

	int opcion=0;
	string nom_user,pass;

	vector<Usuarios*> users;
	vector<Administrador*> admin;
	vector<Supervisor*> supervis;
	vector<Manager*> manager;

	bool esAdmin=false,esManager=false,esSupervisor=false,esIntern=false;

	users.push_back(new Administrador("Aceituno", "aceituno@lol.com", "Aceituno","2/12/16"));

	while ( (opcion = menu()) != 5){
		cout<<"Ingrese nombre de usuario: "<<endl;
		cin>>nom_user;
		cout<<"Ingrese contraseña: "<<endl;
		cin>>pass;

		for (int i=0; i<users.size(); i++){
			cout << "Encontrado en la posicion " << i+1 << endl;
			cout << users[i]->getNom_Usuario();

		}
		//Usuarios* temporalUser= dynamic_cast<Administrador*>(users[i]);

		


	}

	for (int i=0; i<users.size(); i++){
        delete users[i];
	}
 

	return 0;
}


int menu(){
    cout<<endl;
    cout <<"***** MENU ***** "<< endl 
         <<"1. Agregar Usuarios" << endl
         << "2. Agregar Manager" << endl
         << "3. Agregar  Intern" << endl
         <<"4. Agregar Supervisor"<<endl
         << "5. Salir" << endl;
    int opcion;
    do{
        cin >> opcion;
        if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5)
            cerr << "Introduzca un valor correcto" << endl;
    }while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);

    return opcion;
}