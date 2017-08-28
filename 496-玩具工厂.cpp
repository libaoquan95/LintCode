#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

/**
 * http://www.lintcode.com/zh-cn/problem/toy-factory/-496-玩具工厂
 */
 /**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const = 0;
};

class Dog : public Toy {
    // Write your code here
public:
    void talk() const {
        printf("Wow\n");
    }
};

class Cat : public Toy {
    // Write your code here
    void talk() const {
        printf("Meow\n");
    }
};

class ToyFactory {
public:
    /**
    * @param type a string
    * @return Get object of the type
    */
    Toy* getToy(string type) {
        // Write your code here
        Toy* toy;
        if (type == "Dog") {
            toy = new Dog();
        }
        else {
            toy = new Cat();
        }

        return toy;
    }
};

int main()
{
    ToyFactory tf = ToyFactory();
    Toy *toy = tf.getToy("Dog");
    toy->talk();

    toy = tf.getToy("Cat");
    toy->talk();

    return 0;
}