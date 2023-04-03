//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_ZOO_H
#define SISTEMAZOO_ZOO_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include"Habitat.h"


using namespace std;

class Zoo {
private:
    unordered_map<string, vector<string>> comida;
    vector<Habitat> listaHabitats;
public:
    Zoo() = default;
    void agregarHabitat(Habitat habitatTemp);
    vector<Habitat> getHabitats();
    unordered_map<string, vector<string>> getComida();
    bool buscarComida(string tipoDieta, string alimento);
};


#endif //SISTEMAZOO_ZOO_H
