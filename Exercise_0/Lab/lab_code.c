#include <stdio.h>
#include <stdbool.h>
#define PI 3

int main(){

    // Built in types

    int a; // allocate 4 bytes for an integer
    const int abc = 21; // the value of abc should not be able to be changed
    float b = 3.14f; // usually 4 bytes
    double c = 3.14159; // usually 8 bytes
    char d = 'A'; // 1 byte of memory  // ALWAYS SINGLE QUOTE FOR CHARACTERS


    bool x = true; // C has no built in Boolean but with the #include <stdbool.h> statement we will have some
                   // 0 --> False, 1 --> True

    printf("this is a constant %d\n", PI);
    printf("this is a int %d\n", a);
    printf("this is a float %f\n", b);
    printf("this is a double %f\n", c);
    printf("this is a char %c\n", d);

    float e = 10 / 3.0;
    printf("Result %f\n", e);

    // Logical operators

    /*  
    
    >= <= > < 
    
    AND --> &&, OR --> ||, NOT --> !    
    
    */

    // Arrays

    int arr[10];
    arr[0] = 3;
    arr[1] = 4;

    printf("%d\n", arr[9]);

    return 0;
}

// Length of integer Array

int length(int arr[], int size){
    int result = 0;
    for (int i = 0; i < size; i++){
        result += arr[i];
    }
    return result;
}