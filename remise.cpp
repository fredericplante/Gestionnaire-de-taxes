/*
**	Systeme de gestion de la ville Saint-Erable!
**	Auteur: Fr�d�ric Plante
**	Date: 27-octobre-2017
**	Mon but au travers ce travail etait de laisser
**	une trace, Faire une marque, Je crois que mon 
**	objectif est atteint. :D
**	Je l'ai fait sans for() pour le plaisir.
*/

#include<Windows.h> // Ajout d'un titre et modification des dimensions de la console
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

	/*
	*	5. D�finissez une structure (struct) et nommez-la � resident �.
	*	Cette structure permettra de regrouper tous les champs qui 
	*	repr�sentent un r�sident. La structure � resident � doit �tre
	*	visible de partout dans le programme.
	*/

struct resident 
{

   int Identifiant;
   string nom;
   string prenom;
   int NAS;
   string nCivique;
   string Rue;
   string Ville;
   string arrondissement;
   int superficie;

};
/*
struct systeme 
{

   const char Titre[] = "Syst�me de gestion de la ville de Saint-�rable!";;
   string nomdefichie = "residents.txt";
   int nbResident;
   const int nbcasMAX = 1000;

};
*/

const int nbcasMAX = 1000;									//Vous pr�voyez une augmentation de la population?
const char  Titre[] = "Syst�me de gestion de la ville de Saint-�rable!";
const string nomdefichier = "residents.txt";				//Elle sera modifi�e dans une r�vision future du syst�me.
const string  mode_Affichage = "MODE CON LINES=24 COLS=100";
const string Etiquette_nbLigne = "LINES=";
const string Etiquette_nbCollone = "COLS=";

const string texte_Menus[20][25] =							//Tout le texte du programme est charg� depuis ici
{															//Il serait simple de cr�er un fichier langue.txt
															//et ainsi adapter le programme pour d'autres langues.
	{	// 0 Menu principale

	"\t\t\tSyst�me de gestion de la ville\n",
	" (1) Nouveau(x) r�sident(s)\n",
	" (2) Afficher les informations des r�sidents\n"
	" (3) Modifier r�sident(s)\n",
	" (4) Supprimer r�sident(s)\n",
	" (5) TAXES\n",
	" (6) Sortir du programme\n", 
	"\n\n",
	"Votre choix ==>",
	"",
	"\nVille Saint-�rable, � bient�t!\n",
	""

	},

	{	// 1 Nouveau r�sident(s)

	"\n\tCR�ATION DE DOSSIER R�SIDENT\n",
	"\n",
	" (1) ajouter un r�sident\n",
	" (2) Revenir au menu principal\n",
	" (3) Sortir du programme\n",
	"\n",
	"\n",
	"Votre choix ==>",
	"",
	"NOM",
	"PR�NOM",
	"NAS",
	"NUM�RO CIVIQUE",
	"RUE",
	"ARRONDISSEMENT", 
	"VILLE",
	"\nEntrez la superficie en m� ou pi�\nsuivi d'un [espace] et de la lettre [m] ou [p] ",
	"",

	},

	{	// 2 Afficher les informations

	"\n\tAffichage des donn�es des r�sidents\n\nVoulez-vous\n\n",
	" (1) Afficher les r�sidents de la ville\n",
	" (2) Afficher les r�sidents dans l'ordre alphab�tique\n",
	" (3) Afficher les r�sidents dans l'ordre croissant du NAS\n",
	" (4) Revenir au menu principal\n",
	" (5) Sortir du programme\n",
	"\n\n",
	"Votre choix ==>",
	"",
	"id",
	"nom",
	"pr�nom",
	"NAS",
	"numciv",
	"rue",
	"arrond",
	"ville",
	"m�"

	},

	{	// 3 Modifier r�sident(s)

	"\n\tModification des donn�es d'un r�sident\n\n",
	"\nIdentidiant du r�sident ==>",
	"",
	"Modifier...\n"
	" (1) Le nom\n",
	" (2) Le pr�nom\n",
	" (3) Le num�ro civique\n",
	" (4) Le rue\n",
	" (5) L'arrondissement\n",
	" (6) Le ville\n",
	" (7) Le superficie\n",
	"\n",
	" (8) Valider les modifications...\n",
	"\n",
	"Votre choix ==> ",	
	"",
	" (1) Modifier un autre r�sident\n",
	" (2) Revenir au menu principal\n"
	" (3) Sortir du programme\n",
	" \n\n",
	"Votre choix ==> ",
	"",
	"\nModifications effectu�es avec succ�s!",

	},

	{	// 4 Supprimer r�sident(s) �a, c'est quand le r�sident ne paye pas, on le supprime de la liste.

	"\n\tSuppression d'un r�sident\n\n",
	" (1) Supprimer un r�sident\n",
	" (2) Revenir au menu principal\n",
	" (3) Sortir du programme\n",
	" \n\n",
	"Votre choix ==>",
	"",
	"\n",
	"Identifiant du r�sident ==>",
	"\t\t�tes-vous s�r de vouloir supprimer ce r�sident du registre (o/n) ==>",
	"",
	"Le r�sident � �t� supprim� avec succ�s!",
	""

	},

	{	// 5 Les taxes, le bout qui justifie le reste, selon la plupart, sauf moi, je trouve �a poche.

	"\n\tITEM DE TAXATION\n\n Entrez un taux de taxation au ($/m�) pour d�buter la simulation ==>",
	"",
	"Taux actuel:",
	"\n",
	"Total des taxes recueillies par la ville: ",
	"\n",
	"R�sident qui paye le plus de taxe:",
	"\n\n",
	" (1) Revenir au menu principal\n",
	" (2) Sortir du programme\n",
	"\n\n",
	"Votre choix ==>",
	"",

	},
}; 

	/*
	*	2. 	Pour chaque option du menu, vous d�finissez une fonction.
	*/

//Fonctions menu

bool menuPrincipal(resident[]);
bool ajouterResidents(resident[] );
bool afficherInfosResidents(resident[]);
bool modifierResidents(resident[]);
bool supprimerResidents(resident[]);
bool taxes(resident[]);

//Fonctions de services

void remplirTabResidents(resident[]);
void reecrireFichier(resident[]);
void interchanger_position(resident[], int, int);
void copierGrille(resident[], resident[],int);
void tri_Selection_Nom_Croi(resident[]);
void tri_Selection_NAS_Croi(resident[]);
void ajouterunResidents(resident[] ,   int ,  string ,   string ,  string , string , int ,  string , string  , int );
void pause();

//Fonctions de recherche

int rechercheIndiceRes(resident[]);
int rechercherIndiceRes(resident[], int);
int rechercheSuperMax(resident[]);
int NouvelIdentifiant(resident[]);
int trouver_une_valeur_par_Etiquette(string, string); 

//Fonctions d'entr�e

char  demandeCaractere(string);
string demandeTexte(string);
int demandeEntier(string);
int ConvertionPaM(string);
float demandeFloat(string titre);

// Fonctions d'affichage

bool afficherTableauResidents(resident[], int);
void afficherSansTri(resident[]);
string afficherart();
string afficheur_de_menu(int ,int);
string anc( int , string );
void afficher_entete();
void afficher_dossier( resident, int);
void efface();

int nbResident;		//La seule variable visible de partout dans le programme

int main()
{


	setlocale(LC_ALL, "");
	SetConsoleTitle(Titre);
	system((char*)mode_Affichage.c_str()); // �a en prend plus quand on ajoute la Ville

	/*
	*	Vous pr�voyez aussi d�clarer, dans la fonction principale, 
	*	un tableau de type � r�sident � pour contenir les
	*	informations de tous les r�sidents de la ville.
	*/

	resident leResident[nbcasMAX];

	/*
	*	Au d�marrage de l�ex�cution, la fonction � remplirTabResidents� 
	*	remplit le tableau des r�sidents � partir du fichier (s�il existe)
	*/

	remplirTabResidents(leResident);

	while(true)
		if(!menuPrincipal(leResident))break;

	reecrireFichier(leResident);
	cout << texte_Menus[0][9] << endl;

	pause();
	return 0;

}

bool menuPrincipal(resident leResident[])
{

	/*
	1. 	Vous allez cr�er des menus et des sous-menus pour demander
	*	� l�utilisateur de choisir une op�ration � effectuer parmi 
	*	plusieurs possibles. Chaque menu ou sous-menu doit �tre 
	*	affich� en haut de la console (effacer la console apr�s 
	*	chaque op�ration). Vous devez aussi �tre capable de revenir 
	*	au menu principal � partir d�un sous-menu.
	*
	*/

	/*
	*	Fonction � menuPrincipal � contient le menu principal et 
	*	il est possible d�atteindre les autres sous-menus.
	*/

	switch (demandeCaractere(afficheur_de_menu(0,0))) //Voil� le menu principal.
	{

		case '1':

			return ajouterResidents(leResident);

		case '2':

			return afficherInfosResidents(leResident);

		case '3':

			return modifierResidents(leResident); 

		case '4':

			return supprimerResidents(leResident);

		case '5':

			return taxes(leResident);

		case '6':

			return false;

		default:

			return true;

	}

}

bool ajouterResidents(resident leResident[]) 
{

	/*
	*	4. Chaque ligne de ce fichier contiendra
	*	les donn�es d�un r�sident : son identifiant 
	*	unique (un num�ro commen�ant � 1 et augmentant
	*	progressivement pour chaque nouveau r�sident),
	*	son nom, son pr�nom, son NAS (num�ro d�assurance
	*	sociale), le num�ro civique, la rue, la ville, 
	*	l�arrondissement ainsi que la superficie de son 
	*	terrain.
	*
	*	Le champ de la superficie devra �tre en m�tre dans 
	*	le fichier mais l�usager du programme devra pouvoir 
	*	entrer cette superficie soit en m2 ou en pi2. S�il 
	*	entre une valeur en pi2, votre programme convertira 
	*	la valeur saisie en m2.
	*
	*	NB : 1 pi2 = 1 / 10.76 m2
	*/

	int col2 =17;

	while (true)
	{

		int elem=9	;

		switch (demandeCaractere(afficheur_de_menu(1,0)))
		{

			case '1':	

	/*
	*	Fonction � ajouterResidents � permet d�ajouter un ou plusieurs nouveaux r�sidents
	*/

				ajouterunResidents
				(

					leResident,
					ConvertionPaM(texte_Menus[1][16]),
					demandeTexte(texte_Menus[1][15] + anc((col2 - texte_Menus[1][15].length() ),".")), 
					demandeTexte(texte_Menus[1][14] + anc((col2 - texte_Menus[1][14].length() ),".")),   
					demandeTexte(texte_Menus[1][13] + anc((col2 - texte_Menus[1][13].length() ),".")), 
					demandeTexte(texte_Menus[1][12] + anc((col2 - texte_Menus[1][12].length() ),".")), 
					demandeEntier(texte_Menus[1][11] +anc((col2 - texte_Menus[1][11].length() ),".")), 
					demandeTexte(texte_Menus[1][10] + anc((col2 - texte_Menus[1][10].length() ),".")), 
					demandeTexte(texte_Menus[1][9] + anc((col2 - texte_Menus[1][9].length() ),".")), 
					NouvelIdentifiant(leResident)

				);

			//afficher_dossier( leResident ,nbResident-1 );
				afficher_entete();
				afficherTableauResidents(leResident,nbResident-1);
				reecrireFichier(leResident); 
				//remplirTabResidents(leResident);
				pause();

				break;	//C'est fait

			case '2':

				return true;

			case '3':

				return false;

		}

	}

}

bool afficherInfosResidents(resident leResident[]) 
{

	/*
	* 	7. On veut pouvoir afficher les informations des r�sidents selon les 3 formats suivants :
	*		a. Dans l�ordre d�apparition dans le fichier.
	*		b. Dans l�ordre alphab�tique des noms. Ne comparez que les premiers caract�res des noms.
	*		c. Dans l�ordre croissant du NAS
	*
	*	C�est l�utilisateur qui choisira le format d�affichage au moment de l�ex�cution � partir d�un menu.
	*	
	*	NB : Pour les questions b. et c., faites � chaque fois une copie du tableau de r�sidents pour 
	*	effectuer le tri l�-dessus.
	*/

	/*
	*	Fonction � afficherInfosResidents � contient un sous-menu pour choisir le format d�affichage des r�sidents
	*/

	while(true)
	{

		switch (demandeCaractere(afficheur_de_menu(2,0)))
		{

			case '1':

				afficherSansTri(leResident); 
				break;

			case '2':

				tri_Selection_Nom_Croi(leResident);
				break;

			case '3':

				tri_Selection_NAS_Croi(leResident); 
				break;

			case '4':

				return true;

			case '5':

				return false;

		}

		pause();

	}

}

void pause()
{

	system("pause");

}

void afficher_dossier( resident leResident[], int indice )
{

	afficher_entete();
	afficherTableauResidents(leResident,  indice);

}

bool modifierResidents(resident leResident[]) 
{

	/*
	*	8. On veut pouvoir modifier n�importe quelle information d�un r�sident. 
	*	Pour pr�ciser quel r�sident � modifier, l�utilisateur saisira le num�ro 
	*	du r�sident. L�utilisateur choisira ensuite le (ou les) champ(s) � 
	*	modifier et saisira la (ou les) nouvelle(s) valeur(s).
	*	� la fin des modifications, le fichier contenant les r�sidents devra �tre r��crit.
	*	NB : Le num�ro du r�sident et son NAS ne peuvent pas �tre modifi�s.
	*/



	while(true)
	{

		string chaine_Sortante;
		int indice = rechercherIndiceRes(leResident, demandeEntier(afficheur_de_menu(3,0)));

		while(true)

		{

         efface();
         afficher_dossier(leResident, indice );
			int menu = demandeEntier(afficheur_de_menu(3,3)); 

			switch (menu)
			{

				case 1:								//	" (1) Le nom",

					leResident[indice].nom = demandeTexte(texte_Menus[1][9] +": " );
					break;

				case 2:								//	" (2) Le pr�nom",

					leResident[indice].prenom = demandeTexte(texte_Menus[1][10] +": " );
					break;

				case 3:								//	" (3) Le num�ro civique",

					leResident[indice].nCivique = demandeTexte(texte_Menus[1][12] +": ");
					break;

				case 4:								//	" (4) Le rue",

					leResident[indice].Rue = demandeTexte(texte_Menus[1][13] +": ");
					break;

				case 5:								//	" (5) L'arrondissement",

					leResident[indice].arrondissement = demandeTexte(texte_Menus[1][14] +": ");
					break;

				case 6:								//	" (6) Le ville",

					leResident[indice].Ville = demandeTexte(texte_Menus[1][15] +": ");
					break;

				case 7:								//	" (7) Le superficie",

					leResident[indice].superficie = demandeEntier(texte_Menus[1][16] +": ");
					break;

				case 8:								//	" (8) Valider les modifications...",

	/*
	*	Fonction � modifierResidents � permet de modifier les informations d�un ou plusieurs 
	*	r�sident(s). � la fin de la modification, la fonction � reecrireFichier � est appel�e.
	*/

					reecrireFichier(leResident);
					//remplirTabResidents(leResident);
					break;

				default:

					efface();

			}

			if (menu == 8)break;

		}

		efface();

		switch (demandeCaractere(texte_Menus[3][0] + "\n" + afficheur_de_menu(3,14)))
		{

			case '1':

				break;

			case '2':

				return true;

			case '3':

				return false; 

		}

	}

}

void efface()
{

	system("cls");

}

bool supprimerResidents(resident leResident[]) 
{

	/*
	*	9. On veut pouvoir supprimer un r�sident en donnant 
	*	son identifiant. Apr�s avoir supprim� le (ou les) 
	*	r�sident(s) d�sir�(s), le fichier � residents.txt � 
	*	est r��crit.
	*/

	int indice;
	resident temps[nbcasMAX];

	while (true)
	{

		switch (demandeCaractere(afficheur_de_menu(4,0)))
		{

			case '1':

				indice = rechercherIndiceRes(leResident,demandeEntier(texte_Menus[4][8] + "\n" ));
				afficher_dossier(leResident,  indice );

				if (demandeCaractere("\n" + afficheur_de_menu(4,9)) == 'o')
				{

					copierGrille(leResident, temps , indice);
					copierGrille(temps ,leResident , -1);
					nbResident--;
					reecrireFichier(leResident);
					cout << "\n" << texte_Menus[4][11] << "\n";
					pause();

				}

				break;

			case '2':

				return true;

			case '3':

				return false; 

		}

	}

}

bool taxes(resident leResident[]) 
{

	/*
	*	10. Pour le module Taxes de votre application, on veut 
	*	pouvoir simuler les revenus de la ville en entrant un 
	*	taux de taxation en $/m2. Ensuite, votre programme 
	*	affiche le total des taxes recueillies par la ville et
	*	les informations du r�sident qui paye le plus de taxes.
	*
	*	11. Dans chaque sous module (ajout, modification, 
	*	suppression, taxe), l�utilisateur est invit�, avec un 
	*	menu, � choisir une des options disponibles. Dans le 
	*	cas o� il veut sortir du module, il aura le choix entre
	*	revenir au menu principal ou quitter l�application.
	*/

	while (true)
	{

		float taux = demandeFloat(afficheur_de_menu(5,0));
		string chaine_sortante;
		int somme = 0;
		for(int n = 0; n < nbResident; n++)
		  somme += leResident[n].superficie;
  
      chaine_sortante = texte_Menus[5][2] + " ";
      cout << chaine_sortante;
      cout << fixed << setprecision(2) << taux;
            
      chaine_sortante =  "$/m�\n\n" + texte_Menus[5][4] + " ";// 

      cout << chaine_sortante;
      
      cout << fixed << setprecision(2)<< (float)taux * somme;
            
      chaine_sortante = " $\n\n" + texte_Menus[5][6] + "\n";
      cout << chaine_sortante;
      afficher_dossier(leResident, rechercheSuperMax( leResident) );

		switch (demandeCaractere(afficheur_de_menu(5,7)))
		{

			case '1':

				return true;

			case '2':

				return false; 

			default:

				efface();

		}

	}

}

void afficher_entete()
{

	cout << left  
		 << setw(4) << 	texte_Menus[2][9] 
		 << setw(14) << texte_Menus[2][10]
		 << setw(14) << texte_Menus[2][11] 
		 << setw(10) << texte_Menus[2][12]
		 << setw(8)  << texte_Menus[2][13]
		 << setw(14) << texte_Menus[2][14]
		 << setw(14) << texte_Menus[2][15] 
		 << setw(14) << texte_Menus[2][16] 
		 << setw(8)  << texte_Menus[2][17]
		 ;
 
}

bool afficherTableauResidents(resident leResident[], int indice) 
{

	/*
	*Fonction � afficherTableauResidents � affiche les informations des r�sidents. 
	*Utiliser les fonctions � setiosflags � et � setw �.
	*/

	cout << left  
		 << setw(4) << leResident[indice].Identifiant
		 << setw(14)<< leResident[indice].nom
		 << setw(14)<< leResident[indice].prenom 
		 << setw(10)<< leResident[indice].NAS
		 << setw(8) << leResident[indice].nCivique
		 << setw(14)<< leResident[indice].Rue 
		 << setw(14)<< leResident[indice].arrondissement 
		 << setw(14)<< leResident[indice].Ville 
		 << setw(8) << leResident[indice].superficie
		 ;

	return true;

}

void remplirTabResidents(resident leResident[]) 
{
	/*
	*	3. Les informations de chaque r�sident devront
	*	se retrouver dans un fichier texte (� acc�s 
	*	s�quentiel) que vous nommerez � residents.txt �.
	*	La gestion des r�sidents (ajout, suppression et
	*	modification) doit passer seulement par la 
	*	console de votre application en C++.
	*/

	string prenom, nom,nCivique,arrondissement, Rue, Ville;
	int NAS, superficie, Identifiant;
	ifstream Lire(nomdefichier, ios::in);

	while (Lire >> Identifiant 
				>> nom 
				>> prenom 
				>> NAS 
				>> nCivique 
				>> Rue  
				>> arrondissement 
				>> Ville 
				>> superficie

		  )
  
		ajouterunResidents( 
							leResident, 
							superficie, 
							Ville, 
							arrondissement, 
							Rue, 
							nCivique, 
							NAS, 
							prenom , 
							nom, 
							Identifiant

						  );

	Lire.close();

}

void ajouterunResidents(resident leResident[], int superficie, string Ville, string arrondissement, string Rue, string nCivique, int NAS, string prenom, string nom, int Identifiant)
{

	/*
	*	6. On veut pouvoir ajouter de nouveaux r�sidents. 
	*	Vous allez donc d�finir une fonction qui permet 
	*	d�inscrire un ou plusieurs nouveaux r�sidents.
	*	Les informations saisies pour chaque nouveau 
	*	r�sident doivent �tre ins�r�es dans le tableau 
	*	de type � r�sident �.
	*	Une fois l�utilisateur choisi de sortir du module 
	*	d�ajout des r�sidents, le fichier � residents.txt�
	*	 est r��crit.
	*/

	leResident[nbResident].Identifiant = Identifiant;
	leResident[nbResident].nom =nom;
	leResident[nbResident].prenom =prenom;
	leResident[nbResident].NAS =NAS;
	leResident[nbResident].nCivique =nCivique;
	leResident[nbResident].Rue = Rue;
	leResident[nbResident].arrondissement=arrondissement;
	leResident[nbResident].Ville =Ville;
	leResident[nbResident].superficie = superficie;
	nbResident++;

}

int ConvertionPaM(string titre)
{
	/*
	*	Fonction � ConvertionPaM � convertit la superficie saisie en p2 en m2
	*/
	char unite = 'm';

	int unEntier=0;
	cout << titre;
	cin >> unEntier >> unite;

	if (unite == 'm')return unEntier;
	else if (unite == 'p')return (int)(unEntier / 10.76) + 1; //	J'arrondis vers l'entier sup�rieur $$, 
	return -1;

}

void reecrireFichier(resident leResident[]) 
{

	ofstream Ecrire(nomdefichier, ios::out);

	/*
	*Fonction � reecrireFichier � permet de r��crire le fichier � partir du tableau des r�sidents
	*/

	for (int n = 0; n < nbResident; n++)		//	J'utilise le \t parce que �a donne
		if (leResident[n].Identifiant >= 0)		//	un bon effet dans Notepad++
			Ecrire << leResident[n].Identifiant 	<< "\t" 
				   << leResident[n].nom 		 	<< "\t"  
			   	   << leResident[n].prenom 			<< "\t"  
				   << leResident[n].NAS 			<< "\t" 
				   << leResident[n].nCivique 		<< "\t" 
				   << leResident[n].Rue 			<< "\t" 
				   << leResident[n].arrondissement 	<< "\t"
				   << leResident[n].Ville 			<< "\t" 
				   << leResident[n].superficie 		<< "\n";

	Ecrire.close();

}
int trouver_une_valeur_par_Etiquette(string chaine_a_traiter, string Etiquette_recherche ) 
{

	return stoi(
				   chaine_a_traiter.substr( 
				   
				   	chaine_a_traiter.find(Etiquette_recherche) + Etiquette_recherche.length()
				   
				   )
				   
			   );

}

void afficherSansTri(resident leResident[]) 
{

	/*
	*	Fonction � afficherSansTri � qui affiche les informations des r�sidents de la ville sans tri
	*/

	afficher_entete();
	int nb_ligne = trouver_une_valeur_par_Etiquette( mode_Affichage, Etiquette_nbLigne) - 2;

	for (int n = 0 ;n <  nbResident;n++)
	{
	
      if (((n %  nb_ligne) == 0) && (n != 0))pause();	//	�a c'est pour les cas
      afficherTableauResidents(leResident, n);		//	o� la liste est plus	
														//	longue que ce que	
	}													//	l'affichage peut afficher	 
}														//	d'un coup soit 24 lignes	
															
void tri_Selection_Nom_Croi(resident leResident[]) 
{

	/*
	*	Fonction � tri_Selection_Nom_Croi � tri les r�sidents dans l�ordre croissant 
	*	du nom puis affiche les r�sidents en appelant la fonction � afficherTableauResidents �
	*/

	resident Les_Residents[nbcasMAX];
	resident Le_Resident;
	copierGrille( leResident, Les_Residents, -1);
	int n_Max = 0;
	int nb_ligne = trouver_une_valeur_par_Etiquette( mode_Affichage, Etiquette_nbLigne) - 1;

	for (int i = 0; i < nbResident ; i++)
	{

		n_Max = i;

		for (int j = 0; j < nbResident; j++)
		{

			if (Les_Residents[j].nom.compare(Les_Residents[n_Max].nom) > 0)	
				n_Max = j;

			if (n_Max != i)
				interchanger_position(Les_Residents, i, n_Max);

		}

	}

	afficher_entete();

	for (int n = 0 ;n <  nbResident;n++)
	{
	
		if (((n %  nb_ligne) == 0)&& (n != 0)) pause();	//	�a c'est pour les cas
		afficherTableauResidents(Les_Residents, n);
	
	}
	
	/*	Pour r�pondre � la demande, je l'ai fait avec le  
	*	afficherTableauResidents(Les_Residents, n)
	*	Mais comme vous allez le voir dans la prochaine
	*	fonction, j'aurais pu �tre �conome et le faire 
	*	comme �a.
	*
	afficherSansTri(Les_Residents);
	*/

}

void tri_Selection_NAS_Croi(resident leResident[]) 
{

	/*
	*	Fonction � tri_Selection_NAS_Croi � tri les r�sidents 
	*	dans l�ordre croissant du NAS puis affiche les r�sidents 
	*	en appelant la fonction � afficherTableauResidents �
	*/
	/*
	*	Ici, je n'ai rien invent�, tous les m�rites vont au
	*	au Prof et � son exemple de triage en ordre d�croissant,
	*	qui emb�tait un peu dans cet environnement, deux ou trois 
	*	coups de marteau et un peu de peinture et voil�! C'est comme neuf.
	*	Moi, j'ai juste transpos� la grille r�sident sur le processus.
	*	C'est litt�ralement votre bout de code, alors je le r�f�rence comme
	*	tel.
	*/

	resident Les_Residents[nbcasMAX];
	resident Le_Resident;
	copierGrille( leResident, Les_Residents , -1 );
	int nb_ligne = trouver_une_valeur_par_Etiquette( mode_Affichage, Etiquette_nbLigne) - 1;

	int n_Max = 0;
	
	for (int i = 0; i < nbResident ; i++)
	{

		n_Max = i;

		for (int j = 0; j < nbResident; j++)	//	�a, c'�tait le bug � corriger
		{										// 	on doit toujours repartir la 
												//	recherche depuis l'indice 0
			if (Les_Residents[j].NAS > Les_Residents[n_Max].NAS)	
				n_Max = j;

			if (n_Max != i)		
				interchanger_position(Les_Residents,i, n_Max);

		}

	}

	/*

	*
	*
	afficherSansTri(Les_Residents);
	*
	*
	*	Mais, c'est 7 points FAQUE... je vais m'en tenir � la consigne. :D
	*/	

	afficher_entete();

	for (int n = 0 ;n <  nbResident;n++)
	{

		if (((n %  nb_ligne) == 0)&& (n != 0)) pause();	//	�a c'est pour les cas
		afficherTableauResidents(Les_Residents, n);
	
	}
	
}

void copierGrille(resident original[], resident copie[] , int rejet)
{
	int argument = 0;
	
	for (int n = 0 ; n < nbResident;n++)
	{

		if (n != rejet)
		{

			copie[n -argument].Identifiant 		= original[n].Identifiant; 
			copie[n -argument].nom 				= original[n].nom ;
			copie[n -argument].prenom 			= original[n].prenom ;
			copie[n -argument].NAS 				= original[n].NAS ;
			copie[n -argument].nCivique 		= original[n].nCivique ;
			copie[n -argument].Rue 				= original[n].Rue ;
			copie[n -argument].arrondissement 	= original[n].arrondissement ;
			copie[n -argument].Ville 			= original[n].Ville ;
			copie[n -argument].superficie 		= original[n].superficie ;

		}

		else if (n == rejet) argument = 1;

	}

}

void interchanger_position(resident leResident[], int p1, int p2 )
{

	//int temp;										M�me affaire
	resident temp;

				//temp = leTableau[i];				Pareille

				temp.Identifiant 				= leResident[p1].Identifiant; 
				temp.nom 						= leResident[p1].nom; 
				temp.prenom 					= leResident[p1].prenom; 
				temp.NAS 						= leResident[p1].NAS ;
				temp.nCivique 					= leResident[p1].nCivique; 
				temp.Rue 						= leResident[p1].Rue; 
				temp.arrondissement 			= leResident[p1].arrondissement; 
				temp.Ville						= leResident[p1].Ville; 
				temp.superficie 				= leResident[p1].superficie; 

				//leTableau[i] = leTableau[n_Max]; 	Copie

				leResident[p1].Identifiant		= leResident[p2].Identifiant; 
				leResident[p1].nom 				= leResident[p2].nom ;
				leResident[p1].prenom 			= leResident[p2].prenom ;
				leResident[p1].NAS 				= leResident[p2].NAS ;
				leResident[p1].nCivique 		= leResident[p2].nCivique ;
				leResident[p1].Rue 				= leResident[p2].Rue ;
				leResident[p1].arrondissement	= leResident[p2].arrondissement ;
				leResident[p1].Ville 			= leResident[p2].Ville ;
				leResident[p1].superficie 		= leResident[p2].superficie ;

				//leTableau[n_Max] = temp;			J'ai rien invent�

				leResident[p2].Identifiant 		= temp.Identifiant ;
				leResident[p2].nom 				= temp.nom ;
				leResident[p2].prenom 			= temp.prenom ;
				leResident[p2].NAS 				= temp.NAS ;
				leResident[p2].nCivique 		= temp.nCivique ;
				leResident[p2].Rue 				= temp.Rue ;
				leResident[p2].arrondissement	= temp.arrondissement ;
				leResident[p2].Ville 			= temp.Ville ;
				leResident[p2].superficie		= temp.superficie ;

	/*	C'est carr�ment la m�me affaire que vous avez fait
	*	dans les exemples d'algorithme de tri
	*/

}

int rechercherIndiceRes(resident leResident[], int Identifiant) 
{ 

	/*
	*	Fonction � rechercherIndiceRes � permet de trouver l�indice d�un r�sident 
	*	dont l�identifiant est fourni en param�tre.
	*/

	for(int n = 0; n <= nbResident; n++)
		if (leResident[n].Identifiant == Identifiant)return n;

	return -1;

}

int rechercheSuperMax(resident leResident[]) 
{ 


	int plusGrand=0;
	for(int n = 0; n <= nbResident; n++)
	{
		if (leResident[n].superficie > leResident[plusGrand].superficie )
			plusGrand = n;
	}

	return plusGrand;

}


string afficheur_de_menu(int Lemenu, int debut)
{														//pour �clairer les d�veloppeurs dans des projets futurs

	if (debut == 0)efface();
	string Menu;
	int item = debut;
	int ajout_tab = 0;

	if (Lemenu == 0) Menu.append( afficherart());
	Menu.append(texte_Menus[Lemenu][item]);

	while(texte_Menus [Lemenu][++item] != "")
		Menu.append(texte_Menus[Lemenu][item]);

	return Menu;

}

string afficherart()
{

	return ("\n" + anc(30," ") + "::\n" + anc(29," ") + "::\n" + anc(28," ") + "::\n  .:: ::    .::        .::::::::" + anc(17," ") + ".::       .::\n.::    .::  .::        .::" + anc(23," ") + ".::       .::\n .::      .:.: .:      .::      .: .:::   .::    .::       .::   .::\n   .::      .::  .:::::.::::::   .::    .::  .:: .:: .::   .:: .:   .::\n      .::   .::        .::       .::   .::   .:: .::   .:: .::.::::: .::\n.::    .::  .::        .::       .::   .::   .:: .::   .:: .::.:\n" + "  .:: ::     .::       .::::::::.:::     .:: .:::.:: .::  .:::  .::::\n\n" + anc(18," ") + Titre + anc(3,"\n"));

	/* 
	*	Un peu de compression. 
	*	Dans un ordinateur avec des Gigas de m�moire, on a tendance � se foutre de la RAM.
	* 	Toutefois, sur un syst�me type AVR avec 2Ko, gros max 8Ko, les ressources 
	*	sont pr�cieuses. Je pourrais en condenser plus, j'ai juste fait les bords et 
	*	un peu au milieu, mais bon, ce n'est pas sur un syst�me AVR et de la 
	*	RAM, il y en a en masse. :D Le but �tait surtout de d�montrer le savoir-faire.
	*/

}

string anc( int nbRepetission, string Caractere)
{

	string chaine_Sortante;
	for (int n = 0; n < nbRepetission; n++ )chaine_Sortante += Caractere;
	return chaine_Sortante;

}

char demandeCaractere(string chaine_Entrante)
{

	char caractere_Sortant;	
	cout << chaine_Entrante;
	cin >> caractere_Sortant;
	return caractere_Sortant;

}

string demandeTexte(string titre)
{

	string contenant ="";
	cout << titre;
	cin >> titre;
	return titre;

}

int demandeEntier(string titre)
{

	int contenant = 0;
	cout << titre;
	cin >> contenant;
	return contenant;

}

float demandeFloat(string titre)
{

   float  contenant = 0;
   cout << titre;
   cin >> contenant;
   return contenant;

}
int NouvelIdentifiant(resident leResident[])
{

	int indentMAX = 0;
	for(int n = 0; n < nbResident + 1 ; n++)
		if ( leResident[n].Identifiant >= indentMAX) indentMAX = leResident[n].Identifiant + 1;
	return indentMAX;

}
