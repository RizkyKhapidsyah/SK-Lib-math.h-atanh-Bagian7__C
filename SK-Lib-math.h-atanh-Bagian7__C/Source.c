#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    printf("atanh(0) = %f\natanh(-0) = %f\n", atanh(0), atanh(-0.0));
    printf("atanh(0.9) = %f\n", atanh(0.9));
    //error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("atanh(-1) = %f\n", atanh(-1));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }

    if (fetestexcept(FE_DIVBYZERO)) {
        puts("    FE_DIVBYZERO raised");
    }

    _getch();
    return 0;
}