#include <iostream>

int getinteger(void) {
    int i = 0;

    int c = getchar();
    while (c >= '0' && c <= '9') {
        i = i * 10 + (c - '0');
        c = getchar();
    } 

    return i;
}

double getdouble(void) {
    double d = 0;
    int precision = 0;
    

    int c = getchar();
    while ((c >= '0' && c <= '9') || c == '.') {
        if (c == '.') {
            precision = 1;
            c = getchar();
        }

        if (precision == 0)
            d = d * 10 + (c - '0');
        else
        {
            double frac = c - '0';
            for(int i = 0; i < precision; ++i) frac = frac / 10.0;
            
            d += frac;
            precision++;
        }
        
        c = getchar();
    } 

    return d;
}

int main() {
    std::cout << "Enter integer number: "; 
    int i = getinteger();
    std::cout << "Integer: " << i << std::endl;

    std::cout << "Enter real number: "; 
    double d = getdouble();
    
    std::cout.precision(17);
    std::cout << "Real: " << d << std::endl;

    return 0;
}
