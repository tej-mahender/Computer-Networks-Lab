#include <iostream>
#include <string>
using namespace std;

 string stuffing(string& data, char flag, char esc) {
	string stuffed;
	stuffed += flag;
	for (char ch : data) {
    	if (ch == flag || ch == esc)
        	stuffed += esc;
    	stuffed += ch;
	}
	stuffed += flag;
	return stuffed;
}

 string destuffing(string& data, char flag, char esc) {
 	string destuffed;
	bool escNext = false;
	for (int i=1;i<data.length()-1;i++) {
        	if(data[i]==esc&&(data[i+1]==flag||data[i+1]==esc))
            	i++;
        	destuffed.push_back(data[i]);
	}
	return destuffed;
}

int main() {
	char flag,esc;
 	string original;
 	cout<<"Enter Original: ";
 	cin>>original;
  
 	if(original.length()>20)
        cout<<"Error: Data too lengthy!"<<endl;
  else{
 	cout<<"Enter Flag: ";
 	cin>>flag;
    
 	cout<<"Enter Esc Character: ";
 	cin>>esc;
    
 	string stuffed = stuffing(original, flag, esc);
 	cout << "Stuffed Data: " << stuffed <<  endl;
    
 	string destuffed = destuffing(stuffed, flag, esc);
 	cout << "Destuffed Data: " << destuffed <<  endl;
    
 	if (destuffed == original)
    	cout << "Success: Destuffed data matches the original data!" << endl;
	else
    	cout << "Error: Destuffed data does not match the original data!" << endl;
    }
	return 0;
}
