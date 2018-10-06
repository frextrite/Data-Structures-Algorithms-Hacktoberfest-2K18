def findIndex(values, target)
    binarySearch(values, target, 0, values.size - 1)
  end
  
  def binarySearch(values, target, start, finish)
    return -1 if start > finish
  
    middle = ((start+finish)/2).floor
    value = values[middle]
  
    puts "From #{start} to #{finish}. Middle: #{middle}"
  
    return binarySearch(values, target, start, middle-1) if value > target
    return binarySearch(values, target, middle+1, finish) if value < target
  
    puts "Result: #{middle}"
    return middle
  end
  
  findIndex([2, 4, 6, 8, 10, 12, 14, 16, 18, 20], 6)
  
  # =>
  # From 0 to 9. Middle: 4
  # From 0 to 3. Middle: 1
  # From 2 to 3. Middle: 2
  # Result: 2