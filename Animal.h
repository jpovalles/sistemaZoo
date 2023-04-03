//
// Created by jpova on 3/04/2023.
//

#ifndef SISTEMAZOO_ANIMAL_H
#define SISTEMAZOO_ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string nombre;
    string especie;
    string tipoHabitat;
    string dieta;
    int id;
    int edad;
    int horasDormir;
    bool jugar;
public:
    Animal(string nombre, string especie, string tipoHabitat, string dieta, int id, int edad, int horasDormir, bool jugar);

    //~Animal();

    void setNombre(string nombre);
    string getNombre();

    void setEspecie(string especie);
    string getEspecie();

    void setTipoHabitat(string tipoHabitat);
    string getTipoHabitat();

    void setDieta(string Dieta);
    string getDieta();

    void setId(int Id);
    int getId();

    void setEdad(int Edad);
    int getEdad();

    void setHorasDormir(int horasDormir);
    int getHorasDormir();

    void setJugar(bool jugar);
    bool getJugar();

    void juego();
    void dormir();
};


#endif //SISTEMAZOO_ANIMAL_H
