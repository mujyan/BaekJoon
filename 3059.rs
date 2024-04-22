use std::io;
fn main() {
    let mut buffer: String = "".to_string();
    io::stdin().read_line(&mut buffer).unwrap();
    let n: i64 = buffer.trim().parse::<i64>().unwrap();
    for _i in 0..n {
        let mut ans: i64 = 0;
        buffer.clear();
        io::stdin().read_line(&mut buffer).unwrap();
        buffer = buffer.to_string();
        for j in 'A' as i64 ..'Z' as i64 + 1 {
            for (_size, c) in buffer.chars().enumerate() {
                if char::from(j as u8) == c {
                    ans = ans - c as i64;
                    break;
                }
            }
            ans = ans + j;
        }
        println!("{}", ans);
    }
}