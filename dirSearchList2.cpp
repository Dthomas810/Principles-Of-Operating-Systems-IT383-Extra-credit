#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>

#include<cstdio>
#include<cstdlib>

#include <sys/types.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"

using namespace std;

int finds=0;

void search_dir(char * path, char * search);
void show_content(char*path);


void search_dir(char * path, char * search )
{
   DIR * d = opendir(path); // open the path
  if(d==NULL) return; // if was not able return
  struct dirent * dir; // for the directory entries
  
  
  while ((dir = readdir(d)) != NULL) // if we were able to read somehting from the directory
    {
    /*  if(dir-> d_type != DT_DIR) // if the type is not directory just print it with blue
        printf("%s%s\n",BLUE, dir->d_name);  */
        
      
     if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
        //printf("%s%s%s: \n",GREEN,path, dir->d_name); // print its name in green       
        char d_path[255]; // here I am using sprintf which is safer than strcat
        sprintf(d_path, "%s/%s", path, dir->d_name);
        
        // PRINT CONTENT IF CORRECT PATH
                if( strcmp(dir->d_name, search) == 0   ){
                 printf("%s%s/%s: \n",BLUE,path, dir->d_name); // print its name in green
               //show_content(path);
                 show_content(d_path);
                }
                
        search_dir(d_path, search); // recall with the new path
      }
    }
    closedir(d);
}

void show_content(char * path){
//printf("SHOW CONTENT\n");
finds++;
DIR* directory;
struct dirent *pDirent;




directory =  opendir(path);
if (directory == NULL) {
            printf ("Cannot open directory '%s'\n", path);            
            return;
        }



while ((pDirent = readdir(directory)) != NULL) {  
if(pDirent-> d_type != DT_DIR) // if the type is not directory just print it with blue
        printf("%s%s\n",GREEN, pDirent->d_name);  

  if(pDirent -> d_type == DT_DIR && strcmp(pDirent->d_name,".")!=0 && strcmp(pDirent->d_name,"..")!=0 ) // if it is a directory
      {
       // printf("%s%s%s: \n",GREEN,path, pDirent->d_name); // print its name in green
        }
    


            //printf ("[%s]\n", pDirent->d_name);
        } 
        
closedir(directory);


}



int main(int argc, char *argv[]){


search_dir(argv[2], argv[1]);  //searching for argv[1] in path argv[2]
//show_content(argv[1]);
if(finds==0){
printf("Search Failed!!");
}

printf("%s\n", NORMAL_COLOR);

return 0;



    



}
