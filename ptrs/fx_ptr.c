#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <inttypes.h>


void fun() 
{ 
    printf("Value of a"); 
} 
  
int main() 
{ 
    void (*fun_ptr)(); 
    
    fun_ptr = fun;  
    
    fun_ptr(10); 
  
    return 0; 
} 
