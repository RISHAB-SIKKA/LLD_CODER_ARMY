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


int main(){
    HttpRequest request1 = HttpRequestBuilder()
    .withUrl("https://www.google.com")
    .withMethod("GET")
    .withTimeout(10000)
    .withBody("Hello, World!")
    // .build();

    request1.execute();

    map<string,string> headers1 = {{"Content-Type", "application/json"}};
    map<string,string> queryParams1 = {{"key1", "value1"}, {"key2", "value2"}};
    
    HttpRequest request2 = HttpRequestBuilder()
    .withUrl("https://www.google.com")
    .withMethod("GET")
    .withTimeout(10000)
    .withBody("Hello, World!")
    .withHeaders(headers1)
    .withQueryParams(queryParams1)
    .build();

    request2.execute();
    
    map<string,string> headers2 = {{"Content-Type", "application/json"}};
    map<string,string> queryParams2 = {{"key1", "value1"}, {"key2", "value2"}};

    HttpRequestBuilder builder1 = HttpRequestBuilder();
    HttpRequestBuilder builder2 = builder1.withUrl("https://www.google.com");
    HttpRequestBuilder builder3 = builder2.withMethod("GET");
    HttpRequestBuilder builder4 = builder3.withTimeout(10000);
    HttpRequestBuilder builder5 = builder4.withBody("Hello, World!");
    HttpRequestBuilder builder6 = builder5.withHeaders(headers2);
    HttpRequestBuilder builder7 = builder6.withQueryParams(queryParams2);

    HttpRequest request3 = builder7.build();
    
    request3.execute(); 


// HttpRequest objects are designed to be immutable after creation.
// The class intentionally does not expose any setter methods.
// All fields are populated only through the HttpRequestBuilder,
// which is declared as a friend class. Once the request is built
// using build(), the resulting HttpRequest cannot be modified,
// ensuring immutability and thread-safety of the request object.
    return 0;
}