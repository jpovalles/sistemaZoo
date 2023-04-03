//
// Created by LENOVO on 03/04/2023.
//

#include "Terrestres.h"

/*void Terrestres::comer(string alimento, bool dieta){
    if(dieta){
        cout<<""<<this->nombre<<" esta comiendo "<<alimento<<"\n"<<endl;
    }else{
        cout<<""<<alimento<<" no pertenece a la dieta de "<<this->nombre<<"\n"<<endl;
    }
}*/

void Terrestres::juego() {
    if(this->jugar){
        cout << this->nombre << " esta cansado para jugar" << endl;
    }else{
        cout << this->nombre << " se divirtio jugando!" << endl;
    }

    this->jugar = not this->jugar;
}

void Terrestres::dormir(){
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
