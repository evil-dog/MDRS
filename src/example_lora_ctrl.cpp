#ifdef MDRS_EXAMPLE_LORA_CTRL

#include <Arduino.h>
#include "mdrs_globals.h"

#include "fdrs_node_config.h"
#include <fdrs_datatypes.h>
#include <fdrs_debug.h>
#include "mdrs_node.h"

void fdrs_recv_cb(DataReading theData)
{
  DBG("ID: " + String(theData.id));
  DBG("Type: " + String(theData.t));
  DBG("Data: " + String(theData.d));
}

void setup_sensor() {
    return;
}

void setup_FDRS() {
  myPingFDRS(1000);
  myAddFDRS(fdrs_recv_cb);
  mySubscribeFDRS(READING_ID);
}

void loopSensor() {
    return;
}

#endif //MDRS_EXAMPLE_LORA_CTRL