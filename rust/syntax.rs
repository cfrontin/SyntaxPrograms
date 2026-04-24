// Rust syntax program: a compact, runnable language refresher.

use std::collections::{HashMap, HashSet}; // Common collection types.

// This function truncates a floating-point value to an integer.
fn truncate_float(x: f64) -> i32 {
    x as i32
}

// This struct demonstrates encapsulated data with methods.
struct AClass {
    x: i32,
    z: f64,
}

impl AClass {
    // Constructor initializes member fields.
    fn new() -> Self {
        Self { x: 0, z: 0.0 }
    }

    // Method updates one field.
    fn set_x(&mut self, x_in: i32) {
        self.x = x_in;
    }

    // Method computes z = c*x.
    fn set_z_as_product(&mut self, c: f64) {
        self.z = c * self.x as f64;
    }

    // Method reads value without mutation.
    fn get_z(&self) -> f64 {
        self.z
    }
}

fn main() {
    // This prints text output to terminal.
    println!("Hello, Rust syntax program!\n");

    // FUNDAMENTAL TYPES
    let boolean_value: bool = false; // bool stores true/false.
    let integer_value: i32 = 2; // i32 stores 32-bit signed integers.
    let float_value: f64 = 0.25; // f64 stores 64-bit floating-point numbers.
    let char_value: char = 'a'; // char stores a Unicode scalar value.
    let text_value: &str = "hello"; // &str is a string slice.

    println!(
        "bool={}, int={}, float={}, char={}, text={}\n",
        boolean_value, integer_value, float_value, char_value, text_value
    );

    // COLLECTIONS
    let mut vector_value = vec![1, 2, 3]; // Vec is a growable array.
    vector_value.push(4); // Append one value.

    let array_value = [10, 20, 30]; // Array has fixed length.

    let mut set_value = HashSet::new(); // HashSet stores unique values.
    set_value.insert(1);
    set_value.insert(1);
    set_value.insert(2);

    let mut map_value = HashMap::new(); // HashMap stores key/value pairs.
    map_value.insert("alice", 10);
    map_value.insert("bob", 7);

    println!(
        "vec={:?}, array={:?}, set={:?}, map={:?}\n",
        vector_value, array_value, set_value, map_value
    );

    // CONTROL FLOW
    let should_do = true;
    let otherwise_todo = true;
    if !should_do {
        println!("First branch");
    } else if otherwise_todo {
        println!("Else-if branch");
    } else {
        println!("Final else branch");
    }

    print!("for loop: ");
    for value in &vector_value {
        print!("{} ", value);
    }
    println!();

    let mut counter = 2;
    print!("while loop: ");
    while counter < 100 {
        counter *= 2;
        print!("{} ", counter);
    }
    println!("\n");

    let switch_value = 2;
    match switch_value {
        1 => println!("match: one"),
        2 => println!("match: two"),
        _ => println!("match: other"),
    }
    println!();

    // CLOSURES (LAMBDA-LIKE FUNCTIONS)
    let square = |x: i32| x * x; // Closure captures or transforms inputs.
    println!(
        "truncate_float(3.14)={}, square(3)={}\n",
        truncate_float(3.14),
        square(3)
    );

    // OWNERSHIP AND BORROWING
    let owned_string = String::from("hello"); // String owns heap-allocated text.
    let borrowed_len = owned_string.len(); // Borrowing by shared reference is implicit.
    println!("owned_string='{}', len={}\n", owned_string, borrowed_len);

    // STRUCTS AND METHODS
    let mut obj = AClass::new();
    obj.set_x(4);
    obj.set_z_as_product(5.2);
    println!("AClass z={}\n", obj.get_z());

    // RESULT AND ERROR HANDLING
    let parse_result: Result<i32, _> = "42".parse(); // parse can fail, so it returns Result.
    match parse_result {
        Ok(value) => println!("Parsed value={}", value),
        Err(err) => println!("Parse error={}", err),
    }
}
