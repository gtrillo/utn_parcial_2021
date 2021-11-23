#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*)malloc (sizeof (LinkedList));
    if (this != NULL)
    {
    	this -> size = 0;
    	this ->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if (this != NULL)
	{
		returnAux = this->size;
	}
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
    (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoAuxiliar = NULL;

	if (this != NULL && nodeIndex >= 0 && ll_len(this) > nodeIndex )
	{
		nodoAuxiliar = this->pFirstNode;
		for (int i = 0; i < nodeIndex; i++)
		{
			nodoAuxiliar = nodoAuxiliar->pNextNode;
		}
	}
	return nodoAuxiliar;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNodeAnterior;
    if (this!=NULL && nodeIndex >=0 && nodeIndex <= this->size)
    {
    	pNode = (Node*)malloc(sizeof(Node));
		if (pNode != NULL)
		{
				pNode->pElement = pElement;

			if (nodeIndex == 0)
			{
				pNode ->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
				this->size++;

			}
			else
			{
				pNodeAnterior = getNode (this, nodeIndex-1);
				pNode->pNextNode =  pNodeAnterior->pNextNode;
				pNodeAnterior->pNextNode = pNode;
				this->size++;
			}
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	 if (addNode(this, this->size, pElement)==0)
    	 {
    		 returnAux = 0;
    	 }

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retornoAux = NULL;
    Node* pNode;

    if (this!= NULL && index >= 0 && this->size > index)
    {
    	pNode = getNode(this, index);
    	retornoAux = pNode->pElement;
    }
    return retornoAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux;
    if (this != NULL && this->size > index && index>=0)
    {
    	nodoAux = getNode(this, index);
    	if(nodoAux!= NULL)
		{
    		nodoAux->pElement = pElement;
		}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNodeAnterior;

    if (this != NULL && index>=0)
    {
		if (index<this->size)
		{
			if (index==0)
			{
				pNode = this->pFirstNode;
				this->pFirstNode = pNode->pNextNode;
				free(pNode);
				this->size--;
			}
			else
			{
				pNode = getNode(this, index);
				pNodeAnterior = getNode(this, index-1);
				pNodeAnterior->pNextNode = pNode->pNextNode;
				free (pNode);
				this->size--;
			}
			returnAux = 0;
		}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if (this != NULL)
    {
    	for (i = ll_len(this); i >= 0; i--)
    	{
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
		ll_clear(this);
		free(this);
		returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodoAux;

    if (this != NULL)
    {
    	for (i = 0; i< ll_len(this);i++)
    	{
    		nodoAux = getNode(this, i);
    		if (nodoAux->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
    	if (ll_len(this)>0)
    	{
    		returnAux = 0;
    	}else
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && index >=0 && index <= ll_len(this))
    {
    	if(addNode(this, index, pElement)==0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElement;
    if (this != NULL && index < ll_len(this))
    {
    	pElement = ll_get(this, index);
    	if (pElement != NULL)
    	{
    		returnAux = pElement;
    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if (this != NULL)
    {
    	returnAux = 0;
    	index = ll_indexOf(this, pElement);

    	if (index>=0)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElemento;

    if (this != NULL && this2 != NULL)
    {
    	returnAux = 0;
    	for (i = 0; i < ll_len(this); i++)
    	{
    		returnAux=1;
    		pElemento=ll_get(this2,i);
    		if(ll_contains(this, pElemento)==0)
			{
				returnAux=0;
				break;
			}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;

    if (this != NULL && from >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	for	(i = from; i<to; i++)
    	{
    		pElement=ll_get(this,i);
    		ll_add(cloneArray,pElement);
    	}
    }
    		return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;

    if (this != NULL && ll_len(this) > 0)
    {
    	cloneArray = ll_newLinkedList();
    	for (i = 0; i < ll_len(this); i++)
    	{
    		pElement = ll_get(this, i);
    		ll_add(cloneArray, pElement);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int flagSwap=1;
    void *pElementoUno;
    void *pElementoDos;

    if (this!=NULL && pFunc!=NULL)
    {
    	if(order == 0 || order == 1)
    	{
    		if(ll_len(this)>=2)
    		{
    				while(flagSwap==1)
    				{
    					flagSwap=0;

    					for(i=0;i<=ll_len(this);i++)
    					{
    						pElementoUno=ll_get(this,i);

    						pElementoDos=ll_get(this,i+1);

    						if(pElementoUno!= NULL && pElementoDos!= NULL)
    						{
    							if (order == 1)
    							{
    								if(pFunc(pElementoUno, pElementoDos)>0)
    								{
    									ll_set(this, i, pElementoDos);

    									ll_set(this, i+1, pElementoUno);

    									flagSwap=1;
    								}
    							}
    							else
    							{
								if(pFunc(pElementoUno, pElementoDos)<0)
								{
									ll_set(this, i, pElementoDos);

									ll_set(this, i+1, pElementoUno);

									flagSwap=1;
								}
    						}
    					}
    				}
    			}
    				returnAux=0;
    		}
    		else
    		{
    			returnAux=0;
    		}
    	}
  }
        return returnAux;
}

int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux = -1;
	int criterio;
	void* pAuxiliar;

	if(this != NULL && pFunc != NULL){
		//RECORRER MI LISTA
		for(int i=ll_len(this)-1; i >= 0; i--){
			//TOMO EL ELEMENTO
			pAuxiliar = ll_get(this, i);
			if(pAuxiliar != NULL)
			{
				//FILTRO
				criterio = pFunc(pAuxiliar);
				//Si criterio == 0, entonces lo elimino.
				if(criterio == 0){
					returnAux = ll_remove(this, i);
				}
			}
		}

	}
	return returnAux;
}

int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	int retorno = -1;
	void* pAuxiliar;

	//VERIFICAR NULIDAD
	if(this != NULL && pFunc != NULL){
		//RECORRER MI LISTA
		for(int i = 0; i< ll_len(this); i++)

		{
			//TOMO EL ELEMENTO
			pAuxiliar = ll_get(this, i);

			if(pAuxiliar != NULL)
			{
				//MAPEO
				pFunc(pAuxiliar);
			}
		}

		retorno = 0;
	}

	return retorno;
}
