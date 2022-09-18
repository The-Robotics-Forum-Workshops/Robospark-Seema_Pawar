#include<stdio.h>  
int main()  
{  
    char bracket_check[50]; 
    int count=0, y=0; 
    printf("\nEnter an expression :");  
    scanf("%s", bracket_check);  
    while (bracket_check [y]!= '\0')  
    {  
        if(bracket_check [y]=='(')  
        {  
            count++;    
        }  
     else if(bracket_check [y]==')')  
        {  
            count--;    
            if(y<0)  
            break;  
        }  
            y++;       
       }  
     if(count==0)  
    {  
        printf("Brackets are balanced");  
    }  
      else  
    {  
        printf("Brackets are unbalanced");
    }  
    return 0;  
}
