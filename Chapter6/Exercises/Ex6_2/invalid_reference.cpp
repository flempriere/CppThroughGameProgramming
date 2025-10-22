// Exercise 6.2
// What's wrong with the following program?
//
//```cpp
//int main() {
//  int score;
//  score = 1000;
//  float& rScore = score;
//  return 0;
//}
// The reference here is a different type to the original value,
// references must retain the type of the underlying type
// This should generate a compile error

int main() {
    int score;
    score = 1000;
    float& rScore = score;
    return 0;
}