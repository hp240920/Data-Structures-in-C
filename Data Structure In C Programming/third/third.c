#include <stdio.h>
#include <stdlib.h>

int collision = 0;
int searchT = 0;

typedef struct node{
    int data;
    struct node *next;
}node;

node* hashT[10000];

int hashFunc(int data){
    int ans;
    ans = data % 10000;
    if(ans < 0){
        ans = ans + 10000;
    }
    return ans;
}

void insert(int data){
    int num;
    num = hashFunc(data);
    node* ins = (node*)malloc(sizeof(node));
    ins->data = data;
    ins->next = NULL;
    if(hashT[num] == NULL){
        hashT[num] = ins;
    }else{
        collision++;
        ins->next = hashT[num];
        hashT[num] = ins;
        if(hashT[num]->next != NULL){
        }
    }
}

void search(int data){
    int index = hashFunc(data);
    node* current = hashT[index];
    while(current != NULL){
        if(data == current->data){
	  //printf("Hey\n");
            searchT++;
            break;
        }
	current = current->next;
    }
        
}

int main(int argc, char* argv[])
{
    FILE* reader = fopen(argv[1], "r");
    if(reader == NULL){
      printf("error\n");
      return 0;
    }
    for(int i = 0; i < 10000; i++){
        hashT[i] = NULL;
    }
    char c;
    int num;
    int totalS = 0;
    int totalI = 0;
    while((fscanf(reader, "%c\t%d\n", &c, &num) != EOF)){
        if(c == 'i'){
	  // printf("HeyIII\n");
            totalI++;
            insert(num);
        }else if(c == 's'){
	  //printf("HeySSS\n");
            totalS++;
            search(num);
        }
    }
    fclose(reader);
    printf("%d\n", collision);
    printf("%d\n", searchT);
    
    for(int i = 0; i < 10000; i++){
      node *ptr = hashT[i];
      while(ptr != NULL){
	node* temp = ptr;
	ptr = ptr->next;
	free(temp);
      }
    }
   // free(*hashT);
    
    return 0;
}

