// BaseConverter - a simple number base converter
// Created by Leonardo Deliyannis Constantin

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long ll;
typedef unsigned long long ull;

// NOTE:
// computes pow(a, n) in a much faster way 
ll binpow(ll a, ll n){
	/* useless since we're not working with floating point numbers
	if(n < 0){
		a = 1/a;
		n == -n;
	}
	*/
	if(n == 0){
		return 1;
	}
	ll aux = 1;
	while(n > 1){
		if(n&1){
			aux = a * aux;
			a = a * a;
			n = (n-1) / 2;
		}
		else{
			a = a * a;
			n = n / 2;
		}
	}
	return a * aux;
}

// Just so GCC stops bothering me with that stupid 
// "warning: implicit declaration of function ‘strdup’" message
char *strdup(const char *str){
    int n = strlen(str) + 1;
    char *dup = malloc(n);
    if(dup){
        strcpy(dup, str);
    }
    return dup;
}


// convert a number from orig base to dest base
char *baseConversion(char *number, int orig, int dest){
	char *ret;
	/// TO-DO LIST
	
	/* copy number string and convert it to lower or upper case
	* (whichever suits better for the work)
	* 
	* then, work your exponentiation skills with numbers =)
	*/
	
	return strdup(ret);
}

// Driver program to test above functions
int main(void){
	//~ char number[50];
	//~ char *converted;
	//~ int orig;
	//~ int dest;
	
	//~ while(scanf("%s %d %d", number, &orig, &dest) != EOF){
		//~ converted = baseConversion(number, orig, dest);
		//~ printf("%s\n", converted);
		//~ // is free() needed?
		//~ free(converted);
	//~ }
	
	return 0;
}