#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<map>
using namespace std;

class HttpRequest{
    private:
    string url; //required
    string method; //required
    map<string,string> headers;  //optional
    map<string,string> queryParams;
    string body;  //optional
    int timeout;  //required

    public:

    // Constructor with only one arg for url
    HttpRequest(const string& url){
        this->url = url;
        this->method = "GET";
        this->timeout = 10000;
    }

    // Constructor with 2 args for url and method
    HttpRequest(const string& url, const string& method){
        this->url = url;
        this->method = method;
        this->timeout = 10000;
    }

    // Constructor with 3 args for url, method and timeout
    HttpRequest(const string& url, const string& method, int timeout){
        this->url = url;
        this->method = method;
        this->timeout = timeout;
    }

    // Constructor with 4 args for url, method, timeout and body
    HttpRequest(const string& url, const string& method, int timeout, const string& body){
        this->url = url;
        this->method = method;
        this->timeout = timeout;
        this->body = body;
    }

    // Constructor with 5 args for url, method, timeout, body and headers
    HttpRequest(const string& url, const string& method, int timeout, const string& body, const map<string,string>& headers){
        this->url = url;
        this->method = method;
        this->timeout = timeout;
        this->body = body;
        this->headers = headers;
    }

    // Constructor with 6 args for url, method, timeout, body, headers and queryParams
    HttpRequest(const string& url, const string& method, int timeout, const string& body, const map<string,string>& headers, const map<string,string>& queryParams){
        this->url = url;
        this->method = method;
        this->timeout = timeout;
        this->body = body;
        this->headers = headers;
        this->queryParams = queryParams;
    }

    // setters leads to mutable objects

    void setUrl(const string& url){
        this->url = url;
    }

    void setMethod(const string& method){
        this->method = method;
    }

    void setTimeout(int timeout){
        this->timeout = timeout;
    }

    void setBody(const string& body){
        this->body = body;
    }

    void setHeaders(const map<string,string>& headers){
        this->headers = headers;
    }
    
    void setQueryParams(const map<string,string>& queryParams){
        this->queryParams = queryParams;
    }

    void send(){
        cout << "Sending HTTP request to " << url << " with method " << method << " and timeout " << timeout << endl;
    }

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

int main(){
    // using telescopi problem (Not recommended) (method overloading)
    HttpRequest * r1 = new HttpRequest("https://www.google.com");
    r1->execute();

    HttpRequest * r2 = new HttpRequest("https://www.google.com", "POST");
    r2->execute();

    HttpRequest * r3 = new HttpRequest("https://www.google.com", "POST", 10000);
    r3->execute();

    // using mutable problem 
    HttpRequest * r4 = new HttpRequest("https://www.google.com");
    r4->setMethod("POST");
    r4->setTimeout(10000);
    r4->setBody("Hello, World!");
    map<string,string> headers4 = {{"Content-Type", "application/json"}};
    r4->setHeaders(headers4);
    map<string,string> queryParams4 = {{"key1", "value1"}, {"key2", "value2"}};
    r4->setQueryParams(queryParams4);

    // the problem what if we forgot to set the query params or headers or body or timeout or method or url?
    r4->execute();

    HttpRequest * r5 = new HttpRequest("https://www.google.com");
    r5->setMethod("POST");
    r5->setBody("Hello, World!");
    map<string,string> headers5 = {{"Content-Type", "application/json"}};
    r5->setHeaders(headers5);
    
    // the problem what if we forgot to set the query params or headers or body or timeout or method or url?
    r5->execute();
    
    r5->setTimeout(10000);
    map<string,string> queryParams5 = {{"key1", "value1"}, {"key2", "value2"}};
    r5->setQueryParams(queryParams5);

    
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    // delete r6;  
    
    
}