#define MAXSIZE 7
#define MAXKEYSIZE 11
typedef struct neig *Nbr;

typedef union {
	char* string;	// store strings here
	int integer;	// store ints here
	Nbr adj;
}ItemType;
