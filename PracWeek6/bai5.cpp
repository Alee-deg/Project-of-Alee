#include <iostream>
#include <vector>

using namespace std;

int n, m;

class Person {
private:
  int high;
  int weight;

public:
  Person() : Person(0, 0) {}
  Person(int high, int weight) {
    this->high = high;
    this->weight = weight;
  }
  void display() { cout << high << " " << weight << endl; }
};

int main() {
  Person Hau(170, 70);
  Hau.display();
  Person Hai(123, 23);
  Hai.display();
  return 0;
}
