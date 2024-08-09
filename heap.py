# lets write a code to implement heaps
# here we will implement the min heap where the minimum value is at the root

class Heap:
    def __init__(self):
        self.heap = [0]

    # lets push a value into the heap
    def push(self, val):
        # we will insert the value at the last available position
        self.heap.append(val)
        # now lets set the index
        i = len(self.heap) - 1

        # now we will compare the value with the remaining values because we need to maintain 
        # the order and structure of the heap
        # for this the index should be greater than 1 and as per the formulas
        # left child = 2 * i
        # right child = 2*i + 1
        # root = i // 2
        while i > 1 and self.heap[i] < self.heap[i // 2]:
            # now we will swap if the condition is true
            temp = self.heap[i]
            self.heap[i] = self.heap[i // 2]
            self.heap[i // 2] == temp
            # update the pointer to the root
            i = i // 2

    # now lets see how we can remove the value from the heap
    def pop(self):
        # if there are no elements in the heap
        if len(self.heap) == 1:
            return None
        # if there is only one then we just pop it
        if len(self.heap) == 2:
            return self.heap.pop()
        
        # now we need to remove the root node
        res = self.heap[1]
        # now we will move the last value to the root
        self.heap[1] = self.heap.pop()
        # set the pointer to 1
        i = 1
        # now we have to check if there are any nodes and other conditions
        while 2 * i < len(self.heap):
            if (2 * i + 1 < len(self.heap) and self.heap[2 * i + 1] < self.heap[2 * i] and self.heap[i] > self.heap[2 * i + 1]):
                # swap the right child
                temp = self.heap[i]
                self.heap[i] = self.heap[2 * i + 1]
                self.heap[2 * i + 1] = temp
                # update the pointer
                i = 2 * i + 1
            # now if the left child is smaller
            elif self.heap[i] > self.heap[2 * i]:
                # we will swap
                temp = self.heap[i]
                self.heap[i] = self.heap[2 * i]
                self.heap[2 * i] = temp
                i = 2 * i
            else:
                break
        return res