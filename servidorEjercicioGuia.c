#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion[512];
	char respuesta[512];
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// escucharemos en el port 9050
	serv_adr.sin_port = htons(9050);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	//La cola de peticiones pendientes no podr? ser superior a 4
	if (listen(sock_listen, 4) < 0)
		printf("Error en el Listen");
	int i;
	// Atenderemos solo 10 peticione
	for(i=0;i<10;i++){
		printf ("Escuchando\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		printf ("He recibido conexi?n\n");
		//sock_conn es el socket que usaremos para este cliente
		
		// Ahora recibimos su peticion
		ret=read(sock_conn,peticion, sizeof(peticion));
		printf ("Recibida una petición\n");
		// Tenemos que a?adirle la marca de fin de string 
		// para que no escriba lo que hay despues en el buffer
		peticion[ret]='\0';
		
		//Escribimos la peticion en la consola
		
		printf ("La petición es: %s\n",peticion);
		char *p = strtok(peticion, "/");
		int codigo =  atoi (p);
		p = strtok( NULL, "/");
		char nombre[20];
		strcpy (nombre, p);
		printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
		
		if (codigo ==1) //piden la longitd del nombre
			sprintf (respuesta,"%d",strlen (nombre));
		else
			// quieren saber si el nombre es bonito
			if((nombre[0]=='M') || (nombre[0]=='S'))
			strcpy (respuesta,"SI");
			else
				strcpy (respuesta,"NO");
			
			// Enviamos la respuesta
			write (sock_conn,respuesta, strlen(respuesta));
			
			// Se acabo el servicio para este cliente
			close(sock_conn); 
		
		int main() {
	int p_i, p_f;
	char nombre[MAX], caracter;
	int i;
	
	printf("\n Introduzca la palabra: ");
	scanf ("%c", &caracter);
	i=0;
	
	while(i<MAX && caracter !='.') 
	{
		Palabra[i]=caracter;
		i**;
		scanf ("%c", &caracter);
	}
	
	p_i=0;
	p_f=i-1;
	
	while(p_i<p_f && Palabra [p_i] == Palabra[p_f])
	{
		p_i ++;
		p_f = p_f -1;
	}
	
	if(p_i >= p_f)  printf("\nLa palabra es palindroma!\n");
	else printf ("\nLa palabra no es palindroma!\n");
	
	printf ("\n\n");
	return 0;

int main (int argc, char *argv[]) {
	
	
	char peticion[100];
	char respuesta[100];
	
	strcpy (peticion, "Fahrnheit/47/Celsius/12/Celsius/22");
	
	char nombre[20];
	int grados;
	char *p = strtok (peticion, "/");
	
	while ( p!=NULL)
	{
		strcpy (nombre, p);
		p = strtok (NULL, "/");
		grados = atoi (p);
		
		if (nombre == "Fahrenheit")
			grados = (grados - 32)/(9/5);
		else grados = (grados * 9/5) + 322;
		
		sprintf (respuesta, "%s%s*%d-",respuesta, nombre, grados);
		
		p = strtok (NULL, "/");
		
		
	}
	
	respuesta [strlen (respuesta) -1] ='\0'; 
	
	printf ("Resultado: %s\n", respuesta);
	
	
	
	
	
}
			
}
	}
}
