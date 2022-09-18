#include <stdio.h>

int main() {

  int numbers[5] = {0, 0, 0, 0, 0};
  int n, m, num;
  n = 0;
  m = 0;
  num = 0;

  int loopTracker;
  loopTracker = 1;

  int innerLoopTracker, loopCounter, breakChecker;

  if (m == 0) {
    numbers[0] = num;
    m = m + 1;
  } else {
    m = m + 1;
    numbers[m] = num;
    while (loopTracker == 1) {

      innerLoopTracker = 1;
      loopCounter = 0;
      breakChecker = 0;

      while (innerLoopTracker == 1) {
        if (numbers[0 + loopCounter] > numbers[1 + loopCounter]) {
          breakChecker = 1;
          numbers[m] = numbers[0 + loopCounter];

          numbers[0 + loopCounter] = numbers[1 + loopCounter];

          numbers[1 + loopCounter] = numbers[m];
        }

        loopCounter++;
        
        if (loopCounter == (m - 1)) {

          innerLoopTracker = 0;
        }
      }

      if (breakChecker == 0) {

        loopTracker = 0;
      }
    }
  }

  int loop;
  for (loop = 0; loop < 6; loop++)
    printf("%d ", numbers[loop]);
}