#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<fcntl.h>
#include"sharedfile.h"

int main()
{
	void *p =NULL;
	SinglyLL * ptr=NULL;
	SinglyLL * (*fptr1)()=NULL;
	void (*fptr2)(SinglyLL *)=NULL;

	p=dlopen("/home/lenovo/piyushsir/sharedobject/libmyclass.so",RTLD_LAZY);

	if(p==NULL)
	{
	  printf("Unableto load library \n");
          return 0;
	}

	fptr1=(SinglyLL *(*)())dlsym(p,"create");
	fptr2=(void(*)(SinglyLL *))dlsym(p,"destroy");

	ptr=fptr1();

	ptr->InsertFirst(10);
	ptr->InsertAtPosition(70,1);
	ptr->InsertAtPosition(80,2);
	ptr->InsertLast(40);
	ptr->InsertFirst(50);
	ptr->Display();
	ptr->DeleteFirst();
	ptr->DeleteLast();
	ptr->DeleteAtPosition(4);


	fptr2(ptr);
	dlclose(p);

	return 0;
}
