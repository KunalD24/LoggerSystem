#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void to_uppercase(char *str)
{
    while(*str)
    {
        if(*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
}

void to_lowercase(char *str)
{
    while(*str)
    {
        if(*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }
}

void reverse_string(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;
    while(start<end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
} 

int  is_palindrome(char *str)
{
    char *start = str;
    char *end = str + strlen(str)-1;
    while(start < end)
    {
        if(*start != *end)
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main()
{
    char *username = (char *)malloc(101);
    char *fileBuffer = (char *)malloc(1000);
    fileBuffer[0] = '\0';
    int choice;

    printf("Please Enter the Username : \n");
    fgets(username, 101, stdin);
    sprintf(fileBuffer + strlen(fileBuffer),"Username is %s",username);
    

    int len = strlen(username);
    if(len > 0 && username[len - 1]=='\n')
    {
        username[len-1]='\0';
    }
    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Uppercase\n");
        printf("2. Lowercase\n");
        printf("3. Palindrome\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                to_uppercase(username);
                printf("Uppercase: %s\n", username);
                sprintf(fileBuffer + strlen(fileBuffer),"Userame in uppercase is %s\n",username);
                break;
            case 2:
                to_lowercase(username);
                printf("Lowercase: %s\n", username);
                sprintf(fileBuffer + strlen(fileBuffer),"Userame in lowercase is %s\n",username);
                break;
            case 3:
                if (is_palindrome(username)) 
                {
                    printf("%s is a palindrome.\n",username);
                    sprintf(fileBuffer + strlen(fileBuffer),"Userame %s is palindrome\n",username);
                } else 
                {
                    printf("%s is not a palindrome.\n",username);
                    sprintf(fileBuffer + strlen(fileBuffer),"Userame %s is not palindrome\n",username);
                }
                break;
            case 4:
                reverse_string(username);
                printf("Reversed: %s\n", username);
                sprintf(fileBuffer + strlen(fileBuffer),"Userame in reverse is %s\n",username);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!=5);

    printf("\nYou want to export:\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice (1 Or 2): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:{
            FILE *fp = fopen("loggeddata.txt","w");
            if(fp)
            {
                fputs(fileBuffer,fp);
                fclose(fp);
                printf("Exported Successfully");
            }
            else
            {
                printf("Failed to Exported");
            }}
            break;
        case 2:
            printf("Not Exported");
            break;
        default:
            printf("Invalid choice\n"); 
    }
    free(username);
    return 0;
}