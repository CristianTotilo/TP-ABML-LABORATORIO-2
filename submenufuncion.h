#ifndef SUBMENUFUNCION_H_INCLUDED
#define SUBMENUFUNCION_H_INCLUDED


///SUBMENU DE MODIFICACION ALUMNOS
void subMenuModificarAlumno(struct Alumno *reg)
{
    int op;
    bool salir=true;
    while(salir)
    {
        system("cls");


        cout<<" ____________________________________________ "<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|     MODIFICACION DE DATOS DEL ALUMNO       |"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 1- MODIFICAR NOMBRE                        |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 2- MODIFICAR FECHA DE NACIMIENTO           |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"| *| 10- AYUDA |*             *| 0- SALIR |* |"<<endl;
        cout<<"|____________________________________________|"<<endl;

        cout<<"//'Seleccione el campo que quiere modificar'"<<endl;
        cout<<"//En caso de necesitar ayuda ingrese la opcion N°10"<<endl;

        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            cin.ignore();
            cout<<"Ingrese el nombre: "<<endl;
            getline(reg->alumno,50);
            break;
        case 2:
            system("cls");
            cout<<"_____________________INGRESO DE FECHA DE NACIMIENTO____________________"<<endl;
            cin.ignore();
            cout<<"ingrese el dia: ";
            getline(reg->dia,3);
            cout<<endl;
            cout<<"ingrese el mes: ";
            getline(reg->mes,3);
            cout<<endl;
            cout<<"ingrese el anio: ";
            getline(reg->anio,5);
            cout<<endl;
            break;
        case 0:
            salir=false;
            break;
        default:
            cout<< "Opcion no valida"<<endl;
            system("PAUSE");
            break;
        }

    }

}

#endif // SUBMENUFUNCION_H_INCLUDED
