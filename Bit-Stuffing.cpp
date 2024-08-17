#include <iostream>
#include <string>
using namespace std;

string stuffing(string& data) {
	string stuffed;
	int count = 0;
	for (char bit : data) {
    	stuffed.push_back(bit);
    	if (bit == '1') {
        	count++;
        	if (count == 5) {
            	stuffed.push_back('0');
            	count = 0;
        	}
    	} else
        	count = 0;
	}
	return stuffed;
}

string destuffing(string& data) {
	string destuffed;
	int count = 0;
	for (int i = 0; i < data.size(); i++) {
    	if (data[i] == '1') {
        	count++;
        	destuffed.push_back(data[i]);
        	if (count == 5 && i + 1 < data.size() && data[i + 1] == '0') {
            	i++;
            	count = 0;
        	}
    	} else {
        	destuffed.push_back(data[i]);
        	count = 0;
    	}
	}
	return destuffed;
}

bool check(string &s){
    for(auto i:s){
        if(i!='0'&&i!='1')
            return false;
    }
    return true;
}

int main() {
	string original;
	cout << "Enter the original data: ";
	cin >> original;
	if(original.length()>20)
        cout<<"Error: Data too lengthy!"<<endl;
    else if(!check(original))
        cout<<"Error: Data should contain only 0,1!"<<endl;
    else{
	string flag = "01111110";

	string stuffedData = flag + stuffing(original) + flag;
	cout << "Data after stuffing: " << stuffedData << endl;

	string dataWithoutFlag = stuffedData.substr(flag.length(), stuffedData.length() - 2 * flag.length());
	string destuffedData = destuffing(dataWithoutFlag);

	cout << "Data after destuffing: " << destuffedData << endl;
	if (destuffedData == original)
    	cout << "Success: Destuffed data matches the original data!" << endl;
 	else
    	cout << "Error: Destuffed data does not match the original data!" << endl;
    }
	return 0;
}
