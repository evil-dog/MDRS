#ifndef __FDRS_GATEWAY_CONFIG_h__
#define __FDRS_GATEWAY_CONFIG_h__

#include "mdrs_globals.h"

#ifdef MDRS_EXAMPLE_ESPNOW_SENSOR
#define READING_ID    1   //Unique ID for this sensor
#define GTWY_MAC      MDRS_ETH_GATEWAY_MAC //Address of the nearest gateway

#define DEEP_SLEEP
//#define POWER_CTRL    14
#define FDRS_DEBUG

#endif // MDRS_EXAMPLE_ESPNOW_SENSOR

#ifdef MDRS_EXAMPLE_ESPNOW_CTRL
#define READING_ID    2   //Unique ID for this sensor
#define GTWY_MAC      MDRS_ETH_GATEWAY_MAC //Address of the nearest gateway

#define DEEP_SLEEP
//#define POWER_CTRL    14
#define FDRS_DEBUG

#endif // MDRS_EXAMPLE_ESPNOW_CTRL

#ifdef MDRS_EXAMPLE_LORA_CTRL
#define READING_ID    3   //Unique ID for this sensor
#define GTWY_MAC      MDRS_UART_GATEWAY_MAC //Address of the nearest gateway

#define DEEP_SLEEP
//#define POWER_CTRL    14
#define FDRS_DEBUG

#endif // MDRS_EXAMPLE_LORA_CTRL

#ifdef MDRS_EXAMPLE_LORA_SENSOR
#define READING_ID    4   //Unique ID for this sensor
#define GTWY_MAC      MDRS_UART_GATEWAY_MAC //Address of the nearest gateway

#define DEEP_SLEEP
//#define POWER_CTRL    14
#define FDRS_DEBUG

#endif // MDRS_EXAMPLE_LORA_SENSOR

#ifdef MDRS_ESP_NOW_NODE
#define USE_ESPNOW

#endif // MDRS_ESP_NOW_NODE

#ifdef MDRS_LORA_NODE
#define USE_LORA

// LoRa Configuration
#define RADIOLIB_MODULE SX1276 //Tested on SX1276
#define LORA_SS 18
#define LORA_RST 14
#define LORA_DIO 26

#define LORA_TXPWR 17    // LoRa TX power in dBm (: +2dBm - +17dBm (for SX1276-7) +20dBm (for SX1278))
#define LORA_ACK        // Request LoRa acknowledgment.

#endif // MDRS_LORA_NODE

#endif //__FDRS_GATEWAY_CONFIG_h__
