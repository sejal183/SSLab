#include <unistd.h>
#include <stdio.h>
int main (){
    char buff[20];
    read(0,buff,20);
    write(1,buff,20);
    return 0;
}
