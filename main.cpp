#include <iostream>
#include "Zoo.h"
#include "Animal.h"
#include "Habitat.h"

void editarDieta(Zoo* pZoo){
    string opcionEditar[3] = {"Salir","Agregar alimento", "Eliminar alimento"};
    string opcionDieta[4] = {"Salir", "Carnivoro", "Herbivoro", "Omnivoro"};
    string alimento = "";
    int opcEditar, opcDieta;

    do{
        cout << "\nQue deseas hacer?" << endl;
        for(int i = 0; i != 3; i++){
            cout << i << ") " << opcionEditar[i] << endl;
        }

        cin >> opcEditar;

        if(opcEditar == 1 || opcEditar == 2){
            do{
                cout << "\nQue dieta quieres editar?" << endl;
                for(int i = 0; i != 4; i++){
                    cout << i << ") " << opcionDieta[i] << endl;
                }
                cin >> opcDieta;
            }while(opcDieta < 0 || opcDieta > 3);
        }

        switch(opcEditar){
            case 0:
                break;
            case 1:
                if(opcDieta != 0){
                    cout << "\nIngrese el nombre del alimento a ingresar:" << endl;
                    cin >> alimento;
                    pZoo->agregarAlimento(opcionDieta[opcDieta], alimento);
                }
                break;
            case 2:
                if(opcDieta != 0) {
                    if(pZoo->getComida()[opcionDieta[opcDieta]].empty()){   // accedo al mapa de comida, busco la clave del tipo de dieta y ejecuto la funcion empty al vector de alimentos
                        cout << "\n# La dieta " << opcionDieta[opcDieta] << " no tiene alimentos!" << endl;
                    }else{
                        pZoo->imprimirDieta(opcionDieta[opcDieta]);
                        cout << "\nIngresa el alimento a eliminar:" << endl;
                        cin >> alimento;
                        pZoo->eliminarAlimento(opcionDieta[opcDieta], alimento);
                    }
                }
                break;
            default:
                cout << "\n# Ingresa una opcion valida" << endl;
        }



    }while(opcEditar != 0 || opcDieta != 0);
}

void enlistarAnimales(Zoo* pZoo){
    vector<Habitat>::iterator itVector;
    int num = 1;
    vector<Habitat> vectorHabitats = (pZoo->getHabitats());
    for (itVector = vectorHabitats.begin(); itVector != vectorHabitats.end(); ++itVector, num++){
        Habitat habitatTemp = *itVector;
        cout <<"\n"<<num << ") ";
        if(itVector->getMapa().empty()){
            cout<<"En "<<itVector->getNombre()<<" de tipo "<<itVector->getTipo()<< " se encuentran:"<<endl;
            cout<<"\tEste habitat esta vacio"<<endl;
        }else{itVector->imprimirAnimales();}
    }
}

bool esVacia(vector<Habitat> vector){
    return &vector == NULL;
}

bool esVaciaAnimal(vector<Animal> animal){
    return &animal == NULL;
}

int seleccionador(int x, string cadena[]){
    int opcTipo;
    do{
        for(int i = 0; i <= x-1; i++){
            cout << i+1 << ") " << cadena[i] << endl;
        }
        cin >> opcTipo;
    }while(opcTipo < 1 || opcTipo > x);
    return opcTipo;
}

void nuevoAnimal(Zoo* pZoo){
    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    string tiposDietas[3]={"Carnivoro", "Herbivoro","Omnivoro"};
    string especie, nombre, tipoHabitat, tipoDieta;
    int edad, horasDormir, opcDieta = 0, opcTipo = 0, opcHabitat = 0;
    int id = pZoo->getId();
    cout<<"Cual es la especie del animal?: "<<endl;
    cin>>especie;
    cout<<"Como se llama?: "<<endl;
    cin>>nombre;
    do{
        cout<<"Cual es su edad?: "<<endl;
        cin>>edad;
    }while(edad<0 || edad>15);
    cout<<"Cuantas horas necesita dormir?: "<<endl;
    cin>>horasDormir;
    cout << "Selecciona el tipo de habitat del animal:" << endl;
    opcTipo = seleccionador(4, tipoHabitats);
    cout << "Selecciona el tipo de dieta:" << endl;
    opcDieta = seleccionador(3, tiposDietas);
    cout<<"Seleccione el habitat para el nuevo animal: "<<endl;
    pZoo->imprimirHabitats();
    vector<Habitat> habitatTemp = (pZoo->getHabitats());
    do{
        cin>>opcHabitat;
    }while(habitatTemp[opcHabitat-1].getTipo()!=tipoHabitats[opcTipo-1]);

    Animal temp(nombre, especie, tipoHabitats[opcTipo-1], tiposDietas[opcDieta-1], id, edad, horasDormir, false);
    habitatTemp[opcHabitat-1].agregarAnimal(temp);
    pZoo->setVector(habitatTemp);
    pZoo->setId(id + 1);
}

void anadirHabitat(Zoo* pZoo){

    string tipoHabitats[4] = {"Desertico", "Selvatico", "Polar", "Acuatico"};
    int opcTipo = 0;
    string nombreHabitat;

    cout << "Ingrese el nombre del nuevo habitat:" << endl;
    cin >> nombreHabitat;
    cout << "Selecciona el tipo de habitat:" << endl;
    opcTipo = seleccionador(4, tipoHabitats);

    unordered_map<int, Animal> mapaAnimales;

    Habitat habTemp(nombreHabitat, tipoHabitats[opcTipo-1], mapaAnimales);  //opcTipo-1 porque recibe el numeral de seleccion y se lo necesita como indice del arreglo tipoHabitats
    pZoo->agregarHabitat(habTemp);
}

void menu(Zoo* pZoo){
    int opcion = 0;

    cout << "########################\nBienvenido al SendoZoo!\n########################" << endl;

    do{
        cout << "\nQue deseas hacer?" << endl;
        string opcionesMenu[6] = {"Salir","Anadir habitat", "Anadir animal", "Listar habitats y animales", "Realizar accion", "Editar dietas"};
        for(int i = 0; i != 6; i++){
            cout << i << ") " << opcionesMenu[i] << endl;
        }
        cin>>opcion;

        switch(opcion){
            case 0:
                break;
            case 1:
                anadirHabitat(pZoo);
                break;
            case 2:
                if(pZoo->getHabitats().empty()){
                    cout << "\n# No hay habitats para recibir animales!" << endl;
                }else{
                    nuevoAnimal(pZoo);
                }
                break;
            case 3:
                enlistarAnimales(pZoo);
                break;
            case 4:
                //accion();
                break;
            case 5:
                editarDieta(pZoo);
                break;
            default:
                cout << "\n# Ingresa una opcion valida!" << endl;
        }
    }while(opcion != 0);

}


int main(){
    Zoo *pZoo = new Zoo;

    pZoo->setId(0);
    menu(pZoo);
    /*anadirHabitat(pZoo);
    anadirHabitat(pZoo);
    nuevoAnimal(pZoo);
    enlistarAnimales(pZoo);*/
    return 0;
}