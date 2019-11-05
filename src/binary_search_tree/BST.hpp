#pragma once

#include <stdlib.h>
#include <cstddef>
#include <cstdint>
#include <stdexcept>

#include <iostream>

namespace datastruct { namespace bst
{
  template<typename K, typename T>
  class BST {

  public:
    /** Constructor **/
    BST();

    /** Destructor **/
    ~BST();

    /**
     * Inserts an element in the tree
     */
    void insert(const K iKey, const T iValue);

    /**
     * Finds the element with the smallest key, if exists
     */
    const T& find_min() const;

    /**
     * Finds the element with the greatest key, if exists
     */
    const T& find_max() const;

    /**
     * Finds an element, if exists
     */
    const T& find(const K& iKey) const;

    /**
     * Removes an element given its key, if exists
     */
    void remove(const K& iKey);

    /**
     * Gets the tree as a string
     */
    std::string get_as_string();

  private:

    struct Node
    {
      K _key;
      T _value;
      //size_t _size;
      Node *_left, *_right;
      Node(K iKey, T iValue) : _key(iKey), _value(iValue), _left(NULL), _right(NULL)
      {}
    };

    Node *_root;

    /**
     * Safely deletes all nodes in the tree
     */
    void clean(Node* iRoot);

    /**
     * Inserts an element in the tree (interal use)
     */
    BST<K,T>::Node* insert(Node* iNode, const K iKey, const T iValue);

    /**
     * Traveres the the tree inorder
     */
    std::string inorder_traversal(Node* iNode);

  };

  template<typename K, typename T>
  BST<K,T>::BST()
  : _root(NULL)
  {}

  template<typename K, typename T>
  BST<K,T>::~BST() {
    clean(_root);
  }

  template<typename K, typename T>
  void BST<K,T>::clean(Node* iRoot) {
    if(iRoot != NULL) {
      clean(iRoot->_left);
      clean(iRoot->_right);
      delete iRoot;
    }
  }

  template<typename K, typename T>
  void BST<K,T>::insert(const K iKey, const T iValue) {
    if(_root == NULL) {
      _root = new Node(iKey, iValue);
      return;
    }
    if(iKey < _root->_key) {
      _root->_left = insert(_root->_left, iKey, iValue);
    }
    else{
      _root->_right = insert(_root->_right, iKey, iValue);
    }

  }

  template<typename K, typename T>
  typename BST<K,T>::Node* BST<K,T>::insert(Node* iNode, const K iKey, const T iValue) {
    if(iNode == NULL) {
      Node* tmp = new Node(iKey, iValue);
      return tmp;
    }

    if(iKey < iNode->_key) {
      iNode->_left = insert(iNode->_left, iKey, iValue);
    }
    else {
      iNode->_right = insert(iNode->_right, iKey, iValue);
    }
    return iNode;
  }

  template<typename K, typename T>
  const T& BST<K,T>::find_min() const {
    throw std::runtime_error("Not implemented");
  }


  template<typename K, typename T>
  const T& BST<K,T>::find_max() const {
    throw std::runtime_error("Not implemented");
  }


  template<typename K, typename T>
  const T& BST<K,T>::find(const K& iKey) const {
    throw std::runtime_error("Not implemented");
  }

  template<typename K, typename T>
  void BST<K,T>::remove(const K& iKey) {
    throw std::runtime_error("Not implemented");
  }

  template<typename K, typename T>
  std::string BST<K,T>::get_as_string() {
    //TODO Add enum to choose traversal
    return inorder_traversal(_root);
  }

  template<typename K, typename T>
  std::string BST<K,T>::inorder_traversal(Node* iNode) {
    if(iNode == NULL) {
      return "";
    }
    std::string aLeft = inorder_traversal(iNode->_left);
    std::string aRight = inorder_traversal(iNode->_right);
    return aLeft + ":" + std::to_string(iNode->_value) + ":" + aRight;
  }


}}
