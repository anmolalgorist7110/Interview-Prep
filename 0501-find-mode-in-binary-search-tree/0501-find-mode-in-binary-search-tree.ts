/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function findMode(root: TreeNode | null): number[] {
    // check if root is only node if true no need to traverse just return root value in array
    if(!root.left && !root.right) return [root.val]
    // declare hash map to collect frequency
    const hash = new Map<number, number>();
    // declare dfs function:
    const dfs = (root: TreeNode | null) => {
        // check if we have a root
        if(!root) return root;
        // update frequency of current root value
        hash.set(root.val, hash.get(root.val) ? hash.get(root.val) + 1 : 1);
        // traverse to left
        dfs(root.left)
        // traverse to right
        dfs(root.right)
    }
    // call dfs function with root
    dfs(root);
    // declare result array
    const result: number[] = []
    // declare mode variable
    let mode = 0;
    // iterate over hash map to find mode:
    for(let [key, value] of hash) {
        // on each iteration find max value for mode
        mode = Math.max(mode, value)
    }
    // iterate over hash map to gather result
    for(let [key, value] of hash) {
        // if value of key equals to mode then we push key to result array
        if(value === mode) result.push(key)
    }
    // return result array
    return result
};