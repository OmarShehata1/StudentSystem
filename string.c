#include <stdio.h>

/*
void string_print(char* str)
{
    int i;
    if(str==0)
    {
        return;
    }
    for(i=0 ; str[i] ; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}


void string_upperLower(char*str)
{
    int i;
    for(i=0 ; str[i] ; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+'a'-'A';
        }
    }

}

int string_length(char* str)
{
    int i;
    for(i=0 ; str[i] ; i++)
    {

    }
    return i;
}

void string_reverse(char* str)
{
    int i,j=string_length(str)-1;
    char temp;
    for(i=0; i<j ; i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

int string_compare(char*str1,char*str2)
{
    int i;
    for(i=0 ; str1[i] || str2[i] ; i++)
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1 ;
}

int string_compare_NotcaseSenstive(char*str1,char*str2)
{
    string_upperLower(str1);
    string_upperLower(str2);
    int i;
    for(i=0 ; str1[i] || str2[i] ; i++)
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1 ;

}


int string_compare_NotcaseSenstive2(char*str1,char*str2)
{

    int i;
    char c1,c2;
    for(i=0 ; str1[i] || str2[i] ; i++)
    {
       if(str1[i]>='A' && str1[i]<='Z')
       {
           c1=str1[i]+'a'-'A';
       }
       else
       {
           c1=str1[i];
       }
       if(str2[i]>='A' && str2[i]<='Z')
       {
           c2=str2[i]+'a'-'A';
       }
       else
       {
           c2=str2[i];
       }
       if(c1 !=c2)
       {
           return 0;
       }
       else
       {
         ;
       }
    }
      return 1;

}

/*
void string_longestrWord(char* str,char* word)
{
    int i,count=0,max=0,index;
    for(i=0; str[i]; i++)
    {
        if(str[i]==' ')
        {
            count=0;
        }
        else
        {
            count++;
            if(count>max)
            {
                max=count;
                index=i;
            }
        }
    }
    index=index-max+1;
    printf("%d  %d  %d  %c",max,index,count,str[index]);
word[i]=0;
}



void intToString(int num,char*s)
{
    int i=0,flag=0;
    if(num==0)
    {
        s[i]='0';
        s[1]=0;
        return;
    }
    if(num<0)
    {
        num=num*-1;
        s[0]='-';
        i=1;
        flag=1;
    }
    while(num)
    {
        s[i]=num%10+'0';
        i++;
        num=num/10;
    }
    s[i]=0;
    if(flag==1)
    {
        string_reverse(s+1);
    }
    else
        string_reverse(s);
    string_print(s);
}

int stringToInt(char*s)
{
    int i, num=0;
    for(i=0 ;i<s[i] ;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        num=num*10+s[i]-'0';
        else{;}
    }
    return num;
}


*/
void string_scan(char* str,int maxSize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);

    for( ; str[i]!='\n' && i<maxSize-1; )
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}



int string_check(char*arr)
{
    int i,flag;
    for(i=0; arr[i]; i++)
    {
        flag=0;
        if((arr[i]>='a' &&arr[i]<='z')||(arr[i]>='A' &&arr[i]<='Z'))
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        return 1;
    }
    else
        return 0;
}


int string_checkNumber(char*arr)
{
    int i,flag;
    for(i=0; arr[i]; i++)
    {
        flag=0;
        if(arr[i]>='0' &&arr[i]<='9')
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        return 1;
    }
    else
        return 0;
}



int string_compare(char*str1,char*str2)
{
    int i;
    for(i=0 ; str1[i] || str2[i] ; i++)
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1 ;
}




/*

 int stringToInt2(char*s ,int* pnum)
{
    int i, num=0 ,flag=0;
    for(i=0 ;i<s[i] ;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        num=num*10+s[i]-'0';
        else if(s[0]== '-')
        {
            flag=1;
        }
        else {
            return 0;
        }
    }
    if(flag==1)
    {
        *pnum=num*-1;
    }
    else
    *pnum=num;
    return 1;
}
*/
