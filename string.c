#include <stdio.h>

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
