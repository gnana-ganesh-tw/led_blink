#![no_main]
#![no_std]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    loop {}
}

extern "C" {
    #[link_name = "pinMode"]
    fn pin_mode(pin: i32, mode: i32);

    #[link_name = "digitalWrite"]
    fn digital_write(pin: i32, state: i32);

    fn delay(millis: i32);
}

#[no_mangle]
unsafe fn start() {
    _setup();
    loop {
        _loop();
    }
}

const GPIO_21: i32 = 0x15;
const OUTPUT: i32 = 0x01;
const LOW: i32 = 0x00;
const HIGH: i32 = 0x01;

unsafe fn _setup() {
    pin_mode(GPIO_21, OUTPUT);
}

unsafe fn _loop() {
    digital_write(GPIO_21, LOW);
    delay(1000);
    digital_write(GPIO_21, HIGH);
    delay(1000);
}