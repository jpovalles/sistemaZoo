//
// Created by jpova on 3/04/2023.
//

#ifndef SISTEMAZOO_ANIMAL_H
#define SISTEMAZOO_ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class Animal {
private:
    string nombre;
    string especie;
    string tipoHabitat;
    string dieta;
    string estadoSalud;
    int id;
    int edad;
    int horasDormir;
    bool jugar;
public:
    Animal() = default;
    Animal(string nombre, string especie, string tipoHabitat, string dieta, string estadoSalud, int id, int edad, int horasDormir, bool jugar);

    //~Animal();

    string getNombre();

    string getEspecie();

    string getTipoHabitat();

    string getDieta();

    string getSalud();


    int getId();

    int getEdad();

    void juego();

    void dormir();

    void comer(string alimento, bool dieta); // Pensado para que en el argumento bool se ingrese una funcion que verifique que el alimento se encuentre en la dieta
};


#endif //SISTEMAZOO_ANIMAL_H
