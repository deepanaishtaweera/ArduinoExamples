// Now wer are in develop branch
#include <NeoSWSerial.h>
NeoSWSerial Bluetooth(1, 0);

void setup() {
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    Bluetooth.begin(9600);
    Bluetooth.println("Hello from Arduino");
}
char a[10];
void loop() {
    if (Bluetooth.available()) {
        int index = 0;
        while (Bluetooth.available() > 0) {
            if (index < 10)  // One less than the size of the array
            {
                a[index] = (Bluetooth.read());
                index++;          // Increment where to write next
                a[index] = '\0';  // Null terminate the string
            }
        }
        if (a[0] == '1') {
            Bluetooth.println("print 1");
            delay(4000);
        }
        if (a[0] == '2') {
            Bluetooth.println("print 2");
            delay(4000);
        } else {
            for (int i = 0; i < 10; i++) {
                Bluetooth.print(a[i]);
            }
            Bluetooth.println("");
            delay(4000);
        }
    }
}
