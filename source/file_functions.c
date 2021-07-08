#include "../header/file_functions.h"

void findCounts(FILE *ogFile, long int* totalBytes, long int* totalInUncompressed, long int* totalInTopology){
  int idx = 0;
  int distinctCharsInFile = 0;

  // Ensure the FILE pointer is set to the beginning of the file
  fseek(ogFile, 0, SEEK_SET);
  fread(totalBytes, sizeof(long int), 1, ogFile);

  fseek(ogFile, sizeof(long int), SEEK_SET);
  fread(totalInTopology, sizeof(long int), 1, ogFile);

  fseek(ogFile, sizeof(long int)*2, SEEK_SET);
  fread(totalInUncompressed, sizeof(long int), 1, ogFile);
}
