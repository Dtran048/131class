#include <iostream>
#include <vector>
#include <algorithm>   


// Add class Stack here
class Stack{
    public:
    std::vector<const char*> nstack;
    std::vector<const char*> cstack;
    std::vector<const char*> sstack;
    void validPara(const char* x){
        nstack.clear();
        std::string y = x;
        for(int i = 0; i <= y.size()-1; i++){
            if (x[i] == *"("){
                nstack.push_back("(");
            }else if (x[i] == *"{"){
                nstack.push_back("{");
            }else if (x[i] == *"["){
                nstack.push_back("[");
            }else if (x[i] == *")"){
                if(nstack.back() != "("){
                    std::cout<< "Invalid"<<std::endl;
                    return;
                }
                nstack.pop_back();
            }else if (x[i] == *"}"){
                if(nstack.back() != "{"){
                    std::cout<< "Invalid"<<std::endl;
                    return;
                }
                nstack.pop_back();
            }else if (x[i] == *"]"){
                if(nstack.back() != "["){
                    std::cout<< "Invalid"<<std::endl;
                    return;
                }
                nstack.pop_back();
            }
        }
        if(nstack.empty() == true){
            std::cout<< "Valid"<<std::endl;
            return;
        }
        std::cout<< "Invalid"<<std::endl;
    }
    void minPara(const char* x){
        std::string y = x;
        int counter = 0;
        nstack.clear();
        cstack.clear();
        sstack.clear();
        for(int i = 0; i <= y.size()-1; i++){
            if (x[i] == *"("){
                nstack.push_back("(");
            }else if (x[i] == *"{"){
                cstack.push_back("{");
            }else if (x[i] == *"["){
                sstack.push_back("[");
            }else if (x[i] == *")"){
                if(nstack.size() != 0){
                    nstack.pop_back();
                }else if(nstack.size() == 0){
                    counter +=  1;
                }  
            }else if (x[i] == *"}"){
                if(cstack.size() != 0){
                    cstack.pop_back();
                }else if(cstack.size() == 0){
                    counter +=  1;
                }  
            }else if (x[i] == *"]"){
                if(sstack.size() != 0){
                    sstack.pop_back();
                }else if(sstack.size() == 0){
                    counter +=  1;
                }  
            }
        }
        if((counter > 0) or (nstack.size() > 0) or (cstack.size() > 0) or (sstack.size() > 0)){
            std::cout<<  counter + nstack.size() + cstack.size() + sstack.size()   <<std::endl;
            return;
        }
        std::cout<< "0" <<std::endl;
    }
    void scorePara(const char* x){
        std::string y = x;
        int counter = 0;
        nstack.clear();
        cstack.clear();
        sstack.clear();
        for(int i = 0; i <= y.size()-1; i++){
            if (x[i] == *"("){
                nstack.push_back("(");
            }else if (x[i] == *"{"){
                cstack.push_back("{");
            }else if (x[i] == *"["){
                sstack.push_back("[");
            }else if (x[i] == *")"){
                if(nstack.size() != 0){
                    nstack.pop_back();
                    counter +=  1;
                }
            }else if (x[i] == *"}"){
                if(cstack.size() != 0){
                    cstack.pop_back();
                    counter +=  1;
                } 
            }else if (x[i] == *"]"){
                if(sstack.size() != 0){
                    sstack.pop_back();
                    counter +=  1;
                } 
            }
        }
            std::cout<<  counter  <<std::endl;
    }
    int indexError(const char* x){
        nstack.clear();
        std::string y = x;
        for(int i = 0; i <= y.size()-1; i++){
            if (x[i] == *"("){
                nstack.push_back("(");
            }else if (x[i] == *"{"){
                nstack.push_back("{");
            }else if (x[i] == *"["){
                nstack.push_back("[");
            }else if (x[i] == *")"){
                if(nstack.back() != "("){
                    return i;
                }
                nstack.pop_back();
            }else if (x[i] == *"}"){
                if(nstack.back() != "{"){
                    return i;
                }
                nstack.pop_back();
            }else if (x[i] == *"]"){
                if(nstack.back() != "["){
                    return i;
                }
                nstack.pop_back();
            }
        }
        if(nstack.empty() == true){
            return -1;
        }
        return (y.size()-1);
    }
};
// Add class Queue here
class Queue{
    public:
    std::vector<std::string> messque;
    int padding;
    void enqueue(const char* x){
        padding = 0;
        messque.clear();
        std::string y(x);
        std::string parts;
        padding = (8-(y.size()%8));
        y.append("0000000", (8-(y.size()%8)));
        
        for(int i = 0; i<= (y.size()/8)-1; i++){
            parts.append(y, 8*i, 8);
            reverse(parts.begin(), parts.end()); 
            messque.push_back(parts);
             parts.clear();
        }
    }
    void processMsg(){

        std::string messbuild = messque.back();
        messbuild.erase(0,padding);
        messque.pop_back();
        for(int i = 0; i = messque.size(); i++){
            messbuild = messbuild + messque.back();
            messque.pop_back();
        }
        reverse(messbuild.begin(), messbuild.end());
        std::cout<<  messbuild  <<std::endl;
    }
};
// Remove comments before testing and do not change anything in main function
int main(){
Stack s1;
s1.validPara("(([]))");
s1.minPara("(([]))");
s1.scorePara("(([]))");
s1.validPara("(([])");
std::cout<<s1.indexError("(([))")<<std::endl;
s1.minPara("(([])");
s1.validPara("(([{}))");
std::cout<<s1.indexError("(([[}])")<<std::endl;
s1.minPara("(([{}))");
s1.scorePara("(([{}))");
std::cout<<s1.indexError("({}[]()[)")<<std::endl;
s1.validPara("(([))");
s1.minPara("(([))");
std::cout<<s1.indexError("[({)]")<<std::endl;
s1.validPara("(([{[{({})}]}]))");
s1.minPara("(([{[{({})}]}]))");
s1.scorePara("(([{[{({})}]}]))");
s1.validPara("(([[{[{({})}]))");
s1.validPara("(([[{[{({})}]}])]))");
s1.scorePara("(([[{[{({})}]}])]))");
std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
s1.validPara("(())");
s1.validPara("(())");
s1.validPara("void function(){}");
s1.scorePara("void function(){}");
s1.validPara("void function(");
s1.minPara("void function(");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;

Queue q1;
q1.enqueue("This is a secure message.");
q1.processMsg();
q1.enqueue("The product I received is damaged. What should I do?");
q1.processMsg();
q1.enqueue("I need assistance with setting up my new device");
q1.processMsg();
q1.enqueue("The website is not loading properly on my browser.");
q1.processMsg();
q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
q1.processMsg();
q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
q1.processMsg();
q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
q1.processMsg();
q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
q1.processMsg();
return 0;
}