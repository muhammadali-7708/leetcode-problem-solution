class ProductOfNumbers {
public:
    vector<int> prefix; // stores running product

    ProductOfNumbers() {
        // nothing to do here
    }
    
    void add(int num) {
        if (num == 0) {
            // 0 kills everything before it
            // so clear the list and start fresh
            prefix.clear();
        } else {
            if (prefix.empty()) {
                prefix.push_back(num);
            } else {
                // new product = old product * num
                prefix.push_back(prefix.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        // If k is bigger than our list, it means
        // the last k numbers must include a 0
        if (k > prefix.size()) {
            return 0;
        }
        // If k == size, product is just the last prefix
        if (k == prefix.size()) {
            return prefix.back();
        }
        // Otherwise: total / product_before_last_k
        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */