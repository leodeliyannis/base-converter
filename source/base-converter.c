/* BaseConverter - a simple number base converter
Copyright (c) 2015 Leonardo Deliyannis Constantin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// macro for debug prints
//#define DEBP

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

int valueOf(char c){
	if('0' <= c && c <= '9'){
		return c - '0';
	}
	else if('A' <= c && c <= 'Z'){
		return c - 'A' + 10;
	}
	else if('a' <= c && c <= 'z'){
		return c - 'a' + 10;
	}
	// invalid value
	return -1;
}

int toChar(int c){
	if(0 <= c && c <= 9){
		return c + '0';
	}
	else if(10 <= c && c <= 35){
		return c + 'a' - 10;
	}
	// invalid value
	return -1;
} 

// convert a number from orig base to dest base
char *baseConversion(char *number, int orig, int dest){
	char *ret = NULL;
	ll value = 0;
	int tam = strlen(number) - 1;
	int newtam;
	
	// retrieve value from string
	for(int i = tam; i >= 0; i--){
		value += binpow(orig, tam - i) * (ll) valueOf(number[i]);
	}
	
	newtam = (int) ceil(log1p(value)/log(dest));
	ret = (char*) malloc(newtam+1);
	
	// insert value into return string, converted
	for(int i = newtam-1; i >= 0; i--){
		ret[i] = toChar(value % (ll)dest);
		value /= (ll)dest;
	}
	ret[newtam] = '\0';
	
	return ret;
}

// Driver program to test above functions.
// Working only with positive integers by now.
int main(void){
	char number[50];
	char *converted;
	int orig;
	int dest;
	
	while(scanf("%s %d %d", number, &orig, &dest) != EOF){
		converted = baseConversion(number, orig, dest);
		printf("%s\n", converted);
		free(converted);
	}
	
	return 0;
}
