/*
Name: Maleek Hussain Ali
Roll Number: 22i-1526
Section: B
*/
#include<iostream>
using namespace std;
//Recursive function
int find_Length(string s, int counter) //counter will start from zero initially
{

	if (s[counter] == '\0') { //base condition
		return counter;
	}
	else {
		return find_Length(s, counter + 1);
	}

}

bool compareString(string main, string str, int i) {  //helping function that compares str with particular main string character
    static int j;
    bool status = true;
    int strLength = find_Length(str, 0);

    if (j < strLength) {
        if (main[i + j] != str[j]) {
            j = 0;
            return false;
        }
        j++;
        return (status && compareString(main, str, i));
    }
    else {
        return true;
    }
}


struct String_Manipulation {
	int Calculate_length(string s)
	{
		int length;
		length = find_Length(s, 0);
		return length;
	}


	bool substring(string main, string str) {
		static int i;
		bool status = false;
		int mainLength = find_Length(main, 0);

		if (i < mainLength) 
		{
			if (main[i] == str[0]) {
				status = compareString(main, str, i);
				if (status) {
					return true;
				}
			}
			i++;
			return (false || substring(main, str));
		}
		else {
			return false;
		}
	}
	int substring_position(string main, string str)
	{
		int index = -1;
		static int i;
		bool status = false;
		int mainLength = find_Length(main, 0);

		if (i < mainLength) 
		{
			if (main[i] == str[0]) {
				status = compareString(main, str, i);
				if (status) {
					index = i;
					return index;
				}
			}
			i++;
			return substring_position(main, str);
		}
		else {
			index = - 1;
			return index;
		}
	}
};
int main()
{
	String_Manipulation s;
	cout << endl << s.Calculate_length("string");
	cout << endl << s.substring("I love to have coffee in the morning", "  ");
	cout << endl << s.substring_position("Ilove to have coffee in the morning", " ");
	return 0;
}
