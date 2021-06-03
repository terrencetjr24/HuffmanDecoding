#include "main.h"

int main(int argc, char **argv){
   if(argc != 2){
      printf("The executable should be ran with 1 argument.\n");
      return EXIT_FAILURE;
    }

  FILE * compressedFile = NULL;
  FILE * outputFile = NULL;

  char* inputFile = argv[1];
  char outputFileName[100];

  memset(outputFileName, '\0', sizeof(outputFileName));
  strncpy(outputFileName, inputFile, strlen(inputFile) - 4);
  strcat(outputFileName, ".dec");

  long int totalBytesInCompressed = 0;
  long int totalBytesInUncompressed = 0;
  long int topologicalBytes = 0;
  long int beginningOfData = 0;

  compressedFile = fopen(inputFile, "rb");
  findCounts(compressedFile, &totalBytesInCompressedFile, &totalBytesInUncompressed, &topologicalBytes);
  beginningOfData = (8*3) + topologicalBytes;



  // recreate the tree from the file
  TreeNode * tree = recreateTree(compressedFile, topologicalBytes);

  char* decode = decode(compressedFile, tree, totalBytesInUncompressed);
  // Go through the data one bit at a time and use it to traverse the tree to find the decode

    // if I reach a leaf node, add it to the decoded string
    // Continue
    // Check the size of the decoded string against the original size
      // When I reach that, stop decoding

  // Write the string to the output file


  outputFile = fopen(outputFileName, "w");
  for (int i = 0; i < totalBytesInUncompressed; i++){
    fprintf(outputFile, "%c", decode[i]);
  }

  free(decode);
  freeTree(tree);
  fclose(compressedFile);
  fclose(outputFile);
  return EXIT_SUCCESS;
}
