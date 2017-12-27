using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.IO;
using System.Diagnostics;

/// <summary>
/// Descripción breve de ListaJuego
/// </summary>
public class ListaJuego
{
    public NodoLJ primero;
    public NodoLJ ultimo;

    public ListaJuego()
    {
        this.primero = null;
        this.ultimo = null;
    }

    public void agregarLJ(ListaDJuego DATO) //LJ = lista juego
    {
        NodoLJ nuevo = new NodoLJ(DATO);
        if(primero == null)
        {
            primero = nuevo;
            ultimo = primero;
        }
        else
        {
            ultimo.siguiente = nuevo;
            nuevo.anterior = ultimo;
            ultimo = nuevo;
        }
    }
    
    public string mostrarLJ()
    {
        string dato = "";
        if(primero == null)
        {
            dato = "Lista_Vacia";
        }
        else
        {
            NodoLJ tmp = primero;
            while(tmp != null)
            {
                //Console.WriteLine("dato: " + tmp.DATOLISTA.NICKNAME);
                dato += tmp.DATOLISTA.NICKNAME + "   ";
                tmp = tmp.siguiente;
            }
        }
        return dato;
    }

    public void eliminarLJ(ListaDJuego DATO)
    {
        
        if(primero == null)
        {
            Console.WriteLine("lista jugadores vacia");
        }
        else
        {
            NodoLJ temp = primero;
            NodoLJ aux = null;
            while(temp != null)
            {
                if(temp.DATOLISTA == DATO)
                {
                    if(aux == null)
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

    public void graficarLista()
    {
        string cadena = "";
        cadena = "digraph gr{\n";
        cadena += contenidoLista();
        cadena += "\n }";
        CrearArchivo(cadena);
    }

    public String contenidoLista()
    {
        string cad = "";
        string temp1 = "";
        string temp2 = "";
        NodoLJ aux = primero;
        while(aux.siguiente != null)
        {
            cad += aux.DATOLISTA.GetHashCode() + "[label=\"" + aux.DATOLISTA.getListJuego() + "\"]";
            temp1 = aux.DATOLISTA.GetHashCode().ToString();
            temp2 = aux.siguiente.DATOLISTA.GetHashCode().ToString();
            cad += temp1 + " -> " + temp2;
        }
        return cad;
    }

    public void CrearArchivo(String texto)
    {
        string doc = @"C:\Users\Hayrton\Documents\GitHub\EDD_201313875\Proyecto1EDD\Proyecto1EDD\App_Code\com.clases\graficaLista.dot";
        string img = @"C:\Users\Hayrton\Documents\GitHub\EDD_201313875\Proyecto1EDD\Proyecto1EDD\App_Code\com.clases\grafList";
        if (!File.Exists(doc))
        {
            StreamWriter escribir = new StreamWriter(doc);
            escribir.WriteLine(texto);
            escribir.Close();
        }
        //generarImagen(doc, img);
    }

    private void generarImagen(string archivodot, string img)
    {
        Process a = new Process();
        a.StartInfo.FileName = "\"dot.exe\"";
        a.StartInfo.Arguments = "-Tpng" + archivodot + " -o " + img;
        a.StartInfo.UseShellExecute = false;
        a.Start();
        a.WaitForExit();
    }
}