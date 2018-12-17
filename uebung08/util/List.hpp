/*
 * List.hpp
 *
 *  @date 02.12.2018
 *  @author Thomas Wiemann
 * 
 *  Copyright (c) 2018 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */


#ifndef LIST_H
#define LIST_H

namespace asteroids
{

/**
 * @brief   A simple generic list class
 */
template<typename T> class List
{
   public:

      /**
       * @brief Constructs an empty list.
       */
      List<T>();
      /**
       * @brief  Destructor. Frees the generated nodes.
       */
      ~List<T>();
      /**
       * @brief Inserts an item into the list, i.e. a new node
       *        constaining @ref item is created.
       * @param item To be inserted
       *
       */
      void push_back(T item);

      /**
       * @brief Iterates over all items in the list and calls
       * the given function @ref do_something(...) for
       * every item stored in the list.
       *
       * @param do_something Function pointer to apply to all elements.
       */
      void for_each(void (*do_something)(T& item));


      class Interator
      {
      public:
            explicit Interator(typename List<T>::Node* num):index(num){}
            friend class List;

            bool operator!=(const Interator& other)
            {
                  return (index != other.index);
            }
            const Interator& operator++()
            {
                  index = index->next;
                  return *this;
            }

            T& operator*() const
            {
                  return index->data;
            }

      private:
            typename List<T>::Node* index;
      };

            /**
       * @brief 
       */
      Interator begin()
      {
            return List::Interator(m_root);
      }

      /**
       * @brief 
       */
      Interator end()
      {
            return List::Interator(nullptr);
      }

private:

      /**
       * @brief Struct to represent an inner node of the list.
       */
      class Node {
      public:
            Node( T _data, Node* _next) : data(_data), next(_next) {};
            friend class List;
      private:
            T data;
            Node* next;
      };

      Node* m_root;
};

}

#include "List.tcc"

#endif
/* end of include guard: LIST_H */
