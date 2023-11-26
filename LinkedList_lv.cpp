#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
template <typename T> class Tab{
    public:
        std::string url;
        std::string name;
        T memory;
        std::shared_ptr<Tab<T>>next;
        std::shared_ptr<Tab<T>>prev;
    };

// Write template class Browser here
    template <typename T> class Browser{
        public:
        std::shared_ptr<Tab<T>> head;
        std::shared_ptr<Tab<T>> tail;
        std::shared_ptr<Tab<T>> cursor;
        std::vector<std::pair<std::string, std::string>> bm;
        std::shared_ptr<Tab<T>> tobedelete;
        void addNewTab(std::string a, std::string b, double c){
            auto new_tab = std::make_shared<Tab<T>>();
            new_tab->url = a;
            new_tab->name = b;
            new_tab-> memory = c;
            new_tab->next = NULL;
                if(head == NULL){
                    new_tab->prev = NULL;
                    head = new_tab;
                }
                else{
                    tail->next = new_tab;
                    new_tab->prev = tail;                 
                }
                tail = new_tab;
                cursor = new_tab;
            }
        void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
        void switchToPrevTab(){ 
            if(cursor->prev == NULL){
                std::cout<< "No previous tab" <<std::endl;
            }
            else{
                cursor = cursor->prev;
                std::cout<<  cursor->url <<std::endl;
                std::cout<< cursor->name <<std::endl;
                std::cout<< cursor->memory<<std::endl;
                }
            }
        void switchToNextTab(){ 
            if(cursor->next == NULL){
                std::cout<< "No next tab" <<std::endl;
            }
            else{
                cursor = cursor->next;
                std::cout<<  cursor->url <<std::endl;
                std::cout<< cursor->name <<std::endl;
                std::cout<< cursor->memory<<std::endl;
            }
        }
        void bookmarkCurrent(){
            std::pair<std::string, std::string> pair1;
            pair1.first = cursor->url;
            pair1.second = cursor->name;
            for(int i=0; i<bm.size(); i++){
                if (pair1.second == bm[i].second){
                    std::cout<< "The bookmark is already added!!"<<std::endl;
                    return;
                }
            }
            bm.push_back(pair1);
            }
        double total_memory(){
            auto curr = head;
            double meme;
            while(curr){
                meme = meme + curr->memory;
                curr = curr->next;
            }
        return meme;
        }
        void showBookmarkTab(){
            std::cout<<"Bookmarks:"<<std::endl;
            for(int i=0; i<bm.size(); i++){
                std::cout<<bm[i].first<<"("<<bm[i].second<<")"<<std::endl;
            }
        }
        void moveCurrentToFirst(){
            tobedelete = tail;
            head->prev = tail;
            tail->next = head;
            (tail->prev)->next = NULL;
            tail = tobedelete->prev;
            head = tobedelete;                 
            head->prev = NULL;
            cursor = head;
            }
        void deleteTab(){
                auto curr = head;
                double meme = curr->memory;
                curr = curr->next;
                while(curr){
                    if(curr->memory > meme){
                    meme = curr->memory;
                    tobedelete = curr;
                    }
                    curr = curr->next;
                }
            std::cout<< tobedelete->name <<" will be delete,  " << tobedelete->memory << " cleared." <<std::endl;
                if (tobedelete == head){
                (tobedelete->next)->prev = NULL;
                head = tobedelete -> next;
                cursor =  head;
                return;
                } else if(tobedelete == tail){
                (tobedelete->prev)->next = NULL;
                tail = tobedelete -> prev;
                cursor = tail; 
                return;
                } 
                (tobedelete-> next )->prev = tobedelete->prev;
                (tobedelete-> prev )->next = tobedelete->next;
            }
        void closeCurrentTab(){
                if (cursor == head){
                (cursor->next)->prev = NULL;
                head = cursor -> next;
                cursor =  head;
                std::cout<< "Now the current tab  = " << cursor->name<< "." <<std::endl;
                return;
                } else if(cursor == tail){
                (cursor->prev)->next = NULL;
                tail = cursor -> prev;
                cursor = tail; 
                std::cout<< "Now the current tab  = " << cursor->name<< "." <<std::endl;
                return;
                } 
                tobedelete = cursor; 
                (cursor-> next )->prev = cursor->prev;
                (cursor-> prev )->next = cursor->next;
                cursor = cursor->next; 
                std::cout<< "Now the current tab  = " << cursor->name<< "." <<std::endl;

    } 
    };
int main(){
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    b1.total_memory();
    b1.deleteTab();
    b1.display();
    return 0;
}