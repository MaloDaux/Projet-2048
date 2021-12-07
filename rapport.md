# Rapport de projet

## Auteurs

- PESSEL, Malo, malo.pessel@universite-paris-saclay.fr, MI2
- MAILLE, Gabriel, gabriel.maille@universite-paris-saclay.fr, MI01

## Résumé du travail effectué

- Niveau 0: réalisée, documentée, sauf 0.7 (on a pas réussi)
- Niveau 1: réalisée, documentée, sauf le 1.4 (utilisation d'une variable globale)
- Niveau 2: réalisée, documentée, sauf 2.2
- Niveau 3: non traitée

## Démonstration

Une fonction qui m'a pris le plus de temps a été déplacement, car j'ai dû apprendre à utiliser **conio.h**, cette bibliothèque est  de base sur Windows. Cette bibliothèque a été très utile et je pense pourrai nous servir pour de futur projet


```
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
```

Pour le MakeFile j'ai dû chercher quelques informations sur internet pour savoir comment créer un fichier MakeFile et comment avoir la commande : make sur Windows, j'ai donc dû installer **GnuWin** (qui possède la commande make) et ensuite mettre en variable d'environnement le chemin pour aller au fichier bin de GnuWin.


```
! make
```

## Organisation du travail

Pour organiser ce projet nous avons surtout travaillé ensemble, on se donnait des objectifs et on travaillait ensemble sur ceux-là, ce qui nous a permis de comprendre mieux notre code. Nous travaillons soit pendant des pauses soit le soir sur Discord. Ce projet nous a pris environ 10 heures chacun. Nous avons bénéficié de l'aide d'Internet pour comprendre certaines bibliothèques.

## Prise de recul

Les plus grosses difficultés étaient souvent des erreurs d'inattention, nous avions des idées pour chaque fonction, certaines ont été très concluantes certaines un peu moins, par exemple pour les déplacements nous avons été très surpris car ils ont marché très rapidement à notre plus grande surprise. Et si nous devions refaire le projet je pense que nous essayerions d'aller plus vite pour avoir le temps de faire l'interface graphique, car ça à l'air vraiment cool à faire !


```

```
