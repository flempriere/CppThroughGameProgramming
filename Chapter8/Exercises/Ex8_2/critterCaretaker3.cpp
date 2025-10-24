// Exercise 8.2
// Further improve the Critter Caretaker program so that the critter is more
//  expressive about its needs by hinting how hungry and bored it is.

#include <iostream>

using namespace std;

class Critter {
public:
  Critter(int hunger = 0, int boredom = 0);
  void Talk();
  void Eat(int food = 4);
  void Play(int fun = 4);
  void Greet();

private:
  int m_Hunger;
  int m_Boredom;

  int GetMood() const;
  void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom)
    : m_Hunger(hunger), m_Boredom(boredom) {};

inline int Critter::GetMood() const { return (m_Hunger + m_Boredom); }

void Critter::PassTime(int time) {
  m_Hunger += time;
  m_Boredom += time;
}

void Critter::Talk() {
  cout << "I'm a critter and I feel ";
  int mood = GetMood();
  if (mood > 15) {
    cout << "mad.\n";
  } else if (mood > 10) {
    cout << "Frustrated.\n";
  } else if (mood > 5) {
    cout << "Okay.\n";
  } else {
    cout << "happy.\n";
  }
  cout << "The critter looks ";
  if (m_Hunger > 7) {
    cout << "starving.\n";
  }
  else if (m_Hunger > 3) {
    cout << "hungry.\n";
  } else if (m_Hunger > 0) {
    cout << "satisfied.\n";
  } else {
    cout << "full.\n";
  }

  cout << "The critter seems ";
  if (m_Boredom > 7) {
    cout << "bored.\n";
  } else if (m_Boredom > 3) {
    cout << "needy.\n";
  } else if (m_Boredom > 0) {
    cout << "playful.\n";
  } else {
    cout << "Relaxed.\n\n";
  }
  PassTime();
}

void Critter::Eat(int food) {
  cout << "Brrupp.\n";
  m_Hunger -= food;
  if (m_Hunger < 0) {
    m_Hunger = 0;
  }
  PassTime();
}

void Critter::Play(int fun) {
  cout << "Wheee!\n";
  m_Boredom -= fun;
  if (m_Boredom < 0) {
    m_Boredom = 0;
  }
  PassTime();
}

void Critter::Greet() {
    cout << "Critter's Hunger: " << m_Hunger << "\n";
    cout << "Critter's Boredom: " << m_Boredom << "\n\n";
}

int main() {
  Critter crit;
  crit.Talk();
  int choice;
  do {
    cout << "\nCritter Caretaker\n\n";
    cout << "0 - Quit\n";
    cout << "1 - Listen to your critter\n";
    cout << "2 - Feed your critter\n";
    cout << "3 - Play with your critter\n\n";

    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
      cout << "Good-bye.\n";
      break;
    case 1:
      crit.Talk();
      break;
    case 2:
      crit.Eat();
      break;
    case 3:
      crit.Play();
      break;
    case 4:
      crit.Greet();
      break;
    default:
      cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
    }
  } while (choice != 0);

  return 0;
}