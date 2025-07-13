#include <stdio.h>

int main()
{

  enum PowerStatus
  {
    ON = 1,
    OFF = 0
  };

  enum PowerStatus s1 = ON;
  printf("Power status of your machine : %d\n", s1);

  typedef enum
  {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
  } Days;

  Days today = SUNDAY;

  printf("Today's index is %d\n", today);

  return 0;
}