/* 
   boggle.h

   header file for main boggle functions.

   Thomas Weng
*/

bool initBoard(char ***b);
bool readBoard(char ***b);
void solveBoggle(LinkedList **LL, int x, int y, HashSet **HS);
