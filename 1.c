#include <stdio.h>
#include <stdlib.h>
#define _W 12
#define _H 8
#define _X 4
#define _Y 3
int p[4][6] = { { 0,1,0,1,0,0 },
                { 1,0,0,0,1,0 },
                { 1,0,0,0,1,0 },
                { 0,1,0,1,0,0 } };
int main() {
    int i, j;
    for ( i = 0; i < _H; ++i, putchar( '\n' ) )
        for ( j = 0; j < _W; ++j ) 
            printf( "%c", p[(i + _Y) % 4][(j + _X) % 6] ? '*' : ' ' );
 return 0;
}