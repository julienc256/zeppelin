# zeppelin
Calcul du lift d'un ballon gonflé à l'hélium ou l'hydrogène, en fonction de ses dimensions et du grammage de l'enveloppe.  

L'enveloppe d'un ballon en mylar fait environ 30g/m²

## Exemple d'exécution, sur 2 cas concrets :

Cas 1 : Dirigeable radiocommandé (forme ellipsoide), longueur 200 cm, diamètre 50 cm, enveloppe en mylar transparent  

![Dirigeable](/readme/example1_ellipsoide.jpg "Dirigeable")

Cas 2 : Ballon mylar (forme sphérique), diamètre d'environ 40 cm

![Ballon mylar](/readme/example2_sphere.jpg "Ballon mylar")

Lancement : dirigeable.exe  

    *******************************************************************************
    *********         Dirigeable de forme ellispsoide ou spherique        *********
    *******************************************************************************

    Type de volume [1-Ellipsoide] [2-Sphere]   : 1
    Longueur (grand axe) du dirigeable (en cm) : 200
    Diametre (petit axe) du dirigeable (en cm) : 50
    Grammage de l'enveloppe (en g/m2)          : 31
    
    Resultats :
    -----------
     --> VOLUME                      = 0.262 m3
     --> MASSE DE L'ENVELOPPE        = 78.46 g
     --> MASSE TOTALE (si Helium)    = 122.97 g
     --> MASSE TOTALE (si Hydrogene) = 100.72 g
     --> LIFT (si Helium)            = 191.19 g
     --> LIFT (si Hydrogene)         = 213.44 g
    
    Continuer (O/N) ? : O
    
    Type de volume [1-Ellipsoide] [2-Sphere]   : 2
    Diametre du ballon (en cm)                 : 40
    Grammage de l'enveloppe (en g/m2)          : 31

    Resultats :
    -----------
     --> VOLUME                      = 0.034 m3
     --> MASSE DE L'ENVELOPPE        = 15.58 g
     --> MASSE TOTALE (si Helium)    = 21.28 g
     --> MASSE TOTALE (si Hydrogene) = 18.43 g
     --> LIFT (si Helium)            = 18.93 g
     --> LIFT (si Hydrogene)         = 21.78 g
    
    Continuer (O/N) ? : N
    
    A:\>


## Compilation :
gcc zeppelin.c -o zeppelin

## Remarque :
Le code se compile sur n'importe quel OS (Windows, Mac OS, Linux, etc...)  
Néanmoins si l'OS n'est pas Windows, il faut enlever l'instruction #define WINDOWS à la ligne 19 du code source (ou la mettre en commentaires)

Pour avoir les messages en Anglais :  
Sous l'interpréteur de commande Windows (cmd.exe), avant de lancer l'executable, taper : set LANG=EN  
Sous Linux, taper : LANG=EN

