#include <stdlib.h>
#include <fcgi_stdio.h>

int main(void) {
    while(FCGI_Accept() >= 0){
    printf("Content-type: text/html\r\n\r\nHello World!");
    }
return 0;
}
