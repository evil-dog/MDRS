#ifndef __MDRS_NODE_h__
#define __MDRS_NODE_h__

// Node required functions
void setup_sensor();
void setup_FDRS();
void loopSensor();

void myLoadFDRS(float d, uint8_t t);
void myLoadFDRS(float d, uint8_t t, uint16_t id);
uint32_t myPingFDRS(uint32_t timeout);
bool myAddFDRS(void (*new_cb_ptr)(DataReading));
bool myAddFDRS(int timeout, void (*new_cb_ptr)(DataReading));
bool mySubscribeFDRS(uint16_t sub_id);
#endif // __MDRS_NODE_h__