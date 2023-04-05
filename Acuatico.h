//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_ACUATICO_H
#define SISTEMAZOO_ACUATICO_H

#include "Animal.h"
#include "Zoo.h"

class Acuatico : public Animal{
public:
    void juego() override;
    void comer(string alimento, bool dieta) override;
    void dormir() override;

    Acuatico(const string &nombre, const string &especie, const string &tipoHabitat, const string &dieta, int id,
             int edad, int horasDormir, bool jugar);

    Animal retornar();
};


#endif //SISTEMAZOO_ACUATICO_H
