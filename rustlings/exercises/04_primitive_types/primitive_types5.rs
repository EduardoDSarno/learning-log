fn main() {
    let cat = ("Furry McFurson", 3.5);

    // destructing a tuple means unpacking its values into separate variables
    let(name, age) = cat;
    // TODO: Destructure the `cat` tuple in one statement so that the println works.
    // let /* your pattern here */ = cat;

    println!("{name} is {age} years old");
}
