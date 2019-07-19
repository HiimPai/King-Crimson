#include <stdio.h>
#include <stdlib.h>
#include <collectc/hashtable.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


HashTable *table;
int size = 4;
struct stat *arrayFileStat;
static int indexOfArray = 0;


struct stat *createArray(int sizeOfArray) {
    arrayFileStat = realloc(arrayFileStat,sizeof(struct stat)*sizeOfArray);
    return arrayFileStat;
    }


void addToArray(struct stat stando) {
 arrayFileStat[indexOfArray] = stando;
}


void addEntry (char *pathname /*, struct stat statStruct; */) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
 struct stat fileStat/* = statStruct */;
 stat(pathname, &fileStat);
 addToArray(fileStat);
 hashtable_add(table, pathname, &arrayFileStat[indexOfArray]);
 indexOfArray++;
}
   

void createTable() {
 enum cc_stat hsh = hashtable_new(&table);
 if (hsh == CC_ERR_ALLOC) {
  printf("La tabella non è stata creata");
 }
} 


void removeElements() {
 hashtable_remove_all(table);
}


void printTable() {
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
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
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
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
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  if((((struct stat*) (entry) -> value ) -> st_uid) == uid) {
   fprintf(stdout,"# <%s>\n", ((const char*)entry -> key));
   fprintf(stdout,"<%d> ",(((struct stat*) (entry) -> value ) -> st_uid));
   fprintf(stdout,"<%d> ",(((struct stat*) entry -> value ) -> st_gid));
   fprintf(stdout,"<%ld> ",(((struct stat*) entry -> value )-> st_size));
   fprintf(stdout,(S_ISDIR(((struct stat*)(entry -> value)) -> st_mode)) ? "<d" : "<-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IRUSR) ? "r" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IWUSR) ? "w" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IXUSR) ? "x" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IRGRP) ? "r" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IWGRP) ? "w" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IXGRP) ? "x" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IROTH) ? "r" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IWOTH) ? "w" : "-");
   fprintf(stdout,(((struct stat*)(entry -> value)) -> st_mode & S_IXOTH) ? "x>\n" : "->\n");
   fprintf(stdout,"###\n"); 
  }
 }
}


void group(int gid) {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
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


void totStat() {
 FILE* fout = fopen("/home/luca/Desktop/filestat.txt","a");
 HashTableIter hti;
 hashtable_iter_init(&hti, table);
 TableEntry *entry;
 long minLength = 9223372036854775807;
 long maxLength = 0;
 int fileCounter = 0;
 int sum = 0;
 int dirCounter = 0;
 int linkCounter = 0;
 long numLink = 0;
 while(hashtable_iter_next(&hti, &entry) != CC_ITER_END) {
  fileCounter++;
  sum += (((struct stat*) entry -> value )-> st_size);
  numLink += (((struct stat*) (entry) -> value ) -> st_nlink);
  if((S_ISDIR(((struct stat*)(entry -> value)) -> st_mode)) == true) {
   dirCounter++;
  }
  if((((struct stat*) entry -> value )-> st_size) >= maxLength) {
   maxLength = (((struct stat*) entry -> value )-> st_size);
  }
  if((((struct stat*) entry -> value )-> st_size) <= minLength) {
   minLength = (((struct stat*) entry -> value )-> st_size);
  }    
 }
int avg = sum/fileCounter;
 printf("Numero file: %d\n", fileCounter);
 printf("Dimensione totale: %d\n", sum);
 printf("Dimensione media: %d\n", avg);
 printf("Numero directory: %d\n", dirCounter);
 printf("Numero link: %ld\n", numLink);
 printf("Dimensione massima: %ld\n", maxLength);
 printf("Dimensione minima: %ld\n", minLength);
}

int main() {
 createTable();
 createArray(4);
 addEntry("/home/luca/Desktop/eieh.c");
 addEntry("/home/luca/Desktop/threading.c");
 addEntry("/home/luca/Desktop/Polnareff");
 addEntry("/home/luca/Desktop/eieh.c");
 user(1000);
}

