#include <stdio.h>                                                                                                                                     
#include <string.h>                                                                                                                                    
#include <stdlib.h>                                                                                                                                    
                                                                                                                                                       
/**                                                                                                                                                    
 * tokenize - tokenizes command and arguments which are a string                                                                                       
 * @s: string that contains the command and the arguments                                                                                              
 * Return: 0 on success                                                                                                                                
 */                                                                                                                                                    
                                                                                                                                                       
int tokenize(char *s)                                                                                                                                  
{                                                                                                                                                      
        char *token, *d;                                                                                                                               
        int len;                                                                                                                                       
                                                                                                                                                       
        len = strlen(s);                                                                                                                               
                                                                                                                                                       
        d = (char *)malloc(sizeof(char) * (len + 1));                                                                                                  
        d = " ";                                                                                                                                       
                                                                                                                                                       
        token = strtok(s, d);                                                                                                                          
                                                                                                                                                       
        while (token != NULL)                                                                                                                          
        {                                                                                                                                              
                printf("%s\n", token);                                                                                                                 
                token = strtok(NULL, d);                                                                                                               
        }                                                                                                                                              
                                                                                                                                                       
        return (0);                                                                                                                                    
}
