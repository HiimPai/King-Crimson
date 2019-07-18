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
static int kira = 0;


void addArray(struct stat stando) {
 arrayFileStat[kira] = stando;
}


// Metodo per la scrittura del file di output
void writeOut (char *pathname) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 struct stat fileStat;
 stat(pathname, &fileStat);
 addArray(fileStat);
 hashtable_add(table, pathname, &arrayFileStat[kira]);
 kira++;
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
  fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>\n" : "->\n");
  fprintf(fout,"###\n");
 }
}

void length(long min, long max) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  if((((struct stat*) entry -> value )-> st_size) >= min && (((struct stat*) entry -> value )-> st_size) <= max) {
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
   fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>\n" : "->\n");
   fprintf(fout,"###\n"); 
  }
 }
}

void user(int uid) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  if((((struct stat*) (entry) -> value ) -> st_uid) == uid) {
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
   fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>\n" : "->\n");
   fprintf(fout,"###\n"); 
  }
 }
}

void user(int gid) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a+");
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  if((((struct stat*) (entry) -> value ) -> st_gid) == gid) {
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
   fprintf(fout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>\n" : "->\n");
   fprintf(fout,"###\n"); 
  }
 }
}

int main (void){
 createTable();
 writeOut("/home/luca/Desktop/eieh.c");
 writeOut("/home/luca/Desktop/testfilestat");
 writeOut("/home/luca/Desktop/test");
 writeOut("/home/luca/Desktop/threading.c");
 user(1000);
}
