using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de NodoDisperso
/// </summary>
public class NodoDisperso
{
    public NodoDisperso derecho;
    public NodoDisperso izquierdo;
    public NodoDisperso arriba;
    public NodoDisperso abajo;
    public NodoDisperso fondo;
    public NodoDisperso adelante;

    public int x;
    public int y;
    public int nivel;
    public string dato;

    public NodoDisperso(int fila, int columna, int nivel, string dato)
    {
        this.x = columna;
        this.y = fila;
        this.nivel = nivel;
        this.dato = dato;
        this.derecho = null;
        this.izquierdo = null;
        this.arriba = null;
        this.abajo = null;
        this.fondo = null;
        this.adelante = null;
    }
}