#include<iostream> 
#include <string> 
using namespace std;
bool isPalindrome(string str){
	int low =0;
	int high =str.size()-1;
	while(low<high){
		if(str[low]!=str[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;
}
int main()
{
	string str="abba";
	string str1="abcded";
	
	cout<<str<< "is Palindrome"<<isPalindrome(str)<<endl;
	cout<<str1<<"is Palindrome"<<isPalindrome(str1)<<endl;
	return 0;

}