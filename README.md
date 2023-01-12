# Rust for web assembly projects
Using Rust to build web-assembly applications to run on embedded targets.

## Repository structure
(The folders are listed in alphabetical order)
### 1. wasm_esp32
#### 1.1 esp32-pio
This project is used to run a .wasm file on a ESP32 microcontroller. 
### 2. wasm_rust
The projects in this folder are written in Rust.
#### 2.1 add
This project contains the code to generate a wasm file which contains one function named `add`.
#### 2.2 led_blink
This project is used to generate wasm file to blink an led. The entrypoint for this function is `start`.
#### 2.3 wasm-rs
This project contains rust wasm runtime which can execute wasm files. It can be run only in Linux machines.   
### 3. wasmico_esp32
This project is used to run multiple wasm files concurrently on a ESP32 microcontroller. It also allows to remotely start, stop and perform OTA updates.
### 4. wat2wasm
This project demonstrates how to create a wasm file using the wat file. 
