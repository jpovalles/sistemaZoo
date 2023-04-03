//
// Created by jpova on 3/04/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string tipoHabitat, string dieta, int id, int edad, int horasDormir, bool jugar):nombre(nombre), especie(especie), tipoHabitat(tipoHabitat), dieta(dieta), id(id), edad(edad), horasDormir(horasDormir), jugar(jugar) {}

void Animal::juego() {
    if(this->jugar){
        cout << this->nombre << " esta cansado para jugar" << endl;
    }else{
        cout << this->nombre << " se divirtio jugando!" << endl;
    }

    this->jugar = not this->jugar;
}

void Animal::dormir(){
    int inHoras;

    do{
        cout << "Ingresa las horas a dormir: " << endl;
        cin >> inHoras;
        if(inHoras < this->horasDormir){
            cout << this->nombre << " necesita dormir mas!\n" << endl;
        }else if(inHoras > this->horasDormir){
            cout << this->nombre << " no puede dormir tanto!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Muy bien! " << this->nombre << " descanso lo suficiente.\n" << endl;
}

/*
int Animal::comer(string alimento, Zoo zoologico){
    unordered_map mapaDieta = zoologico.getComida();
    vector<string> vectorDieta = mapaDieta[this->dieta];

    vector<string>::iterator itVector;

    for (itVector = vectorDieta.begin(); itVector != vectorDieta.end(); ++itVector){
        //string comida = *itVector;
        if(*itVector == alimento){
            cout << this->nombre << " fue alimentado con " << alimento << endl;
            return 1;
        }else if(itVector == vectorDieta.end()){
            cout << this->nombre << " no puede comer " << alimento << endl;
            return 0;
        }
    }
}
*/

void Animal::setNombre(string nombre){
    this->nombre = nombre;
}

string Animal::getNombre(){
    return this->nombre;
}

void Animal::setEspecie(string especie){
    this->especie = especie;
}

string Animal::getEspecie() {
    return this->especie;
}

void Animal::setTipoHabitat(string tipoHabitat) {
    this->tipoHabitat = tipoHabitat;
}

string Animal::getTipoHabitat() {
    return this->tipoHabitat;
}

void Animal::setDieta(string dieta) {
    this->dieta = dieta;
}

string Animal::getDieta() {
    return this->dieta;
}

void Animal::setId(int Id) {
    this->id = Id;
}

int Animal::getId() {
    return this->id;
}

void Animal::setEdad(int Edad) {
    this->edad = Edad;
}

int Animal::getEdad() {
    return this->edad;
}

void Animal::setHorasDormir(int horasDormir){
    this->horasDormir = horasDormir;
}

int Animal::getHorasDormir(){
    return this->horasDormir;
}

void Animal::setJugar(bool jugar) {
    this->jugar = jugar;
}

bool Animal::getJugar() {
    return this->jugar;
}