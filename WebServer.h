// /-------------------------\
// |         Imports         |
// \-------------------------/

#include <WebServer.h>

// /-------------------------\
// |        Variables        |
// \-------------------------/

WebServer serveurWeb(80);           // Serveur web sur le port 80
String EDS;

void handleRoot() {

String content = "";


content += "<html lang='en'>";
content += "<head>";
content += "<meta charset='UTF-8'>";
content += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
content += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
content += "<title>Document</title>";    
content += "<style>.container {display: flex; align-items: center; justify-content: center; flex-direction: column; } </style>";
content += "<style>#welcome { padding-top: 40px; font-size: 24px; }</style>";
content += "<style>.status { width: 20rem;}</style>";
content += "<style>body {padding: 1rem;background: #4c268f;color: #99eeb4;height: 100vh;}</style>";
content += "<style>span {position: relative;font-family: 'Avenir Next', sans-serif;font-weight: 900;font-size: 76px;text-transform: uppercase;font-style: italic;letter-spacing: 0.07em;display: inline-block;margin-bottom: 30px;}</style>";
content += "<style>span:before {position: absolute;left: 0;top: 0;content: attr(filter-content);filter: url(#motion-blur-filter);}</style>";
content += "<Style>svg {display: none;}</Style>";
content += "</head>";
content += "<body>";
content += "<div class='container'>";
content += "<svg xmlns='http://www.w3.org/2000/svg'>";
content += "<filter id='motion-blur-filter' filterUnits='userSpaceOnUse'>";
content += "<feGaussianBlur stdDeviation='100 0'></feGaussianBlur>";
content += "</filter>";
content += "</svg>";
content += "<h1 id='welcome'>Bienvenue, </h1>";
content += "<span filter-content='Co'>Contact Tracer</span>";
content += "<h1>Etat Actuel : En bonne santé</h1>";
content += "<li><a href=\"bonneSante\">Passer à l'état \"Bonne santé\"</a></li>";
content += "<li><a href=\"etatMalade\">Passer à l'état \"Malade\"</a></li>";
content += "</body></html>";
  
  serveurWeb.send(200, "text/html", content);
}

void handleBonneSante() {

String content = "";


content += "<html lang='en'>";
content += "<head>";
content += "<meta charset='UTF-8'>";
content += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
content += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
content += "<title>Document</title>";    
content += "<style>.container {display: flex; align-items: center; justify-content: center; flex-direction: column; } </style>";
content += "<style>#welcome { padding-top: 40px; font-size: 24px; }</style>";
content += "<style>.status { width: 20rem;}</style>";
content += "<style>body {padding: 1rem;background: #4c268f;color: #99eeb4;height: 100vh;}</style>";
content += "<style>span {position: relative;font-family: 'Avenir Next', sans-serif;font-weight: 900;font-size: 76px;text-transform: uppercase;font-style: italic;letter-spacing: 0.07em;display: inline-block;margin-bottom: 30px;}</style>";
content += "<style>span:before {position: absolute;left: 0;top: 0;content: attr(filter-content);filter: url(#motion-blur-filter);}</style>";
content += "<Style>svg {display: none;}</Style>";
content += "</head>";
content += "<body>";
content += "<div class='container'>";
content += "<svg xmlns='http://www.w3.org/2000/svg'>";
content += "<filter id='motion-blur-filter' filterUnits='userSpaceOnUse'>";
content += "<feGaussianBlur stdDeviation='100 0'></feGaussianBlur>";
content += "</filter>";
content += "</svg>";
content += "<h1 id='welcome'>Bienvenue, </h1>";
content += "<span filter-content='Co'>Contact Tracer</span>";
content += "<h1>Etat Actuel : " + EDS + " </h1>";
content += "<li><a href=\"bonneSante\">Passer à l'état \"Bonne santé\"</a></li>";
content += "<li><a href=\"etatMalade\">Passer à l'état \"Malade\"</a></li>";
content += "</body></html>";
  
  serveurWeb.send(200, "text/html", content);
}

void handleEtatMalade() {

String content = "";


content += "<html lang='en'>";
content += "<head>";
content += "<meta charset='UTF-8'>";
content += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
content += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
content += "<title>Document</title>";    
content += "<style>.container {display: flex; align-items: center; justify-content: center; flex-direction: column; } </style>";
content += "<style>#welcome { padding-top: 40px; font-size: 24px; }</style>";
content += "<style>.status { width: 20rem;}</style>";
content += "<style>body {padding: 1rem;background: #4c268f;color: #99eeb4;height: 100vh;}</style>";
content += "<style>span {position: relative;font-family: 'Avenir Next', sans-serif;font-weight: 900;font-size: 76px;text-transform: uppercase;font-style: italic;letter-spacing: 0.07em;display: inline-block;margin-bottom: 30px;}</style>";
content += "<style>span:before {position: absolute;left: 0;top: 0;content: attr(filter-content);filter: url(#motion-blur-filter);}</style>";
content += "<Style>svg {display: none;}</Style>";
content += "</head>";
content += "<body>";
content += "<div class='container'>";
content += "<svg xmlns='http://www.w3.org/2000/svg'>";
content += "<filter id='motion-blur-filter' filterUnits='userSpaceOnUse'>";
content += "<feGaussianBlur stdDeviation='100 0'></feGaussianBlur>";
content += "</filter>";
content += "</svg>";
content += "<h1 id='welcome'>Bienvenue, </h1>";
content += "<span filter-content='Co'>Contact Tracer</span>";
content += "<h1>Etat Actuel : " + EDS + " </h1>";
content += "<li><a href=\"bonneSante\">Passer à l'état \"Bonne santé\"</a></li>";
content += "<li><a href=\"etatMalade\">Passer à l'état \"Malade\"</a></li>";
content += "</body></html>";
  
  serveurWeb.send(200, "text/html", content);
}

void handleCasContact() {

String content = "";


content += "<html lang='en'>";
content += "<head>";
content += "<meta charset='UTF-8'>";
content += "<meta http-equiv='X-UA-Compatible' content='IE=edge'>";
content += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
content += "<title>Document</title>";    
content += "<style>.container {display: flex; align-items: center; justify-content: center; flex-direction: column; } </style>";
content += "<style>#welcome { padding-top: 40px; font-size: 24px; }</style>";
content += "<style>.status { width: 20rem;}</style>";
content += "<style>body {padding: 1rem;background: #4c268f;color: #99eeb4;height: 100vh;}</style>";
content += "<style>span {position: relative;font-family: 'Avenir Next', sans-serif;font-weight: 900;font-size: 76px;text-transform: uppercase;font-style: italic;letter-spacing: 0.07em;display: inline-block;margin-bottom: 30px;}</style>";
content += "<style>span:before {position: absolute;left: 0;top: 0;content: attr(filter-content);filter: url(#motion-blur-filter);}</style>";
content += "<Style>svg {display: none;}</Style>";
content += "</head>";
content += "<body>";
content += "<div class='container'>";
content += "<svg xmlns='http://www.w3.org/2000/svg'>";
content += "<filter id='motion-blur-filter' filterUnits='userSpaceOnUse'>";
content += "<feGaussianBlur stdDeviation='100 0'></feGaussianBlur>";
content += "</filter>";
content += "</svg>";
content += "<h1 id='welcome'>Bienvenue, </h1>";
content += "<span filter-content='Co'>Contact Tracer</span>";
content += "<h1>Etat Actuel : " + EDS + "</h1>";
content += "<li><a href=\"bonneSante\">Passer à l'état \"Bonne santé\"</a></li>";
content += "<li><a href=\"etatMalade\">Passer à l'état \"Malade\"</a></li>";
content += "</body></html>";
  
  serveurWeb.send(200, "text/html", content);
}

void setupWebServer(){
  EDS = "Bonne sante";
  // On a besoin d'une connexion WiFi !
  if (WiFi.status() != WL_CONNECTED){setupWifi();}  // Connexion WiFi
  
  // Configuration de mon serveur web
  serveurWeb.on("/", handleRoot);
  serveurWeb.on("/bonneSante", handleBonneSante);
  serveurWeb.on("/etatMalade", handleEtatMalade);
  serveurWeb.on("/casContact", handleCasContact);
  // serveurWeb.onNotFound(handleNotFound);

  serveurWeb.begin();                                  // Démarrage du serveur
}

void loopWebServer(void) {
  serveurWeb.handleClient();
}
