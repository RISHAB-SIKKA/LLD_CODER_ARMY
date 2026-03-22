#include<iostream>
#include<string>
#include<vector>

using namespace std;

class HttpRequest{
    private:
    const string url; //required
    const string method; //required
    const map<string,string> headers;  //optional
    const map<string,string> queryParams;
    const string body;  //optional
    const int timeout;  //required
    
    public:

    HttpRequest() { }

    friend class HttpRequestBuilder;

     //execute the request
     void execute(){
        cout << "Executing HTTP request to " << url << " with method " << method << " and timeout " << timeout << endl;

        if(!queryParams.empty()){
            cout<<"query params: " << endl;

            for(const auto & param: queryParams){
                cout << " " << param.first << " " << param.second << endl;
            }
        } 

        if(!headers.empty()){
            cout<<"headers: "<< endl;

            for(const auto& header: headers){
                cout<<" " << header.first << " " << header.second << endl;
            }
        }

        if(!body.empty()){
            cout<<"body: " << body << endl;
        }


        cout<<"request sent successfully" << endl;

    } 
};

// foward declaration
class methodStep;
class headerStep;
class optionalStep;

//Step Interface

class urlStep{
    public:
    virtual methodStep& withUrl(const string& url) = 0;
};

class methodStep{
    public:
    virtual headerStep& withMethod(string Method) = 0;
};

class headerStep& with