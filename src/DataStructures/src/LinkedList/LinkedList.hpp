#pragma once

#include <iostream>
#include <memory>
#include <string>

template <typename T> class LinkedListNode {

private:
  static std::shared_ptr<LinkedListNode> s_first_node;
  static std::shared_ptr<LinkedListNode> s_last_node;
  static size_t s_chainSize;
  T m_data;
  std::unique_ptr<LinkedListNode> m_next;
  std::unique_ptr<LinkedListNode> m_previous;
  // Dangerous functions, one should not delete the pointers of the return
  // values.
  [[nodiscard]] auto getNextUnsafe() -> LinkedListNode const * {
    return m_next.get();
  }
  [[nodiscard]] auto getPreviousUnsafe() -> LinkedListNode const * {
    return m_previous.get();
  }

public:
  [[nodiscard]] auto getNodeData() -> T { return m_data; }

  [[nodiscard]] auto getAndOwnNext() -> std::unique_ptr<LinkedListNode> {
    return std::unique_ptr<LinkedListNode>(m_next.release());
  }

  [[nodiscard]] auto getAndOwnPrevious() -> std::unique_ptr<LinkedListNode> {
    return std::unique_ptr<LinkedListNode>(m_previous.release());
  }

  /**
   * @brief Set the Next object
   *
   * @param node
   * @return std::unique_ptr<LinkedListNode> The old chain of this object
   */
  auto setNext(LinkedListNode &node) -> std::unique_ptr<LinkedListNode> {
    auto old_node_ptr = m_next.release();
    m_next.reset(&node);
    // drop the node's backward chain.
    if (this != node.getPreviousUnsafe()) {
      node.dropBackwardChain();
      node.setPrevious(*this);
    }
    return std::unique_ptr<LinkedListNode>(old_node_ptr);
  }

  /**
   * @brief Set the Previous object
   *
   * @param node
   * @return std::unique_ptr<LinkedListNode> The old chain of this object
   */
  auto setPrevious(LinkedListNode &node) -> std::unique_ptr<LinkedListNode> {
    auto old_node_ptr = m_previous.release();
    m_previous.reset(&node);
    // drop the node's forward chain.
    if (this != node.getNextUnsafe()) {
      node.dropForwardChain();
      node.setNext(*this);
    }
    return std::unique_ptr<LinkedListNode>(old_node_ptr);
  }

  auto dropForwardChain() -> std::unique_ptr<LinkedListNode> {
    if (m_next) {
      return std::unique_ptr<LinkedListNode>(m_next.release());
    }
    return nullptr;
  }

  auto dropBackwardChain() -> std::unique_ptr<LinkedListNode> {
    if (m_previous) {
      return std::unique_ptr<LinkedListNode>(m_previous.release());
    }
    return nullptr;
  }

  auto printForwardChilds() const -> void {
    printNodeInfo();
    if (m_next) {
      m_next->printForwardChilds();
    }
  }

  auto printBackwardChilds() const -> void {
    printNodeInfo();
    if (m_previous) {
      m_previous->printBackwardChilds();
    }
  }

  auto printNodeInfo() const -> void {
    std::cout << "node: " << this << ", data: " << m_data << std::endl;
  }

  explicit LinkedListNode(T data) : m_data(data) {
    if (!s_first_node) {
      s_first_node.reset(this);
    }
    if (!s_last_node) {
      s_last_node.reset(this);
    }
    s_chainSize += 1;
  }

  virtual ~LinkedListNode() {
    s_chainSize -= 1;
    if (m_next && m_previous) {
      m_next->setPrevious(*m_previous);
      m_next.release();
      m_previous.release();
    } else if (m_next) {
      // update the first element
      s_first_node.reset(m_next.release());
    } else if (m_previous) {
      // update the last element
      s_last_node.reset(m_previous.release());
    }
  };
};

template <typename T>
std::shared_ptr<LinkedListNode<T>> LinkedListNode<T>::s_first_node{nullptr};

template <typename T>
std::shared_ptr<LinkedListNode<T>> LinkedListNode<T>::s_last_node{nullptr};

template <typename T> size_t LinkedListNode<T>::s_chainSize{0};