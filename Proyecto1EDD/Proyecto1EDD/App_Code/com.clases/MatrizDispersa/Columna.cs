using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Columna
/// </summary>
public class Columna
{
    NodoColumna primero;
    NodoColumna ultimo;

    public Columna()
    {
        this.primero = null;
        this.ultimo = null;
    }

    public void insertarColumna(int dato)
    {
        NodoColumna nuevo = new NodoColumna(dato);
        if(primero == null)
        {
            primero = nuevo;
            ultimo = primero;
        }
        else
        {
            ultimo.abajo = nuevo;
            nuevo.arriba = ultimo;
            ultimo = nuevo;
        }
    }

    public void eliminarColumna(int dato)
    {
        if (primero == null)
        {
            Console.WriteLine("lateral inexistente");
        }
        else
        {
            NodoColumna temp = primero;
            NodoColumna aux = null;
            while (temp != null)
            {
                if (temp.dato == dato)
                {
                    if (aux == null)
                    {
                        primero = primero.abajo;
                        temp.abajo = null;
                        temp = primero;
                    }
                    else
                    {
                        aux.abajo = temp.abajo;
                        temp.abajo = null;
                        temp = aux.abajo;
                    }
                }
                else
                {
                    aux = temp;
                    temp = temp.abajo;
                }
            }
        }
    }

    public void mostrarColumna()
    {
        if (primero == null)
        {
            Console.WriteLine("lateral inexistente");
        }
        else
        {
            NodoColumna tmp = primero;
            while (tmp != null)
            {
                Console.WriteLine("dato: " + tmp.dato);
                tmp = tmp.abajo;
            }
        }
    }
}