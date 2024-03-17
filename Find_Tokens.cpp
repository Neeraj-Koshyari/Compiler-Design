// Program to find tokens as keyword, number, real number, operator, identifier.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isDelimiter(char ch){
	unordered_set<char> st{' ','+','-','*','/',';','>','<','=','(',')','{','}','[',']'};
	return st.count(ch);
}

bool isOperator(char ch){
	unordered_set<char> st{'+','-','*','/','>','<','='};
	return st.count(ch);
}

bool isNumber(string& s){
	int n = s.length();
	
	if(n==0)	return false;
	
	for(int i=0;i<n;i++){
		if((s[i]!='0' && s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4' && s[i]!='5' && s[i]!='6' && s[i]!='7' && s[i]!='8' && s[i]!='9') || (s[i]=='-' && i>0))
			return false;
	}
	return true;
}

bool isRealNumber(string& s){
	int n = s.length(), hasDecimal = false;
	
	if(n==0)	return false;
	
	for(int i=0;i<n;i++){
		if((s[i]!='0' && s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4' && s[i]!='5' && s[i]!='6' && s[i]!='7' && s[i]!='8' && s[i]!='9' && s[i]!='.') || (s[i]=='-' && i>0))
			return false;
		if(s[i]=='.')	hasDecimal = true;
	}
	return hasDecimal;
}

bool isKeyword(string &str){
	unordered_set<string> st{"int","float","char","long","double","signed","unsigned","static","const","auto","break","continue","default","if","else","for","while","do","goto","switch","case","struct","enum","register","typedef","extern","return","union","short","void","sizeof","volatile"};
	return st.count(str);
}

bool isValidIdentifier(string& s){
	if(s[0]=='0' || s[0]=='1' || s[0]=='2' || s[0]=='3' || s[0]=='4' || s[0]=='5' || s[0]=='6' || s[0]=='7' || s[0]=='8' || s[0]=='9' || isDelimiter(s[0]))
		return false;
	return true;
}

void checkTokens(string &s){
	int l = 0, r = 0, n = s.length();
	
	while(r <= n){
		if(isDelimiter(s[r]) == false)	r++;
		
		if(isDelimiter(s[r]) && l==r){
			if(isOperator(s[r]))
				cout<<s[r]<<" is Operator"<<endl;

			r++;
			l = r;
		}
		else if((isDelimiter(s[r]) && l!=r) || (r==n && l!=r)){
			string str = s.substr(l,r-l);
			
			if(isKeyword(str))	cout<<str<<" is Keyword"<<endl;
			else if(isNumber(str))	cout<<str<<" is Integer"<<endl;
			else if(isRealNumber(str))	cout<<str<<" is Real Number"<<endl;
			else if(isValidIdentifier(str) && isDelimiter(str[r-1])==false)
				cout<<str<<" is valid Identifier"<<endl;
			else if(isValidIdentifier(str)==false && isDelimiter(str[r-1])==false)
				cout<<str<<" is not a Valid Identifier"<<endl;
				
			l = r;
		}
	}
}

int main(){
	
	string s;
	getline(cin,s);    //input whitespaces also

	checkTokens(s);
	
	return 0;
}
