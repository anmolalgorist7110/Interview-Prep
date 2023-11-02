type TTreeNode = {
    val: number;
    left: TTreeNode | null;
    right: TTreeNode | null;
};

function averageOfSubtree(root: TTreeNode | null): number {
    let count = 0;

    const dfs = (node: TTreeNode | null): [number, number] => {
        if (!node) {
            return [0, 0];
        }

        const [leftSum, leftCount] = dfs(node.left);
        const [rightSum, rightCount] = dfs(node.right);

        const totalSum = leftSum + rightSum + node.val;
        const totalCount = leftCount + rightCount + 1;

        const subtreeAverage = Math.floor(totalSum / totalCount);

        if (subtreeAverage === node.val) {
            count++;
        }

        return [totalSum, totalCount];
    };

    dfs(root);

    return count;
}