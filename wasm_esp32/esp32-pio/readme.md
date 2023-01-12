# Wasm on ESP32

Wasm3 library is used to run the wasm file on a ESP32 microcontroller. in this project we use `add.wasm` generated from the wat2wasm. `add.wasm` is converted to `add.wasm.h` using xxd. The `add.wasm.h` header file contains the bytecode of `add.wasm` as byte array.

### Pre-requisites

- PlatformIO's extension in VS Code
- ESP32

### Setup

#### Open project

Open the folder `esp32-pio` in VS code

#### Connect to ESP32

connect the ESP32 to your device

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

