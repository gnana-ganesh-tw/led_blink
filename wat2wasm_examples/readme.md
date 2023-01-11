# wat2wasm example

In the file add.wat, we have a function name add, which gets 2 i32 as args and return an i32.

### Install wat2wasm
Follow the commands given in https://command-not-found.com/wat2wasm, for the respective OS to install wat2wasm

### Build wasm
To build wasm from wat we can use the wat2wasm tool.

`wat2wasm -o add.wasm add.wat`
