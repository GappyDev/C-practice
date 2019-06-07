#pragma region STRUCTURE

struct pila
{

	int valor;
	pila *prox;

}Lista, Cola;

#pragma endregion

#pragma region ADT

//DEVUELVE VERDADERO O FALSO SI LA PILA ESTA VACIA
bool vacio(pila *p)
{

	return (p == NULL);

}

//DEVUELVE EL VALOR DEL TOPE DE LA PILA
int tope(pila *p)
{

	if (!vacio(p))
		return p->valor;

}

//APILAR UN ELEMENTO EN PILA
void apilar(pila **p, int x)
{
	

	pila *aux = new pila;
	aux->valor = x;
	aux->prox = *p;
	*p = aux;

}

//DESAPILAR TOPE DE PILA
void desapilar(pila **p)
{

	pila *aux = *p;
	*p = (*p)->prox;
	delete aux;

}
#pragma endregion

#pragma region FUNCIONES BASICAS

//MUESTRA LA PILA USANDO RECURSIVIDAD
void mostrarPila(pila **p)
{
	if (!vacio(*p))
	{

		int x = tope(*p);
		printf("\t [%i]\n", x);
		desapilar(p);
		mostrarPila(p);
		apilar(p, x);


	}

}

#pragma endregion

//TODOS LOS EJERCICIOS UTILIZAN SOLO LAS ADT Y RECURSIVIDAD

#pragma region EJERCICIOS DE UNA PILA

#pragma region ELIMINACIONES

#pragma region FUNCIONES SECUNDARIAS PARA ELIMINACIONES

//NUMERO DE OCURRENCIAS DE UN NUMERO EN LA PILA
int ocurrenciasDeN(pila **p, int n)
{
	int cont = 0;
	if (!vacio(*p))
	{

		int x = tope(*p);
		desapilar(p);
		cont = ocurrenciasDeN(p, n);
		apilar(p, x);
		if (x == n) return cont++;
		else return cont;

	}

	return 0;
}

#pragma endregion

//ELIMINAR UN ELEMENTO LA PRIMERA VEZ QUE APARECE
void eliminarPrimeraVez(pila **p, int x)
{
	if (!vacio(*p))
	{

		int y = tope(*p);
		if (y == x) desapilar(p);
		else
		{

			desapilar(p);
			eliminarPrimeraVez(p, x);
			apilar(p, y);

		}

	}

}

//ELIMINAR LA ULTIMA VEZ QUE APARECE
void eliminarUltimaVez(pila **p, int z,int ocurrenciasdez,int cont)
{
	int counter = 0;
	
	if(!vacio(*p))
	{
	
		int x = tope(*p);
		desapilar(p);
		if (x == z) counter++;
		eliminarUltimaVez(p, z, ocurrenciasdez,counter);
		if (x == z && counter == ocurrenciasdez) return;
		else
			apilar(p, x);
	
	}

}

//ELIMINAR UN ELEMENTO TODAS LAS VECES QUE APARECE
void eliminarTodasLasVeces(pila **p, int x)
{

	if (!vacio(*p))
	{


		int y = tope(*p);
		desapilar(p);
		eliminarTodasLasVeces(p, x);
		if (y != x) apilar(p, y);

	}

}

//ELIMINA REPETIDOS MENOS UNA INSTANCIA
void elliminarRep(pila **p)
{

	if (!vacio(*p))
	{

		int x = tope(*p);
		desapilar(p);
		eliminarTodasLasVeces(p, x);
		elliminarRep(p);
		apilar(p, x);

	}


}

#pragma endregion

#pragma region VOLTEAR PILA

#pragma region FUNCION SECUNDARIA

//DEJA UN ELEMENTO AL FINAL DE LA PILA
void dejarElementoAlFinal(pila **p, int x)
{

	if (vacio(*p))
		apilar(p, x);
	else
	{
	
		int y = tope(*p);
		desapilar(p);
		dejarElementoAlFinal(p, x);
		apilar(p, y);
	
	}

}

#pragma endregion


//VOLTEA LA PILA
void voltearPila(pila **p)
{

	if(!vacio(*p))
	{
	
		int x = tope(*p);
		desapilar(p);
		voltearPila(p);
		dejarElementoAlFinal(p, x);
	
	}

}

#pragma endregion

#pragma region DEJAR PARES EN EL TOPE

#pragma region FUNCIONES SECUNDARIAS 

//NUMERO IMPAR
bool impar(int n)
{

	if ((n % 2) == 0) return false;
	else return true;

}

//DEJAR IMPARES AL FONDO
void imparesAlFondo(pila **p, int n)
{

	if (vacio(*p))
		apilar(p, n);
	else
	{
		if (!impar(n))
			apilar(p, n);
		else
		{
		
			int x = tope(*p);
			desapilar(p);
			imparesAlFondo(p, n);
			apilar(p, x);
		
		}
	
	
	}

}

#pragma endregion

//DEJAR PARES EN EL TOPE
void paresAlTope(pila **p)
{

	if(!vacio(*p))
	{
		int x = tope(*p);
		desapilar(p);
		paresAlTope(p);
		imparesAlFondo(p, x);
	}

}

#pragma endregion

#pragma endregion

#pragma region EJERCICIOS DE DOS PILAS

#pragma region SUMAR PILAS DESDE EL FONDO

#pragma region FUNCIONES SECUNDARIAS

//CONTAR CANTIDAD DE ELEMENTOS
int cantidadDeElementos(pila *p,int res)
{

	if(!vacio(p))
	{
	
		int x = tope(p);
		desapilar(&p);
		res = cantidadDeElementos(p,res);
		apilar(&p, x);
		return res++;
	
	
	}

	return 0;

}

//IGUALAR CANTIDAD DE ELEMENTOS DE DOS PILAS A Y B APILANDO ZEROS DESDE EL TOPE
void igualaCDE(pila **a, pila**b)
{

	if(!vacio(*a) && !vacio(*b))
	{
		int cantA = cantidadDeElementos(*a,0), cantB = cantidadDeElementos(*b,0);

		if(cantA < cantB)
		{
		
			while (cantA<cantB)
			{
				
				apilar(a, 0);
				cantA = cantidadDeElementos(*a,0);

			}
		
		}else if(cantB<cantA)
		{
		
			while (cantB<cantA)
			{

				apilar(b, 0);
				cantB = cantidadDeElementos(*b,0);

			}
		
		
		}
	
	
	}


}
#pragma endregion

//SUMAR DOS PILAS EN UNA PILA C DESDE EL FONDO
int sumarDesdeElFondo(pila **a, pila**b, pila**c,int res)
{

	int x,y,num;

	if(!vacio(*a) && !vacio(*b))
	{
	
		x = tope(*a);
		y = tope(*b);
		desapilar(a);
		desapilar(b);
		res = sumarDesdeElFondo(a, b, c,res);
		apilar(a, x); 
		apilar(b, y);
		num = (x + y) + res;
		if(num > 9)
		{
		
			res = num / 10;
			apilar(c, num % 10);
			return res;

		}else
		{
		
			apilar(c, num);
			return 0;
		
		}
	
	}

	return 0;
}

#pragma endregion


#pragma endregion


