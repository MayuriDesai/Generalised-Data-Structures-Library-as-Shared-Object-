//using namespace std;
#include "sharedfile.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

SinglyLL::SinglyLL()
{
	head = NULL;
}

SinglyLL::~SinglyLL()
{
	if(head == NULL)
		return;

	PNODE temp1,temp2;
	temp1=head;


	while(temp1 != NULL)
	{
	   temp2=temp1;
	   delete temp2;
	   temp1=temp1->next;
	}
}


void SinglyLL::InsertFirst(int no)
{
	
	PNODE newn =new NODE;
	newn->data=no;

	
//	if(head==NULL)
//	  {
	  	newn->next=NULL;
//	  	return;
//	  }
	 
	 	newn ->next=head;
	 
	 	head=newn;
}


void SinglyLL::InsertLast(int no)
{
	
	PNODE newn =new NODE;
	newn->data=no;
	newn->next=NULL;
	
	if(head==NULL)
	  {
	  	head=newn;
	  	//return;
	  }
	else
	{
	   	PNODE temp =head;
		while(temp->next != NULL)
		{
	    	temp=temp->next;
		}
	 
	 	temp->next=newn;
	}
}


void SinglyLL::InsertAtPosition(int no,int pos)
{
	
	if(pos<=0 || pos> (Count()+1) )
  					{
  						return;
  					}
 	else if(pos==1)
 	{
 		InsertFirst(no);
 	}
 	else if(pos== (Count()+1) )
    {
        InsertLast(no);
    }
 	else 
 	{
			 		PNODE newn=new NODE;
 						newn->data=no;
						newn->next=NULL;

 					PNODE temp=head;
 					while(pos-2 != 0)
 								{
 									temp=temp->next;
									pos--;
 								}
 						newn->next=temp->next;
						temp->next=newn;	
 	}
}

void SinglyLL::DeleteFirst()
{
	
	if(head==NULL)
	  {
	  	return;
	  }
	 
	PNODE temp =head;
	head=head->next;

	delete temp;
}


void SinglyLL::DeleteLast()
{
	
	if(head==NULL)
	  {
	  	return;
	  }
	 
	PNODE temp =head;

	while(temp->next->next != NULL)
		 temp=temp->next;


	delete temp->next;
	temp->next =NULL;
}

void SinglyLL::DeleteAtPosition(int pos)
{
	
	if(pos<=0 || pos> Count() )
  					{
  						return;
  					}
 	else if(pos==1)
 	{
 		DeleteFirst();
 	}
 	else if(pos==Count() )
    {
        DeleteLast();
    }
 	else 
 	{
			 		PNODE temp=head,temp2=NULL;
 						
 					while(pos-2 != 0)
 								{
 									temp=temp->next;
									pos--;
 								}
					temp2=temp->next;

 						temp->next=temp2->next;
						delete temp2;	
 	}
}

void SinglyLL::Display()
  	{	
		PNODE temp=head;

  		while(temp !=NULL)
  	 	{
  	 		printf("|%d|->", temp->data);
  	 	 	
  	 		temp=temp->next;
  	 	}
		printf("\n");
  	}


int SinglyLL::Count()
  	{	
		int cnt=0;
		PNODE temp=head;

  		while(temp !=NULL)
  	 	{	
  	 		temp=temp->next;
			cnt++;
  	 	}
       return cnt; 
  	}

extern "C"
{
	SinglyLL * create()
	{
	   return new SinglyLL;
	}

	void destroy(SinglyLL * p)
	{
	  delete p;
	}

}
