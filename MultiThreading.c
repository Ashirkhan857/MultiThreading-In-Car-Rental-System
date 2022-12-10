#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#include <windows.h>
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void setcolor(unsigned short color) //begining of set color funtion
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);   //gets std handle
SetConsoleTextAttribute(hCon, color); //Sets Console Text Attribute HCon color.
}
struct car
{
int no;
char name[30];
char color[10];
int distance;
int price;
}ob1;

void *car_input(void *arg)
{
pthread_mutex_lock(&m);
char  *msg;
int *myid;
myid = (int *)arg;
printf("thread entered with id '%d", *myid);
int i, n = 0;
FILE *fp;
fp = fopen("car.dat", "ab");
if (fp == NULL)
{
printf("can't create file");
_getch();
exit(1);
}
printf("\n\tHow Many Cars You Want to Enter:=");
scanf("%d", &n);
for (i = 0; i<n; i++)
{
setcolor(2);
printf("SERIAL NO:\n");
scanf("%d", &ob1.no);
setcolor(3);
printf("NAME:\n");
scanf("%s", ob1.name);
setcolor(4);
printf("DISTANCE:\n");
scanf("%d", &ob1.distance);
setcolor(5);
printf("COLOUR:\n");
scanf("%s", ob1.color);
setcolor(7);
printf("Price per day\n");
scanf("%d", &ob1.price);
fwrite(&ob1, sizeof(ob1), 1, fp);
}
fclose(fp);
pthread_mutex_unlock(&m);
pthread_exit(NULL);
return NULL;
}
struct info
{
char name[20];
int age, carno;
char adress[30];
long number;
int days;
int total;
}ob2;
void *info_input(void *args)
{
Sleep(2);
char  *msg;
int *myid;
myid = (int *)args;
printf("thread entered with id '%d", *myid);
FILE *fp;
fp = fopen("info.dat", "ab");
if (fp == NULL)
{
printf("can't create file");
_getch();
exit(1);
}
printf("Enter the Name \n");
scanf("%s", ob2.name);
printf("Enter the Age  || Must Be Greater than 18\n");
scanf("%d", &ob2.age);
if (ob2.age < 18)
{
printf("Underage Not Allowed\n");
exit(0);
}
printf("Enter the Adress\n");
scanf("%s", ob2.adress);
printf("Enter the Phone Number\n");
scanf("%d", &ob2.number);
printf("Enter the Number of Days\n");
scanf("%d", &ob2.days);
printf("Enter the Car No\n");
scanf("%d", &ob2.carno);
printf("Total Bill:\n");
FILE *rp;
rp = fopen("car.dat", "rb");
while (fread(&ob1, sizeof(ob1), 1, rp))
{
if (ob1.no == ob2.carno)
{
ob2.total = ob1.price*ob2.days;
printf("%d \n", ob2.total);
}

}
fclose(rp);
fwrite(&ob2, sizeof(ob2), 1, fp);
fclose(fp);
pthread_exit(NULL);
return NULL;
}
void *display(void *arg)
{
Sleep(2);
char  *msg;
int *myid;
myid = (int *)arg;
printf("thread entered with id '%d", *myid);
FILE *fp;
fp = fopen("info.dat", "rb");
if (fp == NULL)
{
printf("can't read file");
_getch();
exit(1);
}
while (fread(&ob2, sizeof(ob2), 1, fp)==1)
{
printf("Customer Name:%s\n", ob2.name);
printf("Customer Age: %d\n", ob2.age);
printf("Customer Age: %s\n", ob2.adress);
printf("Customer Number:%d\n", ob2.number);
printf("Customer Days:%d\n", ob2.days);
printf("Car Model:%d\n", ob2.carno);

}

fclose(fp);
pthread_exit(NULL);
return NULL;

}
void *display1(void *arg)
{
Sleep(2);
int *myid;
myid = (int *)arg;
printf("thread entered with id '%d", *myid);
FILE *fp;
fp = fopen("car.dat", "rb");
if (fp == NULL)
{
printf("can't read file");
_getch();
exit(1);
}
while (fread(&ob1, sizeof(ob1), 1, fp) == 1)
{


printf("\nCar Number:%d\n", ob1.no);
printf("Car Name: %s\n", ob1.name);
printf("Car Distance:%d\n", ob1.distance);
printf("Car Color:%s\n", ob1.color);
printf("Car Price:%d\n", ob1.price);
}

fclose(fp);
pthread_exit(NULL);
return NULL;

}
void *search(void *arg)
{
int *myid;
myid = (int *)arg;
printf("thread entered with id %d", *myid);
char name[10];
FILE * fp;
fp = fopen("car.dat", "rb");
          system ("cls");
printf("Enter Car Name\n:");
scanf("%s", name);
while (fread(&ob1, sizeof(ob1), 1, fp))
{
if (strcmp(name, ob1.name) == 0)
{
printf("\n Record Exist\n");
printf("Car Number:%d\n", ob1.no);
printf("Car Name: %s\n", ob1.name);
printf("Car Distance:%d\n", ob1.distance);
printf("Car Color:%s\n", ob1.color);
printf("Car Price:%d\n", ob1.price);

break;
}
else
{
printf("|No Record Found|");

}
}
fclose(fp);
pthread_exit(0);
return NULL;
}
int main()
{
int i;
pthread_t t1, t2, t3, t4, t5, t6;
char ch;
char password[7];
setcolor(2);
printf("\t\t===================================================\n");
setcolor(3);
printf("\t\t\t CAR RENTAL PROJECT\t\t\t\t\n");
setcolor(4);
printf("\t\t===================================================\t\t\t\n");
setcolor(5);
printf("\t\t\tLogin:\tAdmin \t\t\t\t\t\t\t\n");
setcolor(6);
printf("\t\t\tPassword:");
for (i = 0; i <= 5; i++)
{
ch = _getch();
password[i] = ch;
ch = '*';
printf("%c", ch);
}
password[i] = '\0';
for (int j = 0; j <= 6; ++j)
{
if (password[j] == 'a')
{
j++;
{
if (password[j] == 's')
j++;
if (password[j] == 'h')
{
j++;
if (password[j] == 'i')
{
j++;
if (password[j] == 'r')
{
j++;
setcolor(7);
printf("\n\t\t\tAccess Granted\n");
system("cls");
int op1;
   do{
printf("\n0:Add Car\n");
printf("1:Car Detail\n");
printf("2:Add Customer Rent\n");
printf("3:Rental Detail\n");
printf("4:Search Car Record\n");
printf("5:Exit\n");
printf("Choose the Number:\n");
scanf("%d",&op1);
int option;
system("cls");
switch (op1)
{
   case 0:

setcolor(3);
printf("Which Car you Choose\n");
setcolor(4);
printf("0:ADD Luxury Car\n");
setcolor(8);
printf("1:ADD Sports Car\n");
setcolor(8);
setcolor(2);
scanf("%d", &option);
switch (option)
{
case 0:
pthread_mutex_init(&m, NULL);
pthread_create(&t1, NULL, car_input, (void *)&t1);
pthread_join(t1, NULL);
printf("After Thread\n");
break;
case 1:
pthread_mutex_init(&m, NULL);
pthread_create(&t2, NULL, car_input, (void *)&t2);
pthread_join(t2, NULL);
break;
default:
break;
}
break;
case 1:
system("cls");
pthread_create(&t3, NULL, display1, (void *)&t3);
pthread_join(t3, NULL);
printf("After Thread \n");
break;
case 2:
system("cls");
pthread_create(&t4, NULL, info_input, (void *)&t4);
pthread_join(t4, NULL);
printf("After Thread \n");

break;
case 3:
system("cls");
pthread_create(&t5, NULL, display, (void *)&t5);
pthread_join(t5, NULL);
break;
case 4:
system("cls");
pthread_create(&t6, NULL, search, (void *)&t6);
pthread_join(t6, NULL);
break;
default:
break;

}
} while (op1<=4);
exit(0);
}
else
{
printf("error");
}
}
}}
}
}
system("pause");
}