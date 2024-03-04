#ifdef MDRS_EXAMPLE_ESPNOW_SENSOR

#include <Arduino.h>
#include "mdrs_globals.h"

#include "fdrs_node_config.h"
#include <fdrs_datatypes.h>
#include "mdrs_node.h"

float data1;
float data2;

float readHum();
float readTemp();

void setup_sensor() {
    return;
}

void setup_FDRS() {
    return;
}

void loopSensor() {
  data1 = readHum();
  myLoadFDRS(data1, HUMIDITY_T);
  data2 = readTemp();
  myLoadFDRS(data2, TEMP_T);
}

float readTemp() {
  return 22.069;
}

float readHum() {
  return random(0, 100);
}

#endif //MDRS_EXAMPLE_ESPNOW_SENSOR