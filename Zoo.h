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
    int currentId = 0;
    unordered_map<string, vector<string>> comida;
    vector<Habitat> listaHabitats;
public:
    Zoo() = default;
    void agregarHabitat(Habitat habitatTemp);
    vector<Habitat> getHabitats();
    void setVector(vector<Habitat> vectorTemp);
    int getId();
    unordered_map<string, vector<string>> getComida();
    void setId(int id);
    bool buscarComida(string tipoDieta, string alimento);
    void agregarAlimento(string tipoDieta, string alimento);
    bool eliminarAlimento(string tipoDieta, string alimento);
    void imprimirHabitats();
    void imprimirDieta(string tipo);
};


#endif //SISTEMAZOO_ZOO_H
