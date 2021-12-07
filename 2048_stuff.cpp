#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "2048_stuff.h"

#define KEY_UP 72	 // Définition de 72 (le code de la flèche vers le haut) a KEY_UP
#define KEY_DOWN 80	 // Définition de 80 (le code de la flèche vers le bas) a KEY_DOWN
#define KEY_LEFT 75	 // Définition de 75 (le code de la flèche vers la gauche) a KEY_LEFT
#define KEY_RIGHT 77 // Définition de 77 (le code de la flèche vers la droite) a KEY_RIGHT
#define QUIT 'q'	 // Définition de 'q' a QUIT

using namespace std;

typedef vector<vector<int>> Plateau; // Définit un type pour ne pas à avoir à réécrire vector<vector<int>>
int SCORE = 0;						 // Création d'une variable globale
/** plateauVide genère un Plateau 4*4 avec que des 0
 * @return le plateau vide
 **/

Plateau plateauVide()
{
	Plateau plateau;	  // Création d'un tableau de tableau
	plateau = Plateau(4); // Alloue sa taille
	for (int i = 0; i < plateau.size(); i++)
	{
		plateau[i] = vector<int>(4); // Boucle pour définir la deuxième dimension
	}
	for (int i = 0; i < plateau.size(); i++)
	{
		for (int j = 0; j < plateau.size(); j++)
		{
			plateau[i][j] = 0; // Double boucle pour le remplir le plateau de 0
		}
	}
	return plateau; // Renvoi le plateau
}

void plateauVide_test()
{
	Plateau plateau = plateauVide();
	for (int i = 0; i < plateau.size(); i++)
	{
		for (int j = 1; j < plateau.size(); j++)
		{
			assert(plateau[i][j] == 0);
		}
	}
}

/** tireDeuxOuQuatre tire aléatoirment un 2 ou un 4
 * @return un 2 ou un 4
 **/

int tireDeuxOuQuatre()
{
	int x = rand() % 10; // Choisi aléatoirement un nombre entre 0 et 9
	if (x == 5)
	{
		return 4; // Si x = 5 ça renvoie 4
	}
	return 2; // Sinon ça renvoie 2
}

void tireDeuxOuQuatre_test()
{
	int x = tireDeuxOuQuatre();
	assert((x == 2) or (x == 4));
}

/** plateauUnutial genère un Plateau 4*4 avec que deux nombre aléatoirement placé
 * @return le plateau avec deux nombre placé aléatoirment
 **/

Plateau plateauInitial()
{
	Plateau plateau = plateauVide(); // Appel du plateau vide
	srand(time(NULL));
	int x = rand() % 4;		 // Variable aléatoire entre 0 et 4
	int y = rand() % 4;		 // Variable aléatoire entre 0 et 4
	int k = rand() % 4;		 // Variable aléatoire entre 0 et 4
	int j = rand() % 4;		 // Variable aléatoire entre 0 et 4
	while (x == k && y == j) // Condition si les nombres choisis sont les mêmes
	{
		srand(time(NULL));
		k = rand() % 4; // Change la varaible
		j = rand() % 4; // Change la varaible
	}
	plateau[x][y] = tireDeuxOuQuatre();
	plateau[k][j] = tireDeuxOuQuatre();

	return plateau; // Renvoie le plateau modifié
}

void plateauInitial_test()
{
	int nbr = 0;
	Plateau plateau = plateauInitial();
	for (int i = 0; i < plateau.size(); i++)
	{
		for (int j = 0; j < plateau.size(); j++)
		{
			if (plateau[i][j] != 0)
			{
				nbr = nbr + 1;
			}
		}
	}
	assert(nbr == 2);
}

/** déplace les nombres d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/

Plateau deplacementGauche(Plateau plateau)
{
	int x = 0;
	while (x < 4) // Pour que les valeurs aillent jusqu'au bout
	{
		for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
		{
			for (int j = 1; j < plateau.size(); j++)
			{
				if (plateau[i][j - 1] != 0)
				{
					if (plateau[i][j - 1] == plateau[i][j])
					{
						plateau[i][j - 1] = plateau[i][j] + plateau[i][j - 1];
						plateau[i][j] = 0;
						SCORE = SCORE + plateau[i][j - 1]; // augmentation du score
					}
				}
				else
				{
					plateau[i][j - 1] = plateau[i][j];
					plateau[i][j] = 0;
				}
			}
		}
		x++;
	}
	return plateau;
}

void deplacementGauche_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int i = 0; i < p.size(); i++)
	{
		p[i] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 2;
	p[0][2] = 0;
	p[0][3] = 2;

	p[1][0] = 0;
	p[1][1] = 2;
	p[1][2] = 0;
	p[1][3] = 2;

	p[2][0] = 0;
	p[2][1] = 2;
	p[2][2] = 0;
	p[2][3] = 2;

	p[3][0] = 0;
	p[3][1] = 2;
	p[3][2] = 0;
	p[3][3] = 2;
	Plateau po;		 // création d'un tableau de tableau
	po = Plateau(4); // alloue sa taille
	for (int j = 0; j < po.size(); j++)
	{
		po[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	po[0][0] = 4;
	po[0][1] = 0;
	po[0][2] = 0;
	po[0][3] = 0;

	po[1][0] = 4;
	po[1][1] = 0;
	po[1][2] = 0;
	po[1][3] = 0;

	po[2][0] = 4;
	po[2][1] = 0;
	po[2][2] = 0;
	po[2][3] = 0;

	po[3][0] = 4;
	po[3][1] = 0;
	po[3][2] = 0;
	po[3][3] = 0;
	assert(deplacementGauche(p) == po);
}

/** déplace les nombres d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/

Plateau deplacementDroite(Plateau plateau)
{
	int x = 0;
	while (x < 4) // Pour que les valeurs aillent jusqu'au bout
	{
		for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
		{
			for (int j = 0; j < plateau.size() - 1; j++)
			{
				if (plateau[i][j + 1] != 0)
				{
					if (plateau[i][j + 1] == plateau[i][j])
					{
						plateau[i][j + 1] = plateau[i][j] + plateau[i][j + 1];
						plateau[i][j] = 0;
						SCORE = SCORE + plateau[i][j + 1];
					}
				}
				else
				{
					plateau[i][j + 1] = plateau[i][j];
					plateau[i][j] = 0;
				}
			}
		}
		x++;
	}
	return plateau;
}

void deplacementDroite_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int i = 0; i < p.size(); i++)
	{
		p[i] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 2;
	p[0][2] = 0;
	p[0][3] = 2;

	p[1][0] = 0;
	p[1][1] = 2;
	p[1][2] = 0;
	p[1][3] = 2;

	p[2][0] = 0;
	p[2][1] = 2;
	p[2][2] = 0;
	p[2][3] = 2;

	p[3][0] = 0;
	p[3][1] = 2;
	p[3][2] = 0;
	p[3][3] = 2;
	Plateau po;		 // création d'un tableau de tableau
	po = Plateau(4); // alloue sa taille
	for (int j = 0; j < po.size(); j++)
	{
		po[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	po[0][0] = 0;
	po[0][1] = 0;
	po[0][2] = 0;
	po[0][3] = 4;

	po[1][0] = 0;
	po[1][1] = 0;
	po[1][2] = 0;
	po[1][3] = 4;

	po[2][0] = 0;
	po[2][1] = 0;
	po[2][2] = 0;
	po[2][3] = 4;

	po[3][0] = 0;
	po[3][1] = 0;
	po[3][2] = 0;
	po[3][3] = 4;
	assert(deplacementDroite(p) == po);
}

/** déplace les nombres d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/

Plateau deplacementHaut(Plateau plateau)
{
	int x = 0;
	while (x < 4) // Pour que les valeurs aillent jusqu'au bout
	{
		for (int i = 1; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
		{
			for (int j = 0; j < plateau.size(); j++)
			{
				if (plateau[i - 1][j] != 0)
				{
					if (plateau[i - 1][j] == plateau[i][j])
					{
						plateau[i - 1][j] = plateau[i][j] + plateau[i - 1][j];
						plateau[i][j] = 0;
						SCORE = SCORE + plateau[i - 1][j];
					}
				}
				else
				{
					plateau[i - 1][j] = plateau[i][j];
					plateau[i][j] = 0;
				}
			}
		}
		x++;
	}
	return plateau;
}

void deplacementHaut_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int i = 0; i < p.size(); i++)
	{
		p[i] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 2;
	p[0][2] = 0;
	p[0][3] = 2;

	p[1][0] = 2;
	p[1][1] = 0;
	p[1][2] = 2;
	p[1][3] = 0;

	p[2][0] = 0;
	p[2][1] = 2;
	p[2][2] = 0;
	p[2][3] = 2;

	p[3][0] = 2;
	p[3][1] = 0;
	p[3][2] = 2;
	p[3][3] = 0;
	Plateau po;		 // création d'un tableau de tableau
	po = Plateau(4); // alloue sa taille
	for (int j = 0; j < po.size(); j++)
	{
		po[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	po[0][0] = 4;
	po[0][1] = 4;
	po[0][2] = 4;
	po[0][3] = 4;

	po[1][0] = 0;
	po[1][1] = 0;
	po[1][2] = 0;
	po[1][3] = 0;

	po[2][0] = 0;
	po[2][1] = 0;
	po[2][2] = 0;
	po[2][3] = 0;

	po[3][0] = 0;
	po[3][1] = 0;
	po[3][2] = 0;
	po[3][3] = 0;
	assert(deplacementHaut(p) == po);
}

/** déplace les nombres d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/

Plateau deplacementBas(Plateau plateau)
{
	int x = 0;
	while (x < 4) // Pour que les valeurs aillent jusqu'au bout
	{
		for (int i = 0; i < plateau.size() - 1; i++) // Double boucle pour regarder le tableau a deux dimensions
		{
			for (int j = 0; j < plateau.size(); j++)
			{
				if (plateau[i + 1][j] != 0)
				{
					if (plateau[i + 1][j] == plateau[i][j])
					{
						plateau[i + 1][j] = plateau[i][j] + plateau[i + 1][j];
						plateau[i][j] = 0;
						SCORE = SCORE + plateau[i + 1][j];
					}
				}
				else
				{
					plateau[i + 1][j] = plateau[i][j];
					plateau[i][j] = 0;
				}
			}
		}
		x++;
	}
	return plateau;
}

void deplacementBas_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int i = 0; i < p.size(); i++)
	{
		p[i] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 2;
	p[0][2] = 0;
	p[0][3] = 2;

	p[1][0] = 2;
	p[1][1] = 0;
	p[1][2] = 2;
	p[1][3] = 0;

	p[2][0] = 0;
	p[2][1] = 2;
	p[2][2] = 0;
	p[2][3] = 2;

	p[3][0] = 2;
	p[3][1] = 0;
	p[3][2] = 2;
	p[3][3] = 0;
	Plateau po;		 // création d'un tableau de tableau
	po = Plateau(4); // alloue sa taille
	for (int j = 0; j < po.size(); j++)
	{
		po[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	po[0][0] = 0;
	po[0][1] = 0;
	po[0][2] = 0;
	po[0][3] = 0;

	po[1][0] = 0;
	po[1][1] = 0;
	po[1][2] = 0;
	po[1][3] = 0;

	po[2][0] = 0;
	po[2][1] = 0;
	po[2][2] = 0;
	po[2][3] = 0;

	po[3][0] = 4;
	po[3][1] = 4;
	po[3][2] = 4;
	po[3][3] = 4;
	assert(deplacementBas(p) == po);
}

/** déplace les nombres d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le Plateau
 *  @return le Plateau déplacé dans la direction
 **/

Plateau deplacement(Plateau plateau)
{
	bool en_moov = false; // Création d'un booléen
	while (en_moov == false)
	{
		char c = _getch(); // getch permet de lire les caractères du clavier avec le code ascii
		switch (c)		   // utilise ce qui va nous renvoyer le code ascii et le transforme pour que c++ puisse le compiler
		{
		case KEY_UP:							  // Si KEY_UP est appuyé alors il exécute la suite
			plateau = deplacementHaut(plateau);	  // Déplacement du plateau vers le haut
			en_moov = true;						  // en_moov deviens true donc la fonction déplacement s'arrête
			break;								  // Arrête de regarder les touches appuyées
		case KEY_DOWN:							  // Si KEY_DOWN est appuyé alors il exécute la suite
			plateau = deplacementBas(plateau);	  // Déplacement du plateau vers la gauche
			en_moov = true;						  // en_moov deviens true donc la fonction déplacement s'arrête
			break;								  // Arrête de regarder les touches appuyées
		case KEY_LEFT:							  // Si KEY_LEFT est appuyé alors il exécute la suite
			plateau = deplacementGauche(plateau); // Déplacement du plateau vers le bas
			en_moov = true;						  // en_moov deviens true donc deplacement s'arrête
			break;								  // Arrête de regarder les touches appuyées
		case KEY_RIGHT:							  // Si KEY_RIGHT est appuyé alors il exécute la suite
			plateau = deplacementDroite(plateau); // Déplacement du plateau vers la droite
			en_moov = true;						  // en_moov deviens true donc la fonction déplacement s'arrête
			break;								  // Arrête de regarder les touches appuyées
		case QUIT:								  // Si QUIT est appuyé alors il exécute la suite
			cout << endl
				 << "Fin de partie ! :-)" << endl;
			en_moov = true; // en_moov deviens true donc la fonction déplacement s'arrête
			Sleep(3000);	// Il attend 3secs
			exit(0);		// Le terminal se ferme
			break;
		}
	}
	return plateau;
}

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/

bool estTermine(Plateau plateau)
{
	for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
	{
		for (int j = 0; j < plateau[0].size(); j++)
		{
			if (plateau[i][j] == 0) // S'il y a un 0 alors true est renvoyé
			{
				return true;
			}
		}
	}
	return false; // Renvoi false dès qu'il y a un nombre
}

void estTermine_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int j = 0; j < p.size(); j++)
	{
		p[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 0;
	p[0][2] = 0;
	p[0][3] = 0;

	p[1][0] = 0;
	p[1][1] = 0;
	p[1][2] = 0;
	p[1][3] = 0;

	p[2][0] = 0;
	p[2][1] = 0;
	p[2][2] = 0;
	p[2][3] = 0;

	p[3][0] = 4;
	p[3][1] = 4;
	p[3][2] = 4;
	p[3][3] = 4;
	assert(estTermine(p) == true);
	Plateau po;		 // création d'un tableau de tableau
	po = Plateau(4); // alloue sa taille
	for (int j = 0; j < po.size(); j++)
	{
		po[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	po[0][0] = 2;
	po[0][1] = 4;
	po[0][2] = 2;
	po[0][3] = 4;

	po[1][0] = 4;
	po[1][1] = 2;
	po[1][2] = 4;
	po[1][3] = 2;

	po[2][0] = 2;
	po[2][1] = 4;
	po[2][2] = 2;
	po[2][3] = 4;

	po[3][0] = 4;
	po[3][1] = 2;
	po[3][2] = 4;
	po[3][3] = 2;
	assert(estTermine(po) == false);
}

/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/

bool estGagnant(Plateau plateau)
{
	for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
	{
		for (int j = 0; j < plateau[0].size(); j++)
		{
			if (plateau[i][j] == 2048) // S'il y a un 2048 alors true est renvoyé
			{
				return true;
			}
		}
	}
	return false; // Renvoi false tant qu'il n'y a pas de 2048
}

void estGagnant_test()
{
	Plateau p;		// création d'un tableau de tableau
	p = Plateau(4); // alloue sa taille
	for (int j = 0; j < p.size(); j++)
	{
		p[j] = vector<int>(4); // bloucle pour définir la deuxième dimension
	}
	p[0][0] = 0;
	p[0][1] = 32;
	p[0][2] = 0;
	p[0][3] = 0;

	p[1][0] = 0;
	p[1][1] = 2;
	p[1][2] = 64;
	p[1][3] = 16;

	p[2][0] = 0;
	p[2][1] = 0;
	p[2][2] = 2048;
	p[2][3] = 0;

	p[3][0] = 0;
	p[3][1] = 4;
	p[3][2] = 4;
	p[3][3] = 4;
	assert(estGagnant(p) == true);
	p[2][2] = 0;
	assert(estGagnant(p) == false);
}

/** affiche un Plateau
 * @param plateau le Plateau
 **/

string dessine(Plateau plateau)
{
	cout << "******************";
	int l_nbr = 1;
	for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
	{
		for (int j = 0; j < plateau.size(); j++)
		{
			if ((floor(log10(plateau[i][j])) + 1) > l_nbr)
			{
				l_nbr = (floor(log10(plateau[i][j])) + 1); // Calcul du nombre de caractères d'un entier (16 = 2)
			}
		}
	}
	for (int i = 0; i < l_nbr - 1; i++) // Boucle pour ajouter 1 étoile dès qu'il y a un nombre avec plus d'un caractère
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < plateau.size(); i++) // Double boucle pour regarder le tableau a deux dimensions
	{
		for (int j = 0; j < plateau.size(); j++)
		{
			if (plateau[i][j] == 0)
			{
				cout << " * "
					 << " ";
			}
			else
			{
				cout << " * " << plateau[i][j];
			}
		}
		cout << " * " << endl
			 << "******************";
		for (int i = 0; i < l_nbr - 1; i++) // Double boucle pour regarder le tableau a deux dimensions
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	return "";
}

/** place un deux ou un quatre aléatoirement sur les cases libre
 * @param plateau un plateau
 * @return le plateau avec un deux ou un quatre en plus
 **/

Plateau placeDeuxOuQuatre(Plateau plateau)
{
	srand(time(NULL));
	int x = rand() % 4;		   // Choisis un nombre aléatoire entre 0 et 3
	int y = rand() % 4;		   // Choisis un nombre aléatoire entre 0 et 3
	while (plateau[x][y] != 0) // Pour que le nombre ne prenne pas la place d'un nombre déjà existant
	{
		srand(time(NULL));
		x = rand() % 4; // Choisis un nombre aléatoire entre 0 et 3
		y = rand() % 4; // Choisis un nombre aléatoire entre 0 et 3
	}
	plateau[x][y] = tireDeuxOuQuatre(); // Ajoute un deux ou un quatre dans le plateau aléatoirement
	return plateau;
}

void placeDeuxOuQuatre_test()
{
	int nbr = 0;
	Plateau plateau = plateauInitial();
	for (int i = 0; i < plateau.size(); i++)
	{
		for (int j = 0; j < plateau.size(); j++)
		{
			if (plateau[i][j] == 2)
			{
				nbr = nbr + 1;
			}
			if (plateau[i][j] == 4)
			{
				nbr = nbr + 2;
			}
		}
	}
	assert(nbr == 2 or nbr == 1);
}

/** place un deux ou un quatre aléatoirement sur les cases libre **/

void game()
{
	Plateau plateau = plateauInitial();
	dessine(plateau);
	while (estTermine(plateau) == true or estGagnant(plateau) == false) // Pour que le jeu ne s'arrête que s'il a gagné ou si c'est fini
	{
		cout << "Appuyer sur une fleche pour vous deplacer";
		plateau = deplacement(plateau);
		plateau = placeDeuxOuQuatre(plateau);
		system("cls"); // Actualisation du terminal
		dessine(plateau);
		cout << "SCORE : " << SCORE << endl;
	}
	cout << "Fin de partie ! :-)" << endl;
	exit(0); // Ferme le terminal
}