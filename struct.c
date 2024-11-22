#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct adresse {
    int rue;
    char ville[30];
    int code_postal;
} adresse;

typedef struct apprenant {
    char nom[20];
    char prenom[30];
    int age;
    float note;
    adresse adres;
} apprenant;
apprenant *t;
int main() {
    int i=0,j,n,k,position;
    int rue,code_postal,age;
    char nom[20],prenom[20],ville[20];
    float note;
    //affichage Menu
    menu:
 	printf("1:saisir\n");
 	printf("2:afficher\n");
 	printf("3:metrre_a_jour\n");
 	printf("4:supression\n");
 	printf("5:pas de option\n");
 	printf("entrez votre choix:\n");
 	scanf("%d",&n);
    if(n==1){
    if(i==0)	
	    t=(apprenant*)malloc(sizeof(apprenant));
	else
	t=(apprenant*)realloc(t,(i+1)*sizeof(apprenant));
    printf("Entrez le nom: \n");
    scanf("%s",t[i].nom);

    printf("Entrez le prénom: \n");
    scanf("%s",t[i].prenom);

    printf("Entrez l'âge: \n");
    scanf("%d",&t[i].age);

    printf("Entrez la note: \n");
    scanf("%f",&t[i].note);

    printf("Entrez le numéro de rue: \n");
    scanf("%d",&t[i].adres.rue);

    printf("Entrez la ville: \n");
    scanf("%s",t[i].adres.ville);

    printf("Entrez le code postal: \n");
    scanf("%d",&t[i].adres.code_postal);
    i++;
    goto menu;
    }
    // Afficher les informations des apprenants
    if(n==2){
    	if(i==0) printf("****le tableau des aprenants est vide****\n");
        for(j=0;j<i;j++){
        printf("Nom: %s\n",t[j].nom);
        printf("Prénom: %s\n",t[j].prenom);
        printf("Âge: %d\n",t[j].age);
        printf("Note: %.2f\n",t[j].note);
        printf("Adresse: Rue %d, %s, Code Postal %d\n",t[j].adres.rue,t[j].adres.ville,t[j].adres.code_postal);
      }
      goto menu;
    }
    //Mettre a jour les informations
    if(n==3){
    printf("entrez la position de l'apprenant que tu veux modifier\n");
    scanf("%d",&position);
    printf("Entrez le nouveau nom: ");
    scanf("%s",nom);
    strcpy(t[position].nom,nom);
    printf("Entrez le prénom: ");
    scanf("%s",prenom);
    strcpy(t[position].prenom,prenom);
    printf("Entrez l'âge: ");
    scanf("%d",&age);
    t[position].age=age;
    printf("Entrez la note: ");
    scanf("%f",&note);
    t[position].note=note;
    printf("Entrez le numéro de rue: ");
    scanf("%d",&rue);
    t[position].adres.rue=rue;
    printf("Entrez la ville:");
    scanf("%s",ville);
    strcpy(t[position].adres.ville,ville);
    printf("Entrez le code postal: ");
    scanf("%d",&code_postal);
    t[position].adres.code_postal=code_postal;
    goto menu;
    }
    //suppression d'un apprenant
    if(n==4){
    printf("entrez la position de l'apprenant que tu veux supprimer\n");
    scanf("%d",&position);
    	for(j=position;j<i;j++){
    		    t[j]=t[j+1];
		}
	 t=(apprenant*)realloc(t,(i)*sizeof(apprenant));
	 i--;
	goto menu;
	}
	if(n==5) printf("la fin\n");
    return 0;
}








