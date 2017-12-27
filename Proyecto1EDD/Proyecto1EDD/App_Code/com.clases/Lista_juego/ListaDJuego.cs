using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de ListaDJuego
/// </summary>
public class ListaDJuego
{
    public string NICKNAME;
    public int NO_DESPLEGADA;
    public int NO_SOBREVIVIENTE;
    public int NO_DESTRUIDA;
    public bool ESTADO_J;

    public ListaDJuego(string nick, int despliegue, int sobreviente, int destruido, bool estado)
    {
        this.NICKNAME = nick;
        this.NO_DESPLEGADA = despliegue;
        this.NO_SOBREVIVIENTE = sobreviente;
        this.NO_DESTRUIDA = destruido;
        this.ESTADO_J = estado;
    }

    public String getListJuego()
    {
        return "Nickname: " + NICKNAME + "\nDespliegue: " + NO_DESPLEGADA + "\nSobrevivientes: " + NO_SOBREVIVIENTE + "\nDestruidos: " + NO_DESTRUIDA + "\nEstado: " + ESTADO_J;
    }
}