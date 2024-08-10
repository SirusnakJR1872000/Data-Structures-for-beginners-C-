// now we will impelement heaps 
// here we are going to implemenet a min heap where the root is the min value and is true at every level

# include <vector>

using std :: vector;

class Heap {
    public:
        vector<int> heap_;

        Heap() {
            heap_.push_back(0);
        }

        void push(int val) {
            heap_.push_back(val);
            int i = heap_.size() - 1;

            while (i > 1 && heap_[i] < heap_[i / 2]) {
                int temp = heap_[i];
                heap_[i] = heap_[i / 2];
                heap_[i / 2] = temp;
                i = i / 2;
            }
        }

        int pop() {
            if (heap_.size() == 1) {
                return -1;
            }
            if (heap_.size() == 2) {
                int res = heap_[heap_.size() - 1];
                heap_.pop_back();
                return res;
            }

            int res = heap_[1];
            heap_[1] = heap_[heap_.size() - 1];
            heap_.pop_back();
            int i = 1;

            while (2 * i < heap_.size()) {
                if (2 * i + 1 < heap_.size() && heap_[2 * i + 1] < heap_[2 * i] && heap_[i] > heap_[2 * i + 1]) {
                    int temp = heap_[i];
                    heap_[i] = heap_[2 * i + 1];
                    heap_[2 * i + 1] = temp;
                    i = 2 * i + 1;
                }
                else if (heap_[i] > heap_[2 * i]) {
                    int temp = heap_[i];
                    heap_[i] = heap_[2 * i];
                    heap_[2 * i] = temp;
                    i = 2 * i + 1;
                }
                else {
                    break;
                }
            }
            return res;
        }

        void heapify(vector<int>& arr) {
            arr.push_back(arr[0]);

            heap_ = arr;
            int curr = (heap_.size() - 1) / 2;
            while (curr > 0) {
                int i = curr;
                while (2 * i < heap_.size()) {
                    if (2 * i + 1 < heap_.size() && heap_[2 * i + 1] < heap_[2 * i] && heap_[i] > heap_[2 * i + 1]) {
                        int temp = heap_[i];
                        heap_[i] = heap_[2 * i + 1];
                        heap_[2 * i + 1] = temp;
                        i = 2 * i + 1;
                    }
                    else if (heap_[i] > heap_[2 * i]) {
                        int temp = heap_[i];
                        heap_[i] = heap_[2 * i];
                        heap_[2 * i] = temp;
                        i = 2 * i;
                    }
                    else {
                        break;
                    }
                }
                curr --;
            }
        }
};