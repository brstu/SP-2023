#include <iostream>
#include <string>
#include "Response.h"

using namespace std;

int main()
{
    system("color f0");
    Response response;
    string request;
    string requestType="";
    while (request != "end") {
        getline(cin, request, '\n');
        for (int i = 0; i < request.size() && request[i] != ' '; i++) {
            requestType += request[i];
        }
        if (requestType == "SELECT") {
            response.selectData(request);
        }
        else if (requestType == "INSERT") {
            response.insertData(request);
        }
        else if (requestType == "DELETE") {
            response.deleteData(request);
        }
        else if (requestType == "UPDATE") {
            response.updateData(request);
        }
        else if (requestType == "end") {
            return 0;
        }
        else {
            cout << "Wrong request!" << endl;
        }
        request.clear();
        requestType.clear();
    }
    
    
}