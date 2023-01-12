# Rust wasm 

### Pre-requisites

- Rust installed in the machine
- `wasm32-wasi` target added in rust toolchain

#### Install Rust

Follow the instructions in this page, https://www.rust-lang.org/tools/install, to install rust on your machine.

#### Add target

To build the wasm target, `wasm32-wasi` must be added to the rust toolchain. In your terminal, execute the following
command.

```
rustup target add wasm32-wasi
```

#### Build

```
cargo b --release
```
Using `--release` flag optimizes the size of the wasm file. 