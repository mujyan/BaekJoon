use std::io;
fn main() {
    let mut buffer: String = "".to_string();
    io::stdin().read_line(&mut buffer).unwrap();
    let mut splited = buffer.split_ascii_whitespace().flat_map(str::parse::<i32>);
    let num1: i32 = splited.next().unwrap();
    let num2: i32 = splited.next().unwrap();
    let num3: i32 = splited.next().unwrap();
    if num1 + num2 == num3 {
        println!("{}+{}={}", num1, num2, num3);
    }
    else if num1 == num2 + num3 {
        println!("{}={}+{}", num1, num2, num3);
    }
    else if num1 - num2 == num3 {
        println!("{}-{}={}", num1, num2, num3);
    }
    else if num1 == num2 - num3 {
        println!("{}={}-{}", num1, num2, num3);
    }
    else if num1 * num2 == num3 {
        println!("{}*{}={}", num1, num2, num3);
    }
    else if num1 == num2 * num3 {
        println!("{}={}*{}", num1, num2, num3);
    }
    else if num1 / num2 == num3 {
        println!("{}+{}={}", num1, num2, num3);
    }
    else if num1 == num2 / num3 {
        println!("{}={}/{}", num1, num2, num3);
    }
}