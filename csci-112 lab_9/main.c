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
linkedl * inorder_insert(linkedl * original, linkedl *new_value_ptr, linkedl * previous_ptr,linkedl * start_ptr);

void print_list(linkedl * listptr) {
	// recursive step:
	if (listptr != NULL) {
		printf("%c \n", (*listptr).head ) ;
		print_list( (*listptr).tail  );
	}
	// base case: do nothing
}



linkedl * inorder_insert(linkedl * original, linkedl *new_value_ptr, linkedl * previous_ptr, linkedl * start_ptr){
    if(original==NULL && previous_ptr==NULL){
        return new_value_ptr;
    }else if(original==NULL && previous_ptr!=NULL){
        original->tail= new_value_ptr;
        return start_ptr;
    }else if(original->head >= new_value_ptr->head){
        if(previous_ptr==NULL){
            new_value_ptr->tail=original;
            return new_value_ptr;
        }else{
            previous_ptr->tail==new_value_ptr;
            new_value_ptr->tail=original;
            
            return start_ptr;
        }
    }else inorder_insert(original->tail, new_value_ptr, original, start_ptr);
    return original;
    
}





int main() {
    linkedl a = {'a', NULL};
        linkedl b = {'b', NULL};
   linkedl *masterlist= inorder_insert(NULL,&a, NULL, NULL) ;
   print_list(masterlist);
    masterlist= inorder_insert(masterlist,&b, NULL, masterlist) ;
   print_list(masterlist);
    return (EXIT_SUCCESS);
}

