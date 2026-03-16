#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<map>
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

// Builder class as a nested class of HttpRequest class

class HttpRequestBuilder{
    private:
    HttpRequest req;

    public:
    HttpRequestBuilder& withUrl(const string &u){
        req.url = u;
        return *this;
    }

    HttpRequestBuilder& withMethod(const string &m){
        req.method = m;
        return *this;
    }

    HttpRequestBuilder& withTimeout(int t){
        req.timeout = t;
        return *this;
    }
    
    HttpRequestBuilder& withBody(const string &b){
        req.body = b;
        return *this;
    }

    HttpRequestBuilder& withHeaders(const map<string,string> &h){
        req.headers = h;
        return *this;
    }
    
    HttpRequestBuilder& withQueryParams(const map<string,string> &q){
        req.queryParams = q;
        return *this;
    }

     // terminating method
    HttpRequest build(){

        if(req.url.empty()){
            throw runtime_error("URL is required");
        }
        if(req.method.empty()){
            throw runtime_error("Method is required");
        }
        if(req.timeout <= 0){
            throw runtime_error("Timeout is required");
        }

        return req;
    }
};

class HttpRequestDirector{
    

    public:
    static httpRequest buildGetRequest(const string &url, int timeout){
        return HttpRequestBuilder()
        .withUrl(url)
        .withMethod("GET")
        .withTimeout(timeout)
        .build();
    }

    static httpRequest buildPostRequest(const string &url, const string &body, int timeout){
        return HttpRequestBuilder()
        .withUrl(url)
        .withMethod("POST")
        .withTimeout(timeout)
        .withBody(body)
        .build();
    }
};  

int main(){
    //Normal Request
    httpRequest request1 = HttpRequestBuilder()
    .withUrl("https://www.google.com")
    .withMethod("GET")
    .withTimeout(10000)
    .build();

    request1.execute();

    //Director Request
    httpRequest request2 = HttpRequestDirector::buildGetRequest("https://www.google.com", 10000);
    request2.execute();

    httpRequest request3 = HttpRequestDirector::buildPostRequest("https://www.google.com", "Hello, World!", 10000);
    request3.execute();

    return 0;
}