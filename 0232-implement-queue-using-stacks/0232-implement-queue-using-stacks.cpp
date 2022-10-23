class MyQueue {
private:
        int* tab;
        int size;
public:
    
    MyQueue() {
        tab=nullptr;
        size=0;
    }
        
    void push(int x) {
        if(empty()){
            tab=new int[1];
            tab[0]=x;
        }else{
            int*temp=new int[size+1];
            for(int i=0;i<size;i++){
                temp[i]=tab[i];
            }
            temp[size]=x; 
            delete[] tab;
            tab=temp;
            temp=nullptr;
        }
        size++;
    }

    int pop() {
        int val;

        if(!empty()){
            val=tab[0];            
            if(size==1){
                delete[] tab;
                tab=nullptr;
            }else{
                int*temp=new int[size-1];
                for(int i=1;i<size;i++){
                    temp[i-1]=tab[i];
                }
                delete[] tab;
                tab=temp;
                temp=nullptr;
            }
            size--;
        }
        return val;
    }
    
    int peek() {
        if(tab!=nullptr){
            return tab[0];
        }else{
            return -1;
        }
    }
    
    bool empty() {
        if(tab==nullptr){
            return true;
        }else{
            return false;
        }
    }
};