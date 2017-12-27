using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

/// <summary>
/// Descripción breve de WebService
/// </summary>
[WebService(Namespace = "http://tempuri.org/")]
[WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
// Para permitir que se llame a este servicio web desde un script, usando ASP.NET AJAX, quite la marca de comentario de la línea siguiente. 
// [System.Web.Script.Services.ScriptService]
public class WebService : System.Web.Services.WebService
{
    public static ListaJuego listt = new ListaJuego();
    //public static ListaDJuego ListJ;
    public WebService()
    {

        //Elimine la marca de comentario de la línea siguiente si utiliza los componentes diseñados 
        //InitializeComponent(); 
    }

    [WebMethod]
    public string HelloWorld()
    {
        return "Hola a todos";
    }

    [WebMethod]
    public void addListaJ(string nick, int despliegue, int sobrevivientes, int destruidas, bool estado)
    {
        listt.agregarLJ(new ListaDJuego(nick, despliegue, sobrevivientes, destruidas, estado));
        //listt.graficarLista();
        //return;
    }

    [WebMethod]
    public string mostrarLista(){

        return listt.mostrarLJ();
    }

}
