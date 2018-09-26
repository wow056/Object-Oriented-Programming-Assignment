typedef struct node
{
	char name[20];
	char genre[20];
	char source[20];
	double production;
	double gross;
	double rating;
} NODE;


typedef struct list
{
	NODE *head;
	int count;
} LIST;