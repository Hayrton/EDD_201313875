using System;
using System.Collections.Generic;
using System.Text;

namespace ArbolBB
{
    class Arbol
    {
        NodoABB raiz;

        public void Insertar(int dato)
        {
            if (raiz == null)
                raiz = new NodoABB(dato);
            else
                Insertar(dato, raiz);
        }

        public void Insertar(int dato, NodoABB temp)
        {
            if(dato < temp.dato)
            {
                if(temp.izq == null)
                {
                    NodoABB nuevo = new NodoABB(dato);
                    temp.izq = nuevo;
                }
                else
                {
                    Insertar(dato, temp.izq);
                }
            }
            else
            {
                if(dato > temp.dato)
                {
                    if(temp.der == null)
                    {
                        NodoABB nuevo = new NodoABB(dato);
                        temp.der = nuevo;
                    }
                    else
                    {
                        Insertar(dato, temp.der);
                    }
                }
            }
        }

        public void PreOrden(NodoABB temp)
        {
            if(temp != null)
            {
                Console.Write(temp.dato + "  ");
                PreOrden(temp.izq);
                PreOrden(temp.der);
            }
        }

        public void EnOrden(NodoABB temp)
        {
            if(temp != null)
            {
                EnOrden(temp.izq);
                Console.Write(temp.dato + "  ");
                EnOrden(temp.der);
            }
            
        }

        public void PostOrden(NodoABB temp)
        {
            if(temp != null)
            {
                PostOrden(temp.izq);
                PostOrden(temp.der);
                Console.Write(temp.dato + "  ");
            }
        }

        public NodoABB getRaiz()
        {
            return raiz;
        }
    }
}
