#include "_def.h"

void setup() { InitBluetooth(); }

void loop() {
    if (Bluetooth.available()) {
        mess = Bluetooth.read();
    }
}

void InitBluetooth(void) { Bluetooth.begin(9600); }