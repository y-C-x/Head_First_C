#include <stdio.h>
#include <hfcal.h>

int main(){
	display_calories(115.2,11.3,0.79);
	return 0;
}

/*
gcc -I ./includes -c hfcal.c -o hfcal.o
gcc -I ./includes -c elliptical.c -o elliptical.o
ar -rcs ./libs/libhfcal.a hfcal.o
gcc elliptical.o -L ./libs 0lhfcal -o elloptical
*/