const binarySearch = (arr, target) => {

    let startIndex = 0;
    let endIndex = arr.length - 1;
    let middle = 0;

    while(startIndex <= endIndex ){

        middle = Math.floor((startIndex + endIndex )/2);

        if( arr[middle] < target){
            startIndex = middle + 1;
        } else if ( arr[middle] > target){
            endIndex = middle - 1;
        } else {
            return middle
        }

    }

    return -1;

};

console.log(binarySearch([1,2,3,4,5,6],3)); //should output 2
console.log(binarySearch([1,2,3,4,5,6],10)); //should output -1