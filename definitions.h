#include "head.h"
struct commodity
 {
	int num;
	char name[15];
	double price;
	double counts;
	double total;
};

struct users
{
    char username[20];
    char password[20];
};

struct commodity comm[50];
struct users user[10];

 extern int getx=20;//default x position ?
 extern int gety=10;//default y position ?

int judge=1;

