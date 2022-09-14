#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <string.h>
#include<assert.h>
#include "function.h"
#define MAXLINE 1000
char *str[10000] = { 0 };
int success = 0;
void read_text(char* patten, const char* file_name,int flag)
{char line[1024] = { 0 };
	char* subString[1024] = { 0 };
	int line_count = 0;
        int i=0,j=0; 
FILE* file = fopen(file_name, "rt");
	if (!file)
		return ;
	while (1)
	{	if (EOF == fscanf(file, "%s", line))
			break;
		else if (flag==1) {
                	if (is_in(line, patten) == 1 )
	             		printf("%s\n", line);
		}
		else if(flag == 2){
			int count = 0;
			for (i = 0; i <=(strlen(line) - strlen(patten)); i++) {
				*subString= GetSubstring(line, i, i + strlen(patten)-1);
				count = 0;
				for (j = 0; j < strlen(patten); j++) {
                                	if (patten[j] == '.' || (patten[j] == (*subString)[j])) {
						count++;
					}
					else
						break;
                                         }
				if (count == strlen(patten)) {
					printf("%s\n", line);
				}
		}
		}
		else if (flag == 3) {
                         if (strcmp(GetSubstring(line, 0, strlen(patten) - 1), patten) == 0) {
				printf("%s\n", line);
			}
		}
		else if (flag == 4) {
                 	if (strcmp(GetSubstring(line, strlen(line) - strlen(patten), strlen(line)), patten) == 0) {
				printf("%s\n", line);
		}
		}
	}
	fclose(file);
	return ;	
}

int main()
{
        char op[MAXLINE], patten[MAXLINE];char filename[100];char argv[2];
        scanf("%s%s%s", op, patten, filename);
        if (strcmp(op, "egrep") == 0) {
                   if (strstr(patten, (char*)"|")>0) {
			printf("%s\n", patten);
			char* pch;
			pch = strchr(patten, '|');
			int pos = pch-patten;
			char* str3[MAXLINE];
			*str3 = GetSubstring(patten, 0, pos - 1);
			read_text(*str3, filename, 1);
			char* str4[MAXLINE];
			*str4 = GetSubstring(patten, pos + 1, strlen(patten));
			read_text(*str4, filename, 1);
			return 0;
		}
	}
        if ((patten[0] == '^') > 0) {
//			printf("found at %s\n", "jinlai");
			char* str2[MAXLINE];
			*str2 = GetSubstring(patten, 1, strlen(patten));
			read_text(*str2, filename, 3);
			return 0;
		}


        if ((patten[strlen(patten) - 1] == '$') > 0) {
			char* str2[MAXLINE];
			*str2 = GetSubstring(patten, 0, strlen(patten) - 2);
			read_text(*str2, filename, 4);
//			printf("* str2 %s\n", *str2);
			return 0;
		}
         if ((is_in(patten, (char*)"[")>0)&& (is_in(patten, (char*)"]")>0)) {
                 char* pch=NULL;
		int start, end;  
pch = strchr(patten, '[');
while (pch != NULL) {
//			printf("found at %d\n", pch - patten);
			start = pch - patten;
         		pch = strchr(pch + 1, 's');
		}
		int i=0,j = 0;
		int start_pos = start;
 //printf("found at %d\n", start_pos);
               char temp[MAXLINE];
		while (patten[start + 1] != ']') {
			
start = start + 1;
	//	printf("found at %c\n", patten[start]);
temp[i] = patten[start];
//printf("found at %d\n", i);
                        
i=i+1;
}
		temp[i] = '\0';
//printf("found at %s\n", temp);
		end = start + 1;
                
		for (i = 0; i < strlen(temp); i++) {
char newpatten[MAXLINE];
 //memset(newpatten, 0, sizeof(newpatten));			
int k = 0;
	for (j = 0; j < start_pos; j++) {
				newpatten[k++] = patten[j];

			}
			newpatten[k++] = temp[i];
			for (j = end + 1; j <= strlen(patten); j++) {
				newpatten[k++] = patten[j];
			}
			newpatten[k] = '\0';
//printf("found at %s\n", newpatten);
			read_text(newpatten, filename, 1);
		}
		return 0;}
if (is_in(patten, (char*)"..")) {
		read_text(patten, filename, 2);
		return 0;
	}
	

		read_text(patten, filename, 1);
	return 0;
}
