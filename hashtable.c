#include <stdio.h>
#include <stdlib.h>
#include <collectc/hashtable.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int main() {
HashTable *table;
struct stat *fileStat = malloc(sizeof(struct stat));
FILE* fout = fopen("/home/luca/Desktop/filestat.txt","w");
int result;

char* date(time_t time){
    char *ctime_no_nl;
    time_t currentTime = time;
    ctime_no_nl = strtok(ctime(&currentTime), "\n");
    return ctime_no_nl;
}

void createTable() {
 enum cc_stat hsh = hashtable_new(&table);
 if (hsh == CC_ERR_ALLOC) {
  printf("polnareff");
 }
}

void addHash (const char* pathname, struct stat *fs) {
 stat(pathname, fs);
 enum cc_stat ulamog = hashtable_add(table, pathname, fs);
 if(ulamog != CC_OK) {
  printf("nani"); 
 }
} 

void printTable() {
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  fprintf(fout,"<%s> ",date(time(NULL)));
  fprintf(fout,"<%d> ",((struct stat*)(entry -> value)) ->st_uid);
  fprintf(fout,"<%d> ",((struct stat*)(entry -> value)) ->st_gid);
  fprintf(fout,"<%ld> ",((struct stat*)(entry -> value)) ->st_size);
  fprintf(fout,(S_ISDIR(((struct stat*)(entry -> value)) ->st_mode)) ? "<d" : "<-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IRUSR) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IWUSR) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IXUSR) ? "x" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IRGRP) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IWGRP) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IXGRP) ? "x" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IROTH) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IWOTH) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) ->st_mode & S_IXOTH) ? "x>" : "->");
  fprintf(fout," <%s> ",date(((struct stat*)(entry -> value)) ->st_atime));
  fprintf(fout," <%s> ",date(((struct stat*)(entry -> value)) ->st_mtime));
  fprintf(fout," <%s> \n",date(((struct stat*)(entry -> value)) ->st_ctime));
  fprintf(fout,"###");
 }
}

 createTable();
 addHash("/home/luca/Desktop/eieh.c", fileStat);
 addHash("/home/luca/Desktop/hashtable.c", fileStat);
 addHash("/home/luca/Desktop/filestat.txt", fileStat); 
 printTable();
 return 0;
}
