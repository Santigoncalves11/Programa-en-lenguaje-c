#include <stdio.h>

int fibonacci(int);

int main (){
    int i;

    for(i=1;i<=5;i++){
        printf("%d, ", fibonacci(i));
    }
    return 0;
}

int fibonacci(int n){
    if(n<2){
        return n;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
