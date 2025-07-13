#include <stdio.h>

// Detect the platform and define a unified interface (SLEEP(x))
// to hide the platform-specific differences.

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#endif

// Define traffic light states
enum TrafficLights
{
  RED,
  YELLOW,
  GREEN
};

// Return a description of the current traffic light state
char *printCurrentLight(enum TrafficLights currentLight)
{
  switch (currentLight)
  {
  case RED:
    return "RED - STOP";
  case YELLOW:
    return "YELLOW - WAIT";
  case GREEN:
    return "GREEN - GO";
  default:
    return "Unknown light code!";
  }
}

// Return the next traffic light state
enum TrafficLights updateCurrentLight(enum TrafficLights currentLight)
{
  switch (currentLight)
  {
  case RED:
    return GREEN;
  case YELLOW:
    return RED;
  case GREEN:
    return YELLOW;
  default:
    return RED;
  }
}

int main()
{
  enum TrafficLights currentLight = RED;

  printf("_____________TRAFFIC LIGHT SIMULATOR_____________\n");

  while (1)
  {
    printf("Current light: %s\n", printCurrentLight(currentLight));
    SLEEP(2);
    currentLight = updateCurrentLight(currentLight);
  }

  return 0;
}