
//TC-O(1) - for addition, and get product. SC-O(N)
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        // If zero occurs, reset the prefix products.
        if(num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            // Store the product of all elements
            // since the most recent zero.
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {

        // If k is greater than the number of elements
        // since the most recent zero, the range contains zero.
        if(k >= prefix.size()) {
            return 0;
        }

        // Divide the total prefix product by the
        // prefix product before the last k elements.
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};


//TC-O(K) for get product and O(1) for add
class ProductOfNumbers {
public:
    vector<int>stream;
    ProductOfNumbers() {

    }
    
    void add(int num) {
        this->stream.push_back(num);
    }
    
    int getProduct(int k) {
        
        int ptr=this->stream.size()-1;
        int prod = 1;
        while(k--){
            prod *= stream[ptr];
            ptr--;
        }

        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */