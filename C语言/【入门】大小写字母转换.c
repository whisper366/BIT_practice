#include<stdio.h>  
int main(){  
    char c;  
    scanf("%c",&c);  
      
    int ASCII=(int)c;  
    if(ASCII>=65&&ASCII<=90){  
        ASCII=ASCII+32;  
        printf("%c\n",ASCII);  
    }  
    else if(ASCII>=92&&ASCII<=122){  
        ASCII=ASCII-32;  
        printf("%c\n",ASCII);  
    }  
    else{  
        printf("%c\n",c);  
    }  
    return 0;  
}  