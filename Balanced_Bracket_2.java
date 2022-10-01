

import java.util.Scanner;   

public class Balanced_Bracket_2{   
      
    public static void main(String[] args)   
    {   
          
        String s;   
        int i, j=0, count=0;   
        char a, ch;   
          
           
        char[] stack = new char[20];   
          
          
        Scanner sc = new Scanner(System.in);   
          
        System.out.print("Enter an expression to check whether it is balanced or not: \n");   
        s = sc.nextLine();   
          
          
        sc.close();   
          
           
          
          
        for(i = 0; i < s.length(); i++) {   
              
            a = s.charAt(i);   
              
               
            if(a =='(' || a =='{' || a =='[') {   
                stack[j] = a;   
                j++;       
                count = 1;  
            } else if(a == ')') {
                if(count == 1)   
                    j--;   
                ch = stack[j];     
                if(stack.length == 0 || ch != '(') {    
                    System.out.println("\nUnbalanced Parentheses!");   
                    return;   
                }   
            } else if(a == '}') { 
                if(count == 1)  
                    j--;   
                ch = stack[j];    
                if(stack.length == 0 || ch != '{') {    
                    System.out.println("\nUnbalanced Parentheses!");   
                    return;   
                }   
            } else if(a == ']') {  
                if(count == 1)    
                    j--;   
                ch = stack[j];    
                if(stack.length == 0 || ch != '[') {    
                    System.out.println("\nUnbalanced Parentheses!");   
                    return;   
                }   
            }   
        }   
          
        System.out.println("\nBalanced Parentheses.");   
    }   
} 
