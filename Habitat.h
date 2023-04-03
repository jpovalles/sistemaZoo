//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_HABITAT_H
#define SISTEMAZOO_HABITAT_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Habitat {
private:
    string nombre;
    string tipo;
    vector<Animal> listaAnimales;
public:
    string getNombre();
    string getTipo();
    vector<Animal> getLista();
    void agregarAnimal();
};


#endif //SISTEMAZOO_HABITAT_H
