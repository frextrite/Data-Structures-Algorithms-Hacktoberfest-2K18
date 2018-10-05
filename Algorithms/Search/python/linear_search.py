def search(num_list, value):
    for element in num_list:
        if(element == value):
            return num_list.index(element)
    
    return -1

if __name__ == "__main__":
    num_list = [1,2,3,4,5,6,7,8,9]
    value = 4

    found = search(num_list, value)

    if found != -1:
        print(f"Element {value} found at index {found}")
    else:
        print(f"Element {value} doesn't exist in the list")
