// Exercise 9.3
// What's wrong with the following code?
//
// int main() {
//      int* pScore = new int;
//      *pScore = 500;
//      pScore = new int(1000);
//      delete pScore;
//      pScore = 0;
//}

int main() {
    int* pScore = new int;
    *pScore = 500;
    pScore = new int(1000);
    delete pScore;
    pScore = 0;
    return 0;
}