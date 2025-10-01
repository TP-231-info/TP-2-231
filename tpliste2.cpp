#include<stdio.h>
#include<stdlib.h>
    typedef struct Noeud {
	   int val;
	   struct Noeud*suiv;
	   }Noeud;
  Noeud* nouveaunoeud(int t){
  	Noeud*p=(Noeud*)malloc(sizeof(Noeud));
  	if(p==NULL){
  		printf("Erreur d allocation memoire\n");
  		exit(1);
	  }
	  p->val=t;
	  p->suiv=NULL;
  	return p;
  }
  Noeud* insertion(Noeud*n,int t){
  	Noeud*p= nouveaunoeud(t);
  	if(n==NULL || t<n->val){
	  p->suiv=n;
	  return p;
	  }
	  Noeud*m=n;
	  while(m->suiv !=NULL && m->suiv->val <t){
	  	m=m->suiv;
	  }
	  p->suiv=m->suiv;
	  m->suiv=p;
	  return n;
  }
  void afficher( Noeud*n){
	 	 Noeud*m=n;
	 	while(m!=NULL){
		 printf("%d ->",m->val);
		 m=m->suiv;
		 }
		 printf("NULL\n");
	 }
  
   int main(){
   	int a,b ,j ;
   Noeud*n= NULL;
   printf("combien d element voulez vous ajouter dans votre liste ?\n");
   scanf("%d",&a);
   for(int i=0;i<a;i++){
   	printf("Entrez l element numero %d \n",i+1);
   	scanf("%d",&b);
        n=insertion(n,b);
   }
   printf("Votre liste actuelle trie par ordre croissant est \n");
      afficher(n);
      printf("Entrez un autre nombre\n");
      scanf("%d",&j);
      n=insertion(n,j);
      printf("Votre nouvelle liste trie est \n");
      afficher(n);
   }
	   
   
