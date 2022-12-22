#![no_std]

#[no_mangle]
pub fn add(left: i32, right: i32) -> i64 {
    left as i64 + right as i64
}

#[panic_handler]
fn handle_panic(_: &core::panic::PanicInfo) -> ! {
    unreachable!()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
