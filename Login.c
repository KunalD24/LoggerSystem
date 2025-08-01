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
    char *dummyUsername = (char *)malloc(101); 
    char *fileBuffer = (char *)malloc(1000);

    fileBuffer[0] = '\0';
    int choice;
    while(1)
    {
        while(1)
        {
            printf("Please Enter a Username : ");
            fgets(username, 101, stdin);
            int len = strlen(username);
            if(len > 0 && username[len - 1]=='\n')
            {
                username[len-1]='\0';
            }
            if (strlen(username) == 0) 
            {
                printf("Please enter a valid username.\n");
            }
            else
            {
                break;
            }
        }

        strcpy(dummyUsername,username);
        printf("Username is %s\n",username);
        sprintf(fileBuffer + strlen(fileBuffer),"\nUsername is %s\n\n",username);
        // sprintf(fileBuffer + strlen(fileBuffer),"%s\n\n",username);
        // printf("%s",username);
    
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
                    strcpy(username,dummyUsername);
                    to_uppercase(username);
                    printf("Uppercase: %s\n", username);
                    sprintf(fileBuffer + strlen(fileBuffer),"Userame in uppercase is %s\n",username);
                    break;
                case 2:
                    strcpy(username,dummyUsername);
                    to_lowercase(username);
                    printf("Lowercase: %s\n", username);
                    sprintf(fileBuffer + strlen(fileBuffer),"Userame in lowercase is %s\n",username);
                    break;
                case 3:
                    strcpy(username,dummyUsername);
                    if (is_palindrome(username)) 
                    {
                        printf("%s is a palindrome.\n",username);
                        sprintf(fileBuffer + strlen(fileBuffer),"Userame %s is palindrome\n",username);
                    } 
                    else 
                    {
                        printf("%s is not a palindrome.\n",username);
                        sprintf(fileBuffer + strlen(fileBuffer),"Userame %s is not palindrome\n",username);
                    }
                    break;
                case 4:
                    strcpy(username,dummyUsername);
                    reverse_string(username);
                    printf("Reversed: %s\n", username);
                    sprintf(fileBuffer + strlen(fileBuffer),"Userame in reverse is %s\n",username);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } 
        while(choice!=5);
        printf("\nDo you want to enter another username?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice != 1) 
        {
            break;
        }
    }
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
                printf("Failed to Export");
            }}
            break;
        case 2:
            printf("Not Exported");
            break;
        default:
            printf("Invalid choice\n"); 
    }
    free(username);
    free(fileBuffer);
    free(dummyUsername);
    return 0;
}
