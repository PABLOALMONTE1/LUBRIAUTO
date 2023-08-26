/*------------------------------------------------------------------------------------|
|  Autor:PABLO ALMONTE                    MATRICULA: 1-20-2318                        | 
|         HOSNY CEBALLOS                             1-20-2085                        |
|  Fecha: 25/08/2023                     Version: 1.2.1		                          |
|-------------------------------------------------------------------------------------|           
|  Descripcion del Programa: ESTE ES UN SISTEMA DE FACTURACION PARA UN LUBRIAUTO,     |
                             DONDE PODREMOS FACTURAR Y COTIZAR NUESTROS PRODUCTOS Y   |
                            SERVICIOS, crear usuarios y manejar la nomina.            |   
                                                                                      |           
| -----------------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamano 100

typedef struct 
{
    char nombre[tamano];
    char clave[tamano];
} Usuario;

void crear_usuario() 
    {
    Usuario user;
    printf("Ingrese el nombre de usuario: ");
    scanf("%s", user.nombre);
    printf("Ingrese la contrasena: ");
    scanf("%s", user.clave);

    FILE *file = fopen("usuarios.txt", "at");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(file, "%s %s\n", user.nombre, user.clave);
    fclose(file);

    printf("Usuario creado exitosamente.\n");
}

void inicio_sesion() 
{
    char nombre[tamano];
    char clave[tamano];

    printf("Ingrese su nombre de usuario: ");
    scanf("%s", nombre);
    printf("Ingrese su contrasena: ");
    scanf("%s", clave);

    FILE *archivo = fopen("usuarios.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char archivo_nombre[tamano];
    char archivo_clave[tamano];
    int found = 0;

    while (fscanf(archivo, "%s %s", archivo_nombre, archivo_clave) != EOF) 
    {
        if (strcmp(nombre, archivo_nombre) == 0 && strcmp(clave, archivo_clave) == 0)
        {
            found = 1;
            break;
        }
    }
      if(found)
      {
      fclose(archivo);
      printf("Inicio de sesion exitoso.\n");
      
      int g;
      printf("desea cambiar la contrasena 1-si, 0-no\n");
      
      scanf("%d",&g);

    if (g==1) 
    {
        

        char nueva_clave[tamano];
        printf("Ingrese la nueva contrasena: ");
        scanf("%s", nueva_clave);

        FILE *archivo_temporal = fopen("temp.txt", "w");
        if (archivo_temporal == NULL) 
        {
            printf("Error al abrir el archivo temporario.\n");
            return;
        }

        FILE *archivo_original = fopen("usuarios.txt", "r");
        if (archivo_original == NULL) 
        {
            printf("Error al abrir el archivo original.\n");
            return;
        }

        while (fscanf(archivo_original, "%s %s", archivo_nombre, archivo_clave) != EOF) 
        {
            if (strcmp(nombre, archivo_nombre) == 0) 
            {
                fprintf(archivo_temporal, "%s %s\n", nombre, nueva_clave);
            } else {
                fprintf(archivo_temporal, "%s %s\n", archivo_nombre, archivo_clave);
            }
        }

        fclose(archivo_original);
        fclose(archivo_temporal);

        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");

        printf("Contrasena modificada exitosamente.\n");


      }
      }
      else 
        printf("\nnombre o clave incorrecta\n");

    
}

struct servicios 
{
    int pre;
    char art1[17];
    char art2[17];
    char art3[21];
    char art4[17];
    char art5[17];
    
    
};


int main() {
    int x;
                 FILE *archivo;
    char caracter;
    char documento[] = "servicios.txt"; 
    int  r,f,c1=0,c2=0;
    float z,zt, st, s,t;

    struct servicios s1 = {2500,"aceite", "filtro de aceite"}, s2 = {2800 ,"aceite", "filtro de aceite","filtro de combustible"}, s3 = {3120,"aceite", "filtro de aceite","filtro de combustible", "filtro de aire"}, s4 = {3321,"aceite", "filtro de aceite","filtro de combustible","filtro de aire", "filtro A/A"}, s5 = {450,"Lavado"};


    do {
        printf("Seleccione una opcion:\n");
        printf("1. Crear usuario\n");
        printf("2. Iniciar sesion\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                crear_usuario();
                break;
            case 2:
                inicio_sesion();
                if(inicio_sesion)
                

    printf("\nBIENVENIDO\n");
   
do
{   
    c1=0;
    do
    {
        if ((archivo = fopen(documento, "r")))
            
            {
                    // Leer y mostrar el contenido del archivo línea por línea
        while ((caracter = fgetc(archivo)) != EOF) 
        {
        printf("%c", caracter);
         }
                fclose(archivo);
            }

         printf("\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            printf("\n%s", s1.art1);
            printf("\n%s", s1.art2);
            printf("\n%d", s1.pre);
            printf("\nrealizar 1-si, 0-no\n");
            scanf("\n%d",&r);
            if(r=1)
            c1=c1+s1.pre;
            


            break;

        case 2:
            printf("\n%s", s2.art1);
            printf("\n%s", s2.art2);
            printf("\n%s", s2.art3);
            printf("\n%d", s2.pre);
            printf("\nrealizar 1-si, 0-no\n");
            scanf("\n%d",&r);
            if(r=1)
            c1=c1+s2.pre;
            
            break;

        case 3:
            printf("\n%s", s3.art1);
            printf("\n%s", s3.art2);
            printf("\n%s", s3.art3);
            printf("\n%s", s3.art4);
            printf("\n%d", s3.pre);
            printf("\nrealizar 1-si, 0-no\n");
            scanf("\n%d",&r);
            if(r=1)
            c1=c1+s3.pre;
            break;

        case 4:
            printf("\n%s", s4.art1);
            printf("\n%s", s4.art2);
            printf("\n%s", s4.art3);
            printf("\n%s", s4.art4);
            printf("\n%s", s4.art5);
            printf("\n%d", s4.pre);
            printf("\nrealizar 1-si, 0-no\n");
            scanf("\n%d",&r);
            if(r=1)
            c1=c1+s4.pre;
            break;

        case 5:
            printf("\n%s", s5.art1);
            printf("\n%d", s5.pre);
            printf("\nrealizar 1-si, 0-no\n");
            scanf("\n%d",&r);
            if(r=1)
            c1=c1+s5.pre;
            break;

        

           

        default:
            if(x>5)
            printf("\nOpcion no valida\n");
            break;
        }

    } while (x > 0);


   printf("\nsub total: %d", c1);
   z=c1*0.18;
   printf("\nitbis: %f", z);
   s=c1*1.18;
   printf("\ntotal a pagar: %f", s);
   c2=c2+c1;
    printf("\ningrese 1 para inicar o 0 para finalizar");
    scanf("%d",&f);

}while(f==1);
    printf("\nsub total generado: %d", c2);
    zt=c2*0.18;
    printf("\nitbis: %f", zt);
    st=c2*1.18;
    t=c2*0.30;
    printf("\ntotal generado: %f", st);
    printf("\nganancias: %f", t);
    printf("\nEl programa se ha ejecutado exitosamente");
    return 0;





                break;
            case 3:
                printf("Saliendo\n");
                exit(0);
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (1);

    return 0;
}

