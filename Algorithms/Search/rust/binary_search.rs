fn binary_search<T: Ord + std::fmt::Debug>(v: &[T], i: T) -> Result<usize, usize> {
    let mut first = 0;
    let mut last = v.len();

    while first < last {
        let pivot = (first+last)/2;
        if i == v[pivot] {
            return Ok(pivot)
        } else if i < v[pivot] {
            last = pivot - 1;
        } else {
            first = pivot + 1;
        }
        
    }
    Err((first+last)/2 + 1)
}
extern crate test;

#[cfg(test)]
mod tests {
 
    use super::*;
    use test::Bencher;

    #[bench]
    fn binary(b: &mut Bencher) {
        let v = (0..100000).filter(|&i| i % 5 != 0).collect::<Vec<usize>>();
        b.iter(|| assert_eq!(binary_search(&v, 8000), Err(6400)));
    }
}
