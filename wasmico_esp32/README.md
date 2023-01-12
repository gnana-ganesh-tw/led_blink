# Blink LEDs on ESP32 using wasm files

### Pre-requisites

- ESP32
- PlatformIO extension in VS Code

#### Open Project

Open the folder `wasmico_esp32` in VS Code

#### Add Wifi Credentials

In the file, `plaformio.ini` add the wifi credentials, by replacing the placeholder with the correct values.

```
build_flags = 
    -D WIFI_SSID='"<wifi>"'
    -D WIFI_PASS='"<password>"'
```

#### Connect to ESP32

Connect ESP32 to your machine.

#### Build the project

In the terminal, run

```
platformio run --environment esp32dev 
```

#### Upload and Monitor

In the terminal, run

```
platformio run --target upload --target monitor --environment esp32dev
```


