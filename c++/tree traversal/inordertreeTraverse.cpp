
class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

public class InorderTraversal {

    // Function for inorder traversal
    void inorder(Node node) {
        if (node == null) {
            return;
        }

        // Traverse the left subtree
        inorder(node.left);

        // Visit the root
        System.out.print(node.data + " ");

        // Traverse the right subtree
        inorder(node.right);
    }

    public static void main(String[] args) {
        InorderTraversal tree = new InorderTraversal();
        
        // Construct a sample tree:
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Perform inorder traversal
        System.out.println("Inorder traversal:");
        tree.inorder(root);
    }
}
