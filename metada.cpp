
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




void listFiles(const char* dirname){
    DIR* dir=opendir(dirname);
    
    if(dir==NULL){
        return ;
    }
    struct dirent* entity;    
    
    entity= readdir(dir);
    while(entity!=NULL){   


        if(entity->d_type==DT_DIR&&strcmp(entity->d_name,".")!=0&&strcmp(entity->d_name,"..")!=0){
            printf("Type: Directory\n");
            printf("%s\n", entity->d_name);
            
        }else{
            printf("Type: File\n");
            printf("%s\n", entity->d_name);


        }
        
        if(entity->d_type==DT_DIR && strcmp(entity->d_name,".")!=0&&strcmp(entity->d_name,"..")!=0){
            char path[100]={0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }    

        entity=readdir(dir);
    }
    closedir(dir);
}



int main(int argc, char* argv[]){
    listFiles(".");    
    return 0;
}