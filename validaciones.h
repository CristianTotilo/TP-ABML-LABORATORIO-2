#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


bool validarMateria(char materia[20],bool *salir)
{
    struct Materia reg;
    bool encontro=false;
    FILE *p;
    p=fopen("materia.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    while(fread(&reg,sizeof(Materia),1,p)!=0)
    {
        if(strcmp(reg.idmateria,materia)==0)
        {
            system("cls");
            cout<<"Se encontro la materia: ";
            cout<<reg.materia<<endl;
            *salir=true;
            encontro=true;
        }
    }
    if(!encontro)
    {
        system("cls");
        cout<<"No se encontro la materia ingresada"<<endl;
        cin.ignore();
        cout<<"desea intentar nuevamente? S/N: ";
        char op;
        cin>>op;
        switch(op)
        {
        case 's':
        case 'S':
            *salir=false;
            break;
        case 'n':
        case 'N':
            *salir=true;
            break;
        default:
            cout<<"ingreso no valido"<<endl;
            break;
        }
        fclose(p);
        return false;
    }
    fclose(p);
    return true;
}

bool validarAlumno(char alumno[20],bool *salir)
{
    struct Alumno reg;
    bool encontro=false;
    FILE *p;
    p=fopen("alumno.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    while(fread(&reg,sizeof(Alumno),1,p)!=0)
    {
        if(strcmp(reg.legajo,alumno)==0)
        {
            system("cls");
            cout<<"Se encontro el Alumno: ";
            cout<<reg.alumno<<endl;
            *salir=true;
            encontro=true;
        }
    }
    if(!encontro)
    {
        system("cls");
        cout<<"No se encontro el legajo ingresado"<<endl;
        cin.ignore();
        cout<<"desea intentar nuevamente? S/N: ";
        char op;
        cin>>op;
        switch(op)
        {
        case 's':
        case 'S':
            *salir=false;
            break;
        case 'n':
        case 'N':
            *salir=true;
            break;
        default:
            cout<<"ingreso no valido"<<endl;
            break;
        }
        fclose(p);
        return false;
    }
    fclose(p);
    return true;
}

void getline(char *cadena,int cantidad)
{
    int contador =0;
    char caracter ='\0';

    while(caracter!=10)
    {
        caracter = std::cin.get();
        if(contador != cantidad && caracter!=10)
        {
            cadena[contador] = caracter;
            contador++;
        }
    }
    cadena[contador]='\0';
}


#endif // VALIDACIONES_H_INCLUDED
