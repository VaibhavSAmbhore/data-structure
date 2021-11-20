#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next ;

};

 typedef struct node NODE;
 typedef struct node * PNODE;
 typedef struct node ** PPNODE;

void Insertfirst(PPNODE Head,int no)
{
	PNODE newn= NULL;

	newn =  (PNODE)malloc(sizeof (NODE));

	newn -> data = no;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

  void InsertLast(PPNODE Head,int no)
  {
  	PNODE newn= NULL;
    PNODE temp = *Head;
	newn =  (PNODE)malloc(sizeof (NODE)); 

	newn -> data = no;
	newn -> next = NULL;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
	  while(temp ->next != NULL)
	  {
	  	temp  = temp ->next;
	  }
	  temp ->next = newn;
	}
  }
    void Display(PNODE Head)
  {
    while(Head != NULL)
    {
    	printf("%d\n",Head -> data);
    	Head = Head -> next;
    }
  }

    int Count(PNODE Head)
    {
    	int iCnt =0;
    	while(Head != NULL)
    	{
    		iCnt ++;
    	  Head = Head -> next;

    	}
    	 return iCnt;
    }

void Deletefirst(PPNODE Head)
{
	PNODE temp = *Head;
    if (*Head != NULL)
    {
    	*Head = (*Head) -> next;
    
    free( temp);
    }	
}

 void DeleteLast(PPNODE Head)

 {
 	PNODE temp = *Head;
  if (*Head == NULL)
  {
  	return;

  }
  else if ((*Head)->next == NULL)

  {
     free (*Head);
     (*Head) = NULL;
  }
  else
  {
  	while(temp->next -> next !=NULL)
  	{
  		temp = temp ->next;
  	}
  	free (temp ->next);
  	temp ->next = NULL;
  }
 }


 int main()
 {
  PNODE first = NULL;
  int iret=0;

  InsertLast(&first,101);
  Insertfirst(&first,51);
  Insertfirst(&first,21);
  Insertfirst(&first,11);
  Display(first);
 iret = Count(first);
 printf("number of NODE:%d\n",iret);
  Deletefirst(&first);
   Display(first);
 iret = Count(first);
 printf("number of NODE:%d\n",iret);

DeleteLast(&first);


  //Deletefirst(first);
  Display(first);

  iret = Count(first);
  printf("number of NODE:%d\n",iret);
   return 0;
 }