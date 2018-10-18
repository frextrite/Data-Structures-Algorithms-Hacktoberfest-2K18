const array = [11,33,5,6,90];
const key1 = 33,key2=121;

function linearSearch(array,key){
	let i=0;
	for(i=0;i<array.length;i++)
		if(array[i]==key)
			return "Number is Present in Array";
	
	return "Number is Not Present in Array";
}


console.log(linearSearch(array,key1));
console.log(linearSearch(array,key2));
