#include<bits/stdc++.h>
#define ll long long
using namespace std;

int strlen(char str[]){
	int len = 0;
	while(str[len] != '\0')	len++;
	return len;
}

char* strcat(char a[], char b[]){
	int n = strlen(a);
	int m = strlen(b);

	char *temp = new char[n+m+1];
	for(int i=0;i<n;i++)	temp[i] = a[i];
	for(int i=0;i<m;i++)	temp[n+i] = b[i];
	temp[n+m] = '\0';
	return temp;
}

char* strcpy(char c[], char d[]){
	char *temp = c;
	int n = strlen(d);
	for(int i=0;i<n;i++)	temp[i] = d[i];
	return c;
}

int strcmp(char e[], char f[]){
	int n = strlen(e);
	int m = strlen(f);

	int len = min(n,m);
	for(int i=0;i<len;i++){
		if(e[i] > f[i])	return 1;
		if(e[i] < f[i])	return -1;
	}
	if(n > m)	return 1;
	if(n < m)	return -1;
	return 0;
}

int main(){

  //Length of string without predefine function
	char str[] = "Hello There!!";
	int n = strlen(str);
	cout<<"Length of string is: "<<n<<endl;

	//Concatinate two string
	char a[] = "Hello ";
	char b[] = "There!!";
	char *copy = strcat(a,b);
	cout<<copy<<endl;

	//Copy one string to another
	char c[] = "Hello ";
	char d[] = "There!!";
	strcpy(c,d);		// copy d in c
	cout<<c<<endl;

	//Compare two string
	char e[] = "Hello ";
	char f[] = "There!!";
	int val = strcmp(e,f);
	if(val == 0)	cout<<"Both equal"<<endl;
	else if(val < 0)	cout<<"First String is smaller"<<endl;
	else cout<<"First is Greater"<<endl;

	
	return 0;
}
