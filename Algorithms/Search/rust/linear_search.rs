fn linear_search(v: &Vec<i32>, x: i32) {
    let mut found: bool = false;
    let mut index: usize = 0;

    for i in 0..v.len() {
        if v[i] == x {
            found = true;
            index = i;
            break;
        }
    }
    if found {
        println!("Element {} found at index {}", x, index);
    } else {
        println!("Element {} doesn't exist", x);
    }
}

fn main() {
    let array: Vec<i32> = vec![0,1,2,3,4,5,6,7,8,9];
    let to_check_one: i32 = 8;
    let to_check_two: i32 = 10;
    linear_search(&array, to_check_one);
    linear_search(&array, to_check_two);
}