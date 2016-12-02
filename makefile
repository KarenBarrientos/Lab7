main:	main.o Usuarios.o Supervisor.o Administrador.o Manager.o Intern.o
	g++ main.o Usuarios.o Supervisor.o Administrador.o Manager.o Intern.o -o main

main.o:	main.cpp Usuarios.h Supervisor.h Administrador.h Manager.h Intern.h
	g++ -c main.cpp 

Usuarios.o:	Usuarios.h Usuarios.cpp 
	g++ -c Usuarios.cpp

Supervisor.o:	Supervisor.h Supervisor.cpp Administrador.h Manager.h Usuarios.h
	g++ -c Supervisor.cpp

Administrador.o:	Administrador.h Administrador.cpp Usuarios.h 
	g++ -c Administrador.cpp

Manager.o:	Manager.h Manager.cpp Usuarios.h
	g++ -c Manager.cpp

Intern.o:	Intern.h Intern.cpp 
	g++ -c Intern.cpp

clean:
	rm -f *.o main

