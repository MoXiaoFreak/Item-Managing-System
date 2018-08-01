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


struct users user[20];

 extern int getx=20;//default x position ?
 extern int gety=5;//default y position ?

int judge=1;

