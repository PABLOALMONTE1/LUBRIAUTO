/*------------------------------------------------------------------------------------|
|  Autor:PABLO ALMONTE                    MATRICULA: 1-20-2318                        | 
|         HOSNY CEBALLOS                             1-20-2085                        |
|  Fecha: 16/08/2023                     Version: 1.00		                            |
|-------------------------------------------------------------------------------------|           
|  Descripcion del Programa: ESTE ES UN SISTEMA DE FACTURACION PARA UN LUBRIAUTO,     |
                             DONDE PODREMOS FACTURAR Y COTIZAR NUESTROS PRODUCTOS Y   |
                            SERVICIOS.                                                |   
                                                                                      |           
| -----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct servicios 
{
    int pre;
    char art1[17];
    char art2[17];
    char art3[21];
    char art4[17];
    char art5[17];
    
    
};

int main()
{
    FILE *archivo;
    char caracter;
    char documento[] = "servicios.txt"; 
    int x,r,f,c1=0,c2=0;
    float z,zt, st, s,t;

    struct servicios s1 = {2500,"aceite", "filtro de aceite"}, s2 = {2800 ,"aceite", "filtro de aceite","filtro de combustible"}, s3 = {3120,"aceite", "filtro de aceite","filtro de combustible", "filtro de aire"}, s4 = {3321,"aceite", "filtro de aceite","filtro de combustible","filtro de aire", "filtro A/A"}, s5 = {450,"Lavado"};

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
}

