use std::cmp::Ordering;
use std::ops::Add;
use std::ops::Div;
use std::ops::Index;
use std::ops::Sub;

pub trait BinarySearch<I, T> {
  /// Returns the index of an equal key, or the index at which the key would be inserted if one does not exist.
  fn binary_search(&self, key: &T, mut lower: I, mut upper: I) -> I;
}

// // Would use this, but std::num::One is unstable
// impl <C, I, T> BinarySearch<I, T> for C
//   where
//    C: Index<I, Output = T>,
//     I: Ord + Add<Output = I> + Sub<Output = I> + Div<Output = I> + Shr<I, Output = I> + One + Copy,
//     T: Ord {
//   fn binary_search(&self, key: &T, mut lower: I, mut upper: I) -> I {
//     let one = I::one();
//     loop {
//       if upper <= lower {
//         return lower;
//       }
//       let mid = (lower + upper).shr(one);
//       match key.cmp(&self[mid]) {
//         Ordering::Less => upper = mid,
//         Ordering::Greater => lower = mid + one,
//         Ordering::Equal => return mid,
//       }
//     }
//   }
// }

impl <C, I, T> BinarySearch<I, T> for C
  where
   C: Index<I, Output = T>,
    I: Ord + Add<Output = I> + Sub<Output = I> + Div<Output = I> + Shr<I, Output = I> + Copy,
    T: Ord {
  fn binary_search(&self, key: &T, mut lower: I, mut upper: I) -> I {
    if upper == lower {
      return lower;
    }
    let one = (upper - lower) / (upper - lower);
    loop {
      if upper <= lower {
        return lower;
      }
      let mid = (lower + upper).shr(one);
      match key.cmp(&self[mid]) {
        Ordering::Less => upper = mid,
        Ordering::Greater => lower = mid + one,
        Ordering::Equal => return mid,
      }
    }
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_binary_search() {
    let data = vec![0, 0, 1, 2, 4, 7];
    for i in 0..data.len() {
      let ix = data.binary_search(&data[i], 0, data.len());
      assert_eq!(data[ix], data[i]); // ix may not be i because of duplicates
    }
    assert_eq!(data.binary_search(&-1, 0, data.len()), 0);
    assert_eq!(data.binary_search(&3, 0, data.len()), 4);
    assert_eq!(data.binary_search(&5, 0, data.len()), 5);
    assert_eq!(data.binary_search(&8, 0, data.len()), 6);
  }
}