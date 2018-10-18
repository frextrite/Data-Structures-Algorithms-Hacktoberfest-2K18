#include <iostream>
#include <cstring>
using namespace std;

void rem_word(char str[100], char word[50], int *n)
{
	int len = strlen(word);
	int flag;
	for(int i = 0; i < *n; i++)
	{
		if(!isalpha(str[i + len]))
		{
			int flag = 1;
			for(int j = 0; j < len; j++)
			{
				if(str[i + j] != word[j])
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1){
				for(int k = i; k < *n; k++)
				{
					str[k] = str[k + len];
					(*n) = (*n) - len;
				}
			}
		}
	}
}

int main(){
	char str[200];
    cout << "Enter a string: ";
    cin.get(str, 200);
    char word[50];
    cin >> word;
    int n = strlen(str);
    rem_word(str, word, &n);
    cout << str;
    return 0;
}