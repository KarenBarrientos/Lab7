#include "Intern.h"
#include "Usuarios.h"

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Intern::Intern(string Nom_Usuario,string Correo,string Password,string Tipo,int Num_Dias):Usuarios(Nom_Usuario,Correo,Password,Tipo){
  this->Num_Dias = Num_Dias;
}
Intern::~Intern(){
}

string Intern::toString(){
	stringstream ss;
	ss << Usuarios::toString();
	return ss.str();
}