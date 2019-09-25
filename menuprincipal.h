#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuprincipal()
{
    bool salir=false;
    int op;

    while (!salir)
    {
        system("cls");
        cout<<" ____________________________________________ "<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|      BASE DE DATOS U.T.N. F.R.G.P.         |"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"|____________________________________________|"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 1- MENU DE ALUMNOS                         |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 2- MENU DE MATERIAS                        |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;
        cout<<"| 3- MENU DE         |"<<endl;
        cout<<"|--------------------------------------------|"<<endl;        cout<<"|                                            |"<<endl;
        cout<<"| 3- Alta de alumnos                         |"<<endl;
        cout<<"| 4- Listado de alumnos                      |"<<endl;
        cout<<"| 5- Asignacion de alumnos a materias        |"<<endl;
        cout<<"| 6- Listado de alumnos por materia          |"<<endl;
        cout<<"| 7- Modificacion de datos del alumno        |"<<endl;
        cout<<"| 8- Dar de baja un alumno a una materia     |"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"| 10_borrar materia.dat                      |"<<endl;
        cout<<"| 11_borrar alumno.dat                       |"<<endl;
        cout<<"| 12_borrar materiasxalumno.dat              |"<<endl;
        cout<<"| 0- Salir del programa                      |"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|                                            |"<<endl;
        cout<<"|  *| 10- AYUDA |*           *| 0- SALIR |*  |"<<endl;
        cout<<"|____________________________________________|"<<endl;

        cout<<"//'Seleccione una opcion'"<<endl;
        cout<<"//En caso de necesitar ayuda ingrese la opcion N°10"<<endl;

        cin>>op;
        cin.ignore();

        switch (op)
        {
        case 1:
            system("cls");
            subMenuAlumno();
            system("PAUSE");
            break;
        case 2:
            system("cls");
            subMenuMateria();
            system("PAUSE");
            break;
        case 3:
            system("cls");
            subMenuMateriaxAlumno();
            system("PAUSE");
            break;
        case 4:
            system("cls");
            listarAlumnos();
            system("PAUSE");
            break;
        case 5:
            system("cls");
            asignarAlumnos();
            system("PAUSE");
            break;
        case 6:
            system("cls");
            listarMateriaPorAlumno();
            system("PAUSE");
            break;
        case 7:
            system("cls");
            modificarAlumno();
            system("PAUSE");
            break;
        case 8:
            system("cls");
            eliminarAlumnoPorMateria();
            system("PAUSE");
            break;
        case 10:
            system("DEL materia.dat");
            break;
        case 11:
            system("DEL alumno.dat");
            break;
        case 12:
            system("DEL materiaxalumno.dat");
            break;
        case 0:
        {
            salir=true;
            break;
        }

        default:
            cout<< "Opcion no valida"<<endl;
            system("PAUSE");
            break;
        }

    }
}


#endif // MENUPRINCIPAL_H_INCLUDED
