/**
 * @file circ_list.h
 * @author Pontus Brusewitz (brusewitz_94@hotmail.com)
 * @brief A multiple instance circular singly linked list queue
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

struct list_t;

namespace list
{
    /**
     * @brief This funtion is used to create an instance(linked list), consisting of nodes that are linked together as a circular linked list.
     *
     * @param size It's the size of the linked list, size > 3
     * @return list_t* A pointer to the created list instance
     */
    list_t *create(std::size_t size);

    /**
     * @brief This funktion is used to insert data into the existing nodes and overwrites the oldest data if the list is full
     *
     * @param lst a pointer to the list
     * @param data the data that should be inserted
     * @return true if data is inserted correct
     * @return false if data isn't inserted correct
     */
    bool insert(list_t *lst, int data);

    /**
     * @brief This function is used to read data from the head of the list, it overwrites the data and moves head to the next node
     *
     * @param lst a pointer to the linked list
     * @return int It's the value of the header node
     */
    int read(list_t *lst);

    /**
     * @brief This function is used to clear all the data that's stored inside the linked lists nodes
     *
     * @param lst a pointer to the list
     */
    void clear(list_t *lst);

    /**
     * @brief Gets the count of nodes that currently store data.
     *
     * @param lst a pointer to the linked list
     * @return std::size_t is a number of the occupied nodes
     */
    std::size_t dataCount(list_t *lst);

    /**
     * @brief This function is used to check if the linked list is full or not
     *
     * @param lst a pointer to the linked list
     * @return true is returned if the list is full
     * @return false is returned if the list isn't full
     */
    bool isFull(list_t *lst);

    /**
     * @brief This function is used to resize the size of the linked list(change amount of nodes), new_size > 3.
     *
     * @param lst a pointer to the linked list
     * @param new_size is the wanted size of the linked list
     * @return true if the linked list was resized successfully
     * @return false if the linked list wasn't resized successfully
     */
    int resize(list_t *lst, std::size_t new_size);

    /**
     * @brief This function is used to delete all the nodes and the instance of the linked list.
     *
     * @param lst lst a reference to the pointer of the list.
     */
    void destroy(list_t *&lst);
}

#endif
