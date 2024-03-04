#include <Arduino.h>

#include "mdrs_globals.h"

#ifdef MDRS_ETH_GATEWAY

#define ETH_CLK_MODE ETH_CLOCK_GPIO16_OUT
#define ETH_POWER_PIN 5

#endif // MDRS_ETH_GATEWAY

#if defined(MDRS_ETH_GATEWAY) || defined(MDRS_UART_GATEWAY)

#define MDRS_GATEWAY

#include "fdrs_gateway_config.h"
#include <fdrs_gateway.h>

#endif // MQTT_GATEWAY or UART_GATEWAY

#if defined(MDRS_LORA_NODE) || defined(MDRS_ESP_NOW_NODE)

#define MDRS_NODE

#include "fdrs_node_config.h"
#include <fdrs_node.h>
#include "mdrs_node.h"

#if defined(MDRS_LORA_CTRL)

#define MDRS_CONTROLLER

#if defined(MDRS_EXAMPLE_LORA_CTRL)
#endif // MDRS_EXAMPLE_LORA_CTRL

#elif defined(MDRS_LORA_SENSOR)

#if defined(MDRS_EXAMPLE_LORA_SENSOR)
#endif // MDRS_EXAMPLE_LORA_SENSOR

#elif defined(MDRS_ESP_NOW_CTRL)

#define MDRS_CONTROLLER

#if defined(MDRS_EXAMPLE_ESPNOW_CTRL)
#endif // MDRS_EXAMPLE_ESPNOW_CTRL

#elif defined(MDRS_ESP_NOW_SENSOR)

#if defined(MDRS_EXAMPLE_ESPNOW_SENSOR)
#endif // MDRS_EXAMPLE_ESPNOW_SENSOR

#endif // MDRS_LORA_CTRL or MDRS_LORA_SENSOR or MDRS_ESP_NOW_CTRL or MDRS_ESP_NOW_SENSOR

#endif // MDRS_LORA_NODE or MDRS_ESP_NOW_NODE

void setup() {
  #ifdef MDRS_ETH_GATEWAY

  pinMode(ETH_POWER_PIN, OUTPUT);
  digitalWrite(ETH_POWER_PIN, HIGH);

  #endif // MDRS_ETH_GATEWAY

  #ifndef MDRS_GATEWAY
  setup_sensor();
  #endif // MDRS_GATEWAY

  beginFDRS();

  #ifndef MDRS_GATEWAY
  setup_FDRS();
  #endif // MDRS_GATEWAY
}

void loop() {
  #if defined(MDRS_CONTROLLER) || defined(MDRS_GATEWAY)
  loopFDRS();
  #endif // MDRS_CONTROLLER || MDRS_GATEWAY

  #ifndef MDRS_GATEWAY
    loopSensor();

    #ifndef MDRS_CONTROLLER
      if(sendFDRS()){
        DBG("Big Success!");
      } else {
        DBG("Nope, not so much.");
      }
      sleepFDRS(10);  //Sleep time in seconds
    #endif // MDRS_CONTROLLER
  #endif // MDRS_GATEWAY
}

// put function definitions here:

#ifdef MDRS_NODE
void myLoadFDRS(float d, uint8_t t) {
  loadFDRS(d, t);
}

void myLoadFDRS(float d, uint8_t t, uint16_t id) {
  loadFDRS(d, t, id);
}

uint32_t myPingFDRS(uint32_t timeout) {
  return pingFDRS(timeout);
}

bool myAddFDRS(void (*new_cb_ptr)(DataReading)) {
  return addFDRS(new_cb_ptr);
}

bool myAddFDRS(int timeout, void (*new_cb_ptr)(DataReading)) {
  return addFDRS(timeout, new_cb_ptr);
}

bool mySubscribeFDRS(uint16_t sub_id) {
  return subscribeFDRS(sub_id);
}
#endif // MDRS_NODE