

HashTable *table;
struct stat *arrayFileStat;
static int indexOfArray = 0;

struct stat createArray(int sizeOfArray);

void addToArray(struct stat statFile);

void addEntry (char *pathname, struct stat statStruct);

void createTable();

void removeElements();

void length(long min, long max);

void user(int uid);

void group(int gid);

void totStat();
