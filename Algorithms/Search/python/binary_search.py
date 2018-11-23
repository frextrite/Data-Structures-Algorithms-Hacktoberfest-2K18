def Binary_Search(Arr, find):
    """
    type Arr: list[int]
    type find: int
    """
    
    left = 0
    right = len(Arr)-1
    
    while(left <= right):
        mid = (left + right)//2
        
        if( Arr[mid] == find):
            return mid
        elif(Arr[mid] < find):
            left = mid + 1
        else:
            right = mid - 1
    
    return -1
    
if __name__ == "__main__":
    Arr = [0,8,31,46,79,93,950]
    find = 950
    loc = Binary_Search(Arr, find)
    if(loc == -1):
        print("Value not found in Array")
    else:
        print("Value found at index", loc)
