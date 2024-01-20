//Ecrire un programme C permettant de :
//Charger un tableau t de taille 5<=n<=100 par des entiers introduits dans un ordre croissant,
//Lire une valeur v quelconque,
//Insérer v dans t de telle façon que le vecteur t reste toujours trié par ordre croissant.
//Afficher les éléments de t pour s’assurer que l’insertion de v dans t a été bien faite.
//La solution doit utiliser la technique des pointeurs et l’allocation dynamique de la mémoire

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n; //dimension du tableau
	int *p; //pointeur
	int *t; //tableau 
	int v; //valeur quelconque
	
	//saisir n
	p=&n ;
	do{
		printf("donner n entre 5 et 100: ");
		scanf("%d",p);
	}while((*p)<5 || (*p)>100 );
	
	//allouer la memoire pour t
	t=(int*)malloc(sizeof(int)*n);
	if (t ==NULL){
		printf("erreur");
		return 0;
	}
	else{ // charger t par des entier en ordre croissant
		p=t; // le pointeur pointe sur la premiere case de t
		printf("donner t[%d]",p-t);
		scanf("%d",p);
		for(p=t+1; p<t+n ; p++){
			do{
				printf("donner t[%d]",p-t);
				scanf("%d",p);
			}while(*p<*(p-1));	
		}
	}
	
	//lire v
	p=&v;
	printf("donner un entier quelconque: ");
	scanf("%d",p);
	
	//inserer v dans le tableau t dans la bonne position 
	p=t+n-1; // le pointeur pointe sur la derniere case de t 
	n=n+1;
	while (*p > v){
		*(p+1) = *p ;
		p--;
	}
	p++;
	*p=v;
	
	
	//affichage des elements de t
	p=t;
	printf("les elements de t sont: ");
	for(p=t ; p<t+n ; p++){
		printf("%d\t",*p);
	}
	
	//free t
	if (t != NULL){
		free(t);
	}
	
	return 0; 
}
