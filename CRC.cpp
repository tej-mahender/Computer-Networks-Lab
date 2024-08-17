#include <iostream>
#include <cstring>
using namespace std;

void performXOR(string& temp, string& divisor, int divisorLength) {
	for (int j = 1; j < divisorLength; j++)
    	temp[j] = (temp[j] == divisor[j]) ? '0' : '1';
}

void calculateCRC(string& data, string& temp, string& divisor, int dataLength, int divisorLength) {
	for (int i = 0; i < divisorLength; i++) 
    	temp[i] = data[i];
    
	int i = divisorLength;
	do {
    	if (temp[0] == '1')
        	performXOR(temp, divisor, divisorLength);
        
    	for (int j = 0; j < divisorLength - 1; j++) 
        	temp[j] = temp[j + 1];
    	
    	temp[divisorLength - 1] = data[i++];
	} while (i <= dataLength + divisorLength - 1);
}

void checkReceiver(string& data, string& divisor, int dataLength, int divisorLength) {
  string temp;
	cout << "Enter the received data: ";
	cin >> temp;
  
	calculateCRC(temp, temp, divisor, dataLength, divisorLength);
	bool errorDetected = false;
  
	for (int i = 0; i < divisorLength - 1; i++) {
    	if (temp[i] != '0') {
        	errorDetected = true;
        	break;
    	}
	}
  
	if (errorDetected)
    	cout << "Error: Sent data doesn't match with received data"<<endl;
 	else
    	cout << "Success: Sent data match with received data"<<endl;
}

int main() {
	string data,temp,divisor;
	cout << "Enter data to be transmitted: ";
	cin >> data;
  
	cout << "Enter the Divisor: ";
	cin >> divisor;
  
	int dataLength = data.length();
	int divisorLength = divisor.length();
  
	for (int i = dataLength; i < dataLength + divisorLength - 1; i++) 
    	data += '0';
	
	cout << "Data padded with n-1 zeros: " << data<<endl;
	calculateCRC(data, temp, divisor, dataLength, divisorLength);
	cout << "CRC or Check value is: ";
	for (int i = 0; i < divisorLength - 1; i++) 
    	cout << temp[i];
	cout<<endl;

	for (int i = dataLength, j = 0; i < dataLength + divisorLength - 1; i++, j++) 
    	data[i] = temp[j];
	
	cout << "Final data to be sent: " << data << endl;
	checkReceiver(data, divisor, dataLength, divisorLength);
	return 0;
}
