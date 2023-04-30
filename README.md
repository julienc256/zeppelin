# zeppelin
Calcul du lift d'un ballon gonflé à l'hélium ou l'hydrogène, en fonction de ses dimensions et du grammage de l'enveloppe

Exemple d'exécution :

    *******************************************************************************
    *********         Dirigeable de forme ellispsoide ou spherique        *********
    *******************************************************************************

    Type de volume [1-Ellipsoide] [2-Sphere]   : 2
    Diametre du ballon (en cm)                 : 100
    Grammage de l'enveloppe (en g/m2)          : 35

    Resultats :
    -----------
     --> VOLUME                      = 0.524 m3
     --> MASSE DE L'ENVELOPPE        = 109.96 g
     --> MASSE TOTALE (si Helium)    = 198.97 g
     --> MASSE TOTALE (si Hydrogene) = 154.46 g
     --> LIFT (si Helium)            = 429.35 g
     --> LIFT (si Hydrogene)         = 473.86 g
    
    Continuer (O/N) ? : O
    
    Type de volume [1-Ellipsoide] [2-Sphere]   : 1
    Longueur (grand axe) du dirigeable (en cm) : 100
    Diametre (petit axe) du dirigeable (en cm) : 50
    Grammage de l'enveloppe (en g/m2)          : 35
    
    Resultats :
    -----------
     --> VOLUME                      = 0.131 m3
     --> MASSE DE L'ENVELOPPE        = 46.98 g
     --> MASSE TOTALE (si Helium)    = 69.24 g
     --> MASSE TOTALE (si Hydrogene) = 58.11 g
     --> LIFT (si Helium)            = 87.84 g
     --> LIFT (si Hydrogene)         = 98.97 g
    
    Continuer (O/N) ? : N


# Compilation :
gcc zeppelin.c -o zeppelin

## Remarque :
Le code se compile sur n'importe quel OS (Windows, Mac OS, Linux, etc...)  
Néanmoins si l'OS n'est pas Windows, il faut enlever l'instruction #define WINDOWS à la ligne 19 du code source (ou la mettre en commentaires)

