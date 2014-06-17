/* 
 * File:   main.c
 * Author: nevin.leh
 *
 * Created on June 12, 2014, 11:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
typedef
struct llist{
    char head;
    struct llist *tail;
}
linkedl;
    void print_list(linkedl * first_ptr);
int inorder_insert(linkedl * original,linkedl *next, char letter, linkedl *previous);

void print_list(linkedl * listptr) {
	// recursive step:
	if (listptr != NULL) {
		printf("%c \n", (*listptr).head ) ;
		print_list( (*listptr).tail  );
	}
	// base case: do nothing
}



int inorder_insert(linkedl * original, linkedl * next, char letter, linkedl *previous){
    if(original->head=='0' && original->tail==NULL){
        linkedl *new_head=malloc(sizeof(linkedl));
        new_head->head=letter;
        new_head->tail=NULL;
        return 0;
        
    }else if(original->head>=letter){
        linkedl *new_list=malloc(sizeof(linkedl));
        new_list->head=letter;
        new_list->tail=next;
        previous->tail=new_list;
        
        return 0;
    }

    
}





int main() {
    linkedl alph  = {'0', NULL};
   alph= inorder_insert(&alph,NULL , 'a', NULL);
   print_list(&(alph));
}

