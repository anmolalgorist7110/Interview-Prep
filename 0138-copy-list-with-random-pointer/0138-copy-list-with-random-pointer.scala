/**
 * Definition for a Node.
 * class Node(var _value: Int) {
 *   var value: Int = _value
 *   var next: Node = null
 *   var random: Node = null
 * }
 */

object Solution {
  import scala.collection.mutable
  
  def copyRandomList(head: Node): Node = {
    val map = mutable.Map[Node, Node]()

    def copy(node: Node): Node = {
      if (node == null) return null
      
      if (map.contains(node)) {
        return map(node)
      }
      
      val newNode = new Node(node.value)
      map.put(node, newNode)
      newNode.next = copy(node.next)
      newNode.random = copy(node.random)
      newNode
    }

    copy(head)
  }
}