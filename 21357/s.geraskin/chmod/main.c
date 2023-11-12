#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void log_user_id(){
    printf("Real User Id: %d\n", getuid());
    printf("Effective User Id: %d\n", geteuid());
}

void open_file(const char* s){
    FILE* f;
    if((f = fopen(s, "r"))==NULL){
        perror("Cannot open file\n");
    }
    else{
        fclose(f);
    }
}

int main(int argc, char** argv){
    
    setuid(geteuid()-1);
    log_user_id();
    printf("%d\n", getuid());
    open_file(argv[1]);

    setuid(geteuid());
    log_user_id();
    printf("%d\n", getuid());
    open_file(argv[1]);

}
