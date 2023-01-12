# wat2wasm example

In the file add.wat, we have a function name add, which gets 2 i32 as args and return an i32.

### Install wat2wasm
Follow the commands given in https://command-not-found.com/wat2wasm, for the respective OS to install wat2wasm

### Install wasm3
Follow the commands given in https://github.com/wasm3/wasm3/blob/main/docs/Installation.md, for installation of was3

### Build wasm
To build wasm from wat we can use the wat2wasm tool.

`wat2wasm -o add.wasm add.wat`

### Run Wasm
To run wasm from wat we can use the wat2wasm tool.

`wasm3 --func add add.wasm 1 2`