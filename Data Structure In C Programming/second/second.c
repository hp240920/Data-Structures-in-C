#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct node
{
    int data;
    struct node *next;
}node;

node * insert(int data, node *head)
{
    count++;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        node *current = head;
        while(current != NULL){
            if(data < current->data && current == head){
                temp->next = current;
                head = temp;
                break;
            }else if((current->data < data && (current->next != NULL && current->next->data > data)) || current->data == data) {
                temp->next= current->next;
                current->next = temp;
                break;
            }else if(current->next == NULL && current->data < data){
                current->next = temp;
                break;
            }
            current = current->next;
        }
    }
    return head;
}

node *deleteNode(int data, node *head)
{
    node *temp = head;
    if(head == NULL){
        return head;
    }
    node *ptr = head;
    node *prev = NULL;
    while(ptr != NULL){
        if(ptr->data == data && prev == NULL){
            count--;
	    //free(head);
	    head = head->next;
	    free(temp);
            return head;
        }else if(ptr->data == data && prev != NULL){
            prev->next = ptr->next;
	    free(ptr);
            count--;
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return head;
}

void print(node *front){
  node *ptr = front;
    ptr = front;
    int data = ptr->data;
    printf("%d\t", data);
    while(ptr != NULL){
      if(data == ptr->data){
	ptr = ptr->next;
	continue;
      }
      printf("%d\t", ptr->data);
      data = ptr->data;
      ptr = ptr->next;
    }
}

int main(int argc, char* argv[])
{
    if(argc < 2){
      return 0;
    }
    FILE *txtReader = fopen(argv[1], "r");
    if (txtReader == NULL) {
        printf("error\n");
        return 0;
    }
    char c;
    int num;
    node* front = NULL;
    while((fscanf(txtReader, "%c\t%d\n", &c, &num) != EOF)){
	if(c == 'i'){
	  //rintf("I = %d\n",num);
	  front = insert(num , front);
	}
	if(c == 'd'){
	  //intf("D : %d\n", num);
	  front = deleteNode(num, front);
	}
    }
    //print(front);
    
    node *ptr = NULL;
    ptr = front;
    printf("%d\n", count);
    int data;
    while(ptr != NULL){
      if(ptr == front){
	printf("%d\t", ptr->data);
	data = ptr->data;
      }else{
	if(data != ptr->data){
	  printf("%d\t", ptr->data);
	}
	data = ptr->data;
      }
      ptr = ptr->next;
    }
    node *current = NULL;
    while(front != NULL){
      current = front;
      front = front->next;
      free(current);
    }
    fclose(txtReader);
    return 0;
}
