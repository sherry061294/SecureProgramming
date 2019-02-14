#include <iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <unistd.h>
#include <ctime>

string sha(const string str)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA_CTX sha;
    SHA_Init(&sha);
    SHA_Update(&sha, str.c_str(), str.size());
    SHA_Final(hash, &sha);
    stringstream ss;
    for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}




int main()
{
    string pwd;
    char s[100];
    cout << "Enter a password ";
    getline (cin,pwd);
    /*Code for time taken from https://stackoverflow.com/questions/16357999/current-date-and-time-as-string"*/
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);
    /*End of borrowed code*/
    /*Code to read from Config file*/
    pwd = sha(pwd);
    ofstream logger;
    logger.open("secretID.log",std::ios_base::app);
    string user = getenv("USER");
    logger<<"File was opened by "<<user <<" | Using password "<<pwd <<" | at " <<str;

    ifstream storedpwd("secretID.cfg");
    string line;
    getline(storedpwd, line);
    while(!line.empty())
	{
         /*code to compare entered password with config file*/
	 if(line.compare(pwd) == 0)
	    {
		/*Code to Log*/
		logger<<" | Success \n";
	        /**Code if a Match is found**/
                ifstream secret("secretID.txt");
                if (secret.is_open())
                   std::cout << secret.rdbuf();
		secret.close();
		return 0;
	    }
	else

		getline(storedpwd, line);
	}
    cout<<"Try Again"<<endl;
    logger<<" | Failure \n";
    return 0;



}
