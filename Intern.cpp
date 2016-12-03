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

int Intern::getNum_Dias(){
	return Num_Dias;
}

string Intern::toString(){
	stringstream ss;
	ss << Usuarios::toString()<<" "<<Num_Dias;
	return ss.str();
}