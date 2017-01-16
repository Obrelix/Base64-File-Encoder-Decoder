# Base64-File-Encryption

A program written in C++ that encrypts/decrypt files with the base64 encription and more complex

# QA

# How the program works?

When the program started it request from the user to choose between 5 possible functions:
1)File encryption with basic base64 encryption
2)File decryption with basic base64 encryption
3)File encryption with complex base64 encryption
4)File decryption with complex base64 encryption
5)exit the program

When the user choose something exept the chose exit the program request the filename of the file that the user want to encrypt/decrypt it can be something like c:\filename.log .
When the user type the file name the program execute the encryption/decryption to the file and it goes to the start page again.

# What is complex base64?

An example:

Encryption:

string Salt1 = "1jsFA245GAWio"
string Salt2 = "4ugh9uKCA973CAQ"
string Salt3 = "7falwbouQWGQWEWva2341"
string Salt4 = "dfaFG24fWFCA2"

string Data = "Hello this is the data :D";
//encrypt data with base64
base64(data);

//instert to base64 string in the 7th index possition the salt1
data.insert(7, Salt1)
//encrypt data with base64
base64(data);

//make a new strige with the salt and data
data = Salt1 + Salt4 + Salt3 + Salt2 + data ;
//encrypt data with base64
base64(data);

//change the base64 string again
data.insert(80, Salt1+Salt4);
data.insert(23, Salt2+Salt3);
base64(data;

//make a new strige with the salt and data
data = Salt1 + Salt3 + Salt4 + Salt2 + data  ;
//encrypt data with base64
base64(data);

Decryption:

base64decrypt(data);
data.erase(0, Salt1.lenght() + Salt3.lenght() + Salt4.lenght() + Salt2.lenght());
base64decrypt(data);
data.erase(23, Salt2.lenght() + Salt3.lenght());
data.erase(23, Salt1.lenght() + Salt4.lenght());
base64decrypt(data);
data.erase(0, Salt1.lenght() + Salt3.lenght() + Salt4.lenght() + Salt2.lenght());
base64decrypt(data);
data.erase(7, Salt1.lenght());
base64decrypt(data);
