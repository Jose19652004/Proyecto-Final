#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <windows.h>
#include <cctype>
#include<iomanip>

using namespace std;

//use std::string;

#define USUARIO "Josegraterol"
#define PASS "proyectojose"

typedef struct {
	char nombre[20];
	char apellido[20];
	char usuario[15];
	char correo[30];
	char clave[15];
} Usuario;

typedef struct {
	char nombre[20];
	char apellido[20];
	char cedula[10];
	char telefono[12];
	char direccion[60];
} Cliente;

typedef struct{
	char cliente[20], producto[50];
	int cantidad;
	float precio, impuesto, subtotal, totalneto, descuento=0; 
}Factura;

typedef struct{
	char nombre[20];
	int codigo, cantidad;
	float precio, monto_total;
}Producto;

void borrar(){
	remove("usuario.txt");
	rename("auxiliar.txt","usuario.txt");
}

void crear_usuario(){
	Usuario datos;
	FILE *fichero;
	
	fichero = fopen("creando_usuario.txt","a+");

		system("cls");
		printf("\n\n    CREAR USUARIO \n\n");
		printf("Nombre: ");
		scanf("%s",datos.nombre);
		printf("Apellido: ");
		scanf("%s",datos.apellido);
		printf("Usuario: ");
		scanf("%s",datos.usuario);
		printf("Correo: ");
		scanf("%s",datos.correo);
		printf("Clave: ");
		scanf("%s",datos.clave);
		fprintf(fichero,"%s %s %s %s %s\n",datos.nombre,datos.apellido,datos.usuario,datos.correo,datos.clave);
		
	fclose(fichero);
	system("pause");
}

void listar_usuario(){
	Usuario datos;
	FILE * fichero;
 	fichero = fopen("usuario.txt", "r");
/*	if (fichero == NULL){
		printf ("\n\n   El Archivo no fue encontrado... \n\n");
		system("pause");
	}else{*/
		system("cls");
		printf("\n\n     LISTADO DE USUARIO  \n\n");
		printf(" NOMBRE               APELLIDO              USUARIO         CORREO\n");
		while(!feof(fichero)){
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%s",datos.apellido);
			fscanf(fichero,"%s",datos.usuario);
			fscanf(fichero,"%s",datos.correo);
			fscanf(fichero,"%s",datos.clave);
			printf(" %s  %s   %s  %s  \n",datos.nombre,datos.apellido,datos.usuario,datos.correo);
		//	fflush(stdin);
		//fgets(linea, sizeof(linea), fichero);
		//printf(" %s\n",linea);
		}
		system("pause");
//	}
	fclose(fichero);
}

void eliminar_usuario(){
	char user[15],u[15];
	Usuario datos;
	FILE *fichero,*aux;
	
	fichero = fopen("usuario.txt","r");
	aux=fopen("auxiliar.txt","a+");
	
	/*	if (fichero == NULL){
		printf ("\n\n   El Archivo no fue encontrado... \n\n");
		system("pause");
	}else{  */
		system("cls");
		printf("\n\n    ELIMINAR USUARIO \n\n");
		printf("Usuario: ");
		scanf("%s",user);
		while(!feof(fichero)){	
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%s",datos.apellido);
			fscanf(fichero,"%s",datos.usuario);
			fscanf(fichero,"%s",datos.correo);
			fscanf(fichero,"%s",datos.clave);
			printf("-%s- %s-",datos.usuario,user);
			if (!strstr(user,datos.usuario)){
				fprintf(aux,"%s %s %s %s %s\n",datos.nombre,datos.apellido,datos.usuario,datos.correo,datos.clave);
			}else{
				printf("\n\n El Usuario fue eliminado con exito... \n\n\n\n");
			}
		}
	fclose(fichero);
	fclose(aux);
	borrar();
	system("pause");
}

void camb_usuario(){
	char user[15],u[15];
	Usuario datos;
	FILE *fichero,*aux;
	
	fichero = fopen("usuario.txt","r");
	aux=fopen("auxiliar.txt","a+");
	
		system("cls");
		printf("\n\n    CAMBIAR USUARIO \n\n");
		printf("Cambiar Usuario: ");
		scanf("%s",user);
		printf("Nuevo Usuario: ");
		scanf("%s",u);
		while(!feof(fichero)){	
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%s",datos.apellido);
			fscanf(fichero,"%s",datos.usuario);
			fscanf(fichero,"%s",datos.correo);
			fscanf(fichero,"%s",datos.clave);
			if (!strstr(user,datos.usuario)){
				fprintf(aux,"%s %s %s %s %s\n",datos.nombre,datos.apellido,datos.usuario,datos.correo,datos.clave);
			}else{
				fprintf(aux,"%s %s %s %s %s\n",datos.nombre,datos.apellido,u,datos.correo,datos.clave);
				printf("\n\n El Usuario fue cambiado con exito... \n\n\n\n");
			}
		}
	fclose(fichero);
	fclose(aux);
	borrar();
	system("pause");
}

void usuario(){
	int op;
	do{
		system("cls");
		printf("\n\n      Men%c de Usuarios\n",163);
		printf(" 1. Crear \n");
		printf(" 2. Listar\n");
		printf(" 3. Eliminar\n");
		printf(" 4. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >4);
		switch (op){
			case 1:
				crear_usuario();
				break;
			case 2:
				listar_usuario();
				break;
			case 3:
				eliminar_usuario();
				break;
		}
	}while(op!=4);
}

void camb_clave(){
	
	char user[15],u[15];
	Usuario datos;
	FILE *fichero,*aux;
	
	fichero = fopen("usuario.txt","r");
	aux=fopen("auxiliar.txt","a+");
	
		system("cls");
		printf("\n\n    CAMBIAR CLAVE DEL USUARIO \n\n");
		printf("Usuario: ");
		scanf("%s",user);
		printf("Nueva clave: ");
		scanf("%s",u);
		while(!feof(fichero)){	
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%s",datos.apellido);
			fscanf(fichero,"%s",datos.usuario);
			fscanf(fichero,"%s",datos.correo);
			fscanf(fichero,"%s",datos.clave);
			if (!strstr(user,datos.usuario)){
				fprintf(aux,"%s %s %s %s %s\n",datos.nombre,datos.apellido,datos.usuario,datos.correo,datos.clave);
			}else{
				fprintf(aux,"%s %s %s %s %s\n",datos.nombre,datos.apellido,datos.usuario,datos.correo,u);
				printf("\n\n La clave fue cambiada con exito... \n\n\n\n");
			}
		}
	fclose(fichero);
	fclose(aux);
	borrar();
	system("pause");
	
}

void crear_cliente(){
	
	Cliente datos;
	FILE *fichero;
	
	fichero = fopen("clientes.txt","a+");

		system("cls");
		printf("\n\n    CREAR CLIENTE   \n\n");
		printf("Nombre: ");
		scanf("%s",datos.nombre);
		fprintf(fichero,"%s ",datos.nombre);
		printf("Apellido: ");
		scanf("%s",datos.apellido);
		fprintf(fichero,"%s ",datos.apellido);
		printf("Cedula: ");
		scanf("%s",datos.cedula);
		fprintf(fichero,"%s ",datos.cedula);
		printf("Telefono: ");
		scanf("%s",datos.telefono);
		fprintf(fichero,"%s ",datos.telefono);
		printf("Direccion: ");
		scanf("%s",datos.direccion);
		fprintf(fichero,"%s\n",datos.direccion);
		
	fclose(fichero);	
}


void listar_cliente(){
	
	Cliente datos;
	FILE * fichero;
 	fichero = fopen("clientes.txt", "a+");

		system("cls");
		printf("\n\n     LISTADO DE CLIENTE  \n\n");
		printf(" NOMBRE: \t \n");
		printf(" APELLIDO: \t \n");
		printf(" CEDULA: \t \n");
		printf(" TELEFONO: \t \n");
		printf(" DIRECCION: \n");

		while(!feof(fichero)){
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%s",datos.apellido);
			fscanf(fichero,"%s",datos.cedula);
			fscanf(fichero,"%s",datos.telefono);
			fscanf(fichero,"%s",datos.direccion);
			printf(" %s %s %s %s %s \n",datos.nombre,datos.apellido,datos.cedula,datos.telefono,datos.direccion);
	
		}
		system("pause");
		fclose(fichero);
}
/*
void modificar_cliente(){
	
	
}
*/
void menu_clientes(){
	
	int op;
	do{
		system("cls");
		printf("\n\n      Men%c de Clientes\n",163);
		printf(" 1. Crear \n");
		printf(" 2. Listar\n");
		printf(" 3. Modificar\n");
		printf(" 4. Eliminar\n");
		printf(" 5. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >5);
		switch (op){
			case 1:
				crear_cliente();
				break;
			case 2:
				listar_cliente();
				break;
			case 3:
				//modificar_cliente();
				break;
			case 4:
				//eliminar_cliente();
				break;	
		}
	}while(op!=5);
	
	
}

void agregar_productos(){
	Producto datos;
	FILE *fichero;
	
	fichero = fopen("Productos.txt","a+");
//AGREGANDO PRODUCTOS
		system("cls");
		printf("\n\n\t    AGREGANDO PRODUCTOS \n\n");
		printf("Nombre: ");
		scanf("%s",&datos.nombre);
		printf("Codigo: ");
		scanf("%d",&datos.codigo);
		printf("Cantidad: ");
		scanf("%d",&datos.cantidad);
		printf("Precio para venta: ");
		scanf("%f",&datos.precio);
		fprintf(fichero,"%s %d %d %f\n", datos.nombre, datos.codigo, datos.cantidad, datos.precio);
		
	fclose(fichero);
	system("pause");
	
}

void listar_productos(){
	Producto datos;
	FILE * fichero;
 	fichero = fopen("Productos.txt", "r");

		system("cls");
		printf("\n\n     LISTADO DE PRODUCTOS  \n\n");
		printf(" NOMBRE     CODIGO     CANTIDAD    PRECIO    MONTO$\n");
		while(!feof(fichero)){
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%d",datos.codigo);
			fscanf(fichero,"%d",datos.cantidad);
			fscanf(fichero,"%.2f",datos.precio);
			
			datos.monto_total = datos.precio * datos.cantidad;
			
			printf(" %s  %d   %d  %.2f %.2f \n",datos.nombre,datos.codigo,datos.cantidad,datos.precio, datos.monto_total);
		
		}
		system("pause");
	fclose(fichero);
}

void eliminar_producto(){
	
char user[15],u[15];
	Producto datos;
	FILE *fichero,*aux;
	
	fichero = fopen("Productos.txt","r");
	aux=fopen("auxiliar.txt","a+");
	
	
		system("cls");
		printf("\n\n    ELIMINAR PRODUCTO \n\n");
		printf("Usuario: ");
		scanf("%s",user);
		while(!feof(fichero)){	
			fscanf(fichero,"%s",datos.nombre);
			fscanf(fichero,"%d",datos.codigo);
			fscanf(fichero,"%d",datos.cantidad);
			fscanf(fichero,"%f",datos.precio);
			printf("-%s- %s-",datos.nombre,user);
			if (!strstr(user,datos.nombre)){
				fprintf(aux,"%s %d %d %.2f\n",datos.nombre,datos.codigo,datos.cantidad,datos.precio);
			}else{
				printf("\n\n El Producto fue eliminado con exito... \n\n\n\n");
			}
		}
	fclose(fichero);
	fclose(aux);
	borrar();
	system("pause");
}

void productos(){
	
	int op;
	do{
		system("cls");
		printf("\n\n      Men%c De Los Productos\n",163);
		printf(" 1. Agregar \n");
		printf(" 2. Listar\n");
		printf(" 3. Eliminar\n");
		printf(" 4. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >4);
		switch (op){
			case 1:
				agregar_productos();
				break;
			case 2:
				listar_productos();
				break;
			case 3:
				eliminar_producto();
				break;
		}
	}while(op!=4);
}


//ENTRADA Y MUESTRA DE LOS DATOS
void menu_archivos()
{

	int op;
	do{
		system("cls");
		printf("\n\n      Men%c de Archivo\n",163);
		printf(" 1. Usuarios\n");
		printf(" 2. Clientes\n");
		printf(" 3. Productos\n");
		printf(" 4. Cambio de Usuario\n");
		printf(" 5. Cambio de contrase%ca\n",164);
		printf(" 6. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >6);
		switch (op){
			case 1:
				usuario();
				break;
			case 2:
				menu_clientes();
				break;
			case 3:
				productos();
				break;
			case 4:
				camb_usuario();
				break;
			case 5:
				camb_clave();
				break;
		}
	}while(op!=6);
}

void entrada_facturacion(){
	Factura datos;
	FILE *fichero;
	int repetir=0;
	
	fichero = fopen("creando_factura.txt","a+");
	do{
				
		system("cls");
				
		printf("INGRESE EL NOMBRE DEL CLIENTE: \n");
		scanf("%s",datos.cliente);
		printf("INGRESE EL NOMBRE DEL PRODUCTO \n");
		scanf("%s",datos.producto);
		printf("INGRESE EL PRECIO DEL MISMO: \n");
		scanf("%f",datos.precio);
		printf("INGRESE LA CANTIDAD: \n");
		scanf("%d",datos.cantidad);
				
			datos.subtotal = datos.precio * datos.cantidad;
			datos.impuesto = datos.subtotal * 0.15;
				
			if(datos.subtotal >= 1000){
				datos.descuento = datos.subtotal * 0.20;	
			}else{
				datos.descuento = 0;
			}
				
			datos.totalneto = datos.subtotal - datos.descuento + datos.impuesto;
			
		fprintf(fichero,"%s %s %d %.2f %.2f %.2f %.2f %.2f", datos.cliente, datos.producto, datos.cantidad, datos.precio, datos.impuesto, datos.subtotal, datos.totalneto, datos.descuento);
			
		printf("Si desea agregar otra venta, presione 0 \n");
		printf("Si desea salir al menu, presione 1 \n");
		scanf("%d",&repetir);
	}while(repetir ==0);
	fclose(fichero);
}


void salida_facturacion(){
	Factura datos;
	FILE * fichero;
 	fichero = fopen("creando_factura.txt", "r");

	system("cls");
		printf("\n\n     LISTADO DE FACTURAS  \n\n");
		while(!feof(fichero)){
			fscanf(fichero,"%s",datos.cliente);
			fscanf(fichero,"%s",datos.producto);
			fscanf(fichero,"%d",datos.cantidad);
			fscanf(fichero,"%.2f",datos.precio);
			fscanf(fichero,"%.2f",datos.impuesto);
			fscanf(fichero,"%.2f",datos.subtotal);
			fscanf(fichero,"%.2f",datos.totalneto);
			fscanf(fichero,"%.2f",datos.descuento);
		
		
			printf("*********************************************\n");
			printf("NOMBRE DEL CLIENTE: %s \n",datos.cliente);
			printf("NOMBRE DEL PRODUCTO: %s \n",datos.producto);
			printf("CANTIDAD: %d \n",datos.cantidad);
			printf("PRECIO: %.2f \n",datos.precio);
			printf("IVA: %.2f \n",datos.impuesto);
			printf("SUBTOTAL: %.2f \n",datos.subtotal);
			printf("DESCUENTO: %.2f \n",datos.descuento);
			printf("MONTO TOTAL: %.2f \n",datos.totalneto);
			
		}
		system("pause");	
		fclose(fichero);
}



void menu_movimientos(){
	/*
	 En el menú movimientos se deberán encontrar los accesos para los subsistemas: a. Nueva Factura b. Reporte de facturas
	*/
	int op;
	do{
		system("cls");
		printf("\n\n\t\t Men%c Movimientos\n",163);
		printf(" 1. Nueva Factura\n");
		printf(" 2. Reporte de facturas\n");
		printf(" 3. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >3);
		switch (op){
			case 1:
				entrada_facturacion();
				break;
			case 2:
				salida_facturacion();
				break;
		}
	}while(op!=3);	
}

void menu_ayuda (){//MENU DE AYUDA CON LOS DATOS MAS IMPORTANTES DEL SISTEMA
    int op;
    do{
		system("cls");
		printf("\n\n          Men%c de Ayuda\n",163);
		printf(" 1. Informaci%cn del Sistema\n",162);
		printf(" 2. Informaci%cn del Estudiante\n",162);
		printf(" 3. Volver al Men%c Principal\n\n",163);
		printf(" Escoja su opci%cn: ",162);
		do{
			scanf("%d",&op);
		}while(op<0 || op >3);
		switch (op){
			case 1:
				system("cls");
				printf("______________________________________ \n");
				printf("|     PROYECTO SISTEMA DE VENTAS      |\n");
				printf("_______________________________________\n");
				printf("|    Sistema de control de Venta de   |\n");
				printf("|        	  Alimentos               |\n");
				printf("_______________________________________\n");
				printf("|TECNICAS DE PROGRAMACION I(SECCION 2)|\n");
				printf("_______________________________________\n");
				printf("|         SEGUNDO SEMESTRE            |\n");
				printf("_______________________________________\n");
				printf("|        SEPTIEMBRE DE 2022           |\n");
				printf("_______________________________________\n\n\n\n");
				system("pause");
				break;
			case 2:
				system("cls");
				printf("_______________________________________ \n");
				printf("|      PROYECTO SISTEMA DE VENTAS      |\n");
				printf("_______________________________________\n");
				printf("|         AUTOR: JOSE GRATEROL        |\n");
				printf("|          CEDULA: 30.530.584         |\n");
				printf("|TECNICAS DE PROGRAMACION I(SECCION 2)|\n");
				printf("|           SEGUNDO SEMESTRE          |\n");
				printf("|          SEPTIEMBRE DE 2022         |\n");
				printf("_______________________________________\n\n\n\n");
				system("pause");
				break;
		}
	}while(op!=3);
}

int menu(){
	
	int op;
	do{
		system("cls");
		cout<<"\n\n\t BIENVENIDO A NUESTRO SISTEMA DE VENTAS... \n";
		cout<<"\n\n\t MENU PRINCIPAL\n";
		cout<<" 1. Menu Archivos\n";
		cout<<" 2. Menu Movimientos\n";
		cout<<" 3. Menu Ayuda\n";
		cout<<" 4. Salir\n";
		cout<<"Escoja una opcion...";
		do{
			scanf("%d",&op);
		}while(op<0 || op >4);
		switch (op){
			case 1:
				menu_archivos();
				break;
			case 2:
				menu_movimientos();
				break;
			case 3:
				menu_ayuda();
				break;
			case 4:
				system("cls");
				cout<<"\n\n\n EL PROGRAMA A FINALIZADO. MUCHAS GRACIAS POR USARLO.\n\n NOS VEMOS PRONTO.\n";
				cout<<"\n ATENTAMENTE: JOSE GRATEROL.\n\n\n";
				break;
		}
	}while(op!=4);
	return 0;
}

int main(){
	
	char Usuario[25];
	char Pass[25];
	int c=1;
	bool f=false;
	//estructura repetitiva
	while (c<=3 and f==false){
		system("cls");
		//Solicitar el usuario y password
		cout<<"\n\n\n\t ******************** INGRESO AL SISTEMA************************** \n\n";
		cout<<"\t\t\t Usuario (user): \t\t";
		cin.getline(Usuario,25);
		cout<<"\t\t\t Clave (Password) : \t\t";
		cin.getline(Pass,25);
		c++;
		if(strlen(Pass)>=8){
			if((strcmp(Pass,PASS)==0) && (strcmp(Usuario,USUARIO)==0)){
				f=true;
			}
			else{
				cout<<"\n\n\n\t\t *********************ERROR************************\n";
				cout<<"\t\t EL USUARIO O CLAVE SON INCORRECTOS. \n";
				cout<<"\t\t**************************************************\n";
				system("pause");
			}
		}
		else{
				cout<<"\n\n\n\t\t *********************ERROR************************\n";
				cout<<"\t\t LA CLAVE O PASSWORD DEBE TENER AL MENOS 8 CARACTERES. \n";
				cout<<"\t\t**************************************************\n";
				system("pause");
		}
	}

	system ("cls");
	if (f==true){
				//cout<<"\n\n\n\t *********************INGRESO CON EXITO!************************\n";
				//cout<<"\t BIENVENIDO AL SISTEMA. USTED INGRESO CORRECTAMENTE!. \n";
				//cout<<"\t*************************************************************\n";
				menu();
	}
	else{
		cout<<"\n\n\n\t\t *********************ERROR************************\n";
				cout<<"\t\t USTED INTENTO TRES VECES SIN EXITO. INTENTE OTRA VEZ MAS TARDE. \n";
				cout<<"\t\t**************************************************\n";
	}		
	system("pause");
}
