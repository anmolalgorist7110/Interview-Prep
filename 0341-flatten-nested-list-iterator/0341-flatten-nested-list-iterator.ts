// N - number of elements
// Time: O(N)
// Space: O(N)
class NestedIterator {
    origList: NestedInteger[] = [];
    #stack: number[] = [];
    #index: number = -1;

    constructor(nestedList: NestedInteger[]) {
		this.origList = nestedList;
    }

    #flatten(curr: NestedInteger): void {
        if (curr.isInteger()) {
            this.#stack.push(curr.getInteger());
        } else {
            const list = curr.getList();

            for (let i = list.length - 1; i >= 0; i--) {
                this.#flatten(list[i]);
            }
        }
    }

    hasNext(): boolean {
        if (this.#stack.length) {
            return true;
        }

        while (this.#stack.length === 0 &&
            ++this.#index < this.origList.length) {
            this.#flatten(this.origList[this.#index]);
        }

        return this.#stack.length > 0;
    }

	next(): number {
        this.hasNext();
        return this.#stack.pop();
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new NestedIterator(nestedList)
 * var a: number[] = []
 * while (obj.hasNext()) a.push(obj.next());
 */