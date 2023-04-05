//
// Created by LENOVO on 03/04/2023.
//

#include "Acuatico.h"


void Acuatico::comer(string alimento, bool dieta){
    if(dieta){
        cout<<""<<this->nombre<<" ahora esta bajo el agua alimentandose de "<<alimento<<"\n"<<endl;
    }else{
        cout<<""<<this->nombre<<" no come "<<alimento<<"\n"<<endl;
    }
}

void Acuatico::juego() {
    if(this->jugar){
        cout << this->nombre << " esta agotado, dejalo descansar" << endl;
    }else{
        cout << this->nombre << " dio su paseo divertido por el acuario!" << endl;
    }

    this->jugar = not this->jugar;
}

void Acuatico::dormir(){
    int inHoras;

    do{
        cout << "Ingresa las horas a dormir: " << endl;
        cin >> inHoras;
        if(inHoras < this->horasDormir){
            cout << this->nombre << " necesita dormir mas!\n" << endl;
        }else if(inHoras > this->horasDormir){
            cout << this->nombre << " debe dormir menos!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Excelente! " << this->nombre << " se hundio para descansar en un rincon del acuario.\n" << endl;
}

Animal Acuatico::retornar() {
    Acuatico prueba("Juan", "Tigre", "Selvatico", "Carnivoro", 12, 34, 5, false);
    return prueba;
}

Acuatico::Acuatico(const string &nombre, const string &especie, const string &tipoHabitat, const string &dieta, int id,
                   int edad, int horasDormir, bool jugar) : Animal(nombre, especie, tipoHabitat, dieta, id, edad,
                                                                   horasDormir, jugar) {}
