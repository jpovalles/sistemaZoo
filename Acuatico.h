//
// Created by LENOVO on 03/04/2023.
//

#ifndef SISTEMAZOO_ACUATICO_H
#define SISTEMAZOO_ACUATICO_H

#include "Animal.h"

class Acuatico : public Animal{
public:
    void juego();
    int comer(string alimento, Zoo zoologico);
    void dormir();
};


#endif //SISTEMAZOO_ACUATICO_H
