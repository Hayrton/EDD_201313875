using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Fila
/// </summary>
public class Fila
{
    NodoFila primero;
    NodoFila ultimo;
    public Fila()
    {
        this.primero = null;
        this.ultimo = null;
    }

    public void agregarFila(int dato)
    {
        NodoFila nuevo = new NodoFila(dato);
        if(primero == null)
        {
            primero = nuevo;
            ultimo = nuevo;
        }
        else
        {
            ultimo.siguiente = nuevo;
            nuevo.anterior = ultimo;
            ultimo = nuevo;
        }
    }

    public void eliminarFila(int dato)
    {
        if (primero == null)
        {
            Console.WriteLine("Fila inexistente");
        }
        else
        {
            NodoFila temp = primero;
            NodoFila aux = null;
            while (temp != null)
            {
                if (temp.dato == dato)
                {
                    if (aux == null)
                    {
                        primero = primero.siguiente;
                        temp.siguiente = null;
                        temp = primero;
                    }
                    else
                    {
                        aux.siguiente = temp.siguiente;
                        temp.siguiente = null;
                        temp = aux.siguiente;
                    }
                }
                else
                {
                    aux = temp;
                    temp = temp.siguiente;
                }
            }
        }
    }

    public void mostrarFila()
    {
        if (primero == null)
        {
            Console.WriteLine("Fila inexistente");
        }
        else
        {
            NodoFila tmp = primero;
            while (tmp != null)
            {
                Console.WriteLine("dato: " + tmp.dato);
                tmp = tmp.siguiente;
            }
        }
    }
}