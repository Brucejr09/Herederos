
#include <iostream>
#include <string>

using namespace std;
class Animal{
	protected:
		string nombre;
		string edad;
		string tamanio;
		string especie;
		string personalidad;
		int hambre = 0;
		int higiene = 100;

	public:
		Animal(string nombre, string edad, string tamanio, string personalidad);
		~Animal();
		string retornar_nombre();
		string retornar_tamanio();
		bool necesita_alimentarse();
		void alimentar();
		virtual void fue_alimentado();
		bool necesita_baniarse();
		void baniar();
		void caracteristicas();
		void modificar_higiene_hambre();
		string espaciar_palabras(int tamanio_caracteristica, int espacio_asignado);
};

class Perro : public Animal{
	public:
		Perro(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Gato : public Animal{
	public:
		Gato(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Caballo : public Animal{
	public:
		Caballo(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Roedor : public Animal{
	public:
		Roedor(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Conejo : public Animal{
	public:
		Conejo(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Erizo : public Animal{
	public:
		Erizo(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

class Lagartija : public Animal{
	public:
		Lagartija(string nombre, string edad, string tamanio, string personalidad);
		void fue_alimentado();
};

