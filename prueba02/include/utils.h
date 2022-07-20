#define _UTILS_H

bool hasAChar(char* strStart, char* strEnd);
int  validInt();
int  producCols(int*, int, int);
int  sumRows(int*, int, int);
bool wantToRepeat();
void printRow(int*, int*);
void printMatrix(int*, int len);
bool hasRepeated(int*, int, int);
bool appearInArr(int*, int, int);
void getRow(int*, int*, int);
void getColumn(int*, int*, int);
int  sumArr(int*, int*);
int  multArr(int*, int*);
int  getMax(int*, int*);
int  getMin(int*, int*);
void printSeparated(int* arr, int* end);
void getNoRepeatedNums(int*, int*, int*, int);
int  getLen(int* arr, int max);
void printSpaced(int n);

