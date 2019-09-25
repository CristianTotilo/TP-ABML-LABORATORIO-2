#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED


///MENU DE ALUMNOS
void subMenuAlumno()
{
    bool salir=false;
    int op;

    while (!salir)
    {
        system("cls");


        cout<<" ____________________________________________"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|              MENU DE ALUMNOS               |"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"*____________________________________________*"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 1- ALTA DE ALUMNOS                         |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 2- LISTADO DE ALUMNOS                      |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 3- MODIFICAR DATOS DE ALUMNO               |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"| *| 10- AYUDA |*             *| 0- SALIR |* |"<<endl;
        cout<<"|____________________________________________|"<<endl;

        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            altaAlumno();
            system("PAUSE");
            break;

        case 2:
            system("cls");
            listarAlumnos();
            system("PAUSE");
            break;

        case 3:
            system("cls");
            modificarAlumno();
            system("PAUSE");
            break;

        case 0:
            salir=true;
            break;
        default:
            cout<< "Opcion no valida"<<endl;
            system("PAUSE");
            break;
        }
    }
}

///MENU DE MATERIAS
void subMenuMateria()
{
    bool salir=false;
    int op;

    while (!salir)
    {
        system("cls");


        cout<<" ____________________________________________"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|              MENU DE MATERIAS              |"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"*____________________________________________*"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 1- ALTA DE MATERIA                         |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 2- LISTADO DE MATERIA                      |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"| *| 10- AYUDA |*             *| 0- SALIR |* |"<<endl;
        cout<<"|____________________________________________|"<<endl;

        cout<<"//'Seleccione una opcion'"<<endl;
        cout<<"//En caso de necesitar ayuda ingrese la opcion N°10"<<endl;

        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            altaMateria();
            system("PAUSE");
            break;

        case 2:
            system("cls");
            listarMaterias();
            system("PAUSE");
            break;

        case 0:
            salir=true;
            break;
        default:
            cout<< "Opcion no valida"<<endl;
            system("PAUSE");
            break;
        }
    }
}

///MENU DE ALUMNOS POR MATERIA
void subMenuMateriaxAlumno()
{
    bool salir=false;
    int op;

    while (!salir)
    {
        system("cls");


        cout<<" ____________________________________________"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|     ABM&L DE ALUMNOS A MATERIAS            |"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"*____________________________________________*"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 1- ASIGNAR ALUMNO A MATERIA                |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 2- LISTADO ALUMNOS POR MATERIA             |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 3- DAR DE BAJA ALUMNOS DE MATERIAS         |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"| *| 10- AYUDA |*             *| 0- SALIR |* |"<<endl;
        cout<<"|____________________________________________|"<<endl;

        cout<<"//'Seleccione una opcion'"<<endl;
        cout<<"//En caso de necesitar ayuda ingrese la opcion N°10"<<endl;

        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            asignarAlumnos();
            system("PAUSE");
            break;

        case 2:
            system("cls");
            listarMateriaPorAlumno();
            system("PAUSE");
            break;

        case 3:
            system("cls");
            eliminarAlumnoPorMateria();
            system("PAUSE");
            break;

        case 0:
            salir=true;
            break;
        default:
            cout<< "Opcion no valida"<<endl;
            system("PAUSE");
            break;
        }
    }
}
#endif // SUBMENU_H_INCLUDED
