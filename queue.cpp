#include "queue.h"
#include <new>
#include <cstddef>
#include <iostream>

struct node_t
{
    int data;
    node_t *next;
};

struct list_t
{
    node_t *head;
    node_t *tail;
    std::size_t size;
    std::size_t count;
};

list_t *list::create(std::size_t size)
{
    if (size <= 3)
    {
        return nullptr;
    }

    list_t *lst = new (std::nothrow) list_t;
    if (lst != nullptr)
    {
        lst->head = nullptr;
        lst->tail = nullptr;
        lst->size = size;
        lst->count = 0;

        node_t *firstNode{new (std::nothrow) node_t{0, nullptr}};
        if (firstNode == nullptr)
        {
            delete (lst);
            lst = nullptr;
            return nullptr; // Returnera nullptr om första noden inte kunde skapas
        }

        lst->head = firstNode;
        lst->tail = firstNode;

        node_t *prevNode = firstNode;
        for (std::size_t i = 1; i < size; ++i)
        {
            node_t *newNode{new (std::nothrow) node_t{0, nullptr}};
            if (newNode == nullptr)
            {
                clear(lst);
                delete lst;
                lst = nullptr;
                return nullptr;
            }

            prevNode->next = newNode;
            lst->tail = newNode; // Uppdatera tail till den nya sista noden
            prevNode = newNode;  // Flytta prevNode till den senaste noden
        }

        // Koppla tail till head för att skapa en cirkel
        lst->tail->next = lst->head;
    }
    return lst;
}

bool list::insert(list_t *lst, int data)
{
    bool status{false};

    if (lst != nullptr)
    {
        if (lst->head != nullptr)
        {
            if (lst->count == lst->size) // If list is full
            {
                lst->tail = lst->tail->next;
                lst->tail->data = data;
                lst->head = lst->head->next;
            }
            else // If list isn't full
            {
                lst->tail = lst->tail->next;
                lst->tail->data = data;
                lst->count++;
            }
            status = true;
        }
    }
    return status;
}

int list::read(list_t *lst)
{
    if (lst == nullptr || lst->head == nullptr || lst->count == 0)
    {
        throw std::invalid_argument("List is null or empty."); // Kasta ett mer relevant undantag
    }

    int data = lst->head->data;
    lst->head = lst->head->next;
    lst->count--;
    return data;
}

void list::clear(list_t *lst)
{
    if (lst != nullptr)
    {
        while (lst->count > 0)
        {
            lst->head = lst->head->next;
            lst->count--;
        }
    }
    return;
}

std::size_t list::dataCount(list_t *lst)
{
    if (lst == nullptr)
    {
        return 0; // Om listan är null, returnera 0
    }
    return lst->count; // Returnera antalet noder med data
}

bool list::isFull(list_t *lst)
{
    return lst != nullptr && lst->count == lst->size;
}

int list::resize(list_t *lst, std::size_t new_size)
{
    if (new_size <= 3)
    {
        std::cerr << "Error: Queue size must be greater than 3.\n";
        return -1; // Error code -1 for unvalid size
    }

    while (lst->size < new_size) // Add nodes
    {
        node_t *newNode{new (std::nothrow) node_t{0, lst->tail->next}};
        if (newNode != nullptr)
        {
            lst->tail->next = newNode;
            lst->size++;
        }
        else
        {
            std::cerr << "Error: Memory allocation failed while resizing.\n";
            return -2; // Error code -2 for bad memory allocation
        }
    }
    while (lst->size > new_size) // Erase nodes
    {
        node_t *oldNode = lst->tail->next;
        lst->tail->next = oldNode->next;
        if (oldNode == lst->head)
        {
            lst->head = lst->tail->next;
            lst->count--;
        }
        delete oldNode;
        oldNode = nullptr;
        lst->size--;
    }

    return 0;
}

void list::destroy(list_t *&lst)
{
    if (lst != nullptr)
    {
        for (std::size_t i = 0; i < lst->size; i++)
        {
            node_t *next{lst->head->next};
            delete lst->head;
            lst->head = next;
        }
        lst->head = nullptr;
        lst->count = 0;
        lst->size = 0;
        delete lst;
        lst = nullptr;
    }
    return;
}