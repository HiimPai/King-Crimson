#include <stdio.h>
#include <stdlib.h>
#include <collectc/hashtable.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

HashTable *table;
int size = 3;
struct stat arrayFileStat[3];


// Metodo per la scrittura del file di output
void writeOut (char *pathname) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 struct stat fileStat;
 stat(pathname, &fileStat);
 fileStat_add(fileStat);
 hashtable_add(table, pathname, arrayFileStat);
 }

void fileStat_add(struct stat fileStat) {
 for(int i = 0; i < 3; i++) {
  arrayFileStat[i] = fileStat;
 }
}
    // Scrittura dei parametri richiesti
   

void createTable() {
 enum cc_stat hsh = hashtable_new(&table);
 if (hsh == CC_ERR_ALLOC) {
  printf("polnareff");
 }
} 

 void printTable() {
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) { 
  fprintf(fout,"# <%s>\n", ((const char*)entry -> key));
  fprintf(fout,"<%d> ",(((struct stat*) (entry) -> value ) -> st_uid));
  fprintf(fout,"<%d> ",(((struct stat*) entry -> value ) -> st_gid));
  fprintf(fout,"<%ld> ",(((struct stat*) entry -> value )-> st_size));
  fprintf(fout,(S_ISDIR(((struct stat*)(entry -> value)) -> st_mode)) ? "<d" : "<-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IRUSR) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IWUSR) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXUSR) ? "x" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IRGRP) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IWGRP) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXGRP) ? "x" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IROTH) ? "r" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IWOTH) ? "w" : "-");
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>" : "->");
  fprintf(fout,"###");
 }
} 



int main (void){
 createTable();
 writeOut("/home/luca/Desktop/eieh.c");
 writeOut("/home/luca/Desktop/testfilestat");
 writeOut("/home/luca/Desktop/test");
}
