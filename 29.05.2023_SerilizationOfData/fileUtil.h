#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT_FILE_OPEN(FILE) if(FILE == NULL) {printf("Cannot open file"); exit(0);}

#endif