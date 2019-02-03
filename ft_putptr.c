#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
 
int main(int argc, const char * argv[])
{
    int a;
    printf("%p\n",&a);
    unsigned int p = (unsigned int)&a;
    char s[2*sizeof(p)];
    for(int i = 2*sizeof(p)-1; i >= 0; --i)
    {
        s[i] = "0123456789abcdef"[p & 0x0F];
        p >>= 4;
    }
    for(int i = 0; i < 2*sizeof(p); ++i)
    {
        putc(s[i],stdout);
    }
}
 
