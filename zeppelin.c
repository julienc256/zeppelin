/* ---------------------------------------------------------------------------------------------- */
/* Julien COPPOLANI - Programme de calculs pour aide à la conception d'enveloppe de Dirigeable RC */
/* ---------------------------------------------------------------------------------------------- */
 
/* Rappels -----------------------------------------------------------------
Volume d'une sphere de rayon r :
V = 4/3 * PI * r^3
Aire d'une sphere de rayon r :
A = 4 * PI * r^2
Volume d'une ellipsoide de demi-longueur a et demi-largeur b :
V = 4/3 * PI * a * b^2
Aire d'une ellipsoide de demi-longueur a et demi-largeur b ( a > b) :
A = 2 * PI * b * ( b + a * arcsin(e) / e ) ,  avec e = sqrt( a^2 - b^2 ) / a
----------------------------------------------------------------------------*/
 
#include <stdio.h>
#include <math.h>

#define WINDOWS

#define MASSE_VOLUMIQUE_AIR       1200.0
#define MASSE_VOLUMIQUE_HELIUM    170.0
#define MASSE_VOLUMIQUE_HYDROGENE 85.0

int main(int argc, char *argv[])
{
	int action, type;
	float longueur, diametre, grammage;
	float demi_longueur, demi_largeur, volume, aire, e, masse_enveloppe,
       lift_helium, lift_hydrogene, masse_totale_helium, masse_totale_hydrogene;
#if defined(WINDOWS)
	system("cls");
#else
	system("clear");
#endif
	printf("*******************************************************************************\n");
	printf("*********         Dirigeable de forme ellispsoide ou spherique        *********\n");
	printf("*******************************************************************************\n");
	do {
		printf("\n");
		do {
			fflush(stdin);
			printf("Type de volume [1-Ellipsoide] [2-Sphere]   : ");
			scanf("%d", &type);
		} while (type != 1 && type != 2);
		if (type == 1)
		{
			printf("Longueur (grand axe) du dirigeable (en cm) : ");
			scanf("%f", &longueur);
			printf("Diametre (petit axe) du dirigeable (en cm) : ");
			scanf("%f", &diametre);
			demi_longueur   = longueur / 200;
			demi_largeur    = diametre / 200;
			volume          = diametre * diametre * longueur * M_PI / 6E6;
			e               = sqrt(demi_longueur * demi_longueur - demi_largeur * demi_largeur) / demi_longueur;
			aire            = 2 * M_PI * demi_largeur * (demi_largeur + demi_longueur * asin(e) / e);
		}
		else
		{
			printf("Diametre du ballon (en cm)                 : ");
			scanf("%f", &diametre);
			volume          = M_PI * diametre * diametre * diametre / 6E6;
			aire            = M_PI * diametre * diametre / 1E4;
		}
		printf("Grammage de l'enveloppe (en g/m2)          : ");
		scanf("%f", &grammage);  
		masse_enveloppe = aire * grammage;
		lift_helium     = volume * (MASSE_VOLUMIQUE_AIR - MASSE_VOLUMIQUE_HELIUM) - masse_enveloppe;
		lift_hydrogene  = volume * (MASSE_VOLUMIQUE_AIR - MASSE_VOLUMIQUE_HYDROGENE) - masse_enveloppe;
		masse_totale_helium    = masse_enveloppe + volume * MASSE_VOLUMIQUE_HELIUM;
		masse_totale_hydrogene = masse_enveloppe + volume * MASSE_VOLUMIQUE_HYDROGENE;
		printf("\n");
		printf("Resultats :\n");
		printf("-----------\n");
		printf(" --> VOLUME                      = %.3f m3\n", volume);
		printf(" --> MASSE DE L'ENVELOPPE        = %.2f g\n", masse_enveloppe);
		printf(" --> MASSE TOTALE (si Helium)    = %.2f g\n", masse_totale_helium);
		printf(" --> MASSE TOTALE (si Hydrogene) = %.2f g\n", masse_totale_hydrogene);
		printf(" --> LIFT (si Helium)            = %.2f g\n", lift_helium);
		printf(" --> LIFT (si Hydrogene)         = %.2f g\n", lift_hydrogene);
		printf("\n");
		do {
			fflush(stdin);
			printf("Continuer (O/N) ? : ");
			action = getchar();
		} while (action != 'o' && action != 'O' && action != 'n' && action != 'N'); 
	} while (action == 'o' || action == 'O');
	return 0;
}
