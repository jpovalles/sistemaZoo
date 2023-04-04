//
// Created by LENOVO on 03/04/2023.
//

#include "Aereo.h"


void Aereo::comer(string alimento, bool dieta){
    if(dieta){
        cout<<""<<this->nombre<<" volo para disfrutar de su "<<alimento<<"\n"<<endl;
    }else{
        cout<<""<<alimento<<" no pertenece a la dieta de "<<this->nombre<<"\n"<<endl;
    }
}

void Aereo::juego() {
    if(this->jugar){
        cout << this->nombre << " no quiere jugar, esta cansado" << endl;
    }else{
        cout << this->nombre << " sobrevolo el habitat en busca de diversion\n" << endl;
    }

    this->jugar = not this->jugar;
}

void Aereo::dormir(){
    int inHoras;

    do{
        cout << "Ingresa las horas a dormir: " << endl;
        cin >> inHoras;
        if(inHoras < this->horasDormir){
            cout << this->nombre << " necesita dormir mas!\n" << endl;
        }else if(inHoras > this->horasDormir){
            cout << this->nombre << " no deberia dormir tanto!\n" << endl;
        }
    }while(inHoras != this->horasDormir);

    cout << "Muy bien! " << this->nombre << " salio volando hasta su nido para descansar.\n" << endl;
}
