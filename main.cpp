#include "queue.h"
#include <cassert> //för assert()
#include <iostream>

int main(void)
{
    list_t *mylist = list::create(4);

    assert(mylist != nullptr);
    assert(0 == list::dataCount(mylist));
    assert(1 == list::insert(mylist, 1));
    assert(1 == list::dataCount(mylist));
    assert(1 == list::insert(mylist, 2));
    assert(1 == list::insert(mylist, 3));
    assert(0 == list::isFull(mylist));
    assert(1 == list::insert(mylist, 4));
    assert(1 == list::isFull(mylist));

    assert(1 == list::read(mylist));
    assert(3 == list::dataCount(mylist));
    assert(1 == list::insert(mylist, 5));

    assert(0 == list::resize(mylist, 6));
    assert(-1 == list::resize(mylist, 3));
    assert(1 == list::insert(mylist, 6));
    assert(5 == list::dataCount(mylist));
    assert(0 == list::resize(mylist, 4));
    assert(1 == list::isFull(mylist));

    assert(3 == list::read(mylist));
    list::clear(mylist);
    assert(0 == list::dataCount(mylist));

    list_t *thelist = list::create(5);
    assert(1 == list::insert(thelist, 1));
    assert(1 == list::insert(thelist, 3));
    assert(1 == list::insert(thelist, 3));
    assert(1 == list::insert(thelist, 7));

    assert(1 == list::insert(mylist, 7));
    assert(1 == list::insert(mylist, 10));
    list::destroy(mylist);
    assert(mylist == nullptr);

    while (list::dataCount(thelist))
    {
        std::cout << list::read(thelist) << " ";
    }
    std::cout << std::endl;

    list::clear(thelist);
    list::destroy(thelist);
    assert(thelist == nullptr);

    return 0;
}
